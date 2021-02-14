/* Copyright 2018 Noah Frederick
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "my.h"
/* #include "my_leader.h" */
/* #include "dynamic_macro.h" */

#ifdef AUDIO_ENABLE
float plover_song[][2] = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif  // AUDIO_ENABLE

#ifndef NO_DEBUG
extern layer_state_t layer_state;
extern uint32_t default_layer_state;
extern debug_config_t debug_config;
#endif  // !NO_DEBUG

#ifdef RGB_MATRIX_ENABLE
void enable_rgb_without_any_leds_by_default(void) {
  rgblight_enable();
  rgb_matrix_config.hsv.v = UINT8_MAX;
  rgb_matrix_increase_val();
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif  // RGB_MATRIX_ENABLE

#ifdef RGB_MATRIX_ENABLE
void rgb_set_brightness_to_zero(void) {
  rgb_matrix_config.hsv.v = 0;
  rgb_matrix_decrease_val();
}
#endif  // RGB_MATRIX_ENABLE

void keyboard_post_init_user() {
  set_single_persistent_default_layer(NORMAN_LAYER);

#ifdef RGB_MATRIX_ENABLE
  enable_rgb_without_any_leds_by_default();
#endif  // RGB_MATRIX_ENABLE
}

// Redefine process_record_keymap() in keymap definitions.
__attribute__((weak)) bool process_record_keymap(uint16_t keycode,
                                                 keyrecord_t* record) {
  return true;
}

bool unregister_mod(int mod) {
  const bool down = get_mods() & MOD_BIT(mod);
  if (!down) return false;
  unregister_code(mod);
  return true;
}

void register_mod(int mod, bool down) {
  if (down) {
    register_code(mod);
  }
}

bool prg_key_mod(const char* text, int mod) {
  const bool down = get_mods() & MOD_BIT(mod);
  if (!down || !text) return false;

  unregister_code(mod);
  send_string_P(text);
  register_code(mod);
  return true;
}

void prg_key(keyrecord_t* record, const char* norm, const char* shift,
             const char* ctrl) {
  if (!record->event.pressed) return;

  if (prg_key_mod(shift, KC_LSHIFT)) return;
  if (prg_key_mod(shift, KC_RSHIFT)) return;
  if (prg_key_mod(ctrl, KC_LCTRL)) return;
  if (prg_key_mod(ctrl, KC_RCTRL)) return;

  send_string_P(norm);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#if defined(ENABLE_NORMAN_ENGRUS)
  static uint16_t shift_english_timer;
  static uint16_t shift_russian_timer;
  static uint16_t kShiftTimeout = 150;
#endif  // defined(ENABLE_NORMAN_ENGRUS)

  /* if (!process_record_dynamic_macro(keycode, record)) { */
  /*   return false; */
  /* } */

  /* if (!process_leader(keycode, record)) { */
  /*   return false; */
  /* } */

  if (!process_record_keymap(keycode, record)) {
    return false;
  }

  switch (keycode) {
#if defined(ENABLE_GAMEPAD)
    case GAMEPD:
      if (record->event.pressed) {
        layer_on(GAMEPAD_LAYER);
      }
      return false;
#endif  // defined(ENABLE_GAMEPAD)
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(QWERTY_LAYER);
#if defined(ENABLE_GAMEPAD)
        layer_off(GAMEPAD_LAYER);
#endif  // defined(ENABLE_GAMEPAD)
#if defined(ENABLE_NORMAN_ENGRUS)
        layer_off(NORMAN_RUS_LAYER);
#endif  // defined(ENABLE_NORMAN_ENGRUS)
      }
      return false;
    case NORMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(NORMAN_LAYER);
#if defined(ENABLE_GAMEPAD)
        layer_off(GAMEPAD_LAYER);
#endif  // defined(ENABLE_GAMEPAD)
#if defined(ENABLE_NORMAN_ENGRUS)
        layer_off(NORMAN_RUS_LAYER);
#endif  // defined(ENABLE_NORMAN_ENGRUS)
      }
      return false;
#if defined(ENABLE_NORMAN_ENGRUS)
    case ENGLISH:
      if (record->event.pressed) {
        shift_english_timer = timer_read();
        register_code(KC_LSHIFT);
      } else {
        unregister_code(KC_LSHIFT);
        if (timer_elapsed(shift_english_timer) < kShiftTimeout) {
          layer_off(NORMAN_RUS_LAYER);

          SEND_STRING(SS_TAP(X_F20));
        }
      }
      return false;
    case RUSSIAN:
      if (record->event.pressed) {
        shift_russian_timer = timer_read();
        register_code(KC_LSHIFT);
      } else {
        unregister_code(KC_LSHIFT);
        if (timer_elapsed(shift_russian_timer) < kShiftTimeout) {
          layer_on(NORMAN_RUS_LAYER);

          SEND_STRING(SS_LSFT(SS_TAP(X_F20)));
        }
      }
      return false;
#endif  // defined(ENABLE_NORMAN_ENGRUS)
    case STCH_EX:
      if (record->event.pressed) {
#if 0
        layer_off(CAMEL_LAYER);
        layer_off(KEBAB_LAYER);
        layer_off(SNAKE_LAYER);
#endif

        layer_off(NORMAL_PROGRAMMING_LAYER);
      }
      return false;
    case SEND_VERSION:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION
                                 " (" QMK_BUILDDATE ")");
      }
      return false;
    case SEND_MAKE:
      if (record->event.pressed) {
        SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP
#if defined(__arm__)
                    ":dfu-util"
#elif (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || \
       defined(BOOTLOADER_QMK_DFU))
                    ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
                    ":teensy"
#elif defined(BOOTLOADER_CATERINA)
                    ":avrdude"
#endif
                    SS_TAP(X_ENTER));
      }
      return false;
#ifndef NO_DEBUG
    case MBL_LYR:
      if (record->event.pressed) {
        // debug_config.enable = 1;
        print("  layer_debug: ");
        xitoa(layer_state, 16, 8);
        /* layer_debug(); */
        println();
        print("d layer_debug: ");
        xitoa(default_layer_state, 16, 8);
        /* default_layer_debug(); */
        println();
      }
      return false;
#endif  // !NO_DEBUG
#ifdef RGB_MATRIX_ENABLE
    case MYRGB:
      if (record->event.pressed) {
        enable_rgb_without_any_leds_by_default();
      }
      return false;
    case MYRGBDM:
      if (record->event.pressed) {
        rgb_set_brightness_to_zero();
      }
      return false;
#endif  // RGB_MATRIX_ENABLE
    case NPRG_CM: {
      const bool SHIFTED = (get_mods() & MOD_BIT(KC_LSHIFT)) ||
                           (get_mods() & MOD_BIT(KC_RSHIFT)) ||
                           (get_mods() & MOD_BIT(KC_LGUI)) ||
                           (get_mods() & MOD_BIT(KC_RGUI));

      if (record->event.pressed) {
        if (SHIFTED) {
          // Required to produce '<'
          SEND_STRING(",");
        } else {
          // FIXME: doesn't work due to this change:
          // https://github.com/qmk/qmk_firmware/pull/8832
          set_oneshot_layer(NORMAL_PROGRAMMING_LAYER, ONESHOT_START);
        }
      } else {
        if (SHIFTED) {
          // noop
        } else {
          clear_oneshot_layer_state(ONESHOT_PRESSED);
        }
      }
      return false;
    }
    case NPRG_SP:
      if (record->event.pressed) {
        SEND_STRING(", ");
      }
      break;
#define PRG1(name, norm)               \
  case PRG_##name:                     \
    prg_key(record, PSTR(norm), 0, 0); \
    break;
#define PRG2(name, norm, shift)                  \
  case PRG_##name:                               \
    prg_key(record, PSTR(norm), PSTR(shift), 0); \
    break;
#define PRG3(name, norm, shift, ctrl)                     \
  case PRG_##name:                                        \
    prg_key(record, PSTR(norm), PSTR(shift), PSTR(ctrl)); \
    break;

      // 528 bytes free with single-char keys
      // 870 bytes free after moving single-char keys to the matrix

      /* PRG1(H01, "%") */
      PRG2(H02, "&", "&&")
      /* PRG1(H03, "?") */
      PRG3(H04, "+", "+=", "++")
      PRG3(H05, "@", "@q", "@@")
      /* PRG1(H06, "$") */
      /* PRG1(H07, "_") */
      PRG2(H08, "[", "[]")
      PRG2(H09, "]", "->")
      PRG2(H10, "!", "!=")

      PRG2(M01, "/", "/=")
      PRG2(M02, "(", "()")
      PRG3(M03, "=", "==", "=>")
      /* PRG1(M04, ";") */
      PRG2(M05, "{", "{}")
      /* PRG1(M06, "}") */
      PRG3(M07, ":", "::", ":=")
      /* PRG1(M08, "*") */
      /* PRG1(M09, ")") */
      PRG3(M10, "-", "!=", "--")

      /* PRG1(L01, "~") */
      /* PRG1(L02, "`") */
      /* PRG1(L03, "^") */
      /* PRG1(L04, "\"") */
      PRG2(L05, "|", "||")
      /* PRG1(L06, "\\") */
      /* PRG1(L07, ",") */
      PRG2(L08, "#", "<=")
      PRG2(L09, "'", ">=")

      // http://www.keyboard-layout-editor.com/#/gists/db89ac8421bfd94801e004ec7a1c828a
    case PRG_H00:
    case PRG_H11:
      if (record->event.pressed) {
        const bool lshift = unregister_mod(KC_LSHIFT);
        const bool rshift = unregister_mod(KC_RSHIFT);
        const bool lctrl = unregister_mod(KC_LCTRL);
        const bool rctrl = unregister_mod(KC_RCTRL);
        register_code(KC_LCTRL);
        tap_code(KC_E);
        unregister_code(KC_LCTRL);
        if (keycode == PRG_H00) {
          if (lshift || rshift) {
            tap_code(KC_SCOLON);
          } else if (lctrl || rctrl) {
            register_code(KC_LSHIFT);
            tap_code(KC_SCOLON);
            unregister_code(KC_LSHIFT);
          }
          tap_code(KC_ENTER);
        } else {
          tap_code(KC_SPACE);
          register_code(KC_LSHIFT);
          tap_code(KC_LBRC);
          unregister_code(KC_LSHIFT);
          if (!lshift && !rshift) {
            tap_code(KC_ENTER);
          }
        }
        register_mod(KC_RCTRL, rctrl);
        register_mod(KC_LCTRL, lctrl);
        register_mod(KC_RSHIFT, rshift);
        register_mod(KC_LSHIFT, lshift);
      }
      break;
  }

  return true;
}

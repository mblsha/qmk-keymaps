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
                                                 keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        layer_off(SHIFT_PROGRAMMING_LAYER);
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
      bool SHIFTED = (get_mods() & MOD_BIT(KC_LSHIFT)) ||
                     (get_mods() & MOD_BIT(KC_RSHIFT));

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
    case SPRG_H1:
      if (record->event.pressed) {
        SEND_STRING("&&");
      }
      break;
    case SPRG_H3:
      if (record->event.pressed) {
        SEND_STRING("+=");
      }
      break;
    case SPRG_H4:
      if (record->event.pressed) {
        SEND_STRING("@q");
      }
      break;
    case SPRG_H7:
      if (record->event.pressed) {
        SEND_STRING("[]");
      }
      break;
    case SPRG_H8:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      break;
    case SPRG_H9:
      if (record->event.pressed) {
        SEND_STRING("!=");
      }
      break;
    case SPRG_M0:
      if (record->event.pressed) {
        SEND_STRING("/=");
      }
      break;
    case SPRG_M1:
      if (record->event.pressed) {
        SEND_STRING("()");
      }
      break;
    case SPRG_M2:
      if (record->event.pressed) {
        SEND_STRING("==");
      }
      break;
    case SPRG_M4:
      if (record->event.pressed) {
        SEND_STRING("{}");
      }
      break;
    case SPRG_M6:
      if (record->event.pressed) {
        SEND_STRING("::");
      }
      break;
    case SPRG_M9:
      if (record->event.pressed) {
        SEND_STRING("-=");
      }
      break;
    case SPRG_L4:
      if (record->event.pressed) {
        SEND_STRING("||");
      }
      break;
    case SPRG_L7:
      if (record->event.pressed) {
        SEND_STRING("<=");
      }
      break;
    case SPRG_L8:
      if (record->event.pressed) {
        SEND_STRING(">=");
      }
      break;
  }

  return true;
}

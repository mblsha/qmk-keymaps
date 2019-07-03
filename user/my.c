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
#include "my_leader.h"
#include "dynamic_macro.h"

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

void enable_rgb_without_any_leds_by_default(void) {
  rgblight_enable();
  rgb_matrix_config.val = UINT8_MAX;
  rgb_matrix_increase_val();
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
}

void rgb_set_brightness_to_zero(void) {
  rgb_matrix_config.val = 0;
  rgb_matrix_decrease_val();
}

void keyboard_post_init_user() {
  set_single_persistent_default_layer(COLEMAK_LAYER);

  enable_rgb_without_any_leds_by_default();
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
}

// Redefine process_record_keymap() in keymap definitions.
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  if (!process_leader(keycode, record)) {
    return false;
  }

  if (!process_record_keymap(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(QWERTY_LAYER);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(COLEMAK_LAYER);
      }
      return false;
    case STCH_EX:
      if (record->event.pressed) {
        layer_off(CAMEL_LAYER);
        layer_off(KEBAB_LAYER);
        layer_off(SNAKE_LAYER);

        layer_off(NORMAL_PROGRAMMING_LAYER);
        layer_off(SHIFT_PROGRAMMING_LAYER);
      }
      return false;
    case SEND_VERSION:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION " (" QMK_BUILDDATE ")");
      }
      return false;
    case SEND_MAKE:
      if (record->event.pressed) {
        SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP
#if defined(__arm__)
            ":dfu-util"
#elif (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
            ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
            ":teensy"
#elif defined(BOOTLOADER_CATERINA)
            ":avrdude"
#endif
            SS_TAP(X_ENTER));
      }
      return false;
    case MYRGB:
      if (record->event.pressed) {
        enable_rgb_without_any_leds_by_default();
      }
      break;
    case MYRGBDM:
      if (record->event.pressed) {
        rgb_set_brightness_to_zero();
      }
      break;
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

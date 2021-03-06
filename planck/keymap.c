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

#include QMK_KEYBOARD_H
#include "my.h"
#include "my_dynamic_macro.h"

// clang-format off
#if 0
  /* Shift-Numeric layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │           │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [GAMEPAD_LAYER] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  _________________QWERTY_L1_________________ _________________QWERTY_R1_________________  KC_BSPC,
    KC_ESC,  _________________QWERTY_L2_________________ _________________QWERTY_R2_________________  KC_ENT,
    KC_LSFT, _________________QWERTY_L3_________________ _________________QWERTY_R3_________________  KC_RSFT,
    KC_F1,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC, KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL, KC_F12
  ),

  /* Base layer (Qwerty)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │Bspc │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Tap for Esc -- │  ⌃  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  ⌃  │ -- Tap for Enter
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for ( -- │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │ -- Tap for )
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for [ -- │ GUI │Hyper│  ⌥  │  ⌘  │  ↓  │   Space   │  ↑  │  ⌘  │  ⌥  │Hyper│ GUI │ -- Tap for ]
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   *                         /                                                     /
   *    Tap for ] [ --------'-----------------------------------------------------'
   */
  [QWERTY_LAYER] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  _________________QWERTY_L1_________________ _________________QWERTY_R1_________________  KC_BSPC,
    CTL_ESC, _________________QWERTY_L2_________________ _________________QWERTY_R2_________________  CTL_ENT,
    KC_LSPO, _________________QWERTY_L3_________________ _________________QWERTY_R3_________________  KC_RSPC,
    GUI_L,   HYPER_L, KC_LALT, KC_LGUI, LOWER,   KC_SPC, KC_SPC,  RAISE,   KC_RGUI, KC_RALT, HYPER_R, GUI_R
  ),

  /* Base layer (Norman)
   *                          ⌥     ⌃     ⌘     ⇧                 ⇧     ⌘     ⌃     ⌥
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  Q  │  W  │  D  │  F  │  K  │  J  │  U  │  R  │  L  │  ;  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  A  │  S  │  E  │  T  │  G  │  Y  │  N  │  I  │  O  │  H  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │ Eng │  Z  │  X  │  C  │  V  │  B  │  P  │  M  │  ,  │  .  │  /  │ Rus │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │           │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [NORMAN_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _________________NORMAN_L1_________________  _________________NORMAN_R1_________________  _______,
    _______, _________________NORMAN_L2_________________  _________________NORMAN_R2_________________  _______,
    ENG_SFT, _________________NORMAN_L3_________________  _________________NORMAN_R3_________________  RUS_SFT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* English layer (Norman)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  Q  │  W  │  D  │  F  │  K  │  J  │  U  │  R  │  L  │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  A  │  S  │  E  │  T  │  G  │  Y  │  N  │  I  │  O  │  H  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │ Eng │  Z  │  X  │  C  │  V  │  B  │  P  │  M  │N-Prg│  .  │     │ Rus │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │           │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [NORMAN_ENG_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ENG_SFT, _______, _______, _______, _______, _______, _______, _______, NPRG_CM, _______, _______, RUS_SFT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Russian layer (Norman)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │ Eng │ ф/й │     │ х/ё │     │     │     │     │  ,  │ г/ш │ ж/щ │ Rus │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │           │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [NORMAN_RUS_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ENG_SFT, TD_ZGRV, _______, TD_CQUO, _______, _______, _______, _______, KC_COMM, TD_DLBC, TD_SRBC, RUS_SFT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Normal-Programming layer
   * http://www.keyboard-layout-editor.com/#/gists/db89ac8421bfd94801e004ec7a1c828a
   *                    0     1     2     3     4     5     6     7     8     9    10    11
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *               H │     │  %  │  &  │  ?  │  +  │  @  │  $  │  _  │  [  │  ]  │  !  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *               M │Ctrl │  /  │  (  │  =  │  ;  │  {  │  }  │  :  │  *  │  )  │  -  │Ctrl │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *               L │Shift│  ~  │  `  │  ^  │  "  │  |  │  \  │  ,  │  #  │  '  │     │Shift│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │  ,+Space  │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
   */
  [NORMAL_PROGRAMMING_LAYER] = LAYOUT_planck_grid_wrapper(
    __________________________PROG__L1__________________  _________________PROG__R1___________________________
    __________________________PROG__L2__________________  _________________PROG__R2___________________________
    __________________________PROG__L3__________________  _________________PROG__R3___________________________
    STCH_EX, STCH_EX, _______, _______, STCH_EX, NPRG_SP, NPRG_SP, STCH_EX, _______, _______, STCH_EX, STCH_EX
  ),

  /* Symbol layer
   *
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │Exit │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  =  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Shift│ `/й │     │     │     │     │     │     │     │     │ ;/ч │Shift│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │  ⌃  │  ⌥  │  ⌘  │     │           ┃     ┃  ⌘  │  ⌥  │  ⌃  │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┺━━━━━┹─────┴─────┴─────┴─────┘
   */
  [RAISE_LAYER] = LAYOUT_planck_grid_wrapper(
    STCH_EX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_EQL,  _________________NUMBERS_L_________________  _________________NUMBERS_R_________________  KC_MINS,
    KC_LSFT, KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_RSFT,
    _______, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, _______, KC_RGUI, KC_RALT, KC_RCTL, _______
  ),

  /* Directional navigation layer
   *
   *    Large movements -----/```````````````````\               /```````````````````\----- Vim-style arrow keys
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │ Del │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Home │PgUp │PgDn │ End │     │     │  ←  │  ↓  │  ↑  │  →  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Shift│ ⌘ ← │ ⌘ ↑ │ ⌘ ↓ │ ⌘ → │     │     │ ⌥ ← │ ⌥ ↓ │ ⌥ ↑ │ ⌥ → │Shift│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴━━━━━╅─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │   ⌥ Bspc  ┃     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴──────━━━━━┹─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = LAYOUT_planck_grid_wrapper(
    __________________________LOWER_L1__________________  _________________LOWER_R1___________________________
    __________________________LOWER_L2__________________  _________________LOWER_R2___________________________
    __________________________LOWER_L3__________________  _________________LOWER_R3___________________________
    _______, _______, _______, _______, LOWER,  PRG_OBS,  PRG_OBS, RAISE,   _______, _______, _______, _______
  ),

  /* GUI (window management/mouse/media controls) layer
   *
   *         Mouse keys -----/```````````````````\
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │Ms B2│Ms Up│Ms B1│Ms WD│     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Ms L │Ms Dn│Ms R │Ms WU│     │     │     │     │     │     │  ⌘\ │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Shift│N-Wnd│     │     │ ⇧⌘4 │ ⇧⌘5 │     │     │     │Panel│Windo│Shift│
   *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────╆━━━━━┪
   *                 ┃     ┃Play │Prev │Next │Brig-│   Sleep   │Brig+│Mute │Vol- │Vol+ ┃     ┃
   *                 ┗━━━━━┹─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┺━━━━━┛
   *                         \___ Media ___/   \___ Screen/sleep __/   \___ Volume __/
   */
#define MYPLAY  KC_F4
#define MYNEXT  KC_F5
#define MYPREV  KC_F6
#define MYSLEEP S(KC_F12)
#define MYNWND  LGUI(KC_GRV)
#define MYSCR4  LGUI(LSFT(KC_4))
#define MYSCR5  LGUI(LSFT(KC_5))
#define MYCBSLS LGUI(KC_BSLS)
  [GUI_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_D, XXXXXXX, XXXXXXX, KC_BTN1, KC_WH_U,  KC_WH_D, KC_BTN2, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D,  KC_MS_U, KC_MS_R, MYCBSLS,
    KC_LSFT, MYNWND,  _______, _______, MYSCR4,  MYSCR5,  XXXXXXX, _______, _______,  KC_F10,  KC_F11,  KC_RSFT,
    _______, MYPLAY,  MYPREV,  MYNEXT,  KC_BRID, MYSLEEP, MYSLEEP, KC_BRIU, KC_MUTE,  KC_VOLD, KC_VOLU, _______
  ),

/* CK_TOGG - Toggles the status (will play sound if enabled) */
/* CK_RST - Resets the frequency to the default state (plays sound at default frequency) */
/* CK_UP - Increases the frequency of the clicks (plays sound at new frequency) */
/* CK_DOWN - Decreases the frequency of the clicks (plays sound at new frequency) */

  /* Keyboard settings layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *     Firmware -- │     │Reset│Make │CK_TG│CK_RS│CK_UP│CK_DN│     │     │     │Vers │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *          RGB -- │Qwert│     │     │Mode-│Mode+│Hue -│Hue +│Sat -│Sat +│     │Play1│Rec 1│ -- Record/play macro 1
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *        Audio -- │Normn│Voic-│Voic+│Mus +│Mus -│MIDI+│MIDI-│Aud +│Aud -│     │Play2│Rec 2│ -- Record/play macro 2
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┴─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │     │Swap │Norm ┃     ┃  Toggle   ┃     ┃Plain│Brig-│Brig+│Stop │ -- Stop recording macro
   *                 └─────┴─────┴─────┴─────┺━━━━━┹───────────┺━━━━━┹─────┴─────┴─────┴─────┘
   *                Swap GUI/Alt _/________/             \_____________\_ Backlight _/
   */
  [ADJUST_LAYER] = LAYOUT_planck_grid_wrapper(
    GAMEPD,  RESET,   SEND_MAKE, CK_TOGG,  CK_RST,  CK_UP,   CK_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, SEND_VERSION,    XXXXXXX,
    QWERTY,  XXXXXXX, XXXXXXX,   RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX, DYN_MACRO_PLAY1, DYN_REC_START1,
    NORMAN,  MUV_DE,  MUV_IN,    MU_ON,    MU_OFF,  MI_ON,   MI_OFF,  AU_ON,   AU_OFF,  XXXXXXX, DYN_MACRO_PLAY2, DYN_REC_START2,
    _______,   XXXXXXX, AG_SWAP,   AG_NORM,  LOWER,   MYRGB,   MYRGB,   RAISE,   MYRGBDM, LIT_DEC, LIT_INC,         DYN_REC_STOP
  )
};
// clang-format off

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
}

#ifdef RGB_MATRIX_ENABLE
uint8_t rgb_brightness(void) {
  return rgb_matrix_config.hsv.v;
}

void mysetcolor(int i, uint8_t red, uint8_t green, uint8_t blue) {
  if (rgb_brightness() >= UINT8_MAX || (!red && !green && !blue)) {
    // save a little bit of CPU
    rgb_matrix_set_color(i, red, green, blue);
    return;
  }

  float frac = (float)rgb_brightness() / UINT8_MAX;
  rgb_matrix_set_color(i, frac * red, frac * green, frac * blue);
}

void myplanck_ez_left_led_on(void) {
  planck_ez_left_led_level(rgb_brightness());
}

void myplanck_ez_right_led_on(void) {
  planck_ez_right_led_level(rgb_brightness());
}

/* |----+----+----+----+----+----+----+----+----+----+----+----|
 * |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 |
 * |----+----+----+----+----+----+----+----+----+----+----+----|
 * | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 |
 * |----+----+----+----+----+----+----+----+----+----+----+----|
 * | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | 33 | 34 | 35 |
 * |----+----+----+----+----+----+----+----+----+----+----+----|
 * | 36 | 37 | 38 | 39 | 40 |   41    | 42 | 43 | 44 | 45 | 46 |
 * |----+----+----+----+----+----+----+----+----+----+----+----|
 */
void rgb_matrix_indicators_user(void) {
  planck_ez_left_led_off();
  planck_ez_right_led_off();

  switch (biton32(layer_state)) {
    case GAMEPAD_LAYER:
    case QWERTY_LAYER:
    case NORMAN_LAYER:
    case NORMAN_ENG_LAYER:
    case NORMAN_RUS_LAYER:
      if (rgb_matrix_get_mode() == RGBLIGHT_MODE_STATIC_LIGHT) {
        rgb_matrix_set_color_all(0x00, 0x00, 0x00);
      }
      break;
    default:
      rgb_matrix_set_color_all(0x00, 0x00, 0x00);
  }

  switch (biton32(layer_state)) {
    case GAMEPAD_LAYER:
      // WASD
      mysetcolor(2, 0xBB, 0x0A, 0x1E);
      mysetcolor(13, 0xBB, 0x0A, 0x1E);
      mysetcolor(14, 0xBB, 0x0A, 0x1E);
      mysetcolor(15, 0xBB, 0x0A, 0x1E);
      break;
    case NORMAN_ENG_LAYER:
      if (rgb_matrix_get_mode() == RGBLIGHT_MODE_STATIC_LIGHT) {
        mysetcolor(40, 0x3A, 0x5F, 0x9F);
      }
      break;
    case NORMAN_RUS_LAYER:
      if (rgb_matrix_get_mode() == RGBLIGHT_MODE_STATIC_LIGHT) {
        mysetcolor(42, 0xBB, 0x0A, 0x1E);
      }
      break;
    case LOWER_LAYER:
      myplanck_ez_left_led_on();
      mysetcolor(40, 0xFF, 0xFF, 0xFF); // LOWER
      for (int i = 13; i <= 16; ++i) mysetcolor(i, 0xFF, 0xFF, 0xFF);
      for (int i = 25; i <= 28; ++i) mysetcolor(i, 0xFF, 0xFF, 0xFF);

      for (int i = 19; i <= 22; ++i) mysetcolor(i, 0xFF, 0x00, 0x00);
      for (int i = 31; i <= 34; ++i) mysetcolor(i, 0xFF, 0xFF, 0xFF);
      break;
    case RAISE_LAYER:
      myplanck_ez_right_led_on();
      mysetcolor(42, 0xFF, 0xFF, 0xFF); // RAISE
      mysetcolor(0, 0xFF, 0x30, 0x00); // STCH_EX
      break;
    case GUI_LAYER:
#ifdef MOUSEKEY_ENABLE
      // WASD
      mysetcolor(2,  0xFF, 0x00, 0x00);
      mysetcolor(13, 0xFF, 0x00, 0x00);
      mysetcolor(14, 0xFF, 0x00, 0x00);
      mysetcolor(15, 0xFF, 0x00, 0x00);
      // buttons
      mysetcolor(1, 0xFF, 0xFF, 0xFF);
      mysetcolor(3, 0xFF, 0xFF, 0xFF);
      // wheel
      mysetcolor(4,  0x00, 0xFF, 0x00);
      mysetcolor(16, 0x00, 0xFF, 0x00);

      // mouse movement
      for (int i = 19; i <= 22; ++i) mysetcolor(i, 0xFF, 0x00, 0x00);
      // buttons
      mysetcolor(7,  0xFF, 0xFF, 0xFF);
      mysetcolor(10, 0xFF, 0xFF, 0xFF);
      // wheel
      mysetcolor(8, 0x00, 0xFF, 0x00);
      mysetcolor(9, 0x00, 0xFF, 0x00);
#endif  // MOUSEKEY_ENABLE
      mysetcolor(36, 0xFF, 0xFF, 0xFF); // GUI_L
      mysetcolor(46, 0xFF, 0xFF, 0xFF); // GUI_R
      break;
    case NORMAL_PROGRAMMING_LAYER:
      for (int i = 12; i <= 35; ++i) {
        mysetcolor(i, 0xFF, 0xFF, 0xFF);
      }
      break;
    case SHIFT_PROGRAMMING_LAYER:
      for (int i = 0; i <= 11; ++i) {
        mysetcolor(i, 0xFF, 0xFF, 0xFF);
      }
      break;
    case ADJUST_LAYER:
      myplanck_ez_left_led_on();
      myplanck_ez_right_led_on();
      mysetcolor(40, 0xFF, 0xFF, 0xFF); // LOWER
      mysetcolor(42, 0xFF, 0xFF, 0xFF); // RAISE

      mysetcolor(1,  0xFF, 0x30, 0x00); // RESET
      mysetcolor(0,  0xFF, 0x00, 0x00); // GAMEPAD
      mysetcolor(12, 0xFF, 0x30, 0x00); // QWERTY
      mysetcolor(24, 0xFF, 0x30, 0x00); // NORMAN

      // Audio
      mysetcolor(3, 0x30, 0xFF, 0x00);
      mysetcolor(4, 0x30, 0xFF, 0x00);
      mysetcolor(5, 0x30, 0xFF, 0x00);
      mysetcolor(6, 0x30, 0xFF, 0x00);
      mysetcolor(31, 0x30, 0xFF, 0x00);
      mysetcolor(32, 0x30, 0xFF, 0x00);

      // Color LEDs
      mysetcolor(15, 0x30, 0x00, 0xFF);
      mysetcolor(16, 0x30, 0x00, 0xFF);
      mysetcolor(41, 0x30, 0x00, 0xFF);
      mysetcolor(43, 0x30, 0x00, 0xFF);
      mysetcolor(44, 0x30, 0x00, 0xFF);
      mysetcolor(45, 0x30, 0x00, 0xFF);
      break;
  }
}
#endif

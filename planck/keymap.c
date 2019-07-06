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

#if 0
  /* Shift-Numeric layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer (Qwerty)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │Bspc │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *  Tap for Esc -- │  ⌃  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  ⌃  │ -- Tap for Enter
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for ( -- │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │ -- Tap for )
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *    Tap for [ -- │ GUI │Hyper│  ⌥  │  ⌘  │  ↓  │Space│Space│  ↑  │  ⌘  │  ⌥  │Hyper│ GUI │ -- Tap for ]
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   *                         /                                                     /
   *    Tap for ] [ --------'-----------------------------------------------------'
   */
  [QWERTY_LAYER] = LAYOUT_planck_grid_wrapper(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CTL_ENT,
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    GUI_L,   HYPER_L, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, HYPER_R, GUI_R
  ),

  /* Base layer (Norman)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  Q  │  W  │  D  │  F  │  K  │  J  │  U  │  R  │  L  │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  A  │  S  │  E  │  T  │  G  │  Y  │  N  │  I  │  O  │  H  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │ Eng │  Z  │  X  │  C  │  V  │  B  │  P  │  M  │N-Prg│  .  │     │ Rus │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [COLEMAK_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN, _______,
    _______, KC_A,    KC_S,    KC_E,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,    _______,
    ENG_SFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RUS_SFT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* English layer (Norman)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  Q  │  W  │  D  │  F  │  K  │  J  │  U  │  R  │  L  │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  A  │  S  │  E  │  T  │  G  │  Y  │  N  │  I  │  O  │  H  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │ Eng │  Z  │  X  │  C  │  V  │  B  │  P  │  M  │N-Prg│  .  │     │ Rus │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [COLEMAK_ENG_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ENG_SFT, _______, _______, _______, _______, _______, _______, _______, NPROGRM, _______, _______, RUS_SFT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Russian layer (Norman)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  Q  │  W  │  D  │  F  │  K  │  J  │  U  │  R  │  L  │  ;  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │  A  │  S  │  E  │  T  │  G  │  Y  │  N  │  I  │  O  │  H  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │ Eng │  Z  │  X  │  C  │  V  │  B  │  P  │  M  │  ,  │  .  │  /  │ Rus │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [COLEMAK_RUS_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ENG_SFT, _______, _______, _______, _______, _______, _______, _______, KC_COMM, _______, KC_SLSH, RUS_SFT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Stitching layer (camel)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │ (⇧) │ (⇧) │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [CAMEL_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    STCH_EX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, CAPITAL, CAPITAL, _______, _______, _______, _______, _______
  ),

  /* Stitching layer (kebab)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │  -  │  -  │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [KEBAB_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    STCH_EX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_MINS, KC_MINS, _______, _______, _______, _______, _______
  ),

  /* Stitching layer (snake)
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │  _  │  _  │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [SNAKE_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    STCH_EX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_UNDS, KC_UNDS, _______, _______, _______, _______, _______
  ),

  /* Normal-Programming layer
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │  %  │  &  │  ?  │  +  │  @  │  $  │  _  │  [  │  ]  │  !  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Exit │  /  │  (  │  =  │  ;  │  {  │  }  │  :  │  *  │  )  │  -  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │S-Prg│  ~  │  `  │  ^  │  "  │  |  │  \  │  ,  │  #  │  '  │     │S-Prg│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │  ,+Space  │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [NORMAL_PROGRAMMING_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, KC_PERC, KC_AMPR, KC_QUES, KC_PLUS, KC_AT,   KC_DLR,  KC_UNDS, KC_LBRC, KC_RBRC, KC_EXLM, _______,
    STCH_EX, KC_SLSH, KC_LPRN, KC_EQL,  KC_SCLN, KC_LCBR, KC_RCBR, KC_COLN, KC_ASTR, KC_RPRN, KC_MINS, _______,
    SPROGRM, KC_TILD, KC_GRV,  KC_CIRC, KC_DQUO, KC_PIPE, KC_BSLS, KC_COMM, KC_HASH, KC_QUOT, _______, SPROGRM,
    _______, _______, _______, _______, _______, NPRG_SP, NPRG_SP, _______, _______, _______, _______, _______
  ),

  /* Shift-Programming layer
   *                          0     1     2     3     4     5     6     7     8     9
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *               H │     │     │ &&  │     │ +=  │ @q  │     │     │ []  │ ->  │ !=  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *               M │Exit │ /=  │ ()  │ ==  │     │ {}  │     │ ::  │     │     │ -=  │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *               L │N-Prg│     │     │     │     │ ||  │     │     │ <=  │ >=  │     │N-Prg│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │     │     │     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [SHIFT_PROGRAMMING_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, _______, SPRG_H1, _______, SPRG_H3, SPRG_H4, _______, _______, SPRG_H7, SPRG_H8, SPRG_H9, _______,
    STCH_EX, SPRG_M0, SPRG_M1, SPRG_M2, _______, SPRG_M4, _______, SPRG_M6, _______, _______, SPRG_M9, _______,
    NPROGRM, _______, _______, _______, _______, SPRG_L4, _______, _______, SPRG_L7, SPRG_L8, _______, NPROGRM,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Symbol layer
   *
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │Exit │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │  =  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Shift│ `/й │     │     │     │     │     │     │     │     │ ;/ч │Shift│
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┴─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │  ⌃  │  ⌥  │  ⌘  │     │           ┃     ┃  ⌘  │  ⌥  │  ⌃  │     │
   *                 └─────┴─────┴─────┴─────┴─────┴───────────┺━━━━━┹─────┴─────┴─────┴─────┘
   */
  [RAISE_LAYER] = LAYOUT_planck_grid_wrapper(
    STCH_EX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
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
   *                 ├─────┼─────┼─────┼─────┼─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┼─────┤
   *                 │     │     │     │     │     │Lead ┃Lead ┃     │     │     │     │     │
   *                 └─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┴─────┘
   */
  [LOWER_LAYER] = LAYOUT_planck_grid_wrapper(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
    XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,

    KC_LSFT, LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_DOWN), LGUI(KC_RGHT), XXXXXXX, XXXXXXX,
                                                                   LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RGHT), KC_RSFT,
    _______, _______, _______, _______, LOWER,   LEADER,  LEADER,  RAISE,   _______, _______, _______, _______
  ),

  /* GUI (window management/mouse/media controls) layer
   *
   *         Mouse keys -----/```````````````````\
   *                 ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   *                 │     │Ms B2│Ms Up│Ms B1│Ms WD│     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │     │Ms L │Ms Dn│Ms R │Ms WU│     │     │     │     │     │     │     │
   *                 ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   *                 │Shift│     │     │     │     │     │     │     │     │Panel│Windo│Shift│
   *                 ┢━━━━━╅─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────╆━━━━━┪
   *                 ┃     ┃Play │Prev │Next │Brig-│Sleep│Sleep│Brig+│Mute │Vol- │Vol+ ┃     ┃
   *                 ┗━━━━━┹─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┺━━━━━┛
   *                         \___ Media ___/   \___ Screen/sleep __/   \___ Volume __/
   */
#define MYPLAY  KC_F4
#define MYNEXT  KC_F5
#define MYPREV  KC_F6
#define MYSLEEP S(KC_F12)
  [GUI_LAYER] = LAYOUT_planck_grid_wrapper(
    _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_D, XXXXXXX, XXXXXXX, _______, _______,  _______, _______, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, XXXXXXX, XXXXXXX, _______, _______,  _______, _______, _______,
    KC_LSFT, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______,  KC_F10,  KC_F11,  KC_RSFT,
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
   *        Audio -- │Colem│Voic-│Voic+│Mus +│Mus -│MIDI+│MIDI-│Aud +│Aud -│     │Play2│Rec 2│ -- Record/play macro 2
   *                 ├─────┼─────┼─────┼─────╆━━━━━╅─────┼─────╆━━━━━╅─────┼─────┼─────┼─────┤
   *                 │     │     │Swap │Norm ┃     ┃  Toggle   ┃     ┃Plain│Brig-│Brig+│Stop │ -- Stop recording macro
   *                 └─────┴─────┴─────┴─────┺━━━━━┹─────┴─────┺━━━━━┹─────┴─────┴─────┴─────┘
   *                Swap GUI/Alt _/________/             \_____________\_ Backlight _/
   */
  [ADJUST_LAYER] = LAYOUT_planck_grid_wrapper(
    XXXXXXX, RESET,   SEND_MAKE, CK_TOGG,  CK_RST,  CK_UP,   CK_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, SEND_VERSION,    XXXXXXX,
    QWERTY,  XXXXXXX, XXXXXXX,   RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX, DYN_MACRO_PLAY1, DYN_REC_START1,
    COLEMAK, MUV_DE,  MUV_IN,    MU_ON,    MU_OFF,  MI_ON,   MI_OFF,  AU_ON,   AU_OFF,  XXXXXXX, DYN_MACRO_PLAY2, DYN_REC_START2,
    _______,   XXXXXXX, AG_SWAP,   AG_NORM,  LOWER,   MYRGB,   MYRGB,   RAISE,   MYRGBDM, LIT_DEC, LIT_INC,         DYN_REC_STOP
  )
};

#ifdef RGB_MATRIX_ENABLE
uint8_t rgb_brightness(void) { return rgb_matrix_config.val; }

void mysetcolor(int i, uint8_t red, uint8_t green, uint8_t blue) {
  if (rgb_brightness() >= UINT8_MAX || (!red && !green && !blue)) {
    // save a little bit of CPU
    rgb_matrix_set_color(i, red, green, blue);
    return;
  }

  float frac = (float)rgb_brightness() / UINT8_MAX;
  rgb_matrix_set_color(i, frac * red, frac * green, frac * blue);
}

void set_planck_spacebar_led(stm32_gpio_t *a, int b) {
  if (!rgb_brightness()) return;

  palSetPad(a, b);
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
  // Clear the space bar LEDs.
  palClearPad(GPIOB, 8);
  palClearPad(GPIOB, 9);

  switch (biton32(layer_state)) {
    case QWERTY_LAYER:
    case COLEMAK_LAYER:
    case COLEMAK_ENG_LAYER:
    case COLEMAK_RUS_LAYER:
      if (rgb_matrix_get_mode() == RGBLIGHT_MODE_STATIC_LIGHT) {
        rgb_matrix_set_color_all(0x00, 0x00, 0x00);
      }
      break;
    default:
      rgb_matrix_set_color_all(0x00, 0x00, 0x00);
  }

  switch (biton32(layer_state)) {
    case COLEMAK_ENG_LAYER:
      if (rgb_matrix_get_mode() == RGBLIGHT_MODE_STATIC_LIGHT) {
        mysetcolor(40, 0x3A, 0x5F, 0x9F);
      }
      break;
    case COLEMAK_RUS_LAYER:
      if (rgb_matrix_get_mode() == RGBLIGHT_MODE_STATIC_LIGHT) {
        mysetcolor(42, 0xBB, 0x0A, 0x1E);
      }
      break;
    case LOWER_LAYER:
      set_planck_spacebar_led(GPIOB, 9);
      mysetcolor(40, 0xFF, 0xFF, 0xFF); // LOWER
      for (int i = 13; i <= 16; ++i) mysetcolor(i, 0xFF, 0xFF, 0xFF);
      for (int i = 25; i <= 28; ++i) mysetcolor(i, 0xFF, 0xFF, 0xFF);

      for (int i = 19; i <= 22; ++i) mysetcolor(i, 0xFF, 0x00, 0x00);
      for (int i = 31; i <= 34; ++i) mysetcolor(i, 0xFF, 0xFF, 0xFF);
      break;
    case RAISE_LAYER:
      set_planck_spacebar_led(GPIOB, 8);
      mysetcolor(42, 0xFF, 0xFF, 0xFF); // RAISE
      mysetcolor(0, 0xFF, 0x30, 0x00); // STCH_EX
      break;
    case GUI_LAYER:
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
      set_planck_spacebar_led(GPIOB, 8);
      set_planck_spacebar_led(GPIOB, 9);
      mysetcolor(40, 0xFF, 0xFF, 0xFF); // LOWER
      mysetcolor(42, 0xFF, 0xFF, 0xFF); // RAISE

      mysetcolor(1, 0xFF, 0x30, 0x00); // RESET
      mysetcolor(12, 0xFF, 0x30, 0x00); // QWERTY
      mysetcolor(24, 0xFF, 0x30, 0x00); // COLEMAK

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
    case CAMEL_LAYER:
    case KEBAB_LAYER:
    case SNAKE_LAYER:
      mysetcolor(12, 0xFF, 0x30, 0x00); // STCH_EX
      mysetcolor(41, 0x88, 0xFF, 0x00); // "Space bar"
      break;
  }
}
#endif

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

#pragma once

#include "quantum.h"
#include "version.h"

#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#endif  // RGB_MATRIX_ENABLE

// #define ENABLE_GAMEPAD
#define ENABLE_NORMAN_ENGRUS

// Limit of 15 layers in total.
enum user_layers {
  QWERTY_LAYER,
  NORMAN_LAYER,

#if defined(ENABLE_NORMAN_ENGRUS)
  NORMAN_RUS_LAYER,
#endif  // defined(ENABLE_NORMAN_ENGRUS)

  NORMAL_PROGRAMMING_LAYER,

  LOWER_LAYER,
  RAISE_LAYER,

  GUI_LAYER,
#if defined(ENABLE_GAMEPAD)
  GAMEPAD_LAYER,
#endif  // ENABLE_GAMEPAD

  ADJUST_LAYER,
};

enum user_keycodes {
  LEADER = SAFE_RANGE,

  QWERTY,
  NORMAN,
#if defined(ENABLE_GAMEPAD)
  GAMEPD,
#endif  // ENABLE_GAMEPAD

#if defined(ENABLE_NORMAN_ENGRUS)
  ENGLISH,
  RUSSIAN,
#endif  // defined(ENABLE_NORMAN_ENGRUS)

  STCH_EX,

  // Send comma when pressed with shift, and act as an
  // OSL(NORMAL_PROGRAMMING_LAYER) when pressed alone
  NPRG_CM,

  NPRG_SP,

  PRG_H00,
  PRG_H01,
  PRG_H02,
  PRG_H03,
  PRG_H04,
  PRG_H05,
  PRG_H06,
  PRG_H07,
  PRG_H08,
  PRG_H09,
  PRG_H10,
  PRG_H11,

  PRG_M00,
  PRG_M01,
  PRG_M02,
  PRG_M03,
  PRG_M04,
  PRG_M05,
  PRG_M06,
  PRG_M07,
  PRG_M08,
  PRG_M09,
  PRG_M10,
  PRG_M11,

  PRG_L00,
  PRG_L01,
  PRG_L02,
  PRG_L03,
  PRG_L04,
  PRG_L05,
  PRG_L06,
  PRG_L07,
  PRG_L08,
  PRG_L09,
  PRG_L10,
  PRG_L11,

#ifndef NO_DEBUG
  // Print current layer info. Mapping it to F1 is not a bad idea.
  MBL_LYR,
#endif  // !NO_DEBUG

#ifdef RGB_MATRIX_ENABLE
  // Enable RGB, disable all animations.
  MYRGB,
  MYRGBDM,  // dim leds
#endif      // RGB_MATRIX_ENABLE

  SEND_MAKE,
  SEND_VERSION,
  DYNAMIC_MACRO_RANGE,
};

enum user_tapdance {
  MY_TD_Z_GRV,
  MY_TD_DOT_LBRC,
  MY_TD_SLASH_RBRC,
  MY_TD_C_QUOT,
};

#define TD_ZGRV TD(MY_TD_Z_GRV)
#define TD_DLBC TD(MY_TD_DOT_LBRC)
#define TD_SRBC TD(MY_TD_SLASH_RBRC)
#define TD_CQUO TD(MY_TD_C_QUOT)

// Dynamic macros add additional keycodes.
#define NEW_SAFE_RANGE (DYNAMIC_MACRO_PLAY2 + 1)

#define NPROGRM OSL(NORMAL_PROGRAMMING_LAYER)

#if defined(ENABLE_NORMAN_ENGRUS)
#define ENG_SFT (ENGLISH)
#define RUS_SFT (RUSSIAN)
#else
#define ENG_SFT (KC_LSFT)
#define RUS_SFT (KC_RSFT)
#endif  // defined(ENABLE_NORMAN_ENGRUS)

#define LOWER MO(LOWER_LAYER)
#define LOWR_TG TG(LOWER_LAYER)
#define RAISE MO(RAISE_LAYER)

// Double-action home row
#define MB_A MOD_LALT(KC_A)
#define MB_S MOD_LCTL(KC_S)
#define MB_E MOD_LGUI(KC_E)
#define MB_T MOD_LSFT(KC_T)
#define MB_N MOD_RSFT(KC_N)
#define MB_I MOD_RGUI(KC_I)
#define MB_O MOD_RCTL(KC_O)
#define MB_H MOD_RALT(KC_H)

#define GUI_L LT(GUI_LAYER, KC_LBRC)
#define GUI_R LT(GUI_LAYER, KC_RBRC)

#define HYPER_L ALL_T(KC_RBRC)
#define HYPER_R ALL_T(KC_LBRC)

#define CTL_ESC CTL_T(KC_ESC)
#define CTL_ENT CTL_T(KC_ENT)

#define CAPITAL OSM(MOD_LSFT)

#define GUI_GRV LGUI(KC_GRV)

// Dashes (macOS)
#define KC_NDSH LALT(KC_MINS)
#define KC_MDSH S(LALT(KC_MINS))

// Window manager keys
#define WM_FULL LALT(LGUI(KC_F))
#define WM_NEXT LCTL(LALT(LGUI(KC_RGHT)))
#define WM_PREV LCTL(LALT(LGUI(KC_LEFT)))
#define WM_NW LCTL(LGUI(KC_LEFT))
#define WM_N LALT(LGUI(KC_UP))
#define WM_NE LCTL(LGUI(KC_RGHT))
#define WM_E LALT(LGUI(KC_RGHT))
#define WM_SE S(LCTL(LGUI(KC_RGHT)))
#define WM_S LALT(LGUI(KC_DOWN))
#define WM_SW S(LCTL(LGUI(KC_LEFT)))
#define WM_W LALT(LGUI(KC_LEFT))
#define WM_CNTR LALT(LGUI(KC_C))

// Unify backlight controls
#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
#define LIT_TOG RGB_TOG
#define LIT_DEC RGB_VAD
#define LIT_INC RGB_VAI
#else
#define LIT_TOG BL_TOGG
#define LIT_DEC BL_DEC
#define LIT_INC BL_INC
#endif  // defined(RGB_MATRIX_ENABLE)

// Alias layout macros that expand groups of keys.
#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)
#define LAYOUT_planck_mit_wrapper(...) LAYOUT_planck_mit(__VA_ARGS__)
#define LAYOUT_preonic_grid_wrapper(...) LAYOUT_preonic_grid(__VA_ARGS__)

// clang-format off
#define _________________QWERTY_L1_________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
#define _________________QWERTY_L2_________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
#define _________________QWERTY_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,

#define _________________QWERTY_R1_________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
#define _________________QWERTY_R2_________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
#define _________________QWERTY_R3_________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,

#define _________________NORMAN_L1_________________ KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,
#define _________________NORMAN_L2_________________ KC_A,    KC_S,    KC_E,    KC_T,    KC_G,
#define _________________NORMAN_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,

#define _________________NORMAN_R1_________________ KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN,
#define _________________NORMAN_R2_________________ KC_Y,    KC_N,    KC_I,    KC_O,    KC_H,
#define _________________NORMAN_R3_________________ KC_P,    KC_M,    NPRG_CM, KC_DOT,  KC_SLSH,

#define PRG_H01 KC_PERC
#define PRG_H03 KC_QUES
#define PRG_H06 KC_DLR
#define PRG_H07 KC_UNDS
#define PRG_M04 KC_SCLN
#define PRG_M06 KC_RCBR
#define PRG_M08 KC_ASTR
#define PRG_M09 KC_RPRN
#define PRG_L01 KC_TILD
#define PRG_L02 KC_GRV
#define PRG_L03 KC_CIRC
#define PRG_L04 KC_DQUO
#define PRG_L06 KC_BSLS
#define PRG_L07 KC_COMM
// Option-Backspace
#define PRG_OBS LALT(KC_BSPACE)
#define __________________________PROG__L1__________________ PRG_H00, PRG_H01, PRG_H02, PRG_H03, PRG_H04, PRG_H05,
#define _________________PROG__R1___________________________ PRG_H06, PRG_H07, PRG_H08, PRG_H09, PRG_H10, PRG_H11,
#define __________________________PROG__L2__________________ KC_LCTL, PRG_M01, PRG_M02, PRG_M03, PRG_M04, PRG_M05,
#define _________________PROG__R2___________________________ PRG_M06, PRG_M07, PRG_M08, PRG_M09, PRG_M10, KC_RCTL,
#define __________________________PROG__L3__________________ KC_LSFT, PRG_L01, PRG_L02, PRG_L03, PRG_L04, PRG_L05,
#define _________________PROG__R3___________________________ PRG_L06, PRG_L07, PRG_L08, PRG_L09, PRG_L10, KC_RSFT,

#define _________________NUMBERS_L_________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
#define _________________NUMBERS_R_________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,

#define __________________________LOWER_L1__________________ XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_Z,
#define _________________LOWER_R1___________________________ KC_J,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,
#define __________________________LOWER_L2__________________ XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX,
#define _________________LOWER_R2___________________________ KC_Z,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
#define __________________________LOWER_L3__________________ KC_LSFT, LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_DOWN), LGUI(KC_RGHT), XXXXXXX,
#define _________________LOWER_R3___________________________ KC_P,    LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RGHT), KC_RSFT,

#if 0
#define _________________QWERTY_L1_________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________LOWER_L1__________________ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________LOWER_L2__________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________LOWER_L3__________________ KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, KC_COLN

#define _________________LOWER_R1__________________ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define _________________LOWER_R2__________________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________LOWER_R3__________________ KC_NDSH, KC_MDSH, KC_COMM, KC_DOT,  KC_SLSH

#define _________________RAISE_L1__________________ KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15
#define _________________RAISE_L2__________________ KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________RAISE_L3__________________ KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE, KC_COLN

#define _________________RAISE_R1__________________ KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20
#define _________________RAISE_R2__________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR
#define _________________RAISE_R3__________________ KC_NDSH, KC_MDSH, KC_COMM, KC_DOT,  KC_SLSH

#define __________________NAV_L1___________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________NAV_L2___________________ XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END
#define __________________NAV_L3___________________ XXXXXXX, LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_DOWN), LGUI(KC_RGHT)

#define __________________NAV_R1___________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __________________NAV_R2___________________ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX
#define __________________NAV_R3___________________ LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RGHT), XXXXXXX

#define __________________GUI_L1___________________ KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_D, XXXXXXX
#define __________________GUI_L2___________________ KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, XXXXXXX
#define __________________GUI_L3___________________ KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX

#define __________________GUI_R1___________________ XXXXXXX, WM_PREV, WM_NW,   WM_N,    WM_NE
#define __________________GUI_R2___________________ XXXXXXX, WM_FULL, WM_W,    WM_CNTR, WM_E
#define __________________GUI_R3___________________ XXXXXXX, WM_NEXT, WM_SW,   WM_S,    WM_SE

#define __________VOLUME_________ KC_MUTE, KC_VOLD, KC_VOLU
#define __________MEDIA__________ KC_MPRV, KC_MPLY, KC_MNXT

#define __________________BASE_L0__________________ _________________LOWER_L1__________________
#define __________________BASE_R0__________________ _________________LOWER_R1__________________
#endif  // if 0
// clang-format on

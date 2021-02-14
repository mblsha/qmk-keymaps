#include QMK_KEYBOARD_H
#include "my.h"
#include "my_dynamic_macro.h"

// clang-format off
/*
LAYOUT_all from keyboards/converter/usb_usb/usb_usb.h:

        K68,K69,K6A,K6B,K6C,K6D,K6E,K6F,K70,K71,K72,K73,
        F13 F14 F15 F16 F17 F18 F19 F20 F21 F22 F23 F24

K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,  K81,K80,K7F,K66, K75,
ESC     F1  F2  F3  F4  F5  F6  F7  F8  F9  F10 F11 F12       PrS ScL Pau   VDn VUp Mut Pwr  Help

K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K89,K2A,  K49,K4A,K4B,  K53,K54,K55,K56, K78,K79,
`   1   2   3   4   5   6   7   8   9   0   -   =   JPY Bsp   Ins Hom PgU   NmL /   *   -    Stp Agn

K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K31,  K4C,K4D,K4E,  K5F,K60,K61,K57, K76,K7A,
Tab Q   W   E   R   T   Y   U   I   O   P   [   ]       \     Del End PgD   7   8   9   +    Mnu Und

K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    K32,K28,                K5C,K5D,K5E,K85, K77,K7C,
CpL A   S   D   F   G   H   J   K   L   ;   '       #   Retn                4   5   6   KP,  Sel Cpy

KE1,K64,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    K87,KE5,      K52,      K59,K5A,K5B,K67, K74,K7D,
ShL XXX Z   X   C   V   B   N   M   ,   ,   /       RO  ShR       Up        1   2   3   KP=  Exe Pst

KE0,KE3,KE2,K8B,K91,    K2C,    K90,K8A,K88,KE6,KE7,K65,KE4,  K50,K51,K4F,  K62,    K63,K58, K7E,K7B
Ctl Gui Alt MHEN HNJ   Space    H/E HEN KAN Alt Gui App Ctl   Lef Dow Rig   0       .   Ent  Fnd Cut


NB:
* q_qwerty.txt needs to be activated in Advantage2 in order for these keymaps to
  work.
* usb_usb converter doesn't support media keys input.

F13 F14 F15 (Pedals)

ESC F1  F2  F3  F4  F5  F6  F7  F8
F9  F10 F11 F12 PrScrn ScrLock Pause

=   1   2   3   4   5   6   7   8   9   0   -
Tab Q   W   E   R   T   Y   U   I   O   P   \
F16 A   S   D   F   G   H   J   K   L   ;   '
ShL Z   X   C   V   B   N   M   ,   .   /   ShR
    `   F17 ←   →           ↑   ↓   [   ]

    CtL AlL     WnR CtR
        Hom     PgU
Bsp Del End     PgD Ent Spc
*/

#define LAYOUT_advantage2_wrapper(...) LAYOUT_advantage2(__VA_ARGS__)

#define LAYOUT_advantage2( \
    K68,K69,K6A, \
    \
    K29,K3A,K3B,K3C,K3D,K3E,K3F,K40,K41, \
            K42,K43,K44,K45,K46,K47,K48, \
    \
    K2E,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D, \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K31, \
    K6B,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34, \
    KE1,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,KE5, \
        K35,K6C,K50,K4F,        K52,K51,K2F,F30,     \
    \
        KE0,KE2,    KE7,KE4,    \
            K4A,    K4B,        \
    K2A,K4C,K4D,    K4E,K28,K2C \
) LAYOUT_all( \
           K68,K69,K6A,K6B,K6C,  0,  0,  0,  0,  0,  0,  0,                                              \
   K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,    0,  0,  0,  0,   0,     \
   K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,  0,K2A,    0,K4A,K4B,    0,  0,  0,  0,   0,  0, \
   K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,F30,    K31,  K4C,K4D,K4E,    0,  0,  0,  0,   0,  0, \
     0,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,      0,K28,                  0,  0,  0,  0,   0,  0, \
   KE1,  0,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,      0,KE5,      K52,        0,  0,  0,  0,   0,  0, \
   KE0,  0,KE2,  0,  0,    K2C,      0,  0,  0,  0,KE7,  0,KE4,  K50,K51,K4F,    0,      0,  0,   0,  0  \
)

/*
           K68,K69,K6A,K6B,K6C,K6D,K6E,K6F,K70,K71,K72,K73,
   K29,    K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,  K81,K80,K7F,K66, K75,
   K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K89,K2A,  K49,K4A,K4B,  K53,K54,K55,K56, K78,K79,
   K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K31,  K4C,K4D,K4E,  K5F,K60,K61,K57, K76,K7A,
   K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    K32,K28,                K5C,K5D,K5E,K85, K77,K7C,
   KE1,K64,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    K87,KE5,      K52,      K59,K5A,K5B,K67, K74,K7D,
   KE0,KE3,KE2,K8B,K91,    K2C,    K90,K8A,K88,KE6,KE7,K65,KE4,  K50,K51,K4F,  K62,    K63,K58, K7E,K7B
*/

// FIXME: Could map extra keys to the numpad on the keyboard level to free up the F-keys.
// FIXME: ScrollLock emits nasty sound when pressed.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY_LAYER] = LAYOUT_advantage2_wrapper(
    // Pedals
    KC_LSFT, KC_LCTL, KC_LGUI,

    // Function row
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,    KC_F7,   KC_F8,
                      KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_MUTE,  KC_VOLD, KC_VOLU,

    KC_EQL,  _________________NUMBERS_L_________________ _________________NUMBERS_R_________________  KC_MINS,
    KC_TAB,  _________________QWERTY_L1_________________ _________________QWERTY_R1_________________  KC_BSLS,
    KC_CAPS, _________________QWERTY_L2_________________ _________________QWERTY_R2_________________  KC_QUOT,
    KC_LSFT, _________________QWERTY_L3_________________ _________________QWERTY_R3_________________  KC_RSFT,
             KC_GRV,  KC_ESC,  KC_LEFT, KC_RIGHT,                 KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,

             KC_LCTL, KC_LALT,          KC_RGUI, KC_RCTRL,
                      KC_HOME,          KC_PGUP,
    KC_BSPC, KC_DEL,  KC_END,           KC_PGDN, KC_ENT,  KC_SPC
  ),

  [NORMAN_LAYER] = LAYOUT_advantage2_wrapper(
    _______, _______, _______,

    _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______,

    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_TAB,  _________________NORMAN_L1_________________  _________________NORMAN_R1_________________  KC_BSPC,
    CTL_ESC, _________________NORMAN_L2_________________  _________________NORMAN_R2_________________  CTL_ENT,
    ENG_SFT, _________________NORMAN_L3_________________  _________________NORMAN_R3_________________  RUS_SFT,
             GUI_L,   HYPER_L, KC_LALT, KC_LGUI,                   KC_RGUI, KC_RALT, HYPER_R, GUI_R,

             XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
                      _______,          _______,
    LOWER,   KC_BSPC, _______,          _______, KC_SPC,  KC_SPC
  ),

#if defined(ENABLE_NORMAN_ENGRUS)
  // FIXME: Do a reverse layout so the Cmd+Keys will work the same as in the english layout
  [NORMAN_RUS_LAYER] = LAYOUT_advantage2_wrapper(
    _______, _______, _______,

    _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______,

    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
#if 0  // Make it key-compatible with Russian-PC layout
    // http://www.keyboard-layout-editor.com/#/gists/e322e7feda873f8601d10ec4c88ab53e
    _______, KC_W,    KC_M,    KC_Z,    _______, KC_SLSH, KC_P,    KC_D,    KC_R,    KC_L,    KC_X,    _______,
    _______, KC_E,    KC_B,    KC_T,    KC_J,    KC_F,    KC_K,    KC_Y,    KC_N,    KC_C,    KC_H,    _______,
    ENG_SFT, KC_A,    KC_QUOT, KC_LBRC, KC_S,    KC_DOT,  KC_COMM, KC_V,    KC_G,    KC_U,    KC_SCLN, RUS_SFT,
#else
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ENG_SFT, TD_ZGRV, _______, TD_CQUO, _______, _______, _______, _______, KC_COMM, TD_DLBC, TD_SRBC, RUS_SFT,
#endif
             _______, _______, _______, _______,                   _______, _______, _______, _______,

             _______, _______,          _______, _______,
                      _______,          _______,
    _______, _______, _______,          _______, _______, _______
  ),
#endif // defined(ENABLE_NORMAN_ENGRUS)

  [NORMAL_PROGRAMMING_LAYER] = LAYOUT_advantage2_wrapper(
    _______, _______, _______,

    _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______,

    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    __________________________PROG__L1__________________  _________________PROG__R1___________________________
    __________________________PROG__L2__________________  _________________PROG__R2___________________________
    __________________________PROG__L3__________________  _________________PROG__R3___________________________
             STCH_EX, STCH_EX, _______, _______,                   _______, _______, STCH_EX, STCH_EX,

             _______, _______,          _______, _______,
                      _______,          _______,
    STCH_EX, _______, _______,          _______, _______, NPRG_SP
  ),

  [LOWER_LAYER] = LAYOUT_advantage2_wrapper(
    _______, _______, _______,

    _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______,

    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    __________________________LOWER_L1__________________  _________________LOWER_R1___________________________
    __________________________LOWER_L2__________________  _________________LOWER_R2___________________________
    __________________________LOWER_L3__________________  _________________LOWER_R3___________________________
             _______, _______, _______, _______,                   _______, _______, _______, _______,

             _______, _______,          _______, _______,
                      _______,          _______,
    LOWER,   _______, _______,          _______, _______, PRG_OBS
  ),
};
// clang-format on

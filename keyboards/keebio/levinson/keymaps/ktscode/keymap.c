// Copyright 2026 Kyle San Clemente (@KTSCode)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "ktscode.h"

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ortho_4x12_wrapper(KTS_QWERTY),
    [_LOWER]  = LAYOUT_ortho_4x12_wrapper(KTS_LOWER),
    [_RAISE]  = LAYOUT_ortho_4x12_wrapper(KTS_RAISE),

 /* ADJUST (hardware control — per-board; Levinson has rgblight + backlight)
  * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
  * │  Esc │      │      │      │ Boot │      │      │ Hue+ │ Hue- │ Spd+ │ Spd- │ C+A+D│
  * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
  * │ Caps │      │      │ Sat+ │ Sat- │ Game │      │ AGNrm│PrtScn│ ScrLk│ Paus │      │
  * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
  * │      │ Val+ │ Val- │      │      │ Prev │ Next │ Mute │ Vol- │ Vol+ │      │      │
  * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
  * │ Light│      │      │      │ BLStp│ Play │ Play │      │ BLTog│ RGB+ │ RGB- │ RGTog│
  * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
  */
    [_ADJUST] = LAYOUT_ortho_4x12(
        KC_ESC,  _______, _______, _______, QK_BOOT, _______, _______, RGB_HUI, RGB_HUD, RGB_SPI,        RGB_SPD,  LALT(LCTL(KC_DEL)),
        KC_CAPS, _______, _______, RGB_SAI, RGB_SAD, GAME,    _______, AG_NORM, KC_PSCR, KC_SCROLL_LOCK, KC_PAUS,  _______,
        _______, RGB_VAI, RGB_VAD, _______, _______, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,        _______,  _______,
        BACKLIT, _______, _______, _______, BL_STEP, KC_MPLY, KC_MPLY, _______, BL_TOGG, RGB_MOD,        RGB_RMOD, RGB_TOG
    ),

    [_GAME]   = LAYOUT_ortho_4x12_wrapper(KTS_GAME),
};
/* clang-format on */

// Copyright 2026 Kyle San Clemente (@KTSCode)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "ktscode.h"

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ortho_4x12_wrapper(KTS_QWERTY),
    [_LOWER]  = LAYOUT_ortho_4x12_wrapper(KTS_LOWER),
    [_RAISE]  = LAYOUT_ortho_4x12_wrapper(KTS_RAISE),

 /* ADJUST (hardware control — per-board; Nyquist LM has rgb_matrix only)
  * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
  * │  Esc │      │      │      │ Boot │      │      │ Hue+ │ Hue- │ Spd+ │ Spd- │ C+A+D│
  * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
  * │ Caps │      │      │ Sat+ │ Sat- │ Game │      │ AGNrm│PrtScn│ ScrLk│ Paus │      │
  * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
  * │      │ Val+ │ Val- │      │      │ Prev │ Next │ Mute │ Vol- │ Vol+ │      │      │
  * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
  * │ Light│      │      │      │      │ Play │ Play │      │      │ RGB+ │ RGB- │ RGTog│
  * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
  */
    [_ADJUST] = LAYOUT_ortho_4x12(
        KC_ESC,  _______, _______, _______, QK_BOOT, _______, _______, RM_HUEU, RM_HUED, RM_SPDU,        RM_SPDD,  LALT(LCTL(KC_DEL)),
        KC_CAPS, EE_CLR,  _______, RM_SATU, RM_SATD, GAME,    _______, AG_NORM, KC_PSCR, KC_SCROLL_LOCK, KC_PAUS,  _______,
        DT_PRNT, RM_VALU, RM_VALD, DT_DOWN, DT_UP,   KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,        _______,  _______,
        BACKLIT, _______, _______, _______, _______, KC_MPLY, KC_MPLY, _______, _______, RM_NEXT,        RM_PREV,  RM_TOGG
    ),

    [_GAME]   = LAYOUT_ortho_4x12_wrapper(KTS_GAME),
};
/* clang-format on */

#define RGB_SCREENSAVER_TIMEOUT 60000  // 60s idle -> screensaver effect

// RGB "screensaver": once the keyboard sits idle, switch rgb_matrix to Digital
// Rain; snap back to a solid color on the next keypress. Effect only — your
// hue/sat/brightness carry over. Uses _noeeprom so the swaps don't wear flash,
// and only acts on the idle<->active flip. Starts "idle" so the first tick
// forces SOLID at boot.
void housekeeping_task_user(void) {
    static bool idle = true;
    bool now_idle = last_input_activity_elapsed() > RGB_SCREENSAVER_TIMEOUT;
    if (now_idle == idle) return;
    idle = now_idle;
    rgb_matrix_mode_noeeprom(idle ? RGB_MATRIX_DIGITAL_RAIN : RGB_MATRIX_SOLID_COLOR);
}

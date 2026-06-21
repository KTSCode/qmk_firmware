/* Copyright 2015-2023 Jack Humbert
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

#include QMK_KEYBOARD_H

enum ktscode_layers { _QWERTY, _LOWER, _RAISE, _ADJUST, _GAME };

enum ktscode_keycodes {
    QWERTY = SAFE_RANGE,
    GAME,
    BACKLIT,
    KTSCODE_SAFE_RANGE  // boards continue custom keycodes from here
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

/* Expand a shared KTS_* layer-content macro into a board's ortho_4x12 layout.
 *
 * The wrapper indirection is required: each KTS_* macro is 48 comma-separated
 * keycodes, but LAYOUT_ortho_4x12 counts its arguments before expanding them.
 * Routing through a variadic wrapper expands KTS_* to 48 tokens first, so
 * LAYOUT_ortho_4x12 then sees the 48 arguments it expects.
 */
#define LAYOUT_ortho_4x12_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)

/* Shared layer content. Identical on every board; the hardware-control
 * ADJUST layer is NOT shared and is defined per board in its own keymap.c.
 */

/* clang-format off */

/* QWERTY
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │  Tab │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ C/Esc│   A  │   S  │   D  │   F  │   G  │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shft │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │   /  │ S/Ent│
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  C/S │  Esc │  Alt │  Gui │ Lower│  C/\ │ Space│ Raise│ Rs/[ │   -  │   =  │ Alt/]│
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define KTS_QWERTY \
    KC_TAB,         KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,                  KC_Y,   KC_U,  KC_I,           KC_O,    KC_P,    KC_BSPC,        \
    LCTL_T(KC_ESC), KC_A,   KC_S,    KC_D,    KC_F,  KC_G,                  KC_H,   KC_J,  KC_K,           KC_L,    KC_SCLN, KC_QUOT,        \
    KC_LSFT,        KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,                  KC_N,   KC_M,  KC_COMM,        KC_DOT,  KC_SLSH, SFT_T(KC_ENT),  \
    LCTL(KC_LSFT),  KC_ESC, KC_LALT, KC_LGUI, LOWER, MT(MOD_RCTL, KC_BSLS), KC_SPC, RAISE, LT(3, KC_LBRC), KC_MINS, KC_EQL,  MT(MOD_RALT, KC_RBRC)

/* LOWER
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │   `  │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │   4  │   5  │   6  │   .  │   *  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  F7  │  F8  │  F9  │  F10 │  F11 │  F12 │   1  │   2  │   3  │   /  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │   0  │      │      │      │   +  │      │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define KTS_LOWER \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_4,    KC_5,    KC_6,    KC_DOT,  KC_ASTR, \
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_1,    KC_2,    KC_3,    KC_SLSH, _______, \
    _______, _______, _______, _______, _______, _______, KC_0,   _______, _______, _______, KC_PLUS, _______

/* RAISE
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │   ~  │   !  │   @  │   #  │   $  │   %  │   ^  │   &  │   *  │   (  │   )  │  Del │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ WHUp │ MSB1 │ MSUp │ MSB2 │Qwerty│ Left │ Down │  Up  │ Right│  S/- │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ WHDw │ MSLf │ MSDw │ MSRgt│  S/= │   -  │   =  │   [  │   ]  │   {  │   }  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │  Ins │      │ Home │ PgDn │ PgUp │ G/End│
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define KTS_RAISE \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,       KC_DEL,         \
    _______, MS_WHLU, MS_BTN1, MS_UP,   MS_BTN2, QWERTY,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, RSFT(KC_MINS), KC_BSLS,        \
    _______, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, RSFT(KC_EQL), KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC),  \
    _______, _______, _______, _______, _______, _______,      KC_INS,  _______, KC_HOME, KC_PGDN, KC_PGUP,       MT(MOD_LGUI, KC_END)

/* GAME
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │   `  │  Esc │   Q  │   W  │   E  │   R  │   T  │ MSB1 │ MSUp │ MSB2 │   Y  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shift│  Tab │   A  │   S  │   D  │   F  │   G  │ MSLf │ MSDw │ MSRgt│   L  │Qwerty│
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   I  │  Alt │   Z  │   X  │   C  │   V  │   B  │   1  │   2  │   3  │   4  │ Enter│
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  Alt │ Ctrl │ Down │  Up  │ MSB2 │ Space│ Space│ Shft │ Left │ Down │  Up  │ Right│
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define KTS_GAME \
    KC_GRV,  KC_ESC,  KC_Q,    KC_W,  KC_E,    KC_R,   KC_T,   MS_BTN1, MS_UP,   MS_BTN2, KC_Y,    KC_BSPC, \
    KC_LSFT, KC_TAB,  KC_A,    KC_S,  KC_D,    KC_F,   KC_G,   MS_LEFT, MS_DOWN, MS_RGHT, KC_L,    QWERTY,  \
    KC_I,    KC_RALT, KC_Z,    KC_X,  KC_C,    KC_V,   KC_B,   KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_ENT,  \
    KC_LALT, KC_LCTL, KC_DOWN, KC_UP, MS_BTN2, KC_SPC, KC_SPC, KC_RSFT, KC_LEFT, KC_PGUP, KC_PGUP, KC_RGHT

/* clang-format on */

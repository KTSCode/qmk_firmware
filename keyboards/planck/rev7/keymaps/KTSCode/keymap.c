#include QMK_KEYBOARD_H

enum planck_layers { _QWERTY, _LOWER, _RAISE, _ADJUST, _GAME };

enum planck_keycodes { QWERTY = SAFE_RANGE, GAME, BACKLIT };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

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
  [_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,                  KC_Y,     KC_U,   KC_I,           KC_O,    KC_P,    KC_BSPC,
    LCTL_T(KC_ESC), KC_A,   KC_S,    KC_D,    KC_F,  KC_G,                  KC_H,     KC_J,   KC_K,           KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,        KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,                  KC_N,     KC_M,   KC_COMM,        KC_DOT,  KC_SLSH, SFT_T(KC_ENT),
    LCTL(KC_LSFT),  KC_ESC, KC_LALT, KC_LGUI, LOWER, MT(MOD_RCTL, KC_BSLS), KC_SPC,   RAISE,  LT(3, KC_LBRC), KC_MINS, KC_EQL,  MT(MOD_RALT, KC_RBRC)
  ),

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
  [_LOWER] = LAYOUT_planck_grid(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_4,    KC_5,    KC_6,    KC_DOT,  KC_ASTR,
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
      _______, _______, _______, _______, _______, _______, KC_0,   _______, _______, _______, KC_PLUS, _______
  ),

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
  [_RAISE] = LAYOUT_planck_grid(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,       KC_DEL,
      _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, QWERTY,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, RSFT(KC_MINS), KC_BSLS,
      _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, RSFT(KC_EQL), KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC),
      _______, _______, _______, _______, _______, _______,      KC_INS,  _______, KC_HOME, KC_PGDN, KC_PGUP,       MT(MOD_LGUI, KC_END)
      ),

 /* ADJUST
  * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
  * │  Esc │      │      │      │ Reset│      │      │ LdH+ │ LdH- │ LdBr │      │ C+A+D│
  * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
  * │ Caps │      │      │ AuOn │ AuOff│ Game │      │ AGNrm│PrtScn│ ScrLk│ Paus │      │
  * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
  * │      │Voice-│Voice+│ MuOn │ MuOff│ Prev │ Next │ Mute │ Vol- │ Vol+ │      │      │
  * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
  * │ Light│      │      │      │      │ Play │ Play │      │ BLTog│ LdM+ │ LdM- │ LdTog│
  * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
  */
  [_ADJUST] = LAYOUT_planck_grid(
      KC_ESC,  _______, _______, _______, RESET,   _______, _______, RGB_HUI, RGB_HUD, RGB_MODE_BREATHE, _______,  LALT(LCTL(KC_DEL)),
      KC_CAPS, _______, _______, AU_ON,   AU_OFF,  GAME,    _______, AG_NORM, KC_PSCR, KC_SLCK,          KC_PAUS,  _______,
      _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,          _______,  _______,
      BACKLIT, _______, _______, _______, _______, KC_MPLY, KC_MPLY, _______, BL_TOGG, RGB_MOD,          RGB_RMOD, RGB_TOG
      ),

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
  [_GAME] = LAYOUT_planck_grid(
      KC_GRV,  KC_ESC,  KC_Q,    KC_W,  KC_E,    KC_R,   KC_T,   KC_BTN1, KC_MS_U, KC_BTN2, KC_Y,    KC_BSPC,
      KC_LSFT, KC_TAB,  KC_A,    KC_S,  KC_D,    KC_F,   KC_G,   KC_MS_L, KC_MS_D, KC_MS_R, KC_L,    QWERTY,
      KC_I,    KC_RALT, KC_Z,    KC_X,  KC_C,    KC_V,   KC_B,   KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_ENT,
      KC_LALT, KC_LCTL, KC_DOWN, KC_UP, KC_BTN2, KC_SPC, KC_SPC, KC_RSFT, KC_LEFT, KC_PGUP, KC_PGUP, KC_RGHT
      )

};
/* clang-format on */

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case GAME:
            if (record->event.pressed) {
              set_single_persistent_default_layer(_GAME);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
#ifdef KEYBOARD_planck_rev5
                writePinLow(E6);
#endif
            } else {
                unregister_code(KC_RSFT);
#ifdef KEYBOARD_planck_rev5
                writePinHigh(E6);
#endif
            }
            return false;
            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}
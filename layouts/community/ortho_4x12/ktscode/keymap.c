#include QMK_KEYBOARD_H
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _ARROW  1
#define _GAME   2
#define _LOWER 3
#define _RAISE 4
#define _PLOVER 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  LOWER,
  RAISE,
  BACKLIT,
  PLOVER,
  EXT_PLV
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl | Wh Up|LeftC | M-Up |RightC|QWERTY| Left | Down |  Up  | Right|  _   |   \  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Wh Dn| M-L  | M-Dn | M-R  |  +   |  -   |  =   |  [   |  ]   |  {   |  }   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  Ins |      | Home | PGDN | PGUP |  End |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_TILD,   KC_EXLM,     KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,   KC_RPRN, KC_DEL, \
  _______,   KC_WH_U,   KC_BTN1, KC_MS_U, KC_BTN2, QWERTY, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   RSFT(KC_MINS),  KC_BSLS, \
  _______,   KC_WH_D,   KC_MS_L, KC_MS_D, KC_MS_R, RSFT(KC_EQL), KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC), \
  _______, _______, _______, _______, _______, _______, KC_INS, _______, KC_HOME, KC_PGDN,   KC_PGUP,  MT(MOD_LGUI, KC_END) \
),
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Esc/Ctrl| A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  Z   |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | C+S  | Esc  | RAlt | GUI  | Lower|\ Ctrl| Space|Raise |   [  |   -  |   =  |] Alt |
 * `-----------------------------------------------------------------------------------'
 * TODO figure out why KC_LGUI and KC_RALT are swapped
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC, \
  LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, SFT_T(KC_ENT), \
  LCTL(KC_LSFT), KC_ESC, KC_LALT, KC_LGUI, LOWER,  MT(MOD_RCTL, KC_BSLS),  KC_SPC,  RAISE,  LT(3, KC_LBRC), KC_MINS, KC_EQL, MT(MOD_RALT, KC_RBRC) \
),
/* Lower   (switched to # because KP# were weird in terminal emulators)
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |   .  |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   0  |      |      |      | KP_+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
   KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,  KC_8, KC_9,    KC_0,  _______, \
   _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,  KC_5, KC_6,  KC_DOT, KC_ASTR, \
  _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,  KC_1,  KC_2, KC_3, KC_SLSH,  _______, \
  _______, _______, _______, _______, _______, _______,    KC_0, _______,  _______, _______, KC_PLUS, _______ \
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |Qwerty|      |      |Reset |Macro0|RGB_HUI|RGB_HUD|RGBreath|  |PLOVER|C-A-D |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |      |      |Aud on|Audoff|GAME, |AGswap|AGnorm| PrtSc|ScrLck| Break|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff| Prev | Next | Mute | VolDn| VolUp|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite|      |      |      |      | Play/Pause  |      |RGB_BR|RGB_F |RGB_R |RGB_T |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12( \
  KC_ESC, QWERTY,   _______, _______,   RESET,    M(0),    M(1), RGB_HUI, RGB_HUD, RGB_MODE_BREATHE,   PLOVER, LALT(LCTL(KC_DEL)), \
  KC_CAPS, _______, _______, AU_ON,    AU_OFF,    GAME, _______, AG_NORM, KC_PSCR,          KC_SLCK,  KC_PAUS,            _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,    MU_OFF, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD,          KC_VOLU,  _______,            _______, \
  BACKLIT, _______, _______, _______, _______, KC_MPLY, KC_MPLY, _______, BL_TOGG,          RGB_MOD, RGB_RMOD,             RGB_TOG \
),
/* Game
 * ,-----------------------------------------------------------------------------------.
 * |   ` |  Esc  |   Q  |   W  |   E  |   R  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |-----+-------+------+------+------+-------------+------+------+------+------+------|
 * |   F | Shift |   A  |   S  |   D  |   V  | Wh Up|LeftC | M-Up |RightC|   ;  |  '   |
 * |-----+-------+------+------+------+------|------+------+------+------+------+------|
 * |   B |CtrlTab|   Z  |   X  |   C  |   H  | Wh Dn| M-L  | M-Dn | M-R  |   /  |Enter |
 * |-----+-------+------+------+------+------+------+------+------+------+------+------|
 * | Alt |  Tab  |   2  |   1  | Lower|    Space    |Raise | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_ortho_4x12( \
   KC_GRV,    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \
   KC_F,   KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_V, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_SCLN,  KC_QUOT, \
   KC_B,   LCTL_T(KC_TAB),   KC_Z,    KC_X,    KC_C,    KC_H, KC_WH_D,  KC_MS_L, KC_MS_D, KC_MS_R, KC_SLSH, _______ , \
  KC_LALT,   KC_TAB,    KC_2,    KC_1,    LOWER,  KC_SPC,  KC_SPC,  RAISE, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT \
),
/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = LAYOUT_ortho_4x12 ( \
  KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   , \
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
  XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX \
)


};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) // this is the function signature -- just copy/paste it into your keymap file as it is.
{
  switch(id) {
    case 0: // this would trigger when you hit a key mapped as M(0)
      if (record->event.pressed) {
        return MACRO( D(LSFT), T(LEFT), U(LSFT), D(LCTL), T(X), U(LCTL), T(RIGHT), D(LCTL), T(V), U(LCTL), T(LEFT),  END  ); // this swaps the characters on either side of the cursor when the macro executes
      }
      break;
    case 1: // this would trigger when you hit a key mapped as M(1)
      if (record->event.pressed) {
        SEND_STRING("I love you, Sarah!");
      }
      break;
  }
  return MACRO_NONE;
};


#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(music_scale);
        #endif
        persistant_default_layer_set(1UL<<_GAME);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
     }
  return true;
}

void matrix_init_user(void) {

}

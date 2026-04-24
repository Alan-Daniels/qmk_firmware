/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
:q
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
    KC_VIBE  = SAFE_RANGE,
};

#define KC_CAD	LALT(LCTL(KC_DEL))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_VIBE:
        if (record->event.pressed) {
        } else {
            SEND_STRING("work back and forth with me, starting with your questions and outline before writing the plan");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,-------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, XXXXXXX,   XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,   KC_P ,     KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+-------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_CAPS,   KC_F20 , KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,    KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------/  \--------+--------+--------+--------+--------+--------+-------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+-------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_LALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,-------------------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_4   , KC_5   , KC_6   , XXXXXXX, KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+-------|
      KC_LCTL, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, XXXXXXX,    XXXXXXX, XXXXXXX, KC_1   , KC_2   , KC_3   , KC_0   , KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------/  \--------+--------+--------+--------+--------+--------+-------|
      KC_LSFT, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                      XXXXXXX, KC_7   , KC_8   , KC_9   , XXXXXXX,XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+-------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,-------------------------------------------------------------.
      KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , XXXXXXX,   XXXXXXX, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+-------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------/  \--------+--------+--------+--------+--------+--------+-------|
      KC_LSFT, KC_LCBR, KC_RCBR, KC_PLUS, KC_UNDS, XXXXXXX,                     XXXXXXX, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+-------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,-------------------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_CAD , KC_VIBE, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+-------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------/  \--------+--------+--------+--------+--------+--------+-------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+-------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_LALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        uint8_t caps_led = g_led_config.matrix_co[1][6];
        if (caps_led != NO_LED && caps_led >= led_min && caps_led < led_max) {
            rgb_matrix_set_color(caps_led, 255, 0, 0); // solid red on Caps Lock (matrix [1,6])
        }
    }
    return false;
}
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

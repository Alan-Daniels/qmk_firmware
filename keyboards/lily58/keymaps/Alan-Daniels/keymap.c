#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _COLMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define COLMAK TG(_COLMAK)
//#define QWERTY TG(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───┬───┬──────┬──────┬────────────┐               ┌────────────┬──────┬─────┬───┬───┬──────┐
//    │ esc  │ 1 │ 2 │  3   │  4   │     5      │               │     6      │  7   │  8  │ 9 │ 0 │  `   │
//    ├──────┼───┼───┼──────┼──────┼────────────┤               ├────────────┼──────┼─────┼───┼───┼──────┤
//    │ tab  │ q │ w │  f   │  p   │     b      │               │     j      │  l   │  u  │ y │ ; │  -   │
//    ├──────┼───┼───┼──────┼──────┼────────────┤               ├────────────┼──────┼─────┼───┼───┼──────┤
//    │ lctl │ a │ r │  s   │  t   │     g      │               │     m      │  n   │  e  │ i │ o │  '   │
//    ├──────┼───┼───┼──────┼──────┼────────────┼─────┐   ┌─────┼────────────┼──────┼─────┼───┼───┼──────┤
//    │ lsft │ z │ x │  c   │  d   │     v      │  [  │   │  ]  │     k      │  h   │  ,  │ . │ / │ caps │
//    └──────┴───┴───┼──────┼──────┼────────────┼─────┤   ├─────┼────────────┼──────┼─────┼───┴───┴──────┘
//                   │ lalt │ lgui │ MO(_LOWER) │ spc │   │ ent │ MO(_RAISE) │ bspc │ del │
//                   └──────┴──────┴────────────┴─────┘   └─────┴────────────┴──────┴─────┘
[_COLMAK] = LAYOUT(
  KC_ESC  , KC_1 , KC_2 , KC_3    , KC_4    , KC_5       ,                         KC_6       , KC_7    , KC_8    , KC_9   , KC_0    , KC_GRV ,
  KC_TAB  , KC_Q , KC_W , KC_F    , KC_P    , KC_B       ,                         KC_J       , KC_L    , KC_U    , KC_Y   , KC_SCLN , KC_MINS,
  KC_LCTL , KC_A , KC_R , KC_S    , KC_T    , KC_G       ,                         KC_M       , KC_N    , KC_E    , KC_I   , KC_O    , KC_QUOT,
  KC_LSFT , KC_Z , KC_X , KC_C    , KC_D    , KC_V       , KC_LBRC ,     KC_RBRC , KC_K       , KC_H    , KC_COMM , KC_DOT , KC_SLSH , KC_CAPS,
                          KC_LALT , KC_LGUI , MO(_LOWER) , KC_SPC  ,     KC_ENT  , MO(_RAISE) , KC_BSPC , KC_DEL
),

//    ┌──────┬───┬───┬──────┬──────┬────────────┐               ┌────────────┬──────┬─────┬───┬───┬──────┐
//    │ esc  │ 1 │ 2 │  3   │  4   │     5      │               │     6      │  7   │  8  │ 9 │ 0 │  `   │
//    ├──────┼───┼───┼──────┼──────┼────────────┤               ├────────────┼──────┼─────┼───┼───┼──────┤
//    │ tab  │ q │ w │  e   │  r   │     t      │               │     y      │  u   │  i  │ o │ p │  -   │
//    ├──────┼───┼───┼──────┼──────┼────────────┤               ├────────────┼──────┼─────┼───┼───┼──────┤
//    │ lctl │ a │ s │  d   │  f   │     g      │               │     h      │  j   │  k  │ l │ ; │  '   │
//    ├──────┼───┼───┼──────┼──────┼────────────┼─────┐   ┌─────┼────────────┼──────┼─────┼───┼───┼──────┤
//    │ lsft │ z │ x │  c   │  v   │     b      │  [  │   │  ]  │     n      │  m   │  ,  │ . │ / │ caps │
//    └──────┴───┴───┼──────┼──────┼────────────┼─────┤   ├─────┼────────────┼──────┼─────┼───┴───┴──────┘
//                   │ lalt │ lgui │ MO(_LOWER) │ spc │   │ ent │ MO(_RAISE) │ bspc │ del │
//                   └──────┴──────┴────────────┴─────┘   └─────┴────────────┴──────┴─────┘
[_QWERTY] = LAYOUT(
  KC_ESC  , KC_1 , KC_2 , KC_3    , KC_4    , KC_5       ,                         KC_6       , KC_7    , KC_8    , KC_9   , KC_0    , KC_GRV ,
  KC_TAB  , KC_Q , KC_W , KC_E    , KC_R    , KC_T       ,                         KC_Y       , KC_U    , KC_I    , KC_O   , KC_P    , KC_MINS,
  KC_LCTL , KC_A , KC_S , KC_D    , KC_F    , KC_G       ,                         KC_H       , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z , KC_X , KC_C    , KC_V    , KC_B       , KC_LBRC ,     KC_RBRC , KC_N       , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_CAPS,
                          KC_LALT , KC_LGUI , MO(_LOWER) , KC_SPC  ,     KC_ENT  , MO(_RAISE) , KC_BSPC , KC_DEL
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐               ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │     │     │     │     │     │               │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │     │     │               │ no  │  4  │  5  │  6  │ no  │ f12 │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  !  │  @  │  #  │  $  │  %  │               │ no  │  1  │  2  │  3  │  0  │ no  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  ^  │  &  │  *  │  (  │  )  │     │   │     │ no  │  7  │  8  │  9  │  ;  │ no  │
//    └─────┴─────┴─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┴─────┴─────┘
//                      │     │     │     │     │   │     │     │     │     │
//                      └─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┘
[_LOWER] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______ , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ ,                         XXXXXXX , KC_4    , KC_5    , KC_6    , XXXXXXX , KC_F12 ,
  _______ , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,                         XXXXXXX , KC_1    , KC_2    , KC_3    , KC_0    , XXXXXXX,
  _______ , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______ ,     _______ , XXXXXXX , KC_7    , KC_8    , KC_9    , KC_SCLN , XXXXXXX,
                                _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐               ┌─────┬──────┬──────┬─────┬──────┬─────┐
//    │     │     │     │     │     │     │               │     │      │      │     │      │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼──────┼──────┼─────┼──────┼─────┤
//    │ f1  │ f2  │ f3  │ f4  │ f5  │ f6  │               │ f7  │  f8  │  f9  │ f10 │ f11  │ f12 │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼──────┼──────┼─────┼──────┼─────┤
//    │     │     │     │     │     │     │               │ no  │ left │ down │ up  │ rght │ no  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼─────┼──────┼──────┼─────┼──────┼─────┤
//    │     │     │     │     │     │     │     │   │     │ no  │  -   │  =   │  [  │  ]   │  \  │
//    └─────┴─────┴─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼──────┼──────┼─────┴──────┴─────┘
//                      │     │     │     │     │   │     │     │      │      │
//                      └─────┴─────┴─────┴─────┘   └─────┴─────┴──────┴──────┘
[_RAISE] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______ , _______ , _______ , _______ , _______ , _______,
  KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                         KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12 ,
  _______ , _______ , _______ , _______ , _______ , _______ ,                         XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , XXXXXXX,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,     _______ , XXXXXXX , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS,
                                _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______
),

//    ┌────┬────┬────┬─────┬─────┬─────┐                  ┌─────┬──────┬───────────┬─────────┬─────┬────┐
//    │ no │ no │ no │ no  │ no  │ no  │                  │ no  │  no  │    no     │   no    │ no  │ no │
//    ├────┼────┼────┼─────┼─────┼─────┤                  ├─────┼──────┼───────────┼─────────┼─────┼────┤
//    │ no │ no │ no │ no  │ no  │ no  │                  │ no  │  no  │    no     │   no    │ no  │ no │
//    ├────┼────┼────┼─────┼─────┼─────┤                  ├─────┼──────┼───────────┼─────────┼─────┼────┤
//    │ no │ no │ no │ no  │ no  │ no  │                  │ no  │ home │ pAGE_DOWN │ pAGE_UP │ end │ no │
//    ├────┼────┼────┼─────┼─────┼─────┼────────┐   ┌─────┼─────┼──────┼───────────┼─────────┼─────┼────┤
//    │ no │ no │ no │ no  │ no  │ no  │ COLMAK │   │ no  │ no  │  no  │    no     │   no    │ no  │ no │
//    └────┴────┴────┼─────┼─────┼─────┼────────┤   ├─────┼─────┼──────┼───────────┼─────────┴─────┴────┘
//                   │     │     │     │        │   │     │     │      │           │
//                   └─────┴─────┴─────┴────────┘   └─────┴─────┴──────┴───────────┘
[_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX      , XXXXXXX    , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX      , XXXXXXX    , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , KC_HOME , KC_PAGE_DOWN , KC_PAGE_UP , KC_END  , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , COLMAK  ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX      , XXXXXXX    , XXXXXXX , XXXXXXX,
                                _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // if (!is_keyboard_left()) return OLED_ROTATION_270;
    // if (is_keyboard_master()) {
    //     if (is_keyboard_left())
    //     {
    //         return rotation;
    //     } else {
    //         return OLED_ROTATION_180;
    //     }
    // };
    // return OLED_ROTATION_180;
    return OLED_ROTATION_270;
}

static void render_status(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERT"), false);
            break;
        case _COLMAK:
            oled_write_P(PSTR("COLMA"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJST"), false);
            break;
        default:
            oled_write_P(PSTR("ERROR"), false);
    }
    oled_advance_page(false);
    oled_advance_page(false);
    oled_advance_page(false);
    oled_advance_page(false);

    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR(" NUM "), led_state.num_lock);
    oled_advance_page(false);
    oled_write_P(PSTR(" CAPS"), led_state.caps_lock);
    oled_advance_page(false);
    oled_write_P(PSTR(" SCRL"), led_state.scroll_lock);
}

bool oled_task_user(void) {
    // If you want to change the display of OLED, you need to change here
    if (is_keyboard_master()) {
        oled_set_cursor(0,0);
        render_status();
    }
    return false;
}

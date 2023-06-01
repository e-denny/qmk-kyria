/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _NAV,
    _NUM,
    _SYM,
    _FKEYS,
    _ADJUST,
    _MEDIA
};


#define ADJUST  MO(_ADJUST)
#define FN_KEYS MO(_FKEYS)
#define MEDIA   MO(_MEDIA)

#define SYM_TAB LT(_SYM, KC_TAB)
#define NUM_ENT LT(_NUM, KC_ENT)
#define NAV_ESC LT(_NAV, KC_ESC)

#define CTL_F LCTL_T(KC_F)
#define CTL_J LCTL_T(KC_J)
#define ALT_D LALT_T(KC_D)
#define ALT_K LALT_T(KC_K)
#define GUI_S LGUI_T(KC_S)
#define GUI_L LGUI_T(KC_L)
#define SFT_G LSFT_T(KC_G)
#define SFT_H LSFT_T(KC_H)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
     KC_GRV , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P    , KC_EQL ,
     KC_TILD, KC_A   , GUI_S  , ALT_D  , CTL_F  , SFT_G  ,                                        SFT_H  , CTL_J  , ALT_K  , GUI_L  , KC_SCLN , KC_QUOT,
     XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LPRN, KC_CAPS,    CW_TOGG, KC_RPRN, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH , KC_MINS,
                                ADJUST , FN_KEYS, NAV_ESC, SYM_TAB, NUM_ENT ,   KC_SPC , KC_BSPC, KC_DEL , XXXXXXX, MEDIA
    ),
    [_NAV] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                                        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
     _______, _______, _______, _______, _______, _______,                                        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_UNDO, KC_COPY, KC_PASTE,KC_CUT , _______, _______,
                                _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),
    [_NUM] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                                        KC_0   , KC_1   , KC_2   , KC_3   , KC_DLR , _______,
     _______, _______, _______, _______, _______, KC_LSFT,                                        _______, KC_4   , KC_5   , KC_6   , _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_7   , KC_8   , KC_9   , _______, _______,
                                _______, _______, _______, _______, _______,    _______, _______, KC_0   , KC_COMM, KC_DOT
    ),
    [_SYM] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                                        KC_LPRN, KC_EXLM, KC_AT  , KC_HASH, KC_RPRN, KC_GRV ,
     _______, _______, _______, _______, _______, _______,                                        KC_LBRC, KC_DLR , KC_PERC, KC_CIRC, KC_RBRC, KC_TILD,
     _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______,
                                _______, _______, _______, _______, _______,    _______, _______, KC_RPRN, KC_BSLS, KC_PIPE
    ),
    [_FKEYS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                        _______, KC_F1  , KC_F2  , KC_F3  , _______, _______,
      _______, _______, _______, _______, _______, _______,                                        _______, KC_F4  , KC_F5  , KC_F6  , _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_F7  , KC_F8  , KC_F9  , _______, _______,
                                 _______, _______, _______, _______, _______,    _______, _______, KC_F10 , KC_F11 , KC_F12
    ),
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______ , _______,
      _______, _______, _______, _______, _______, _______,                                        RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD , _______,
      _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),
    [_MEDIA] = LAYOUT(
      _______, _______, _______, KC_VOLU, KC_VOLD, KC_MUTE,                                        _______, _______, _______, _______, _______, _______,
      _______, _______, _______, KC_BRIU, KC_BRID, _______,                                        _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,_______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______,_______, _______,     _______, _______, _______, _______, _______
    )
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {

        static const char PROGMEM nav_logo[] = {
            0,254,254,112,224,192,128,  0,  0,254,254,  0,  0,224,240, 56, 28,  6,  6, 28, 56,240,224,  0,  0,254,254,  0,  0,  0,  0,  0,  0,254,254,  0,  0,  0,  6,  6,254,254,  6,  6,  0,  0,  0,248,252, 14,  6,  6,  6,  6, 14, 28, 24,  0,  0,224,240, 56, 28,  6,  6, 28, 56,240,224,  0,  0,  6,  6,  6,  6,254,254,  6,  6,  6,  6,  0,  0,  0,  6,  6,254,254,  6,  6,  0,  0,  0,248,252, 14,  6,  6,  6,  6, 14,252,248,  0,  0,254,254,112,224,192,128,  0,  0,254,254,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,127,127,  0,  0,  1,  3,  7, 14,127,127,  0,  0,127,127,  6,  6,  6,  6,  6,  6,127,127,  0,  0,  7, 15, 28, 56, 96, 96, 56, 28, 15,  7,  0,  0,  0, 96, 96,127,127, 96, 96,  0,  0,  0, 31, 63,112, 96, 96, 99, 99,115, 63, 31,  0,  0,127,127,  6,  6,  6,  6,  6,  6,127,127,  0,  0,  0,  0,  0,  0,127,127,  0,  0,  0,  0,  0,  0,  0, 96, 96,127,127, 96, 96,  0,  0,  0, 31, 63,112, 96, 96, 96, 96,112, 63, 31,  0,  0,127,127,  0,  0,  1,  3,  7, 14,127,127,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };

        static const char PROGMEM num_logo[] = {
            0,254,254,112,224,192,128,  0,  0,254,254,  0,  0,254,254,  0,  0,  0,  0,  0,  0,254,254,  0,  0,254,254,112,224,192,192,224,112,254,254,  0,  0,254,254,134,134,134,134,134,206,252,120,  0,  0,254,254,134,134,134,134,134,134,  6,  6,  0,  0,254,254,206,134,134,134,134,206,252,120,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,127,127,  0,  0,  1,  3,  7, 14,127,127,  0,  0, 31, 63,112, 96, 96, 96, 96,112, 63, 31,  0,  0,127,127,  0,  0,  1,  1,  0,  0,127,127,  0,  0,127,127, 97, 97, 97, 97, 97,115, 63, 30,  0,  0,127,127, 97, 97, 97, 97, 97, 97, 96, 96,  0,  0,127,127,  1,  3,  7, 15, 29, 57,112, 96,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };

        static const char PROGMEM sym_logo[] = {
            0,120,252,206,134,134,134,134,142, 28, 24,  0,  0,  6, 30,120,224,128,128,224,120, 30,  6,  0,  0,254,254,112,224,192,192,224,112,254,254,  0,  0,254,254,134,134,134,134,134,206,252,120,  0,  0,248,252, 14,  6,  6,  6,  6, 14,252,248,  0,  0,254,254,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0, 24, 56,113, 97, 97, 97, 97,115, 63, 30,  0,  0,  0,  0,  0,  1,127,127,  1,  0,  0,  0,  0,  0,127,127,  0,  0,  1,  1,  0,  0,127,127,  0,  0,127,127, 97, 97, 97, 97, 97,115, 63, 30,  0,  0, 31, 63,112, 96, 96, 96, 96,112, 63, 31,  0,  0,127,127, 96, 96, 96, 96, 96, 96, 96, 96,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };

        static const char PROGMEM media_logo[] = {
            0,254,254,112,224,192,192,224,112,254,254,  0,  0,254,254,134,134,134,134,134,134,  6,  6,  0,  0,254,254,  6,  6,  6,  6,  6, 14,252,248,  0,  0,  0,  6,  6,254,254,  6,  6,  0,  0,  0,224,240, 56, 14,  6,  6, 14, 56,240,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,127,127,  0,  0,  1,  1,  0,  0,127,127,  0,  0,127,127, 97, 97, 97, 97, 97, 97, 96, 96,  0,  0,127,127, 96, 96, 96, 96, 96,112, 63, 31,  0,  0,  0, 96, 96,127,127, 96, 96,  0,  0,  0,127,127,  6,  6,  6,  6,  6,  6,127,127,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };

        static const char PROGMEM function_logo[] = {
            0,254,254,134,134,134,134,134,134,  6,  6,  0,  0,254,254,  0,  0,  0,  0,  0,  0,254,254,  0,  0,254,254,112,224,192,128,  0,  0,254,254,  0,  0,  0,248,252, 14,  6,  6,  6,  6, 14, 28, 24,  0,  0,  6,  6,  6,  6,254,254,  6,  6,  6,  6,  0,  0,  0,  6,  6,254,254,  6,  6,  0,  0,  0,248,252, 14,  6,  6,  6,  6, 14,252,248,  0,  0,254,254,112,224,192,128,  0,  0,254,254,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,127,127,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0, 31, 63,112, 96, 96, 96, 96,112, 63, 31,  0,  0,127,127,  0,  0,  1,  3,  7, 14,127,127,  0,  0,  0, 31, 63,112, 96, 96, 96, 96,112, 56, 24,  0,  0,  0,  0,  0,  0,127,127,  0,  0,  0,  0,  0,  0,  0, 96, 96,127,127, 96, 96,  0,  0,  0, 31, 63,112, 96, 96, 96, 96,112, 63, 31,  0,  0,127,127,  0,  0,  1,  3,  7, 14,127,127,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };

        static const char PROGMEM adjust_logo[] = {
            0,224,248, 60, 14,  6,  6, 14, 60,248,224,  0,  0,254,254,  6,  6,  6,  6,  6, 14,252,248,  0,  0,  6,  6,  6,  6,  6,254,254,  6,  6,  6,  0,  0,  0,254,254,  0,  0,  0,  0,  0,  0,254,254,  0,  0,120,252,206,134,134,134,134,142, 28, 24,  0,  0,  0,  6,  6,  6,  6,254,254,  6,  6,  6,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,127,127,  6,  6,  6,  6,  6,  6,127,127,  0,  0,127,127, 96, 96, 96, 96, 96,112, 63, 31,  0,  0, 24, 56,112, 96,112, 63, 31,  0,  0,  0,  0,  0,  0, 31, 63,112, 96, 96, 96, 96,112, 63, 31,  0,  0, 24, 56,113, 97, 97, 97, 97,115, 63, 30,  0,  0,  0,  0,  0,  0,  0,127,127,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };

        static const char PROGMEM qwerty_logo[] = {
            0,248,252, 14,  6,  6,  6,  6, 14,252,248,  0,  0,254,254,  0,  0,192,192,  0,  0,254,254,  0,  0,254,254,134,134,134,134,134,134,  6,  6,  0,  0,  0,254,254,134,134,134,134,134,206,252,120,  0,  0,  6,  6,  6,  6,254,254,  6,  6,  6,  6,  0,  0,  0, 14, 62,120,224,192,192,224,120, 62, 14,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0, 31, 63,112, 96,102,110, 92, 56,119,111,  0,  0,127,127, 60, 15,  3,  3, 15, 60,127,127,  0,  0,127,127, 97, 97, 97, 97, 97, 97, 96, 96,  0,  0,  0,127,127,  1,  3,  7, 15, 29, 57,112, 96,  0,  0,  0,  0,  0,  0,127,127,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,127,127,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };

        oled_write_P(PSTR("Kyria rev3\n\n"), false);

        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
        case _QWERTY:
            oled_set_cursor(0, 4);
            oled_write_raw_P(qwerty_logo, sizeof(nav_logo));
            break;
        case _NAV:
            oled_set_cursor(0, 4);
            oled_write_raw_P(nav_logo, sizeof(nav_logo));
            break;
        case _NUM:
            oled_set_cursor(0, 4);
            oled_write_raw_P(num_logo, sizeof(nav_logo));
            break;
        case _SYM:
            oled_set_cursor(0, 4);
            oled_write_raw_P(sym_logo, sizeof(nav_logo));
            break;
        case _FKEYS:
            oled_set_cursor(0, 4);
            oled_write_raw_P(function_logo, sizeof(nav_logo));
            break;
        case _ADJUST:
            oled_set_cursor(0, 4);
            oled_write_raw_P(adjust_logo, sizeof(nav_logo));
            break;
        case _MEDIA:
            oled_set_cursor(0, 4);
            oled_write_raw_P(media_logo, sizeof(nav_logo));
            break;
        default:
            //oled_write_P(PSTR("Undefined\n"), false);
        }


        // Write host Keyboard LED Status to OLEDs
        /* led_t led_usb_state = host_keyboard_led_state(); */
        /* oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false); */
        /* oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false); */
        /* oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false); */
    } else {
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };

        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}

#define MY_YELLOW 17, 25, 0
#define MY_GREEN  0, 25, 17
#define MY_TEAL 17, 0, 25
#define MY_RED 25, 0, 0
#define MY_ORANGE 25, 17, 0
#define MY_BLUE 0, 0, 25
#define MY_WHITE 10, 10, 10
#define MY_PINK 17, 0, 25


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t curr_layer = get_highest_layer(layer_state|default_layer_state);
    switch(curr_layer) {
    case _QWERTY:
        break;
    case _NAV:
        rgb_matrix_set_color(7, MY_PINK);
        rgb_matrix_set_color(8, MY_PINK);
        rgb_matrix_set_color(9, MY_PINK);
        rgb_matrix_set_color(10, MY_PINK);
        rgb_matrix_set_color(14, MY_PINK);
        rgb_matrix_set_color(15, MY_PINK);
        rgb_matrix_set_color(16, MY_PINK);
        rgb_matrix_set_color(20, MY_PINK);
        rgb_matrix_set_color(21, MY_PINK);
        rgb_matrix_set_color(22, MY_PINK);

        rgb_matrix_set_color(44, MY_WHITE);
        rgb_matrix_set_color(45, MY_WHITE);
        rgb_matrix_set_color(46, MY_WHITE);
        rgb_matrix_set_color(47, MY_WHITE);
        rgb_matrix_set_color(50, MY_BLUE);
        rgb_matrix_set_color(51, MY_BLUE);
        rgb_matrix_set_color(52, MY_BLUE);
        rgb_matrix_set_color(53, MY_BLUE);
        break;
    case _NUM:
        rgb_matrix_set_color(13, MY_BLUE);

        rgb_matrix_set_color(33, MY_YELLOW);
        rgb_matrix_set_color(34, MY_GREEN);
        rgb_matrix_set_color(35, MY_GREEN);
        rgb_matrix_set_color(39, MY_YELLOW);
        rgb_matrix_set_color(40, MY_YELLOW);
        rgb_matrix_set_color(41, MY_YELLOW);
        rgb_matrix_set_color(45, MY_YELLOW);
        rgb_matrix_set_color(46, MY_YELLOW);
        rgb_matrix_set_color(47, MY_YELLOW);
        rgb_matrix_set_color(51, MY_YELLOW);
        rgb_matrix_set_color(52, MY_YELLOW);
        rgb_matrix_set_color(53, MY_YELLOW);
        rgb_matrix_set_color(54, MY_GREEN);
        break;
    case _SYM:
        rgb_matrix_set_color(38, MY_BLUE);
        rgb_matrix_set_color(39, MY_BLUE);
        rgb_matrix_set_color(44, MY_BLUE);
        rgb_matrix_set_color(45, MY_BLUE);
        rgb_matrix_set_color(48, MY_TEAL);
        rgb_matrix_set_color(49, MY_TEAL);
        rgb_matrix_set_color(50, MY_BLUE);
        rgb_matrix_set_color(51, MY_BLUE);
        rgb_matrix_set_color(54, MY_TEAL);
        rgb_matrix_set_color(55, MY_TEAL);
        break;
    case _FKEYS:
        rgb_matrix_set_color(33, MY_YELLOW);
        rgb_matrix_set_color(34, MY_YELLOW);
        rgb_matrix_set_color(35, MY_YELLOW);
        rgb_matrix_set_color(39, MY_YELLOW);
        rgb_matrix_set_color(40, MY_YELLOW);
        rgb_matrix_set_color(41, MY_YELLOW);
        rgb_matrix_set_color(45, MY_YELLOW);
        rgb_matrix_set_color(46, MY_YELLOW);
        rgb_matrix_set_color(47, MY_YELLOW);
        rgb_matrix_set_color(50, MY_YELLOW);
        rgb_matrix_set_color(51, MY_YELLOW);
        rgb_matrix_set_color(52, MY_YELLOW);
        break;
    case _ADJUST:
        rgb_matrix_set_color(39, MY_TEAL);
        rgb_matrix_set_color(40, MY_TEAL);
        rgb_matrix_set_color(41, MY_TEAL);
        rgb_matrix_set_color(42, MY_TEAL);
        rgb_matrix_set_color(44, MY_RED);
        rgb_matrix_set_color(45, MY_TEAL);
        rgb_matrix_set_color(46, MY_TEAL);
        rgb_matrix_set_color(47, MY_TEAL);
        rgb_matrix_set_color(48, MY_TEAL);
        break;
    case _MEDIA:
        rgb_matrix_set_color(14, MY_ORANGE);
        rgb_matrix_set_color(15, MY_ORANGE);
        rgb_matrix_set_color(19, MY_RED);
        rgb_matrix_set_color(20, MY_GREEN);
        rgb_matrix_set_color(21, MY_GREEN);
        break;
    }
    return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

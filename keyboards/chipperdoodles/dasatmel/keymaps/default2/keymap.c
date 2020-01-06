/* Copyright 2017 Mathias Andersson <wraul@dbox.se>
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

// Helpful defines
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = KEYMAP(\
        KC_F6,   KC_LALT,  KC_H, KC_G, KC_F4,  KC_ESC,   KC_F11,  KC_P0,    KC_QUOT,  KC_SPACE, KC_PDOT,  KC_UP,\
        KC_8,    KC_PSCR,  KC_9, KC_7, KC_4,   KC_3,     KC_2,    KC_1,     KC_F5,    KC_F10,   KC_0,     KC_PGDN,  KC_END,\
        KC_EQL,  KC_F8,    KC_6, KC_5, KC_F2,  KC_F1,    KC_GRV,  KC_LCTL,  KC_F9,    KC_INS,   KC_MINS,  KC_DEL,   KC_PGUP,  KC_HOME,\
        KC_K,    KC_L,     KC_J, KC_F, KC_D,   KC_S,     KC_A,    KC_BSLS,  KC_P2,    KC_SCLN,  KC_P1,    KC_P3,    KC_RGUI,  KC_RSHIFT,   KC_PENT,\
        KC_RBRC, KC_F7,    KC_Y, KC_T, KC_F3,  KC_CAPS,  KC_TAB,  KC_BSPC,  KC_P5,    KC_LBRC,  KC_P4,    KC_P6,    KC_LGUI,  KC_LSHIFT, \
        KC_I,    KC_SLCK,  KC_O, KC_U, KC_R,   KC_E,     KC_W,     KC_Q,    KC_PAUSE, KC_P8,    KC_P,     KC_P7,    KC_P9,    KC_PPLS,\
        KC_COMM, KC_DOT,   KC_M, KC_V, KC_C,   KC_X,     KC_Z,    KC_RCTL,  KC_ENT,   KC_PSLS,  KC_NLCK,  KC_PAST, \
        KC_RALT, KC_MENU,  KC_N, KC_B, KC_F12, KC_RIGHT, KC_SLSH, KC_DOWN,  KC_PMNS,  KC_LEFT )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            break;
    }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

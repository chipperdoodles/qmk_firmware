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

#include "phant_teensy2pp.h"

/*
( \
*    K00, K53, K02, K03, K04, K05, K56, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, \
*    K01, K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, \
*    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D,      K2E, K2F, K2G, \
*    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,      K3E, K3F, K3G, \
*    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D,      K4E, K4F, K4G, \
*    K50, K51, K52, K54,      K55, K57, K58,           K5A, K5B, K5C, K5D,      K5E, K5F, K5G  \
* )
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_7bit(
    KC_ESC,  KC_F1,   KC_F2,  KC_F3, KC_F4,KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSLASH, KC_ASTERISK, KC_MINS, KC_PLUS, KC_NUMLOCK, \
    KC_GRV,  KC_1,    KC_2,   KC_3,  KC_4, KC_5,  KC_6,  KC_7,  KC_8,  KC_9,    KC_0,    KC_EQL, KC_MINS,  KC_PSCR, KC_DEL,  KC_7, KC_8, KC_9, \
    KC_TAB,  KC_Q,    KC_W,   KC_E,  KC_R, KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_4, KC_5, KC_6, \
    KC_LCTL, KC_A,    KC_S,   KC_D,  KC_F, KC_G,  KC_H,  KC_J,  KC_K,  KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,           KC_1, KC_2, KC_3, \
    KC_LSFT, KC_LSFT, KC_Z,   KC_X,  KC_C, KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,          KC_0, KC_UP, KC_DOT, \
    KC_LCTL, KC_LGUI, KC_RCTL,KC_SPC,      KC_SPC,KC_SPC,KC_SPC,                KC_RALT, KC_RGUI, KC_MENU, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RIGHT),

};

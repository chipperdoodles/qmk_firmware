/* Copyright 2019 Martin Knobel
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
#ifndef DASATMEL_H
#define DASATMEL_H

#include "quantum.h"

#define KEYMAP( \
          K00,   K01,   K03,   K04,   K05,   K07,   K09,   K0A,   K0B,   K0C,   K0D,   K0H, \
          K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1B,   K1D,   K1H, \
          K20,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,   K2D,  K2H, \
          K30,   K32,   K33,   K34,   K35,   K36,   K37,   K39,   K3A,   K3B,   K3C,   K3D,   K3E,  K3G, K3H, \
          K40,   K42,   K43,   K44,   K45,   K46,   K47,   K49,   K4A,   K4B,   K4C,   K4D,   K4F,  K4G,\
          K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57,   K58,   K5A,   K5B,   K5C,   K5D,   K5H,\
          K60,   K62,   K63,   K64,   K65,   K66,   K67,   K68,   K69,   K6A,   K6C,   K6D,\
          K71,   K72,   K73,   K74,   K79,   K7A,   K7B,   K7C,   K7D,   K7H \
) { \
          { K00,   K01,   KC_NO, K03,   K04,   K05,   KC_NO, K07,   KC_NO, K09,   K0A,   K0B,   K0C,   K0D,   KC_NO, KC_NO, KC_NO, K0H }, \
          { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   KC_NO, K1B,   KC_NO, K1D,   KC_NO, KC_NO, KC_NO, K1H }, \
          { K20,   KC_NO, K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,   K2D,   KC_NO, KC_NO, KC_NO, K2H }, \
          { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   KC_NO, K39,   K3A,   K3B,   K3C,   K3D,   K3E,   KC_NO, K3G,   K3H }, \
          { K40,   KC_NO, K42,   K43,   K44,   K45,   K46,   K47,   KC_NO, K49,   K4A,   K4B,   K4C,   K4D,   KC_NO, K4F,   K4G,   KC_NO }, \
          { K50,   K51,   K52,   K53,   K54, K55,   K56,   K57,   K58,   KC_NO, K5A,   K5B,   K5C,   K5D,   KC_NO, KC_NO, KC_NO, K5H }, \
          { K60,   KC_NO, K62,   K63,   K64,   K65,   K66,   K67,   K68,   K69,   K6A,   KC_NO, K6C,   K6D,   KC_NO, KC_NO, KC_NO, KC_NO }, \
          { KC_NO, K71,   K72,   K73,   K74,   KC_NO, KC_NO, KC_NO, KC_NO, K79,   K7A,   K7B,   K7C,   K7D,   KC_NO, KC_NO, KC_NO, K7H } \
}

#endif

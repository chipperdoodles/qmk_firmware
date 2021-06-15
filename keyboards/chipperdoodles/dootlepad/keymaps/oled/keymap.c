/* Copyright 2019 chipperdoodles
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
          KC_ESC, KC_PGUP, KC_PGDN, KC_BSPC, \
          KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
          KC_P7, KC_P8, KC_P9, KC_PPLS, \
KC_EQL, KC_LGUI, KC_P4, KC_P5, KC_P6, \
KC_LSFT, KC_LCTL, KC_P1, KC_P2, KC_P3, KC_PENT, \
MO(1), MO(2), KC_P0, KC_PDOT      \
),

 [1] = LAYOUT( /* media */
          KC_ESC, KC_PGUP, KC_PGDN, KC_BSPC, \
          KC_VOLD, KC_MPLY, KC_MUTE, KC_VOLU, \
          KC_TAB, KC_UP, KC_SPC, KC_TRNS, \
KC_LEFT, KC_RIGHT, KC_LEFT, KC_DOWN, KC_RIGHT, \
KC_UP, KC_DOWN, KC_P1, KC_P2, KC_P3, KC_PENT, \
KC_TRNS, KC_TRNS, KC_P0, KC_PDOT      \
),

[2] = LAYOUT( /* music */
          RESET, KC_TRNS, KC_TRNS, KC_DEL, \
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
          BL_TOGG, RGB_VAI, BL_DEC, BL_INC, \
KC_LEFT, KC_RIGHT, RGB_SAD, RGB_TOG, RGB_SAI, \
KC_UP, KC_DOWN, RGB_HUD, RGB_VAD, RGB_HUI, RGB_MOD,\
KC_TAB, KC_SPC, MU_MOD, MU_TOG      \
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {
  #ifdef OLED_DRIVER_ENABLE
  oled_init(0);
  void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}
  #endif

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
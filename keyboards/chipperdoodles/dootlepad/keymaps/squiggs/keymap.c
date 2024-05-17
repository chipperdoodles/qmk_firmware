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
          KC_ESC, TG(1), KC_MUTE, KC_BSPC, \
          KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
          KC_P7, KC_P8, KC_P9, KC_PPLS, \
LSFT(KC_SLASH), LSFT(KC_4), KC_P4, KC_P5, KC_P6, \
LSFT(KC_7), LSFT(KC_1), KC_P1, KC_P2, KC_P3, KC_PENT, \
LSFT(KC_9), LSFT(KC_0), KC_P0, KC_PDOT      \
),

 [1] = LAYOUT( /* media */
          KC_TRNS, TO(0), KC_TRNS, KC_TRNS, \
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
          KC_TRNS, KC_VOLU, KC_SPC, KC_TRNS, \
KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, \
KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, \
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS      \
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
            oled_write_P(PSTR("MEDIA\n"), false);
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
#include "derpypad.h"

enum {
    _BASE = 0,
    _MULTIMEDIA = 1,
    _MOUSE = 2,
    _ADJUST = 3
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = KEYMAP(
		KC_MUTE, KC_VOLD, KC_VOLU, KC_BSPC,
		LT(3, KC_NLCK), KC_PSLS, KC_PAST, KC_PMNS,
		KC_P7, KC_P8, KC_P9,
		KC_P4, KC_P5, KC_P6, KC_PPLS,
		KC_P1, KC_P2, KC_P3,
		KC_P0, KC_PDOT, KC_PENT),
        
    [_MULTIMEDIA] = KEYMAP(
        KC_MUTE, KC_VOLD, KC_VOLU, KC_BSPC,
        LT(3, KC_NLCK), KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7, KC_VOLU, KC_P9,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_PPLS,
        KC_P1, KC_VOLD, KC_P3,
        KC_P0, KC_PDOT, KC_PENT),
        
    [_MOUSE] = KEYMAP(
        KC_MUTE, KC_VOLD, KC_VOLU, KC_BSPC,
        LT(3, KC_NLCK), KC_PSLS, KC_PAST, KC_WH_U,
        KC_BTN1, KC_MS_U, KC_BTN2,
        KC_MS_L, KC_BTN3, KC_MS_R, KC_WH_D,
        KC_BTN4, KC_MS_D, KC_BTN5,
        KC_ACL0, KC_ACL1, KC_ACL2),

    [_ADJUST] = KEYMAP(
        TO(0), TO(1), TO(2), TO(3),
        LT(3, KC_NLCK), OUT_USB, OUT_BT, OUT_AUTO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO),
    };
    
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}
    
void led_set_user(uint8_t usb_led) {
        
    }
    
void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

void matrix_scan_user(void) {
  

}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case _MULTIMEDIA:
            oled_write_P(PSTR("MULTIMEDIA\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("MOUSE\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJUST\n"), false);
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
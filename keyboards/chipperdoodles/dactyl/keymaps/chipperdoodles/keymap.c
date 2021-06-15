#include "Dactyl.h"
#include "action_layer.h"
#include "eeconfig.h"


#define _QWERTY 0
#define _ADJ 5

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	ADJ,
};

#define _______ KC_TRNS



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.           ,----------------------------------_--------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+------|           |------+------+------+------+------|--------|
 * |Tab\FN3 |   Q  |   W  |   F  |   P  |   G  |           |   J  |   L  |   U  |   Y  |   :  |   \    |
 * |--------+------+------+------+------+----- |           |------+------+------+------+------|--------|
 * | ENT/ADJ|   A  |   R  |   S  |   T  |   D  |           |   H  |   N  |   E  |   I  |   O  | ENTER  |
 * |--------+------+------+------+------+------|           |------+------+------+------+------|--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |           |   K  |   M  |   ,  |   .  |  /   |RShift |
 * `--------+------+------+------+------+------'           `-------+------+------+------+------|--------|'
 * |CTR     |  ALT | GUI  | Left | Right|    1                1   | LEFT | RIGHT|  UP  | DOWN  | ~L1  |
 * `----------------------------------'                          `----------------------------------'
 *				6	5		4	   3		2				2		 3		4		5		6
 *                                 ,-------------.       ,-------------.
 *                                 |   6  |   5  |       | 5    |  6     |
 *                          ,------|------|------|       |------+--------+------.
 *                          |   1  |  2    |   4  |       | 4    |        |      |
 *                          |Backsp|GUI   |------|       |------|    1   |    2 |
 *                          |  acs |TAB   |   3  |       | 3    |        |      |
 *                         `--------------------'       `----------------------'
 
 
  		PGUP,PGDN, 			END, HOME,
  BSPC,LDWN, PSCR, 			DEL, ENT, SPC
			LGUIT,			LUP
 */

		[_QWERTY] = LAYOUT(
	//,----+----+----+----+----+----.								,----+----+----+----+----+----.
		KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5,   					KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
	//,----+----+----+----+----+----.								,----+----+----+----+----+----.
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,    					KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
	//|----+----+----+----+----+----|   							|----+----+----+----+----+----|
		KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G,						KC_H, KC_J, KC_K, KC_L, KC_SCLN ,KC_QUOT,
	//|----+----+----+----+----+----|								|----+----+----+----+----+----|
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,						KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_GRV,
	//|----+----+----+----+----+----|								|----+----+----+----+----+----|
		KC_ESC, KC_LALT, KC_LGUI, KC_LEFT, KC_RIGHT, KC_BSPC,		KC_SPC, KC_UP, KC_DOWN, KC_LBRC , KC_RBRC, KC_ESC,
	//`----+----+----+----+----+----'   							`----+----+----+----+----+----'
	//							`----+----+----+'			`----+----+----'
								KC_PGUP,KC_PGDN,			 KC_HOME, KC_END,
	//							`----+----+----+'			`----+----+----'
										KC_HOME,			 KC_DEL,
	//							`----+----+----+'			`----+----+----'
								KC_SPC,KC_BSPC,MO(_ADJ),	 MO(_ADJ), KC_ENT, KC_BSPC
	//							`----+----+----+'			`----+----+----'

	),
	
	
	[_ADJ] = LAYOUT(
	//,----+----+----+----+----+----.								,----+----+----+----+----+----.
		KC_EQL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,   				KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
	//,----+----+----+----+----+----.								,----+----+----+----+----+----.
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,    					KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
	//|----+----+----+----+----+----|   							|----+----+----+----+----+----|
		KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G,						KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
	//|----+----+----+----+----+----|								|----+----+----+----+----+----|
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,						KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_GRV,
	//|----+----+----+----+----+----|								|----+----+----+----+----+----|
		KC_ESC, KC_LALT, KC_LGUI, KC_LEFT, KC_RIGHT, KC_BSPC,		KC_SPC, KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, KC_ESC,
	//`----+----+----+----+----+----'   							----+----+----+----+----+----'
	//							`----+----+----+'			`----+----+----'
								KC_PGUP, KC_PGDN,			KC_INS, KC_PSCR,
	//							`----+----+----+'			`----+----+----'
										 KC_ENT,			KC_SPC,
	//							`----+----+----+'			`----+----+----'
								KC_SPC, KC_BSPC, KC_TRNS,	KC_TRNS, KC_ENT, KC_BSPC
	//							`----+----+----+'			`----+----+----'

	),

};

void persistent_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
	
	
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case QWERTY:
		if (record->event.pressed) {
			#ifdef AUDIO_ENABLE
			PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
			#endif
			persistent_default_layer_set(1UL<<_QWERTY);
		}
		return false;
		break;
	}
	return true;
}
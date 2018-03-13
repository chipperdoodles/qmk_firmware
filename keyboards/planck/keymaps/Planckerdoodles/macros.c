#include "macros.h"
#include "quantum.h"
#include "action.h"
#include "version.h"


__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_CONFETTI:
    if (!record->event.pressed) {
      SEND_STRING("✧･ﾟ:*✧･ﾟ:*(◕ω◕✿)/ *:･ﾟ✧*:･ﾟ✧");
    }
    return false;
    break;
  }
  case KC_KIRBY_DANCE:
     if (!record->event.pressed) {
      SEND_STRING("<('-'<) (^'-'^) (>'-')>")
  }
  return false;
  break;
  return process_record_keymap(keycode, record);
}
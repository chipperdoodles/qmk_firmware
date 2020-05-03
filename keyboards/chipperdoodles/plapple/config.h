
#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0003
#define MANUFACTURER    chipperdoodles
#define PRODUCT         PlappleTeensyPP
#define DESCRIPTION     QMK keyboard firmware for plapplepp
/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 18


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

// ROWS: Top to bottom, COLS: Left to right
/* Row pin configuration
*/
#define MATRIX_ROW_PINS { C2, C3, A3, A6, A7 }
/* Column pin configuration
 */
#define MATRIX_COL_PINS { B6, C0, E7, C1, E1, E0, F4, F5, F6, F7, C7, C6, C5, C4, D7, D5, D4, B7 }


/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

#define AdafruitBleResetPin B5
#define AdafruitBleCSPin B0
#define AdafruitBleIRQPin B4

#endif

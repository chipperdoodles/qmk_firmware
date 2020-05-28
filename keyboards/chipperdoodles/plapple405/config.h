
#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0003
#define MANUFACTURER    chipperdoodles
#define PRODUCT         Plapple405
#define DESCRIPTION     QMK keyboard firmware for plapple405

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 18


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

// ROWS: Top to bottom, COLS: Left to right
/* Row pin configuration
*/
#define MATRIX_ROW_PINS { C10, C11, C12, C7, C6 }
/* Column pin configuration
 */
#define MATRIX_COL_PINS { C0, C1, C2, C3, A0, A1, A2, A3, A6, A7, C4, C5, B0, B1, B9, C13, C14, C15 }


/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

#endif

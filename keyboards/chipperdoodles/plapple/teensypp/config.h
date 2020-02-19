
#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0003
#define MANUFACTURER    noties
#define PRODUCT         plapplepp
#define DESCRIPTION     QMK keyboard firmware for plapplepp



// ROWS: Top to bottom, COLS: Left to right
/* Row pin configuration
*/
#define MATRIX_ROW_PINS { D1, D2, D3, D4, D5 }
/* Column pin configuration
 */
#define MATRIX_COL_PINS { B6, B5, B5, B3, B2, B1, C7, C6, C5, C4, C3, C2, B7, D0, F0, F1, F2, F3}


#endif

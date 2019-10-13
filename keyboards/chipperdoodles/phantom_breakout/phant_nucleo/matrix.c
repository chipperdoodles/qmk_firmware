#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "hal.h"
#include "timer.h"
#include "wait.h"
#include "printf.h"
#include "backlight.h"
#include "matrix.h"

/*
 *     col: { B4, D2, C12, C11, C10, A15, A10, A9, A8, C9, C8, C7, C6, B15, B14, B13, B2, B1, B0, C4 }
 *     row: { B12, C5, A7, A6, A5, A4 }
 */

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_COLS];
static bool debouncing = false;
static uint16_t debouncing_time = 0;

// static bool dip_switch[4] = {0, 0, 0, 0};

__attribute__ ((weak))
void matrix_init_user(void) {}

__attribute__ ((weak))
void matrix_scan_user(void) {}

__attribute__ ((weak))
void matrix_init_kb(void) {
  matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
  matrix_scan_user();
}

void matrix_init(void) {
    printf("matrix init\n");
    //debug_matrix = true;

    // actual matrix setup
    //COL
    palSetPadMode(GPIOB, 4, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOD, 2, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOC, 12, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOC, 11, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOC, 10, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA, 15, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA, 10, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA, 9, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA, 8, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOC, 9, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOC, 8, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOC, 6, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB, 15, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB, 14, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB, 13, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB, 2, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB, 1, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB, 0, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOC, 4, PAL_MODE_OUTPUT_PUSHPULL);
    
    //ROW
    palSetPadMode(GPIOB, 12,PAL_MODE_INPUT_PULLDOWN);
    palSetPadMode(GPIOC, 5, PAL_MODE_INPUT_PULLDOWN);
    palSetPadMode(GPIOA, 7, PAL_MODE_INPUT_PULLDOWN);
    palSetPadMode(GPIOA, 6, PAL_MODE_INPUT_PULLDOWN);
    palSetPadMode(GPIOA, 5, PAL_MODE_INPUT_PULLDOWN);
    palSetPadMode(GPIOA, 4, PAL_MODE_INPUT_PULLDOWN);


    memset(matrix, 0, MATRIX_ROWS * sizeof(matrix_row_t));
    memset(matrix_debouncing, 0, MATRIX_COLS * sizeof(matrix_row_t));


    matrix_init_quantum();
}

__attribute__ ((weak))

uint8_t matrix_scan(void) {

    // actual matrix
    for (int col = 0; col < MATRIX_COLS; col++) {
        matrix_row_t data = 0;

        // strobe col {  }
        switch (col) {
            case 0: palSetPad(GPIOB, 4); break;
            case 1: palSetPad(GPIOD, 2); break;
            case 2: palSetPad(GPIOC, 12); break;
            case 3: palSetPad(GPIOC, 11); break;
            case 4: palSetPad(GPIOC, 10); break;
            case 5: palSetPad(GPIOA, 15); break;
            case 6: palSetPad(GPIOA, 10); break;
            case 7: palSetPad(GPIOA, 9); break;
            case 8: palSetPad(GPIOA, 8); break;
            case 9: palSetPad(GPIOC, 8); break;
            case 10: palSetPad(GPIOC, 7); break;
            case 11: palSetPad(GPIOC, 6); break;
            case 12: palSetPad(GPIOB, 15); break;
            case 13: palSetPad(GPIOB, 14); break;
            case 14: palSetPad(GPIOB, 13); break;
            case 15: palSetPad(GPIOB, 2); break;
            case 16: palSetPad(GPIOB, 1); break;
            case 17: palSetPad(GPIOB, 0); break;
            case 18: palSetPad(GPIOC, 4); break;
        }

        // need wait to settle pin state
        wait_us(20);

        // read row data { A10, A9, A8, B15, C13, C14, C15, A2 }
        data = (
            (palReadPad(GPIOB, 12) << 0 ) |
            (palReadPad(GPIOC, 5)  << 1 ) |
            (palReadPad(GPIOA, 7)  << 2 ) |
            (palReadPad(GPIOA, 6) << 3 ) |
            (palReadPad(GPIOA, 5) << 4 ) |
            (palReadPad(GPIOA, 4) << 5 )

        );

        // unstrobe  col { B11, B10, B2, B1, A7, B0 }
        switch (col) {
            case 0: palClearPad(GPIOB, 4); break;
            case 1: palClearPad(GPIOD, 2); break;
            case 2: palClearPad(GPIOC, 12); break;
            case 3: palClearPad(GPIOC, 11); break;
            case 4: palClearPad(GPIOC, 10); break;
            case 5: palClearPad(GPIOA, 15); break;
            case 6: palClearPad(GPIOA, 10); break;
            case 7: palClearPad(GPIOA, 9); break;
            case 8: palClearPad(GPIOA, 8); break;
            case 9: palClearPad(GPIOC, 8); break;
            case 10: palClearPad(GPIOC, 7); break;
            case 11: palClearPad(GPIOC, 6); break;
            case 12: palClearPad(GPIOB, 15); break;
            case 13: palClearPad(GPIOB, 14); break;
            case 14: palClearPad(GPIOB, 13); break;
            case 15: palClearPad(GPIOB, 2); break;
            case 16: palClearPad(GPIOB, 1); break;
            case 17: palClearPad(GPIOB, 0); break;
            case 18: palClearPad(GPIOC, 4); break;
        }

        if (matrix_debouncing[col] != data) {
            matrix_debouncing[col] = data;
            debouncing = true;
            debouncing_time = timer_read();
        }
    }

    if (debouncing && timer_elapsed(debouncing_time) > DEBOUNCE) {
        for (int row = 0; row < MATRIX_ROWS; row++) {
            matrix[row] = 0;
            for (int col = 0; col < MATRIX_COLS; col++) {
                matrix[row] |= ((matrix_debouncing[col] & (1 << row) ? 1 : 0) << col);
            }
        }
        debouncing = false;
    }

    matrix_scan_quantum();

    return 1;
}

bool matrix_is_on(uint8_t row, uint8_t col) {
    return (matrix[row] & (1<<col));
}

matrix_row_t matrix_get_row(uint8_t row) {
    return matrix[row];
}

void matrix_print(void) {
    printf("\nr/c 01234567\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        printf("%X0: ", row);
        matrix_row_t data = matrix_get_row(row);
        for (int col = 0; col < MATRIX_COLS; col++) {
            if (data & (1<<col))
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
}

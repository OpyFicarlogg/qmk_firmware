
#include QMK_KEYBOARD_H

#define ___ KC_TRNS


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
     * ┌───┬───┬───┬
     * │ 7 │ 8 │ 9 │
     * ├───┼───┼───┼
     * https://docs.qmk.fm/#/keycodes
     */
    [0] = LAYOUT_ortho_2x3(
        KC_A,   KC_B,   KC_C,
        KC_D,   KC_E,   KC_F
    ),
    [1] = LAYOUT_ortho_2x3(
        ___,   ___,   ___,
        ___,   ___,   ___
    ),
    [2] = LAYOUT_ortho_2x3(
        ___,   ___,   ___,
        ___,   ___,   ___
    ),
    [3] = LAYOUT_ortho_2x3(
        ___,   ___,   ___,
        ___,   ___,   ___
    )
};

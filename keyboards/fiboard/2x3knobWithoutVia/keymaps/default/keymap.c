
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
        KC_A, KC_B,  
        KC_C, KC_D, KC_E
    ),
    [1] = LAYOUT_ortho_2x3(
        ___, ___,
        ___, ___, ___
    ),
    [2] = LAYOUT_ortho_2x3(
        ___, ___,
        ___, ___, ___
    ),
    [3] = LAYOUT_ortho_2x3(
        ___, ___,
        ___, ___, ___
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] =   { ENCODER_CCW_CW(___, ___) },
    [2] =   { ENCODER_CCW_CW(___, ___) },
    [3] =   { ENCODER_CCW_CW(___, ___) }
};
#endif // ENCODER_MAP_ENABLE
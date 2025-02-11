#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

        /* Keymap _BL: (Base Layer) Default Layer
    * .-------------------.
    * |Prts| del| end| ins|
    * .-------------------.
    * |NL F|   /|   *|   -|
    * |-------------------|
    * |   7|   8|   9|    |
    * |--------------|    |
    * |   4|   5|   6|   +|
    * |-------------------|
    * |   1|   2|   3|    |
    * |--------------|    |
    * |        0|   .| Ent|
    * '-------------------'  
    * https://docs.qmk.fm/#/keycodes
    */
    [0] = LAYOUT_6x4(
        KC_PSCR,    LT(1, KC_DEL),     KC_END,     KC_INS, 
        KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,
        KC_P7,      KC_P8,      KC_P9,      KC_PPLS,
        KC_P4,      KC_P5,      KC_P6, 
        KC_P1,      KC_P2,      KC_P3,
                    KC_P0,      KC_PDOT,    KC_PENT
    ),

    
    /* Keymap _FL: Function Layer
    * .-------------------.
    * |____|____|____|____|
    * .-------------------.
    * |____|____|____|____|
    * |-------------------|
    * |____|____|____|____|
    * |--------------|    |
    * |____|____|____|____|
    * |-------------------|
    * |____|____|____|    |
    * |--------------|    |
    * |     ____|____|____|
    * '-------------------'
    */

    [1] = LAYOUT_6x4(
        QK_REBOOT,  KC_DEL,     QK_BOOT,     EE_CLR, 
        KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,
        KC_P7,      KC_P8,      KC_P9,      KC_PPLS,
        KC_P4,      KC_P5,      KC_P6, 
        KC_P1,      KC_P2,      KC_P3,
                    KC_P0,      KC_PDOT,    KC_PENT
    ),

    [2] = LAYOUT_6x4(
        KC_PSCR,    KC_DEL,     KC_END,     KC_INS, 
        KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,
        KC_P7,      KC_P8,      KC_P9,      KC_PPLS,
        KC_P4,      KC_P5,      KC_P6, 
        KC_P1,      KC_P2,      KC_P3,
                    KC_P0,      KC_PDOT,    KC_PENT
    ),

    [3] = LAYOUT_6x4(
        KC_PSCR,    KC_DEL,     KC_END,     KC_INS, 
        KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,
        KC_P7,      KC_P8,      KC_P9,      KC_PPLS,
        KC_P4,      KC_P5,      KC_P6, 
        KC_P1,      KC_P2,      KC_P3,
                    KC_P0,      KC_PDOT,    KC_PENT
    )
};
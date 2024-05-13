
#include QMK_KEYBOARD_H


enum {
    TD_BACK,
    TD_RESET
};

enum {
    _BL,
    _FL,
    _L1,
    _L2
};


void td_reset_key(qk_tap_dance_state_t *state, void *user_data){
    if (state->count == 1) {
        tap_code(KC_PSCR);
    }
}

void td_back_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 2:
            SEND_STRING("Layer");
            layer_move(_BL);
            break;
        default :
           if (state->count >= 5) {
                SEND_STRING("RESET");
                reset_keyboard();
            }
            break;
    }
}

void td_reset_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 2:
            SEND_STRING("Layer");
            layer_move(_FL);
            break;
        default :
           if (state->count >= 5) {
                SEND_STRING("RESET");
                reset_keyboard();
            }
            break;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RESET] = ACTION_TAP_DANCE_FN_ADVANCED(td_reset_key, td_reset_finished,NULL),
    [TD_BACK] = ACTION_TAP_DANCE_FN_ADVANCED(td_reset_key, td_back_finished,NULL)
};

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

    [_BL] = LAYOUT_npad_6x4(
        TD(TD_RESET),     KC_DEL,  KC_END,  KC_INS, 
        LT(_FL, KC_NUM),  KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,            KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,            KC_P5,   KC_P6, 
        KC_P1,            KC_P2,   KC_P3,
        KC_P0,                     KC_PDOT, KC_PENT
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
    [_FL] = LAYOUT_npad_6x4(
        TD(TD_BACK),    _______, _______, _______, 
        _______,        _______, _______, _______,
        _______,        _______, _______,
        _______,        _______, _______, _______,
        _______,        _______, _______,
        _______,                 _______, _______
    ),

    [_L1] = LAYOUT_npad_6x4(
        TD(TD_BACK),    _______, _______, _______, 
        _______,        _______, _______, _______,
        _______,        _______, _______,
        _______,        _______, _______, _______,
        _______,        _______, _______,
        _______,                 _______, _______
    ),

    [_L2] = LAYOUT_npad_6x4(
        TD(TD_BACK),    _______, _______, _______, 
        _______,        _______, _______, _______,
        _______,        _______, _______,
        _______,        _______, _______, _______,
        _______,        _______, _______,
        _______,                 _______, _______
    )
};
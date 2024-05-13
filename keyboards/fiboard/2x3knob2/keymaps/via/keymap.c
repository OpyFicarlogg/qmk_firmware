
#include QMK_KEYBOARD_H

#define ___ KC_TRNS

enum layers {
    _MAIN = 0,
    _SECOND,
    _THIRD,
    _FOURS
};

enum {
    TD_A_Q,
    CT_FLSH,
    CT_EGG,
    TD_RESET
};

enum custom_keycodes {
    LAYER_INCREMENT
};

int LAYER_LEVEL = 0; 


//https://github.com/qmk/qmk_firmware/blob/master/docs/feature_layers.md
//https://www.reddit.com/r/olkb/comments/mkry1v/understanding_how_to_switch_between_layers_in_qmk/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LAYER_INCREMENT:
        if (record->event.pressed) {
            ++LAYER_LEVEL;
            if (LAYER_LEVEL > 3) {
                LAYER_LEVEL = 0;
            }
            layer_move(LAYER_LEVEL);
        }
        break;
    }
    return true;
};

void td_reset_key(qk_tap_dance_state_t *state, void *user_data){
    if (state->count == 1) {
        tap_code(KC_MPLY);
    }
}

//touche avec controle https://stackoverflow.com/questions/69307910/struggling-with-qmk-modifier-keys

void td_reset_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 2:
            tap_code(KC_MUTE);
            break;
        case 3:
            //https://github.com/qmk/qmk_firmware/blob/master/docs/feature_layers.md#switching-and-toggling-layers-idswitching-and-toggling-layers
            //https://www.reddit.com/r/olkb/comments/8wks46/qmk_question_layer_toggling_with_tap_momentary/
            SEND_STRING("Layer");
            layer_move(1);
            //layer_off(0);
            break;
        case 4:
            tap_code(KC_MPLY);
            break;
        default :
           if (state->count >= 5) {
                SEND_STRING("RESET");
                reset_keyboard();
            }
            break;
    }
}


void dance_egg(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 5) {
        SEND_STRING("Safety dance!");
        reset_tap_dance(state);
    }
    else{
        tap_code(KC_B);
    }
}

/*
//https://docs.qmk.fm/#/feature_tap_dance
void dance_flsh_each(qk_tap_dance_state_t *state, void *user_data){
    if (state->count == 1) {
        tap_code(KC_E);
    }
}
void dance_flsh_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 4) {
        reset_keyboard();
    }
}

void dance_flsh_reset(qk_tap_dance_state_t *state, void *user_data) {
}

void dance_egg(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 100) {
        SEND_STRING("Safety dance!");
        reset_tap_dance(state);
    }
}

*/
qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_EGG] = ACTION_TAP_DANCE_FN(dance_egg),
    [TD_A_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_A),
    [TD_RESET] = ACTION_TAP_DANCE_FN_ADVANCED(td_reset_key, td_reset_finished,NULL)
    //[CT_FLSH] = ACTION_TAP_DANCE_FN_ADVANCED(dance_flsh_each, dance_flsh_finished, dance_flsh_reset)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
     * ┌───┬───┬───┬
     * │ 7 │ 8 │ 9 │
     * ├───┼───┼───┼
     * https://docs.qmk.fm/#/keycodes
     */
    [0] = LAYOUT_ortho_2x3(
        KC_Q,   KC_B,   TD(TD_RESET),
        KC_D,  KC_E
    ),
    [1] = LAYOUT_ortho_2x3(
        TD(TD_A_Q),  TD(CT_EGG),  LAYER_INCREMENT,
        ___,    ___
    ),
    [2] = LAYOUT_ortho_2x3(
        KC_W,   ___,  LAYER_INCREMENT,
        ___,    ___  
    ),
    [3] = LAYOUT_ortho_2x3(
        KC_X,   ___,   LAYER_INCREMENT,
        ___,    ___
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW( KC_VOLD, KC_VOLU) },
    [1] =   { ENCODER_CCW_CW(___, ___) },
    [2] =   { ENCODER_CCW_CW(___, ___) },
    [3] =   { ENCODER_CCW_CW(___, ___) }
};
#endif // ENCODER_MAP_ENABLE
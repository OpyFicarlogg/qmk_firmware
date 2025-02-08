#include QMK_KEYBOARD_H


/*
//https://github.com/qmk/qmk_firmware/issues/6014
// https://github.com/qmk/qmk_firmware/blob/master/docs/gpio_control.md
void matrix_init_user(void) { setPinInputHigh(F6); }

static bool encoder_pressed;

void matrix_scan_user(void) {
  if (readPin(F6)) {
    encoder_pressed = false;
  } else {
    if (!encoder_pressed) {
      tap_code(KC_MUTE);
    }
    encoder_pressed = true;
  }
}

*/

// https://github.com/qmk/qmk_firmware/issues/6014
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_dip_switch.md
// https://github.com/qmk/qmk_firmware/blob/88555d8e18e90c2571c5d6553aae46c697c3341b/keyboards/handwired/6key/rules.mk
/*bool dip_switch_update_user(uint8_t index, bool active) { 
    switch (index) {
        case 0:		//ENC0_SW
            if(active) //ENC0 pressed
            { 
                
            } 
            else //ENC0 released
            {
                tap_code(KC_MUTE);
            }
            break;
    }

    return true;
}*/


/*
// Sans utiliser ENCODER_MAP_ENABLE
// https://golem.hu/guide/rotary-encoder-programming/
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code_delay(KC_VOLU, 10);
    } else {
        tap_code_delay(KC_VOLD, 10);
    }

    // tap_code(clockwise ? KC_VOLU : KC_VOLD);
    return false;
}
// exemple avec encoder_map https://github.com/qmk/qmk_firmware/blob/ced8142847e7c6a1e0e260017131e34e3da1b0ff/keyboards/pica40/keymaps/zzeneg/keymap.c
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md

*/

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) }
};
#endif // ENCODER_MAP_ENABLE
    
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
    )
};

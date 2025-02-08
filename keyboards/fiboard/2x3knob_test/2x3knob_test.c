#include "2x3knob.h"

//exemple : https://github.com/qmk/qmk_firmware/tree/88555d8e18e90c2571c5d6553aae46c697c3341b/keyboards/handwired/6key
// https://github.com/qmk/qmk_firmware/issues/6014
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_dip_switch.md
bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) { return false; }
    
    switch (index) {
        case 0:		//ENC0_SW
            if(!active) 
            { 
                tap_code(KC_MPLY);
            } 
    }

    return true;
}

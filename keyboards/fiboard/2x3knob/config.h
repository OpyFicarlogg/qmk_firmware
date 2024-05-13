// Copyright 2022 Samuel FUCHS (@OpYFicarloGG)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xF1CA 
#define PRODUCT_ID 0xF1B1
//#define DEVICE_VER 0x0001
//#define MANUFACTURER "Ficarlo"
//#define PRODUCT "fiboard"

//#define ENCODERS_PAD_A {A3}
//#define ENCODERS_PAD_B {A2}
//#define ENCODER_RESOLUTIONS {4}
#define DIP_SWITCH_PINS { F6 }

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

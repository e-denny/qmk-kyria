/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    ifndef RGBLIGHT_LIMIT_VAL
#       define RGBLIGHT_LIMIT_VAL 150
#    endif
#endif

#define LED_CAPS_LOCK_PIN 24
#define LED_PIN_ON_STATE 0

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_DEFAULT_HUE 231
    #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
    #define RGB_MATRIX_TYPING_MEATMAP_DECREASE_DELAY_MS 50
    #define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #ifdef RGB_MATRIX_MAXIMUM_BRIGHTNESS
        #undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #endif
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100 // limits maximum brightness of LEDs
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 8
    #define RGB_MATRIX_SPD_STEP 10
#endif

#define TAPPING_TERM 250
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#define SPLIT_LAYER_STATE_ENABLE

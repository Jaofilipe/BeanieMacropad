// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _ZERO,
    _ONE,
    _TWO,
    _THREE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ 9 │ A │ B │       
     * ├───┼───┼───┤
     * │ 6 │ 7 │ 8 │
     * ├───┼───┼───┤
     * │ 3 │ 4 │ 5 │
     * ├───┼───┼───┤
     * │ 0 │ 1 │ 2 │
     * └───┴───┴───┘
     */
    [_ZERO] = LAYOUT(
        KC_LEFT_CTRL,   KC_C,           KC_V,
        KC_LEFT_ALT,    KC_MPLY,        KC_MUTE ,  
        KC_LEFT_SHIFT,  KC_VOLD,        KC_VOLU,
        KC_NO,          KC_NO,          QK_USER
    )
};

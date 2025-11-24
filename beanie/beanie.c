/* Copyright 2023 Jaofilipe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

 // check bitmap generation https://joric.github.io/qle/

#include "quantum.h"
#include "matrix.h"
#include "bootloader.h"
#include "wait.h"
#include "eeconfig.h"

#ifndef BOOTMAGIC_COLUMN
#    define BOOTMAGIC_COLUMN 0
#endif
#ifndef BOOTMAGIC_ROW
#    define BOOTMAGIC_ROW 0
#endif

#define BOOTMAGIC_AUX_COLUMN 0
#define BOOTMAGIC_AUX_ROW    0
#define BOOTMAGIC_DEBOUNCE 30

// 1st layer on the cycle
#define LAYER_CYCLE_START 0
// Last layer on the cycle
#define LAYER_CYCLE_END   3
enum layers {
    _ZERO,
    _ONE,
    _TWO,
    _THREE
};

/*
 * Override bootmagic scan
 */
void bootmagic_scan(void) {
    // We need multiple scans because debouncing can't be turned off.
    matrix_scan();
    wait_ms(BOOTMAGIC_DEBOUNCE);
    matrix_scan();

    if (matrix_get_row(BOOTMAGIC_ROW) & (1 << BOOTMAGIC_COLUMN) ) {
        if (matrix_get_row(BOOTMAGIC_AUX_ROW) & (1 << BOOTMAGIC_AUX_COLUMN)) {
            //reset eeprom on double button press
            eeconfig_disable();   //bootmagic_reset_eeprom();
        }
        // Jump to bootloader.
        bootloader_jump();
    }
}

#ifdef OLED_ENABLE

static const uint8_t digits[4][8] PROGMEM = {
    // 0
    {
        0b00111100,
        0b01100110,
        0b01101110,
        0b01110110,
        0b01100110,
        0b01100110,
        0b00111100,
        0b00000000,
    },
    // 1
    {
        0b00011000,
        0b00111000,
        0b00011000,
        0b00011000,
        0b00011000,
        0b00011000,
        0b00111100,
        0b00000000,
    },
    // 2
    {
        0b00111100,
        0b01100110,
        0b00000110,
        0b00001100,
        0b00110000,
        0b01100000,
        0b01111110,
        0b00000000,
    },
    // 3
    {
        0b00111100,
        0b01100110,
        0b00000110,
        0b00011100,
        0b00000110,
        0b01100110,
        0b00111100,
        0b00000000,
    },
};


#define DIGIT_SIZE 8

void render_big_digit(layer_state_t state) {

    uint8_t n = 0;

    oled_clear();

    switch (state) {
        case _ZERO:
            n = 0;
            break;
        case _ONE:
            n = 1;
            break;
        case _TWO:
            n = 2;
            break;
        case _THREE:
            n = 3;
            break;
        default:
            n = 0;
    }

    char buf[DIGIT_SIZE + 1];
    buf[DIGIT_SIZE] = '\0';

    for (uint8_t row = 0; row < DIGIT_SIZE; row++) {
        uint16_t mask = pgm_read_word(&digits[n][row]);
        for (uint8_t col = 0; col < DIGIT_SIZE; col++) {
            buf[col] = (mask & (1 << (DIGIT_SIZE - 1 - col))) ? '\b' : ' ';
        }
            oled_set_cursor(6, row);
            oled_write_ln(buf, false);

    }
    oled_render_dirty(true);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // This runs every time the layer state changes
    // Example: light up an LED depending on layer
    render_big_digit(get_highest_layer(state));
    return state; // Always return the state
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_clear();
    oled_write_P(qmk_logo, false);
    oled_render_dirty(true);

}

void keyboard_post_init_user(void) {
    render_logo();
    wait_ms(1600);
    render_big_digit(_ZERO); //layers always begin with zero
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
    bool mod_pressed_status  = false;

    if((record->event.key.row == 3) && (record->event.key.col == 2)){

        mod_pressed_status = record->event.pressed;
        if (mod_pressed_status){
            uint8_t current_layer = get_highest_layer(layer_state);

            layer_move(((current_layer >= LAYER_CYCLE_END) ? LAYER_CYCLE_START : current_layer + 1));
        }
        return false;
    }

    return true;
}


/* Copyright (C) 2023 jonylee@hfd
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

#include QMK_KEYBOARD_H

enum latex_keycodes {
  LATEX_VARPHI = SAFE_RANGE,
  LATEX_ALPHA,
  LATEX_LAMBDA
};

enum game_keycodes {
GAME_GG_EZ = SAFE_RANGE
};

enum __layers {
    MAIN_LAYER,
    LATEX_LAYER
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [MAIN_LAYER] = LAYOUT_all( /* Base */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,          KC_F11,  KC_F12,   KC_DEL,           KC_MEDIA_PLAY_PAUSE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,            KC_MINS, KC_EQL,   KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,            KC_LBRC, KC_RBRC,  KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,         KC_QUOT, KC_NUHS,  KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,          KC_SLSH,           KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(LATEX_LAYER), KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT),

    [LATEX_LAYER] = LAYOUT_all( /* Base */
        _______, _______,     _______, _______, _______, _______,    _______, _______,             _______,             _______,              _______,              _______, _______, _______,          _______,
        _______, _______,     _______, _______, _______, _______,    _______, _______,             _______,             _______,              _______,              _______, _______, _______,          _______,
        _______, _______,     _______, _______, _______, _______,    _______, _______,             _______,             _______,              LATEX_VARPHI,         _______, _______, _______,          _______,
        _______, LATEX_ALPHA, _______, _______, _______, GAME_GG_EZ, _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, LATEX_LAMBDA,         _______,              _______, _______, _______,          _______,
        _______, _______,     _______, _______, _______, _______,    _______, _______,             _______,             _______,              _______,              _______,          _______, _______, _______,
        _______, _______,     _______,                   _______,                                                       _______,              MO(LATEX_LAYER),      _______,          _______, _______, _______)
};

bool process_latex(keyrecord_t* record, const char* text, const char* shifted_text) {
    if(record->event.pressed) {
        if(get_mods() & MOD_BIT(MOD_MASK_SHIFT)) {
            SEND_STRING(shifted_text);
        } else {
            SEND_STRING(text);
        }
    }

    return false;
}

// Process Latex keycodes
bool process_latex_keycodes(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LATEX_ALPHA:
            return process_latex(record, "\\alpha", "\\Alpha");
        case LATEX_VARPHI:
            return process_latex(record, "\\varphi", "\\phi");
        case LATEX_LAMBDA:
           return process_latex(record, "\\lambda", "\\Lambda");
        default:
            return true;
    }

    return true;
}

bool process_game_keycodes(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case GAME_GG_EZ:
            if(record->event.pressed) {
                SEND_STRING("\ngg ez, mejoren\n");
            }
            return false;
    }

    return true;
}

//Process record
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_latex_keycodes(keycode, record)
        && process_game_keycodes(keycode, record);
}


// clang-format off
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAIN_LAYER] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [LATEX_LAYER] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) }
};
#endif

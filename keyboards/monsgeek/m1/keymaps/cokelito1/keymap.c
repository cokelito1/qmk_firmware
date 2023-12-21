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

#define N_TILDE 0x00F1
#define N_TILDE_SHIFTED 0x00D1

enum latex_keycodes {
  LATEX_VARPHI = SAFE_RANGE,
  LATEX_ALPHA,
  LATEX_LAMBDA,
  LATEX_SERIES
};

enum game_keycodes {
GAME_GG_EZ = SAFE_RANGE
};

enum __layers {
    MAIN_LAYER,
    LATEX_LAYER,
    CONFIG_LAYER
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [MAIN_LAYER] = LAYOUT_all( /* Base */
        KC_ESC,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,          KC_F11,  KC_F12,   KC_DEL,           KC_MEDIA_PLAY_PAUSE,
        KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,            KC_MINS, KC_EQL,   KC_BSPC,          KC_HOME,
        KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,            KC_LBRC, KC_RBRC,  KC_BSLS,          KC_PGUP,
        MO(LATEX_LAYER), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,         KC_QUOT, KC_NUHS,  KC_ENT,           KC_PGDN,
        KC_LSFT,         KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,          KC_SLSH,           KC_RSFT, KC_UP,   TG(CONFIG_LAYER),
        KC_LCTL,         KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(LATEX_LAYER), KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT),

    [LATEX_LAYER] = LAYOUT_all( /* Base */
        _______,         _______,     _______,      _______, _______, _______,    _______,                      _______,             _______,             _______,              _______,              _______, _______, _______,          _______,
        _______,         _______,     _______,      _______, _______, _______,    _______,                      _______,             _______,             _______,              _______,              _______, _______, _______,          _______,
        _______,         _______,     _______,      _______, _______, _______,    _______,                      _______,             _______,             _______,              LATEX_VARPHI,         _______, _______, _______,          _______,
        MO(LATEX_LAYER), LATEX_ALPHA, LATEX_SERIES, _______, _______, GAME_GG_EZ, _______,                      KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, LATEX_LAMBDA,         _______,              _______, _______, _______,          _______,
        _______,         _______,     _______,      _______, KC_CAPS, _______,    UP(N_TILDE, N_TILDE_SHIFTED), _______,             _______,             _______,              _______,              _______,          _______, _______, _______,
        _______,         _______,     _______,                        _______,                                                                            _______,              MO(LATEX_LAYER),      _______,          _______, _______, _______),


    [CONFIG_LAYER] = LAYOUT_all( /* Base */
        RGB_TOG,         _______,     _______,      _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,          _______,
        _______,         _______,     _______,      _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,          _______,
        _______,         _______,     RGB_MOD,      _______, _______, AS_TOGG,    _______,    _______,    RGB_SAI,    _______,    _______,    _______, _______, _______,          _______,
        _______,         RGB_HUD,     RGB_RMOD,     RGB_HUI, _______, _______,    _______,    RGB_VAD,    RGB_SAD,    RGB_VAI,    _______,    _______, _______, _______,          _______,
        _______,         _______,     _______,      _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,          _______, _______, TG(CONFIG_LAYER),
        _______,         _______,     _______,                        _______,                                        _______,    _______,    _______,          _______, _______, _______)
};

bool process_macro(keyrecord_t* record, const char* text, const char* shifted_text) {
    const uint8_t mods = get_mods();

    if(record->event.pressed) {
        if(mods & MOD_BIT(MOD_MASK_SHIFT)) {
            unregister_mods(MOD_MASK_SHIFT);
            SEND_STRING(shifted_text);
            register_mods(MOD_MASK_SHIFT);
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
            return process_macro(record, "\\alpha", "\\Alpha");
        case LATEX_VARPHI:
            return process_macro(record, "\\varphi", "\\phi");
        case LATEX_LAMBDA:
            return process_macro(record, "\\lambda", "\\Lambda");
        case LATEX_SERIES:
            return process_macro(record, "\\sigma", "\\sum_{n = 1}^{\\infty}");
        default:
            return true;
    }

    return true;
}

bool process_game_keycodes(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case GAME_GG_EZ:
            return process_macro(record, "\ngg wp\n", "\nGG WP\n");
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
    [MAIN_LAYER] = { ENCODER_CCW_CW(KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK) },
    [LATEX_LAYER] = { ENCODER_CCW_CW(KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK) },
    [CONFIG_LAYER] = { ENCODER_CCW_CW(KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK) }
};
#endif

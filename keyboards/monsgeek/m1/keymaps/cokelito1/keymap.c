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

//Screenshot macro
#define KC_SS LSG(KC_S)

//Virtual Desktop macros
#define KC_DO C(G(KC_D))
#define KC_DC C(G(KC_F4))
#define KC_DN C(G(KC_RIGHT))
#define KC_DP C(G(KC_LEFT))

//Window managment macro
#define KC_WU A(G(KC_UP))
#define KC_WD A(G(KC_DOWN))
#define KC_WL G(KC_LEFT)
#define KC_WR G(KC_RIGHT)
#define KC_WM G(KC_UP)

//N tilde macros
#define KC_NTIL UP(N_TILDE, SHIFTED_N_TILDE)
#define KC_AACC UP(A_ACCENT, SHIFTED_A_ACCENT)
#define KC_EACC UP(E_ACCENT, SHIFTED_E_ACCENT)
#define KC_IACC UP(I_ACCENT, SHIFTED_I_ACCENT)
#define KC_OACC UP(O_ACCENT, SHIFTED_O_ACCENT)
#define KC_UACC UP(U_ACCENT, SHIFTED_U_ACCENT)

#define EMAIL_1 "cokelitocokelito@gmail.com"
#define EMAIL_2 "dereference@nllptr.xyz"
#define EMAIL_3 "jorge.bravos@usm.cl"
#define EMAIL_4 "jorge.eduardo.bravo.soto@gmail.com"

#define NICKNAME_1 "cokelito1"
#define NICKNAME_2 "Cosarh"

enum latex_keycodes {
  LATEX_VARPHI = SAFE_RANGE,
  LATEX_ALPHA,
  LATEX_LAMBDA,
  LATEX_SERIES,
  WEB_SHR,
  KC_EMAIL,
  KC_NICK,
  KC_EMAIL2
};

enum __layers {
    MAIN_LAYER,
    LATEX_LAYER,
    CONFIG_LAYER
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

enum unicode_names {
  N_TILDE,
  SHIFTED_N_TILDE,
  A_ACCENT,
  SHIFTED_A_ACCENT,
  E_ACCENT,
  SHIFTED_E_ACCENT,
  I_ACCENT,
  SHIFTED_I_ACCENT,
  O_ACCENT,
  SHIFTED_O_ACCENT,
  U_ACCENT,
  SHIFTED_U_ACCENT
};

const uint32_t PROGMEM unicode_map[] = {
  [N_TILDE]          = 0x00F1, //ñ
  [SHIFTED_N_TILDE]  = 0x00D1, //Ñ
  [A_ACCENT]         = 0x00E1, //á
  [SHIFTED_A_ACCENT] = 0x00C1, //Á
  [E_ACCENT]         = 0x00E9, //é
  [SHIFTED_E_ACCENT] = 0x00C9, //É
  [I_ACCENT]         = 0x00ED, //í
  [SHIFTED_I_ACCENT] = 0x00CD, //Í
  [O_ACCENT]         = 0x00F3, //ó
  [SHIFTED_O_ACCENT] = 0x00D3, //Ó
  [U_ACCENT]         = 0x00FA, //ú
  [SHIFTED_U_ACCENT] = 0x00DA  //Ú
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [MAIN_LAYER] = LAYOUT_all( /* Base */
        KC_ESC,                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,          KC_F11,  KC_F12,   KC_DEL,           KC_MEDIA_PLAY_PAUSE,
        KC_GRV,                   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,            KC_MINS, KC_EQL,   KC_BSPC,          KC_F13,
        KC_TAB,                   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,            KC_LBRC, KC_RBRC,  KC_BSLS,          KC_F14,
        MO(LATEX_LAYER),          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,         KC_QUOT, KC_NUHS,  KC_ENT,           KC_F15,
        KC_LSFT,                  KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,          KC_SLSH,           KC_RSFT, KC_UP,   KC_F16,
        KC_LCTL,                  KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(LATEX_LAYER), KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT),

    [LATEX_LAYER] = LAYOUT_all( /* Base */
        _______,                  _______,     _______,      _______, _______, _______,    _______, _______,             _______,             _______,              _______,              _______, _______, _______,          _______,
        _______,                  KC_F1,       KC_F2,        KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,               KC_F8,               KC_F9,                KC_F10,               _______, _______, _______,          _______,
        _______,                  _______,     _______,      KC_EACC, _______, _______,    _______, KC_UACC,             KC_IACC,             KC_OACC,              LATEX_VARPHI,         _______, _______, _______,          _______,
        MO(LATEX_LAYER),          KC_AACC,     LATEX_SERIES, _______, _______, _______,    KC_LEFT, KC_DOWN,             KC_UP,               KC_RIGHT,             KC_BSPC,              _______, _______, _______,          _______,
        _______,                  _______,     _______,      _______, KC_CAPS, _______,    _______, KC_NTIL,             _______,             _______,              _______,              _______,          _______, _______, TG(CONFIG_LAYER),
        _______,                  _______,     _______,                        _______,                                                                             _______,              MO(LATEX_LAYER),      _______,          _______, _______, _______),


    [CONFIG_LAYER] = LAYOUT_all( /* Base */
        RGB_TOG,         _______,     _______,      _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,          _______,
        _______,         _______,     _______,      _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,          QK_MAKE,
        _______,         _______,     _______,      _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,          _______,
        _______,         _______,     _______,      _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______,          _______,
        _______,         _______,     _______,      _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,          _______, _______, TG(CONFIG_LAYER),
        _______,         _______,     _______,                        _______,                                        _______,    _______,    _______,          _______, _______, _______)
};

bool process_macro(keyrecord_t* record, const char* text, const char* shifted_text) {
    const uint8_t mods = get_mods();

    if(record->event.pressed) {
        if(mods & MOD_MASK_SHIFT) {
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
        case WEB_SHR:
          if(record->event.pressed) {
            SEND_STRING(SS_LCTL("ct") SS_DELAY(100) SS_LCTL("v") SS_TAP(X_ENTER));
          }
          return false;
        case KC_EMAIL:
          return process_macro(record, EMAIL_1, EMAIL_2);
        case KC_NICK:
          return process_macro(record, NICKNAME_1, NICKNAME_2);
        case KC_EMAIL2:
          return process_macro(record, EMAIL_3, EMAIL_4);
        default:
            return true;
    }
    return true;
}

//Process record
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_latex_keycodes(keycode, record);
}

void leader_start_user() {}

void leader_end_user() {
    // Discord Macros
    if(leader_sequence_three_keys(KC_D, KC_M, KC_M)) {
        tap_code16(KC_F14);
    } else if(leader_sequence_three_keys(KC_D, KC_M, KC_A)) {
        tap_code16(KC_F15);
    } else if(leader_sequence_two_keys(KC_D, KC_S)) {
        tap_code16(KC_F13);
    } else if(leader_sequence_two_keys(KC_D, KC_O)) {
        tap_code16(KC_DO);
    } else if(leader_sequence_two_keys(KC_D, KC_C)) {
        tap_code16(KC_DC);
    } else if(leader_sequence_two_keys(KC_D, KC_H)) {
        tap_code16(KC_DP);
    } else if(leader_sequence_two_keys(KC_D, KC_L)) {
        tap_code16(KC_DN);
    } else if(leader_sequence_one_key(KC_C)) {
        SEND_STRING(SS_LCTL("c"));
    } else if(leader_sequence_one_key(KC_V)) {
        SEND_STRING(SS_LCTL("v"));
    } else if(leader_sequence_one_key(KC_S)) {
        tap_code16(KC_SS);
    } else if(leader_sequence_two_keys(KC_W, KC_K)) {
        tap_code16(KC_WU);
    } else if(leader_sequence_two_keys(KC_W, KC_J)) {
        tap_code16(KC_WD);
    } else if(leader_sequence_two_keys(KC_W, KC_H)) {
        tap_code16(KC_WL);
    } else if(leader_sequence_two_keys(KC_W, KC_L)) {
        tap_code16(KC_WR);
    } else if(leader_sequence_two_keys(KC_W, KC_M)) {
        tap_code16(KC_WM);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t current_brigthness = rgblight_get_val();

    switch(get_highest_layer(state)) {
        case MAIN_LAYER:
            rgblight_sethsv_noeeprom(201, 200, current_brigthness);
            break;
        case LATEX_LAYER:
            rgblight_sethsv_noeeprom(148, 200, current_brigthness);
            break;
        case CONFIG_LAYER:
            rgblight_sethsv_noeeprom(43, 200, current_brigthness);
            break;
        default:
            rgblight_sethsv_noeeprom(201, 200, current_brigthness);
            break;
    }

    return state;
}

void keyboard_post_init_user() {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(201, 200, 255);

    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

// clang-format off
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAIN_LAYER] = { ENCODER_CCW_CW(KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK) },
    [LATEX_LAYER] = { ENCODER_CCW_CW(KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK) },
    [CONFIG_LAYER] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) }
};
#endif

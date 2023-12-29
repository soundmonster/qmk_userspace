// Copyright 2022 Soundmonster (@soundmonster)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/achordion.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
// Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers { _QWERTY, _LOWER, _RAISE, _ADJUST };

// Custom keycodes for layer keys
// Dual function escape with left command
#define KC_LGESC LGUI_T(KC_ESC)

enum custom_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE, ADJUST, RGBRST };

const uint16_t PROGMEM lprn_combo[]            = {KC_Z, LALT_T(KC_X), COMBO_END};
const uint16_t PROGMEM rprn_combo[]            = {LALT_T(KC_DOT), KC_SLSH, COMBO_END};
combo_t                key_combos[COMBO_COUNT] = {
    COMBO(lprn_combo, KC_LPRN),
    COMBO(rprn_combo, KC_RPRN),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,--------+------------+------------+------------+------------+------.  ,------+------------+------------+------------+---------------+--------.
     KC_NO,       KC_Q,       KC_W,        KC_E,        KC_R,     KC_T,      KC_Y,     KC_U,        KC_I,        KC_O,         KC_P,       KC_NO,
  //|--------+------------+------------+------------+------------+------|   |------+------------+------------+------------+---------------+--------|
     KC_NO, LGUI_T(KC_A),RALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F), KC_G,      KC_H, RSFT_T(KC_J),RCTL_T(KC_K),RALT_T(KC_L),RGUI_T(KC_SCLN),  KC_NO,
  //|--------+------------+------------+------------+------------+------|   |------+------------+------------+------------+---------------+--------|
     KC_NO,       KC_Z,   LALT_T(KC_X),    KC_C,        KC_V,     KC_B,      KC_N,     KC_M,      KC_COMM,  LALT_T(KC_DOT),    KC_SLSH,    KC_NO,
  //|--------+------------+------------+------------+------------+------|   |------+------------+------------+------------+---------------+--------|
                         LT(_RAISE, KC_ESC), LT(_LOWER, KC_QUOT), KC_SPC,     RSFT_T(KC_ENT), LT(_RAISE, KC_BSPC), LT(_LOWER, KC_TAB)
                                     //`------------------------------'       `-----------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,--------+------------+------------+------------+------------+------.   ,------+---------------+-------------+----------------+---------------+--------.
       KC_NO,     KC_1,        KC_2,        KC_3,        KC_4,     KC_5,      KC_6,     KC_7,            KC_8,          KC_9,           KC_0,       KC_NO,
  //|--------+------------+------------+------------+------------+------|   |------+---------------+-------------+----------------+---------------+--------|
       KC_NO,    KC_LGUI,     KC_RALT,     KC_LCTL,     KC_LSFT,  KC_NO,    KC_LEFT,RSFT_T(KC_DOWN),RCTL_T(KC_UP),RALT_T(KC_RIGHT),    KC_RGUI,     KC_NO,
  //|--------+------------+------------+------------+------------+------|   |------+---------------+-------------+----------------+---------------+--------|
       KC_NO,     KC_NO,      KC_LALT,      KC_NO,       KC_Y,    KC_NO,    KC_HOME,     KC_PGDN,      KC_PGUP,    LALT_T(KC_END),      KC_NO,      KC_NO,
  //|--------+------------+------------+------------+------------+------|   |------+---------------+-------------+----------------+---------------+--------|
                       LT(_RAISE, KC_ESC), LT(_LOWER, KC_QUOT), KC_SPC,       RSFT_T(KC_ENT), RAISE,  LT(_LOWER, KC_TAB)
                                     //`------------------------------'       `-----------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,--------+------------+-------------+-------------+-------------+------.   ,------+--------------+---------------+---------------+---------------+-------.
       KC_NO,     KC_EXLM,      KC_AT,      KC_HASH,        KC_DLR,  KC_PERC,   KC_CIRC,    KC_AMPR,      KC_ASTR,         KC_LPRN,        KC_RPRN,    KC_NO,
  //---------+------------+-------------+-------------+-------------+------|   |------+--------------+---------------+---------------+---------------+-------|
       KC_NO, LGUI_T(KC_F1),RALT_T(KC_F2),LCTL_T(KC_F3),LSFT_T(KC_F4),KC_F5,    KC_MINS,RSFT_T(KC_EQL),RCTL_T(KC_LBRC),RALT_T(KC_RBRC),RGUI_T(KC_BSLS),KC_NO,
  //|--------+------------+-------------+-------------+-------------+------|   |------+--------------+---------------+---------------+---------------+-------|
       KC_NO,     KC_F6,    LALT_T(KC_F7),   KC_F8,         KC_F9,    KC_F10,   KC_UNDS,   KC_PLUS,        KC_LCBR,        KC_RCBR,        KC_PIPE,    KC_NO,
  //|--------+------------+-------------+-------------+-------------+------|   |------+--------------+---------------+---------------+---------------+-------|
                                          LT(_RAISE, KC_ESC), LOWER, KC_GRV,    RSFT_T(KC_ENT), LT(_RAISE, KC_BSPC), LT(_LOWER, KC_TAB)
                                       //`------------------------------'       `-----------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------.                ,-----------------------------------------.
    QK_BOOT,RGBRST, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO,KC_MUTE, KC_NO, KC_NO, KC_NO, DB_TOGG,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,RGB_SPI,KC_NO,               KC_PAUSE,KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO,
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,RGB_SPD,KC_NO,               KC_SCRL,KC_VOLD, KC_NO, KC_NO, KC_NO, RGB_RMOD,
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                 KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO
                    //`------------------------------'   `-----------------------------'
  )
};
// clang-format on

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
    if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
        layer_on(layer3);
    } else {
        layer_off(layer3);
    }
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
#endif
}

void matrix_scan_user(void) {
    achordion_task();
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[]  = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[]  = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[]  = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[]  = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[]  = {0xc7, 0};
    static const char PROGMEM on_off_2[]  = {0xc8, 0};
    static const char PROGMEM off_on_1[]  = {0xc9, 0};
    static const char PROGMEM off_on_2[]  = {0xca, 0};
    static const char PROGMEM on_on_1[]   = {0xcb, 0};
    static const char PROGMEM on_on_2[]   = {0xcc, 0};

    bool gui = modifiers & MOD_MASK_GUI;
    bool alt = modifiers & MOD_MASK_ALT;

    if (gui) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if (gui && alt) {
        oled_write_P(on_on_1, false);
    } else if (gui) {
        oled_write_P(on_off_1, false);
    } else if (alt) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if (alt) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if (gui) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (gui && alt) {
        oled_write_P(on_on_2, false);
    } else if (gui) {
        oled_write_P(on_off_2, false);
    } else if (alt) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if (alt) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[]  = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[]  = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[]  = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[]  = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[]  = {0xc7, 0};
    static const char PROGMEM on_off_2[]  = {0xc8, 0};
    static const char PROGMEM off_on_1[]  = {0xc9, 0};
    static const char PROGMEM off_on_2[]  = {0xca, 0};
    static const char PROGMEM on_on_1[]   = {0xcb, 0};
    static const char PROGMEM on_on_2[]   = {0xcc, 0};

    bool ctrl = modifiers & MOD_MASK_CTRL;
    bool shift = modifiers & MOD_MASK_SHIFT;

    if (ctrl) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if (ctrl && shift) {
        oled_write_P(on_on_1, false);
    } else if (ctrl) {
        oled_write_P(on_off_1, false);
    } else if (shift) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if (shift) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if (ctrl) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (ctrl && shift) {
        oled_write_P(on_on_2, false);
    } else if (ctrl) {
        oled_write_P(on_off_2, false);
    } else if (shift) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if (shift) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {0x20, 0x94, 0x95, 0x96, 0x20, 0x20, 0xb4, 0xb5, 0xb6, 0x20, 0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[]   = {0x20, 0x97, 0x98, 0x99, 0x20, 0x20, 0xb7, 0xb8, 0xb9, 0x20, 0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[]   = {0x20, 0x9a, 0x9b, 0x9c, 0x20, 0x20, 0xba, 0xbb, 0xbc, 0x20, 0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[]  = {0x20, 0x9d, 0x9e, 0x9f, 0x20, 0x20, 0xbd, 0xbe, 0xbf, 0x20, 0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if (layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if (layer_state_is(_LOWER)) {
        oled_write_P(lower_layer, false);
    } else if (layer_state_is(_RAISE)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

bool oled_task_user(void) {
    // Renders the current keyboard state (layers and mods)
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods() | get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods() | get_oneshot_mods());
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case RGBRST:
#ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
                RGB_current_mode = rgblight_config.mode;
            }
#endif
#ifdef RGB_MATRIX_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
                rgb_matrix_enable();
            }
#endif
            break;
    }
    return true;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand.
    switch (tap_hold_keycode) {
        // only apply opposite hands rule to modifiers, not layer tap keys
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            return true;

            // case LGUI_T(KC_A):  // example for HRM exception
            //   if (other_keycode == KC_Q) { return true; }
            //   break;
    }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case LSFT_T(KC_F):
        case RSFT_T(KC_J):
            return 800; // High Achordion timeout for shift keys.
    }

    return 400;
}

#ifdef RGB_MATRIX_ENABLE

void suspend_power_down_keymap(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_keymap(void) {
    rgb_matrix_set_suspend_state(false);
}

#endif

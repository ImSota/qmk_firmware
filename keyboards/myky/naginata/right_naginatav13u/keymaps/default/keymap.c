// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "naginata.h"
NGKEYS naginata_keys;

// #define BASE 0
// #define LOWER 1
// #define RAISE 2
// #define NAGINATA 3

enum keymap_layers {
  BASE,
// 薙刀式
  NAGINATA, // 薙刀式入力レイヤー
// 薙刀式
  LOWER,
  RAISE,
};

enum custom_keycodes {
  EISU = NG_SAFE_RANGE,
  KANA2,
  LCTOGL, // Macのライブ変換対応オンオフ
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* BASE
      * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │               │ 6 │ 7 │ 8 │ 9 │ 0 │ - │
      * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
      * │Tab│ Q │ W │ E │ R │ T │               │ Y │ U │ I │ O │ P │ = │
      * ├───┼───┼───┼───┼───┼───┼───┐       ┌───├───┼───┼───┼───┼───┼───┤
      * │Cap│ A │ S │ D │ F │ G │Ins│       │ [ │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │ ' │       │ ] │ N │ M │ , │ . │ / │ ¥ │
      * └───┴───┴───┴───┴───┴───┴───┘       └───└───┴───┴───┴───┴───┴───┘
      * ┌───────┐   ┌───┬───┐                       ┌───┬───┐   ┌───────┐
      * │ EISU  │   │Alt│Win├───┐               ┌───┤Ent│Alt│   │ KANA  │
      * └───────┘   └───┴───┤Spc├───┐       ┌───┤Bsp├───┴───┘   └───────┘
      *                     └───┤LOW│       │UPR├───┘                             SandSはSFT_T(kc)で実装可
      *                         └───┘       └───┘
      */
    [BASE] = LAYOUT(
        KC_ESC,       KC_1, KC_2,    KC_3, KC_4, KC_5,                         KC_6,    KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS,
        KC_TAB,       KC_Q, KC_W,    KC_E, KC_R, KC_T,                         KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_EQL,
        KC_CAPS_LOCK, KC_A, KC_S,    KC_D, KC_F, KC_G,   KC_INS,    KC_LBRC,   KC_H,    KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT,      KC_Z, KC_X,    KC_C, KC_V, KC_B,   KC_GRV,    KC_RBRC,   KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
        EISU,            KC_LCTL, KC_LGUI,    KC_SPC, TT(LOWER), TT(RAISE), KC_BSPC, KC_ENT, KC_RALT,                  KANA2
    ),

    [NAGINATA] = LAYOUT(
        KC_ESC,       KC_1, KC_2,    KC_3, KC_4, KC_5,                         KC_6,    KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS,
        KC_TAB,       NG_Q, NG_W,    NG_E, NG_R, NG_T,                         NG_Y,    NG_U,   NG_I,    NG_O,   NG_P,    KC_EQL,
        KC_CAPS_LOCK, NG_A, NG_S,    NG_D, NG_F, NG_G,   KC_INS,    KC_LBRC,   NG_H,    NG_J,   NG_K,    NG_L,   NG_SCLN, KC_QUOT,
        KC_LSFT,      NG_Z, NG_X,    NG_C, NG_V, NG_B,   KC_GRV,    KC_RBRC,   NG_N,    NG_M,   NG_COMM, NG_DOT, NG_SLSH, KC_BSLS,
        _______,              _______, _______, _______, _______,  _______, _______, _______, _______,                 _______
    ),
     /* LOWER
      * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
      * │Esc│F1 │F2 │F3 │F4 │F5 │               │BR+│ 7 │ 8 │ 9 │ / │NUM│
      * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
      * │Tab│F6 │F7 │F8 │F9 │F10│               │BR-│ 4 │ 5 │ 6 │ * │   │
      * ├───┼───┼───┼───┼───┼───┼───┐       ┌───├───┼───┼───┼───┼───┼───┤
      * │Cap│F11│F12│ ↑ │   │HOM│Ins│       │ ( │VL+│ 1 │ 2 │ 3 │ - │   │
      * ├───┼───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┼───┤
      * │Sft│   │ ← │ ↓ │ → │END│Del│       │ ) │VL-│ . │ 0 │ = │ + │   │
      * └───┴───┴───┴───┴───┴───┴───┘       └───└───┴───┴───┴───┴───┴───┘
      * ┌───────┐   ┌───┬───┐                       ┌───┬───┐   ┌───────┐
      * │ EISU  │   │Ctl│Win├───┐               ┌───┤Ent│Alt│   │ KANA  │
      * └───────┘   └───┴───┤Spc├───┐       ┌───┤Bsp├───┴───┘   └───────┘
      *                     └───┤LOW│       │UPR├───┘                             SandSはSFT_T(kc)で実装可
      *                         └───┘       └───┘
      */
    [LOWER] = LAYOUT(
        KC_ESC,       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_BRIU, KC_P7,   KC_P8, KC_P9,   KC_PSLS, KC_NUM,
        KC_TAB,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    KC_BRID, KC_P4,   KC_P5, KC_P6,   KC_PAST, XXXXXXX,
        KC_CAPS_LOCK, KC_F11,  KC_F12,  KC_UP,   XXXXXXX, KC_HOME, KC_INS,  KC_LPRN, KC_VOLU, KC_P1,   KC_P2, KC_P3,   KC_PMNS, XXXXXXX,
        KC_LSFT,      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_DEL,  KC_RPRN, KC_VOLD, KC_PDOT, KC_P0, KC_EQL, KC_PPLS, XXXXXXX,
        _______,                       _______, _______, _______, _______,  _______, _______, _______, _______,                 _______
    ),
     /* RAISE
      * ┌───┬───┬───┬───┬───┬───┐               ┌───┬───┬───┬───┬───┬───┐
      * │Esc│   │   │   │   │   │               │BR+│MD←│MD→│   │   │   │
      * ├───┼───┼───┼───┼───┼───┤               ├───┼───┼───┼───┼───┼───┤
      * │Tab│   │   │   │   │   │               │BR-│VAD│VAI│Swr│   │   │
      * ├───┼───┼───┼───┼───┼───┼───┐       ┌───├───┼───┼───┼───┼───┼───┤
      * │Cap│PGU│   │ ↑ │   │HOM│Ins│       │TOG│VL+│HUD│HUI│Pln│   │   │
      * ├───┼───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┼───┤
      * │Sft│PGD│ ← │ ↓ │ → │END│Del│       │   │VL-│SAD│SAI│Brt│   │   │
      * └───┴───┴───┴───┴───┴───┴───┘       └───└───┴───┴───┴───┴───┴───┘
      * ┌───────┐   ┌───┬───┐                       ┌───┬───┐   ┌───────┐
      * │ EISU  │   │Alt│Win├───┐               ┌───┤Ent│Alt│   │ KANA  │
      * └───────┘   └───┴───┤Spc├───┐       ┌───┤Bsp├───┴───┘   └───────┘
      *                     └───┤LOW│       │UPR├───┘                             SandSはSFT_T(kc)で実装可
      *                         └───┘       └───┘
      */
    [RAISE] = LAYOUT(
        KC_ESC,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_BRIU, RGB_RMOD, RGB_MOD, XXXXXXX,  XXXXXXX, XXXXXXX,
        KC_TAB,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_BRID, RGB_VAD,  RGB_VAI, RGB_M_SW, XXXXXXX, XXXXXXX,
        KC_CAPS_LOCK, KC_PGUP, XXXXXXX, KC_UP,   XXXXXXX, KC_HOME, KC_INS,   RGB_TOG, KC_VOLU, RGB_HUD,  RGB_HUI, RGB_M_P,  XXXXXXX, XXXXXXX,
        KC_LSFT,      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_DEL,   XXXXXXX, KC_VOLD, RGB_SAD,  RGB_SAI, RGB_M_B,  XXXXXXX, XXXXXXX,
        _______,                      _______, _______, _______,  _______,   _______, _______, _______,  _______,                    _______
    )
};

void matrix_init_user(void) {
  uint16_t ngonkeys[] = {KC_H, KC_J};
  uint16_t ngoffkeys[] = {KC_F, KC_G};
  set_naginata(NAGINATA, ngonkeys, ngoffkeys);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EISU:
      if (record->event.pressed) {
        // 薙刀式
        naginata_off();
        // 薙刀式
      }
      return false;
      break;
    case KANA2:
      if (record->event.pressed) {
        // 薙刀式
        naginata_on();
        // 薙刀式
      }
      return false;
      break;
}
    if (!process_naginata(keycode, record))
      return false;
  return true;
}
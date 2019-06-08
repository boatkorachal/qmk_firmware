/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _BASE_MAC,
  _BASE_WIN,
  _MAC_1,
  _MAC_N,
  _NUMBER,
  _WIN_1,
  _WIN_N,
  _FN,
  _ARROW,
  _MOUSE,
  _DYN,
};

enum planck_keycodes {
  BASE_MAC = SAFE_RANGE,
  BASE_WIN,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

#define MAC_1 MO(_MAC_1)
#define MAC_N MO(_MAC_N)
#define MAC_N_CLN LT(_MAC_N, KC_SCLN)
#define NUMBER MO(_NUMBER)
#define WIN_1 MO(_WIN_1)
#define WIN_N MO(_WIN_N)
#define WIN_N_CLN LT(_WIN_N, KC_SCLN)
#define FN MO(_FN)
#define DYN MO(_DYN)
#define MOUSE MO(_MOUSE)

#define CTL_ESC LCTL_T(KC_ESC)
#define SFT_ENT RSFT_T(KC_ENT) // Hold = Shift, Tap = Enter
#define PRVTAB SGUI(KC_LBRC)
#define NXTTAB SGUI(KC_RBRC)
#define ALT_LFT A(KC_LEFT)
#define ALT_RGT A(KC_RGHT)
#define CTL_LFT C(KC_LEFT)
#define CTL_RGT C(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE_MAC
 *        ,-----------------------------------------------------------------------------------.
 *        | Tab  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | Bksp |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *    CTL | Esc  |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |  '   | > ; MAC_N
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        | Shift|  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |Shift | Enter
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        | NUM  | Ctrl |  ⌥   |  ⌘   |MAC_1 |    Space    |MAC_1 |  FN  |      | DYN  |MAC_N |
 *        `-----------------------------------------------------------------------------------'
 */
[_BASE_MAC] = LAYOUT_planck_grid(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R   , KC_T    , KC_Y    , KC_U   , KC_I     , KC_O     , KC_P     , KC_BSPC  ,
    CTL_ESC  , KC_A     , KC_S     , KC_D     , KC_F   , KC_G    , KC_H    , KC_J   , KC_K     , KC_L     , MAC_N_CLN, KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V   , KC_B    , KC_N    , KC_M   , KC_COMM  , KC_DOT   , KC_SLSH  , SFT_ENT  ,
    NUMBER   , KC_LCTL  , KC_LALT  , KC_LCMD  , MAC_1  , KC_SPC  , KC_SPC  , MAC_1  , FN       , XXXXXXX  , DYN      , MAC_N
),

/* MAC_1
 *        ,-----------------------------------------------------------------------------------.
 *        |  `   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |      |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  -   |  =   |  \   |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |  {   |  }   |  (   |  )   |  ~   |  .   |  _   |  +   |  [   |  ]   |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |      |      |      |      |      |
 *        `-----------------------------------------------------------------------------------'
 */
[_MAC_1] = LAYOUT_planck_grid(
    KC_GRV   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     , KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , _______  ,
    _______  , KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  , KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_MINS  , KC_EQL   , KC_BSLS  ,
    _______  , KC_LCBR  , KC_RCBR  , KC_LPRN  , KC_RPRN  , KC_TILD  , KC_DOT   , KC_UNDS  , KC_PLUS  , KC_LBRC  , KC_RBRC  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______
),

/* MAC_N
 *        ,-----------------------------------------------------------------------------------.
 *        |      |      | ⌥ →  |      |      |      | ⌘⇧`  | ⌘⇧[  | ⌘⇧]  | ⌘`   | ⌘Tab | Del  |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      | Home | PgUp | PgDn | End  |  ←   |  ↓   |  ↑   |  →   |      | Ins  |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      |      |      |      | ⌥ ←  |      |      |      |      |      |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |      |      |      |      |      |
 *        `-----------------------------------------------------------------------------------'
 */
[_MAC_N] = LAYOUT_planck_grid(
    _______  , _______  , A(KC_RGHT)  , _______  , _______  , _______     , G(S(KC_GRV))  , G(S(KC_LBRC))  , G(S(KC_RBRC))  , G(KC_GRV)  , G(KC_TAB)  , KC_DEL   ,
    _______  , _______  , KC_HOME     , KC_PGUP  , KC_PGDN  , KC_END      , KC_LEFT       , KC_DOWN        , KC_UP          , KC_RGHT    , _______    , KC_INS   ,
    _______  , _______  , _______     , _______  , _______  , A(KC_LEFT)  , _______       , _______        , _______        , _______    , _______    , _______  ,
    _______  , _______  , _______     , _______  , _______  , _______     , _______       , _______        , _______        , _______    , _______    , _______
),

/* BASE_WIN
 *        ,-----------------------------------------------------------------------------------.
 *        | Tab  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | Bksp |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *    CTL | Esc  |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |; NAV |  '   |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        | Shift|  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |Shift | Enter
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        | Ctrl | Ctrl |  ⌥   |  ⌘   |NUMBER|    Space    |WIN_1 |  FN  |      | DYN  |WIN_N |
 *        `-----------------------------------------------------------------------------------'
 */
[_BASE_WIN] = LAYOUT_planck_grid(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R   , KC_T    , KC_Y    , KC_U   , KC_I     , KC_O     , KC_P     , KC_BSPC  ,
    CTL_ESC  , KC_A     , KC_S     , KC_D     , KC_F   , KC_G    , KC_H    , KC_J   , KC_K     , KC_L     , WIN_N_CLN, KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V   , KC_B    , KC_N    , KC_M   , KC_COMM  , KC_DOT   , KC_SLSH  , SFT_ENT  ,
    KC_LCTL  , KC_LCTL  , KC_LWIN  , KC_LALT  , NUMBER , KC_SPC  , KC_SPC  , WIN_1  , FN       , XXXXXXX  , DYN      , WIN_N
),

/* WIN_1
 *        ,-----------------------------------------------------------------------------------.
 *        |  `   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |      |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  -   |  =   |  \   |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |  {   |  }   |  (   |  )   |  ~   |  .   |  _   |  +   |  [   |  ]   |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |      |      |      |      |      |
 *        `-----------------------------------------------------------------------------------'
 */
[_WIN_1] = LAYOUT_planck_grid(
    KC_GRV   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     , KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , _______  ,
    _______  , KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  , KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_MINS  , KC_EQL   , KC_BSLS  ,
    _______  , KC_LCBR  , KC_RCBR  , KC_LPRN  , KC_RPRN  , KC_TILD  , KC_DOT   , KC_UNDS  , KC_PLUS  , KC_LBRC  , KC_RBRC  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______
),

/* WIN_N
 *        ,-----------------------------------------------------------------------------------.
 *        |      |      | ^ →  |      |      |      |      |^PGUP |^PGDN |      |      | Del  |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      | Home | PgUp | PgDn | End  |  ←   |  ↓   |  ↑   |  →   |      | Ins  |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      |      |      |      | ^ ←  |      |      |      |      |      |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |      |      |      |      |      |
 *        `-----------------------------------------------------------------------------------'
 */
[_WIN_N] = LAYOUT_planck_grid(
    _______  , _______  , C(KC_RGHT)  , _______  , _______  , _______     , _______  , C(KC_PGUP)  , C(KC_PGDN)  , _______  , _______  , KC_DEL   ,
    _______  , _______  , KC_HOME     , KC_PGUP  , KC_PGDN  , KC_END      , KC_LEFT  , KC_DOWN     , KC_UP       , KC_RGHT  , _______  , KC_INS   ,
    _______  , _______  , _______     , _______  , _______  , C(KC_LEFT)  , _______  , _______     , _______     , _______  , _______  , _______  ,
    _______  , _______  , _______     , _______  , _______  , _______     , _______  , _______     , _______     , _______  , _______  , _______
),

/* FN
 *        ,-----------------------------------------------------------------------------------.
 *        |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      |      |      |      |      |      |      |      |      |      | F12  |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      |      |      |      |      |      |      |      |      |  ↑   |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |      |      |  ←   |  ↓   |  →   |
 *        `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_grid(
    _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_F12  ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_UP   , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_LEFT , KC_DOWN , KC_RGHT
),

/* MOUSE
 *        ,-----------------------------------------------------------------------------------.
 *        |  ×   |  ×   |  ×   | MS ↑ | WH ↑ |  ×   |  ×   |  ×   |  ×   |  ×   |  ×   |  ×   |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |  ×   | WH ← | MS ← | MS ↓ | MS → | WH → |  ×   |MS AC1|MS AC2|MS AC3|  ×   |  ×   |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |  ×   |  ×   |  ×   |  ×   | WH ↓ |  ×   |  ×   |MS B1 |MS B2 |  ×   |  ×   |  ×   |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |  ×   |  ×   |  ×   |  ×   |  ×   |      ×      |  ×   |  ×   |  ×   |  ×   |      |
 *        `-----------------------------------------------------------------------------------'
 */
/*
[_MOUSE] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, XXXXXXX, KC_ACL2, KC_ACL1,  KC_ACL0, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, _______
),
*/

/* DYN
 *        ,-----------------------------------------------------------------------------------.
 *        | REST |      | WIN  |      |      |      |      | BRDN | BRUP | VLDN | VLUP | POWR |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      |      |      |      | PLY1 | PLY2 |      |      |      | VLMU |      |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      |      | COPY |PASTE | REQ1 | REQ2 | MAC  |      |      |      |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |      |      |      |      |      |
 *        `-----------------------------------------------------------------------------------'
 */
[_DYN] = LAYOUT_planck_grid(
    RESET    , _______  , BASE_WIN  , _______    , _______    , _______          , _______          , KC_BRMD   , KC_BRMU  , KC__VOLDOWN  , KC__VOLUP  , KC_POWER  ,
    _______  , _______  , _______   , _______    , _______    , DYN_MACRO_PLAY1  , DYN_MACRO_PLAY2  , _______   , _______  , _______      , KC__MUTE   , _______   ,
    _______  , _______  , _______   , C(KC_INS)  , S(KC_INS)  , DYN_REC_START1   , DYN_REC_START2   , BASE_MAC  , _______  , _______      , _______    , _______   ,
    _______  , _______  , _______   , _______    , _______    , _______          , _______          , _______   , _______  , _______      , _______    , _______
),

/* NUMBER
 *        ,-----------------------------------------------------------------------------------.
 *        |      |  ×   |  ×   |  ×   |  ×   |  ×   |  %   |  7   |  8   |  9   |  *   |      |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |  ×   |  ×   |  ×   |  ×   |  ×   |  (   |  4   |  5   |  6   |  -   |  =   |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |  ×   |  ×   |  ×   |  ×   |  ×   |  )   |  1   |  2   |  3   |  +   |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |  0   |  .   |  =   |  /   |      |
 *        `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_planck_grid(
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PERC , KC_KP_7 , KC_KP_8 , KC_KP_9 , KC_PAST , _______ ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_LPRN , KC_KP_4 , KC_KP_5 , KC_KP_6 , KC_PMNS , KC_PEQL ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_RPRN , KC_KP_1 , KC_KP_2 , KC_KP_3 , KC_PPLS , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_KP_0 , KC_PDOT , KC_PEQL , KC_PSLS , _______
),

/* Blank
 *        ,-----------------------------------------------------------------------------------.
 *        |      |      |      |      |      |      |      |      |      |      |      |      |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      |      |      |      |      |      |      |      |      |      |      |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      |      |      |      |      |      |      |      |      |      |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |      |      |      |      |      |
 *        `-----------------------------------------------------------------------------------'
 */
/*
[_] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),
*/

/* NUMBER
 *        ,-----------------------------------------------------------------------------------.
 *        |      |  ×   |  ×   |  ×   |  ×   |  ×   |  ×   |  7   |  8   |  9   |  -   | Del  |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |  ×   |  ×   |  ×   |  ×   |  ×   |  (   |  4   |  5   |  6   |  +   |  =   |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |  ×   |  ×   |  ×   |  ×   |  ×   |  )   |  1   |  2   |  3   |  *   |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |  0   |  .   |  =   |  /   |      |
 *        `-----------------------------------------------------------------------------------'
 */
/*
[_NUMBER] = LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8,  KC_KP_9, KC_PMNS, KC_DEL ,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_KP_4, KC_KP_5,  KC_KP_6, KC_PPLS, KC_PEQL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RPRN, KC_KP_1, KC_KP_2,  KC_KP_3, KC_PAST, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_KP_0, KC_PDOT,  KC_PEQL, KC_PSLS, _______
),
*/

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint16_t macro_kc = (keycode == DYN ? DYN_REC_STOP : keycode);
  if (!process_record_dynamic_macro(macro_kc, record)) {
    return false;
  }

  switch (keycode) {
    case BASE_MAC:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE_MAC);
      }
      return false;
      break;
    case BASE_WIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE_WIN);
      }
      return false;
      break;
  }
  return true;
}

void matrix_scan_user(void) {
}

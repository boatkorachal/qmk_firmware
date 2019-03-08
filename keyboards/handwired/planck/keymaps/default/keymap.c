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
  _QWERTY,
  _RAISE,
  _NUMBER,
  _NAV,
  _FN,
  _MOUSE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE
};

#define RAISE MO(_RAISE)
#define NUMBER MO(_NUMBER)
#define NAV_CLN LT(_NAV, KC_SCLN)
#define FN MO(_FN)
#define MOUSE MO(_MOUSE)
#define CTL_ESC LCTL_T(KC_ESC)
#define SFT_ENT RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *        ,-----------------------------------------------------------------------------------.
 *        | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *    CTL | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ; NAV|  '   |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter | Shift
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        | NUM  | Ctrl | Alt  | GUI  |RAISE |    Space    |RAISE |  FN  |      |      |MOUSE |
 *        `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R   , KC_T    , KC_Y    , KC_U   , KC_I     , KC_O     , KC_P     , KC_BSPC  ,
    CTL_ESC  , KC_A     , KC_S     , KC_D     , KC_F   , KC_G    , KC_H    , KC_J   , KC_K     , KC_L     , NAV_CLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V   , KC_B    , KC_N    , KC_M   , KC_COMM  , KC_DOT   , KC_SLSH  , SFT_ENT  ,
    NUMBER   , KC_LCTL  , KC_LALT  , KC_LGUI  , RAISE  , KC_SPC  , KC_SPC  , RAISE  , FN       , XXXXXXX  , XXXXXXX  , MOUSE
),

/* RAISE
 *        ,-----------------------------------------------------------------------------------.
 *        |  `   |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  (   |  )   | Del  |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  \   |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      |      |      |      |      |      |  -   |  =   |  [   |  ]   |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |      |      |      |      |      |
 *        `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_DEL  ,
    _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSLS ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
),

/* NUMBER
 *        ,-----------------------------------------------------------------------------------.
 *        |      |  ×   |  ×   |  ×   |  ×   |  ×   |  ×   |  7   |  8   |  9   |  -   |      |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |  ×   |  ×   |  ×   |  ×   |  ×   |  (   |  4   |  5   |  6   |  +   |      |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |  ×   |  ×   |  ×   |  ×   |  ×   |  )   |  1   |  2   |  3   |  *   |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |  0   |  .   |  =   |  /   |      |
 *        `-----------------------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8,  KC_KP_9, KC_PMNS, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_KP_4, KC_KP_5,  KC_KP_6, KC_PPLS, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RPRN, KC_KP_1, KC_KP_2,  KC_KP_3, KC_PAST, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_KP_0, KC_PDOT,  KC_PEQL, KC_PSLS, _______
),

/* NAV
 *        ,-----------------------------------------------------------------------------------.
 *        |      |      |      |      |      |      |      |      |      |      |      |      |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      | Home | PgUp | PgDn | End  |  ←   |  ↓   |  ↑   |  →   |      |      |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      |      |      |      |      |      |      |      |      |      |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |      |      |      |      |      |
 *        `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_LEFT, KC_DOWN, KC_UP  ,  KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* FN
 *        ,-----------------------------------------------------------------------------------.
 *        |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      |      |      |      |      |      |      |      |      |      | F12  |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |      |      |      |      |      |      |      |      |      |      |      |      |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |      |      |      |      |      |             |      |      |      |      |      |
 *        `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_grid(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  ,  KC_F9  , KC_F10 , KC_F11 ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_F12 ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* MOUSE
 *        ,-----------------------------------------------------------------------------------.
 *        |  ×   |  ×   |  ×   | MS ↑ | WH ↑ |  ×   |  ×   |  ×   |  ×   |  ×   |  ×   |  ×   |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |  ×   | WH ← | MS ← | MS ↓ | MS → | WH → |      |MS AC1|MS AC2|MS AC3|  ×   |  ×   |
 *        |------+------+------+------+------+------|------+------+------+------+------+------|
 *        |  ×   |  ×   |  ×   |  ×   | WH ↓ |  ×   |  ×   |MS B1 |MS B2 |  ×   |  ×   |  ×   |
 *        |------+------+------+------+------+------+------+------+------+------+------+------|
 *        |  ×   |  ×   |  ×   |  ×   |  ×   |      ×      |  ×   |  ×   |  ×   |  ×   |      |
 *        `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, XXXXXXX, KC_ACL2, KC_ACL1,  KC_ACL0, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, _______
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

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_scan_user(void) {
}

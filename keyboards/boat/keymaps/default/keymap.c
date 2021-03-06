/* Copyright 2019 'Korachal Phadvibulya'
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

#define ___ KC_TRANSPARENT
#define XXX KC_NO

#define BASE 0
#define ARROW 1
#define NUMBER 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT( \
    KC_ESC     , KC_F1    , KC_F2    , KC_F3    , KC_F4            , KC_F5     , \
    KC_GRV     , KC_1     , KC_2     , KC_3     , KC_4             , KC_5      , KC_6     , \
    KC_TAB     , KC_Q     , KC_W     , KC_E     , KC_R             , KC_T      , \
    KC_CAPS    , KC_A     , KC_S     , KC_D     , KC_F             , KC_G      , \
    KC_LSFT    , KC_Z     , KC_X     , KC_C     , KC_V             , KC_B      , \
    MO(ARROW)  , KC_LCTL  , KC_LALT  , KC_LGUI  , KC_SPC           , \
    \
    KC_F6      , KC_F7    , KC_F8    , KC_F9    , KC_F10           , KC_F11    , KC_F12   , \
    KC_7       , KC_8     , KC_9     , KC_0     , KC_MINS          , KC_EQL    , KC_BSPC  , \
    KC_Y       , KC_U     , KC_I     , KC_O     , KC_P             , KC_LBRC   , KC_RBRC  , KC_BSLS  , \
    KC_H       , KC_J     , KC_K     , KC_L     , KC_SCLN          , KC_QUOT   , KC_ENT   , \
    KC_N       , KC_M     , KC_COMM  , KC_DOT   , RSFT_T(KC_SLSH)  , KC_UP     , KC_SLSH  , \
    KC_SPC     , KC_RALT  , KC_RCTL  , KC_LEFT  , KC_DOWN          , KC_RGHT \
  ),
  [ARROW] = LAYOUT( \
    XXX         , XXX      , XXX      , XXX        , XXX     , XXX   , \
    XXX         , XXX      , XXX      , XXX        , XXX     , XXX   , XXX        , \
    XXX         , XXX      , XXX      , XXX        , XXX     , XXX   , \
    MO(NUMBER)  , XXX      , XXX      , XXX        , XXX     , XXX   , \
    KC_LSFT     , XXX      , XXX      , XXX        , XXX     , XXX   , \
    ___         , ___      , ___      , ___        , XXX     , \
    \
    XXX         , XXX      , XXX      , XXX        , XXX     , XXX   , XXX        , \
    XXX         , XXX      , XXX      , XXX        , XXX     , XXX   , KC_DELETE  , \
    KC_HOME     , KC_PGUP  , KC_UP    , KC_PGDOWN  , KC_END  , XXX   , XXX        , XXX  , \
    XXX         , KC_LEFT  , KC_DOWN  , KC_RIGHT   , XXX     , XXX   , XXX        , \
    XXX         , XXX      , XXX      , XXX        , XXX     , XXX   , XXX        , \
    XXX         , XXX      , XXX      , XXX        , XXX     , XXX \
  ),
  [NUMBER] = LAYOUT( \
    XXX      , XXX      , XXX      , XXX      , XXX        , XXX   , \
    XXX      , XXX      , XXX      , XXX      , XXX        , XXX   , XXX  , \
    XXX      , XXX      , XXX      , XXX      , XXX        , XXX   , \
    ___      , XXX      , XXX      , XXX      , XXX        , XXX   , \
    KC_LSFT  , XXX      , XXX      , XXX      , XXX        , XXX   , \
    ___      , ___      , ___      , ___      , XXX        , \
    \
    XXX      , XXX      , XXX      , XXX      , XXX        , XXX   , XXX  , \
    XXX      , XXX      , XXX      , XXX      , XXX        , XXX   , XXX  , \
    XXX      , KC_KP_7  , KC_KP_8  , KC_KP_9  , XXX        , XXX   , XXX  , XXX  , \
    XXX      , KC_KP_4  , KC_KP_5  , KC_KP_6  , XXX        , XXX   , XXX  , \
    XXX      , KC_KP_1  , KC_KP_2  , KC_KP_3  , KC_KP_DOT  , XXX   , XXX  , \
    KC_KP_0  , XXX      , XXX      , XXX      , XXX        , XXX \
  ),
};

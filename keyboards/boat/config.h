/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

#define VENDOR_ID       0x20A0
#define PRODUCT_ID      0x422D
#define MANUFACTURER    You
#define PRODUCT         boat

#define MATRIX_ROWS 15
#define MATRIX_ROWS_PER_SIDE 8
#define MATRIX_COLS 8

/* key combination for magic key command */
/* defined by default; to change, uncomment and set to the combination you want */
// #define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))

/* Bootmagic Lite key configuration */
// #define BOOTMAGIC_LITE_ROW 0
// #define BOOTMAGIC_LITE_COLUMN 0

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
#pragma once

#include <quantum.h>
#include <i2c_master.h>

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

/* ----------------------- hardware I/O abstraction ------------------------ */
#define PORTCOLUMNS PORTB  ///< port on which we read the state of the columns
#define PINCOLUMNS  PINB   ///< port on which we read the state of the columns
#define DDRCOLUMNS  DDRB   ///< port on which we read the state of the columns
#define PORTROWS1   PORTA  ///< first port connected to the matrix rows
#define PINROWS1    PINA   ///< first port connected to the matrix rows
#define DDRROWS1    DDRA   ///< first port connected to the matrix rows
#define PORTROWS2   PORTC  ///< second port connected to the matrix rows
#define PINROWS2    PINC   ///< second port connected to the matrix rows
#define DDRROWS2    DDRC   ///< second port connected to the matrix rows


// register addresses (see "mcp23018.md")
#define IODIRA 0x00  // i/o direction register
#define IODIRB 0x01
#define GPPUA  0x0C  // GPIO pull-up resistor register
#define GPPUB  0x0D
#define GPIOA  0x12  // general purpose i/o port register (write modifies OLAT)
#define GPIOB  0x13
#define OLATA  0x14  // output latch register
#define OLATB  0x15

#define TW_READ		1
#define TW_WRITE	0

#define MCP23018_TWI_ADDRESS 0b0100000

// TWI aliases
#define TWI_ADDR_WRITE ( (MCP23018_TWI_ADDRESS<<1) | TW_WRITE )
#define TWI_ADDR_READ  ( (MCP23018_TWI_ADDRESS<<1) | TW_READ  )

#define I2C_TIMEOUT     10

i2c_status_t init_mcp23018(void);

#define LAYOUT( \
    k00,  k01,  k02,  k03,  k04,  k05,  \
    k10,  k11,  k12,  k13,  k14,  k15,  k16,  \
    k20,  k21,  k22,  k23,  k24,  k25,  \
    k30,  k31,  k32,  k33,  k34,  k35,  \
    k40,  k41,  k42,  k43,  k44,  k45,  \
    k50,  k51,  k52,  k53,  k54,  \
    \
    k80,  k81,  k82,  k83,  k84,  k85,  k86,  \
    k90,  k91,  k92,  k93,  k94,  k95,  k96, \
    k100, k101, k102, k103, k104, k105, k106,  k107, \
    k110, k111, k112, k113, k114, k115, k116, \
    k120, k121, k122, k123, k124, k125, k126, \
    k131, k132, k133, k134, k135, k136  \
) \
{ \
  { k00,   k01,   k02,   k03,   k04,   k05,   KC_NO, KC_NO }, \
  { k10,   k11,   k12,   k13,   k14,   k15,   KC_NO, KC_NO }, \
  { k20,   k21,   k22,   k23,   k24,   k25,   KC_NO, KC_NO }, \
  { k30,   k31,   k32,   k33,   k34,   k35,   KC_NO, KC_NO }, \
  { k40,   k41,   k42,   k43,   k44,   k45,   KC_NO, KC_NO }, \
  { k50,   k51,   k52,   k53,   k54,   k16,   KC_NO, KC_NO }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
  { k80,   k81,   k82,   k83,   k84,   k85,   k86,   KC_NO }, \
  { k90,   k91,   k92,   k93,   k94,   k95,   k96,   KC_NO }, \
  { k100,  k101,  k102,  k103,  k104,  k105,  k106,  KC_NO }, \
  { k110,  k111,  k112,  k113,  k114,  k115,  k116,  KC_NO }, \
  { k120,  k121,  k122,  k123,  k124,  k125,  k126,  KC_NO }, \
  { k107,   k131,  k132,  k133,  k134,  k135,  k136,  KC_NO }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }  \
}

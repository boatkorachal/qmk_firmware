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
#include "boat.h"

#include <avr/pgmspace.h>
#include "action_layer.h"
#include <quantum.h>
#include <i2c_master.h>


bool i2c_initialized = 0;

// for keyboard subdirectory level init functions
// @Override
void matrix_init_kb(void) {
  // call user level keymaps, if any
  matrix_init_user();
}

void matrix_scan_kb(void) {
  matrix_scan_user();
  /* Nothing else for now. */
}

__attribute__((weak)) // overridable
void matrix_init_user(void) {

}


__attribute__((weak)) // overridable
void matrix_scan_user(void) {

}

i2c_status_t init_mcp23018(void) {

    // if (i2c_initialized == 0) {
    //     i2c_init();  // on pins D(1,0)
    //     i2c_initialized = true;
    //     _delay_ms(1000);
    // }

    i2c_status_t ret;
	uint8_t data[3];
	// set pin direction
	// - unused  : input  : 1
	// - input   : input  : 1
	// - driving : output : 0
	data[0] = IODIRA;
	data[1] = 0b00000000;  // IODIRA
	data[2] = (0b11111111);  // IODIRB

    ret = i2c_transmit(TWI_ADDR_WRITE, data, sizeof(data), I2C_TIMEOUT);
	if (ret) goto out;  // make sure we got an ACK
	// set pull-up
	// - unused  : on  : 1
	// - input   : on  : 1
	// - driving : off : 0
	data[0] = GPPUA;
	data[1] = 0b00000000;  // IODIRA
	data[2] = (0b11111111);  // IODIRB

	ret = i2c_transmit(TWI_ADDR_WRITE, data, sizeof(data), I2C_TIMEOUT);
	if (ret) goto out;  // make sure we got an ACK

	// set logical value (doesn't matter on inputs)
	// - unused  : hi-Z : 1
	// - input   : hi-Z : 1
	// - driving : hi-Z : 1
	data[0] = OLATA;
	data[1] = 0b11111111;  // IODIRA
	data[2] = (0b11111111);  // IODIRB

	ret = i2c_transmit(TWI_ADDR_WRITE, data, sizeof(data), I2C_TIMEOUT);

out:
	return ret;
}

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

#include <avr/io.h>
#include <util/delay.h>

#include "matrix.h"
#include <i2c_master.h>

#include "boat.h"

#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif

#ifndef BV
	#define BV(bit)			(1<<(bit))
#endif

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];

void i2c_set_bitrate(uint16_t bitrate_khz);
void delegateSetCellStatus(uint8_t xCol);
uint8_t delegateGetCellStatus(uint8_t xRow);

inline matrix_row_t matrix_get_row(uint8_t row) {
    return matrix[row];
}

void matrix_init(void)
{
    // initialize row and col
    DDRB = 0xFF;
    PORTB = 0xFF;
    // all inputs for columns
    DDRA = 0x00;
    DDRC &= ~(0x111111<<2);
    DDRD &= ~(1<<PIND7);
    // all columns are pulled-up
    PORTA = 0xFF;
    PORTC |= (0b111111<<2);
    PORTD |= (1<<PIND7);

    i2c_init();

    init_mcp23018();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }

    matrix_init_quantum();
}

uint8_t matrix_scan(void) {
    uint8_t col, row;
	uint8_t prev, cur;


    for(col = 0; col < MATRIX_COLS; ++col) {
        delegateSetCellStatus(col);

        // scan each rows
        for(row = 0; row < MATRIX_ROWS_PER_SIDE; ++row) {
            cur = delegateGetCellStatus(row);

            prev = matrix[row] & BV(col);

            if(!(prev && cur) && !(!prev && !cur)) {
                if(cur)
                	matrix[row] |= BV(col);
                else
                	matrix[row] &= ~BV(col);
            }
        }
    }
    // i2c
    uint8_t ret, data;
    uint8_t txdata[3];

	// initialize things, just to make sure
	// - it's not appreciably faster to skip this, and it takes care of the
	//   case when the i/o expander isn't plugged in during the first
	//   init()
	ret = init_mcp23018();

	// if there was an error
	if (ret) {
		return 0;
	}


	// --------------------------------------------------------------------
	// update our part of the matrix
	for (col=0; col < MATRIX_COLS; ++col) {
		// set active column low  : 0
		// set other columns hi-Z : 1
		txdata[0] = (GPIOA);
		txdata[1] = ( 0xFF & ~(1<<col) );
        i2c_transmit(TWI_ADDR_WRITE, txdata, 2, I2C_TIMEOUT);

		// read row data
        i2c_receive(TWI_ADDR_WRITE, &data, 1, I2C_TIMEOUT);

		// update matrix
		for (row=MATRIX_ROWS_PER_SIDE; row < MATRIX_ROWS; ++row) {

			// data: 현재 col의 row 데이터, 0bit가 on
			cur = ((~data)>>(row-MATRIX_ROWS_PER_SIDE)) & 0x01; //(~data) & BV(row);

			prev = matrix[row] & BV(col);

			if(!(prev && cur) && !(!prev && !cur)) {
				if(cur)
					matrix[row] |= BV(col);
				else
					matrix[row] &= ~BV(col);
			}
		}

	}

	// set all columns hi-Z : 1
	txdata[0] = (GPIOA);
	txdata[1] = ( 0xFF );

    i2c_transmit(TWI_ADDR_WRITE, txdata, 2, I2C_TIMEOUT);

    return 1;
}

void delegateSetCellStatus(uint8_t xCol){
	// Col -> set only one port as output low and all others as input full up
	DDRCOLUMNS  = BV(xCol);	// 해당 col을 출력으로 설정, 나머지 입력
	PORTCOLUMNS = ~BV(xCol);	// 해당 col output low, 나머지 컬럼을 풀업 저항

	/*
	DDR을 1로 설정하면 출력, 0이면 입력
	입력중, PORT가 1이면 풀업(풀업 상태는  high 상태);

	출력 상태의 PORT가 0이면 output low(0v);

	스위치를 on하면 0, off하면 1이 PIN에 저장;
	row는 내부 풀업 저항 상태 이기 때문에 1값이 기본값
	*/

	_delay_us(5);
}

uint8_t delegateGetCellStatus(uint8_t xRow){

	if(xRow<8)	{				// for 0..7, PORTA 0 -> 7
		return (~PINROWS1) & BV(xRow);
	}else if(xRow<14) {	// for 8..13, PORTC 7 -> 0
		return (~PINROWS2) & BV(15-xRow);
	}else if(xRow==14) { // for 14
	    return (~PIND) & BV(7);
	}
	return 0;

}


void matrix_print(void) {
}

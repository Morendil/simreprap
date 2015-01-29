/*
	arduidiot_pins.c

	Copyright 2008-2012 Michel Pollet <buserror@gmail.com>

 	This file is part of simavr.

	simavr is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	simavr is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with simavr.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include "arduidiot_pins.h"
#include "sim_irq.h"
#include "avr_ioport.h"

ardupin_t arduidiot_644[100] = {
	[ 0] = { .ardupin =  0, .port = 'B', .pin =  0 },
	[ 1] = { .ardupin =  1, .port = 'B', .pin =  1 },
	[ 2] = { .ardupin =  2, .port = 'B', .pin =  2 },
	[ 3] = { .ardupin =  3, .port = 'B', .pin =  3 },
	[ 4] = { .ardupin =  4, .port = 'B', .pin =  4 },
	[ 5] = { .ardupin =  5, .port = 'B', .pin =  5 },
	[ 6] = { .ardupin =  6, .port = 'B', .pin =  6 },
	[ 7] = { .ardupin =  7, .port = 'B', .pin =  7 },

	[ 8] = { .ardupin =  8, .port = 'D', .pin =  0 },
	[ 9] = { .ardupin =  9, .port = 'D', .pin =  1 },
	[10] = { .ardupin = 10, .port = 'D', .pin =  2 },
	[11] = { .ardupin = 11, .port = 'D', .pin =  3 },
	[12] = { .ardupin = 12, .port = 'D', .pin =  4 },
	[13] = { .ardupin = 13, .port = 'D', .pin =  5 },
	[14] = { .ardupin = 14, .port = 'D', .pin =  6 },
	[15] = { .ardupin = 15, .port = 'D', .pin =  7 },

	[16] = { .ardupin = 16, .port = 'C', .pin =  0 },
	[17] = { .ardupin = 17, .port = 'C', .pin =  1 },
	[18] = { .ardupin = 18, .port = 'C', .pin =  2 },
	[19] = { .ardupin = 19, .port = 'C', .pin =  3 },
	[20] = { .ardupin = 20, .port = 'C', .pin =  4 },
	[21] = { .ardupin = 21, .port = 'C', .pin =  5 },
	[22] = { .ardupin = 22, .port = 'C', .pin =  6 },
	[23] = { .ardupin = 23, .port = 'C', .pin =  7 },

	[24] = { .ardupin = 24, .port = 'A', .pin =  7, .analog = 1, .adc = 7 },
	[25] = { .ardupin = 25, .port = 'A', .pin =  6, .analog = 1, .adc = 6 },
	[26] = { .ardupin = 26, .port = 'A', .pin =  5, .analog = 1, .adc = 5 },
	[27] = { .ardupin = 27, .port = 'A', .pin =  4, .analog = 1, .adc = 4 },
	[28] = { .ardupin = 28, .port = 'A', .pin =  3, .analog = 1, .adc = 3 },
	[29] = { .ardupin = 29, .port = 'A', .pin =  2, .analog = 1, .adc = 2 },
	[30] = { .ardupin = 30, .port = 'A', .pin =  1, .analog = 1, .adc = 1 },
	[31] = { .ardupin = 31, .port = 'A', .pin =  0, .analog = 1, .adc = 0 },
        [32] = { .ardupin = 32, .port = 'E', .pin =  0 },
        [33] = { .ardupin = 33, .port = 'E', .pin =  1 },
        [34] = { .ardupin = 34, .port = 'E', .pin =  2 },
        [35] = { .ardupin = 35, .port = 'E', .pin =  3 },
        [36] = { .ardupin = 36, .port = 'E', .pin =  4 },
        [37] = { .ardupin = 37, .port = 'E', .pin =  5 },
        [38] = { .ardupin = 38, .port = 'E', .pin =  6 },
        [39] = { .ardupin = 39, .port = 'E', .pin =  7 },
        [40] = { .ardupin = 40, .port = 'F', .pin =  0 },
        [41] = { .ardupin = 41, .port = 'F', .pin =  1 },
        [42] = { .ardupin = 42, .port = 'F', .pin =  2 },
        [43] = { .ardupin = 43, .port = 'F', .pin =  3 },
        [44] = { .ardupin = 44, .port = 'F', .pin =  4 },
        [45] = { .ardupin = 45, .port = 'F', .pin =  5 },
        [46] = { .ardupin = 46, .port = 'F', .pin =  6 },
        [47] = { .ardupin = 47, .port = 'F', .pin =  7 },
        [48] = { .ardupin = 48, .port = 'G', .pin =  0 },
        [49] = { .ardupin = 49, .port = 'G', .pin =  1 },
        [50] = { .ardupin = 50, .port = 'G', .pin =  2 },
        [51] = { .ardupin = 51, .port = 'G', .pin =  3 },
        [52] = { .ardupin = 52, .port = 'G', .pin =  4 },
        [53] = { .ardupin = 53, .port = 'G', .pin =  5 },
        [54] = { .ardupin = 54, .port = 'G', .pin =  6 },
        [55] = { .ardupin = 55, .port = 'G', .pin =  7 },
        [56] = { .ardupin = 56, .port = 'H', .pin =  0 },
        [57] = { .ardupin = 57, .port = 'H', .pin =  1 },
        [58] = { .ardupin = 58, .port = 'H', .pin =  2 },
        [59] = { .ardupin = 59, .port = 'H', .pin =  3 },
        [60] = { .ardupin = 60, .port = 'H', .pin =  4 },
        [61] = { .ardupin = 61, .port = 'H', .pin =  5 },
        [62] = { .ardupin = 62, .port = 'H', .pin =  6 },
        [63] = { .ardupin = 63, .port = 'H', .pin =  7 },
        [64] = { .ardupin = 64, .port = 'I', .pin =  0 },
        [65] = { .ardupin = 65, .port = 'I', .pin =  1 },
        [66] = { .ardupin = 66, .port = 'I', .pin =  2 },
        [67] = { .ardupin = 67, .port = 'I', .pin =  3 },
        [68] = { .ardupin = 68, .port = 'I', .pin =  4 },
        [69] = { .ardupin = 69, .port = 'I', .pin =  5 },
        [70] = { .ardupin = 70, .port = 'I', .pin =  6 },
        [71] = { .ardupin = 71, .port = 'I', .pin =  7 },
        [72] = { .ardupin = 72, .port = 'J', .pin =  0 },
        [73] = { .ardupin = 73, .port = 'J', .pin =  1 },
        [74] = { .ardupin = 74, .port = 'J', .pin =  2 },
        [75] = { .ardupin = 75, .port = 'J', .pin =  3 },
        [76] = { .ardupin = 76, .port = 'J', .pin =  4 },
        [77] = { .ardupin = 77, .port = 'J', .pin =  5 },
        [78] = { .ardupin = 78, .port = 'J', .pin =  6 },
        [79] = { .ardupin = 79, .port = 'J', .pin =  7 },
        [80] = { .ardupin = 80, .port = 'K', .pin =  0 },
        [81] = { .ardupin = 81, .port = 'K', .pin =  1 },
        [82] = { .ardupin = 82, .port = 'K', .pin =  2 },
        [83] = { .ardupin = 83, .port = 'K', .pin =  3 },
        [84] = { .ardupin = 84, .port = 'K', .pin =  4 },
        [85] = { .ardupin = 85, .port = 'K', .pin =  5 },
        [86] = { .ardupin = 86, .port = 'K', .pin =  6 },
        [87] = { .ardupin = 87, .port = 'K', .pin =  7 },
        [88] = { .ardupin = 88, .port = 'L', .pin =  0 },
        [89] = { .ardupin = 89, .port = 'L', .pin =  1 },
        [90] = { .ardupin = 90, .port = 'L', .pin =  2 },
        [91] = { .ardupin = 91, .port = 'L', .pin =  3 },
        [92] = { .ardupin = 92, .port = 'L', .pin =  4 },
        [93] = { .ardupin = 93, .port = 'L', .pin =  5 },
        [94] = { .ardupin = 94, .port = 'L', .pin =  6 },
        [95] = { .ardupin = 95, .port = 'L', .pin =  7 },
        [96] = { .ardupin = 96, .port = 'M', .pin =  0 },
        [97] = { .ardupin = 97, .port = 'M', .pin =  1 },
        [98] = { .ardupin = 98, .port = 'M', .pin =  2 },
        [99] = { .ardupin = 99, .port = 'M', .pin =  3 },

};

struct avr_irq_t *
get_ardu_irq(
		struct avr_t * avr,
		int ardupin,
		ardupin_t pins[])
{
	if (pins[ardupin].ardupin != ardupin) {
		printf("%s pin %d isn't correct in table\n", __func__, ardupin);
		return NULL;
	}
	struct avr_irq_t * irq = avr_io_getirq(avr,
			AVR_IOCTL_IOPORT_GETIRQ(pins[ardupin].port), pins[ardupin].pin);
	printf("%s %d -> %d (%s)\n",__func__,ardupin,irq->irq,irq->name);
	if (!irq) {
		printf("%s pin %d PORT%C%d not found\n", __func__, ardupin, pins[ardupin].port, pins[ardupin].pin);
		return NULL;
	}
	return irq;
}

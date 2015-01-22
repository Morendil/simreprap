# 
# 	Copyright 2008, 2012 Michel Pollet <buserror@gmail.com>
#
#	This file is part of simreprap.
#
#	simavr is free software: you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation, either version 3 of the License, or
#	(at your option) any later version.
#
#	simavr is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You should have received a copy of the GNU General Public License
#	along with simavr.  If not, see <http://www.gnu.org/licenses/>.

CC = gcc
target=	reprap
firm_src = ${wildcard atmega*.c}
firmware = ${firm_src:.c=.hex}

SIMAVR	= shared/simavr

IPATH = .
IPATH += src
IPATH += ${SIMAVR}/include
IPATH += ${SIMAVR}/simavr/sim
IPATH += ${SIMAVR}/examples/parts
IPATH += ${SIMAVR}/examples/shared

VPATH = src
VPATH += ${SIMAVR}/examples/parts
VPATH += ${SIMAVR}/examples/shared

# for the Open Motion Controller board
CPPFLAGS := -DMOTHERBOARD=91
CPPFLAGS += ${patsubst %,-I%,${subst :, ,${IPATH}}}

LDFLAGS += -lpthread -lutil -ldl
LDFLAGS += -Wl,-rpath ${SIMAVR}/simavr/${OBJ} -L${SIMAVR}/simavr/${OBJ} 
LDFLAGS += -lm

all: obj ${firmware} ${target}

include ${SIMAVR}/Makefile.common

board = ${OBJ}/${target}.elf

${board} : ${OBJ}/arduidiot_pins.o
${board} : ${OBJ}/button.o
${board} : ${OBJ}/uart_pty.o
${board} : ${OBJ}/thermistor.o
${board} : ${OBJ}/heatpot.o
${board} : ${OBJ}/stepper.o
${board} : ${OBJ}/${target}.o

build-simavr:
	$(MAKE) -C $(SIMAVR) CC="$(CC)" CFLAGS="$(CFLAGS)" build-simavr

${target}:  build-simavr ${board}
	@echo $@ done

clean: clean-${OBJ}
	rm -rf *.a *.axf ${target} *.vcd
	$(MAKE) -C $(SIMAVR)/simavr CC="$(CC)" CFLAGS="$(CFLAGS)" clean


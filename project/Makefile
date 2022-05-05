# makefile configuration
COMMON_OBJECTS		= main.o wdtInterruptHandler.o draw_shapes.o buzzer.o switches.o states.o
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: main_c.elf main_s.elf

#additional rules for files
main_c.elf: ${COMMON_OBJECTS} stateSelection_c.o 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

main_s.elf: ${COMMON_OBJECTS} stateSelection_s.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load_c: main_c.elf
	msp430loader.sh $^

load_s: main_s.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf \#* \~*

buzzer.o: buzzer.h
switches.o: switches.h
state.o: state.h swtiches.h draw_shapes.h
stateSelection_c.o: stateSelection_c.c
stateSelection_s.o: stateSelection_s.s

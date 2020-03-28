#makefile configuration
COMMON_OBJECTS =
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../project/h
LDFLAGS = -L/opt/ti/msp430_gcc/include

#switch compiler
CC = msp430-elf-gcc
AS = msp430-elf-as

all: main.elf

#additional rules for files
main.elf: ${COMMON_OBJECTS} main.o stateMachines.o led.o buzzer.o switches.o interrupts.o p2_interrupt_handler.o ../project/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf

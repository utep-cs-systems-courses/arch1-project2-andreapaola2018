#makefile configuration
COMMON_OBJECTS =
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../project/h
LDFLAGS = -L/opt/ti/msp430_gcc/include

#switch compiler
CC = msp430-elf-gcc
AS = msp430-elf-as

all: project.elf

#additional rules for files
project.elf: ${COMMON_OBJECTS} buzzer.o 

#ali reda
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I.
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC: .c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS: .s=.o)

all: embedded.bin

%.o: %.c
	$(CC)gcc.exe  -c  $(CFLAGS) $(INCS)    $< -o  $@

%.o: %.s
	$(CC)as.exe   -c -g  $<  -o  $@ 

embedded.elf: main.o  uart.o  startup.o
	$(CC)ld.exe   -T  linkerscript.ld  $(LIBS)   main.o startup.o 	uart.o  -o $@ -Map=output.map

embedded.bin: embedded.elf
	$(CC)objcopy.exe  -O   binary  $<   $@

clean:
	rm *.o

clean_all:
	rm *.o  *.elf *.bin
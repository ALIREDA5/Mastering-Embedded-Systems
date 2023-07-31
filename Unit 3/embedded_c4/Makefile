
CC= arm-none-eabi-
CFLAGS=  -mcpu=cortex-m4 -gdwarf-2
INCS=-I.
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC: .c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS: .s=.o)
Project_Name = lab4

all: $(Project_Name).bin

%.o: %.c
	$(CC)gcc.exe  -c  $(CFLAGS) $(INCS)    $< -o $@

%.o: %.s
	$(CC)as.exe   -c  $(CFLAGS)   $<  -o $@ 

$(Project_Name).elf: main.o   startup.o
	$(CC)ld.exe   -T  linkerscript.ld  $(LIBS)   main.o startup.o 	 -o $@ -Map=output.map

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe  -O   binary  $<   $@
	cp $(Project_Name).elf  $(Project_Name).axf
clean:
	rm *.o
clean_all:
	rm *.o  *.elf *.bin
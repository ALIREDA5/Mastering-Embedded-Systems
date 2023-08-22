
CC= arm-none-eabi-
CFLAGS=  -mcpu=cortex-m3 -gdwarf-2
INCS=-I.
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project_Name = Pressure_Controller

all: $(Project_Name).bin

%.o: %.c
	$(CC)gcc.exe  -c  $(CFLAGS) $(INCS)    $< -o $@

%.o: %.s
	$(CC)as.exe   -c  $(CFLAGS)   $<  -o $@ 

$(Project_Name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe   -T  linkerscript.ld  $(LIBS)   $(OBJ) $(ASOBJ)	 -o $@ -Map=output.map

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe  -O   binary  $<   $@
clean:
	rm *.o
clean_all:
	rm *.o  *.elf *.bin
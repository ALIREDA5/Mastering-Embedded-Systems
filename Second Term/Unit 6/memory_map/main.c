/*
 * main.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Ali Reda
 */
#include "stdint.h"
#include "stdio.h"

#pragma pack(1)

// Write 1 on pit 16 on ODR register
// Method 1: Using numeric memory address directly
#define GPIO_ODR 0x48000404

// Method 2: Casting an address to a pointer
#define GPIO_ODR *(0x48000404)

// Method 3: Casting to a pointer and then dereferencing it
#define GPIO_ODR *((volatile unsigned int *)0x48000404)

// Method 4: use structure, union and pointer for one register
struct  S_GPIO
{
	int bit1 : 1;
	int bit2 : 1;
	int bit3 : 1;
	int bit4 : 1;
	int bit5 : 1;
	int bit6 : 1;
	int bit7 : 1;
	int bit8 : 1;
};
    // union has shared area so it allow to read or write on register or any bit
union U_GPIO
{
	struct  S_GPIO bits;
	unsigned int reg;
};

// Method 5: use structures and pointers for all registers in a GPIO peripheral
struct SGPIO
{
	unsigned int MODER;
	unsigned int ODR;
	unsigned int ASCR;
	unsigned int IDR;
};

#define GPIOA  ((struct SGPIO *)0x48000000)
#define GPIOB  ((struct SGPIO *)0x48000400)
#define GPIOC  ((struct SGPIO *)0x48000800)

int main()
{
	// Method 1: Using numeric memory address directly
	*((volatile unsigned int *)GPIO_ODR)|=1<<16;

	// Method 2: Casting an address to a pointer
	((volatile unsigned int *)GPIO_ODR)|=1<<16;

	// Method 3: Casting to a pointer and then dereferencing it
	GPIO_ODR|=1<<16;

	// Method 4: use structure, union and pointer for one register
	volatile union U_GPIO* ps= (union U_GPIO* )GPIO_ODR;
	ps->bits.bit1=1;

	// Method 5: use structures and pointers for all registers in a GPIO peripheral
	GPIOA->ODR=(1<<16);







	return 0;
}

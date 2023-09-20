/*
 * GccApplication1.c
 *
 * Created: 9/18/2023 6:55:29 PM
 * Author : Ali Reda
 */ 

#define F_CPU 8000000ul


#include "stdint.h"
#include "MCAL/DIO.h"



int main(void)
{
    Init_Pins();
	uint8_t flag1=0;
	while(1)
	{
		DIO_Writepin(PINA0,LOW);
		DIO_Writepin(PINA2,LOW);
		DIO_Writepin(PINA4,LOW);
	if (DIO_Readpin(PINC0)==0 && flag1==0)
	{
		DIO_Writepin(PINA0,HIGH);
		while(DIO_Readpin(PINC0)==0);
		flag1=1;
	}
 	if (DIO_Readpin(PINC0)==0 && flag1==1)
 	{
 	 	DIO_Writepin(PINA2,HIGH);
 	 	while(DIO_Readpin(PINC0)==0);
 	 	flag1=2;
 	}
	if (DIO_Readpin(PINC0)==0 && flag1==2)
	{
	 	DIO_Writepin(PINA4,HIGH);
	 	while(DIO_Readpin(PINC0)==0);
	 	flag1=0;
	}
	// delay
	for (uint16_t i=0; i<300 ; i++);
	}
}



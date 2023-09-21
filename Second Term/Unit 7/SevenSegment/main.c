/*
 * GccApplication1.c
 *
 * Created: 9/18/2023 6:55:29 PM
 * Author : Ali Reda
 */ 


				/*----------------- Libraries and Definitions ------------*/
#define F_CPU 8000000ul


#include "stdint.h"
#include <util/delay.h>
#include "MCAL/DIO.h"
#include "HAL/SevenSegment.h"
#include "MCAL/EXTI.h"


				/*--------------------- Functions Prototypes ---------------------------*/
// this program counts from 99 to 00 through 2 seven-segment
// interrupts counting by 2 leds toggling
void  Led0(void);
void  Led1(void);

				/*-------------------------- The Main Function ----------------------------*/
int main(void)
{
    Init_Pins();
	// enable global interrupt
	sei();
				/*------------- External Interrupt INT0 Initialization -------------*/
	// enable EXI 0
	EXI_Enable(EXI_0);
	// rising edge triggering
	EXI_TriggerEdge(EXI_0,RISING_EDGE);
				/*------------- External Interrupt INT1 Initialization -------------*/
	// enable EXI 1
	EXI_Enable(EXI_1);
	// FALLING EDGE triggering
	EXI_TriggerEdge(EXI_1,FALLING_EDGE);
	
	//  Ex.interrupt --> it calls led fun to toggle led 
	EXI_SetCallBack(EXI_0,Led0);
	EXI_SetCallBack(EXI_1,Led1);
	
	while(1)
	{	
		int8_t i,j;
		for (j=9; j>=0 ; j--)
		{
			
			for (i=9; i>=0; i--)
			{
				
					// enable seven segment 1
					DIO_Writepin(PINC2,HIGH);
					// disable seven segment 2
					DIO_Writepin(PINC3,LOW);
					// write second digit
					Write_Value_4MSB(PC,i);
					_delay_ms(50);
					
					// enable seven segment 2
					DIO_Writepin(PINC3,HIGH);
					// disable seven segment 1
					DIO_Writepin(PINC2,LOW);
					// write first digit
					Write_Value_4MSB(PC,j);
					_delay_ms(50);
			}
			_delay_ms(50);
		}
	}

}
					/*--------------------- Interrupt Functions Definitions  ---------------------------*/
void  Led0(void)
{
	for (volatile uint8_t i=0 ; i<100; i++)
	{
		DIO_Toggle(PIND7);
		_delay_ms(100);
	}	
}

void  Led1(void)
{
	for (volatile uint8_t i=0 ; i<10; i++)
	{
		DIO_Toggle(PIND6);
		_delay_ms(100);	
	}
}

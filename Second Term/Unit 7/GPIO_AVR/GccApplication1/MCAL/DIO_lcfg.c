/*
 * DIO_lcfg.c
 *
 * Created: 9/20/2023 11:34:06 PM
 *  Author: Ali Reda
 */ 
#include "DIO.h"
const DIO_PINstatus_type PinStatusArray[32]={
	/*PORTA*/
	output,
	infree,
	output,
	infree,
	output,
	infree,
	infree,
	infree,
	/*PORTB*/
	infree,
	infree,
	infree,
	infree,
	infree,
	infree,
	infree,
	infree,
	/*PORTC*/
	inplup,
	output,
	output,
	output,
	output,
	output,
	output,
	output,
	/*PORTD*/
	infree,
	infree,
	infree,
	infree,
	infree,
	infree,
	infree,
	infree,
};
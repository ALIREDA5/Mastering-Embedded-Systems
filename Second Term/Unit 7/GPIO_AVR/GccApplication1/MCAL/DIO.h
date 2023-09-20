/*
 * DIO.h
 *
 * Created: 9/20/2023 11:21:51 PM
 *  Author: Ali Reda
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../Utils.h"
#include "../MemoryMap.h"
#include "stdint.h"
#define pins_per_port  8

typedef enum
{
	HIGH,
	LOW
}DIO_PIN_voltagetype;

typedef enum{
	PINA0=0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
Total_Pins} DIO_PIN_type;

typedef enum{
	infree=0,
	inplup,
	output
}DIO_PINstatus_type;

typedef enum{
	PA,
	PB,
	PC,
	PD
}DIO_Port_type;

extern const DIO_PINstatus_type PinStatusArray[32];

void Init_Pins(void);
void DIO_Writepin(DIO_PIN_type pin,DIO_PIN_voltagetype volt);
DIO_PIN_voltagetype DIO_Readpin(DIO_PIN_type pin);
void DIO_Toggle(DIO_PIN_type pin);
void Write_Value_4LSB(DIO_Port_type port, uint8_t value);
void Write_Value_4MSB(DIO_Port_type port, uint8_t value);
void DIO_Writeport(DIO_Port_type port,uint8_t data);
uint8_t DIO_Readport(DIO_Port_type port);
void DIO_Initpin(DIO_PIN_type pin, DIO_PINstatus_type status);
void DIO_InitPort(DIO_Port_type port,DIO_PINstatus_type status);




#endif /* DIO_H_ */
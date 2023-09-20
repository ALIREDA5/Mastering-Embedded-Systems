/*
 * DIO.c
 *
 * Created: 9/20/2023 11:21:33 PM
 *  Author: Ali Reda
 */ 

#include "DIO.h"
#include "stdint.h"

// initiate pin
void DIO_Initpin(DIO_PIN_type pin, DIO_PINstatus_type status){
	DIO_Port_type port=pin/8;
	uint8_t pin_num=pin%8;
	switch(status)
	{
		case  inplup:
		switch(port){
			case PA :
			CLEAR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLEAR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLEAR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLEAR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
		case  infree:
		switch(port){
			case PA :
			CLEAR_BIT(DDRA,pin_num);
			CLEAR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLEAR_BIT(DDRB,pin_num);
			CLEAR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLEAR_BIT(DDRC,pin_num);
			CLEAR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLEAR_BIT(DDRD,pin_num);
			CLEAR_BIT(PORTD,pin_num);
			break;
		}
		break;
		
		case  output:
		switch(port){
			case PA :
			SET_BIT(DDRA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			break;
		}
		break;
		
	}
	
};


void DIO_Writepin(DIO_PIN_type pin,DIO_PIN_voltagetype volt)
{
	DIO_Port_type port=pin/8;
	uint8_t pin_num=pin%8;
	if(volt==HIGH){
		
		switch(port){
			case PA :
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
			
		}
	}
	else if(volt==LOW){
		switch(port){
			case PA :
			CLEAR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLEAR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLEAR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLEAR_BIT(PORTD,pin_num);
			break;
		}
	}
	
	
}

DIO_PIN_voltagetype DIO_Readpin(DIO_PIN_type pin){
	uint8_t res=0;
	DIO_Port_type port=pin/8;
	uint8_t pin_num=pin%8;
	switch(port){
		case PA:
		res= READ_BIT(PINA,pin_num);
		break;
		case PB:
		res= READ_BIT(PINB,pin_num);
		break;
		case PC:
		res=READ_BIT(PINC,pin_num);
		break;
		case PD:
		res=READ_BIT(PIND,pin_num);
		break;
	}
	return res;
}

void DIO_Toggle(DIO_PIN_type pin){
	DIO_Port_type port=pin/8;
	uint8_t pin_num=pin%8;
	switch(port)
	{
		case PA:
		TOGGLE_BIT(PORTA,pin_num);
		break;
		case PB:
		TOGGLE_BIT(PORTB,pin_num);
		break;
		case PC:
		TOGGLE_BIT(PORTC,pin_num);
		break;
		case PD:
		TOGGLE_BIT(PORTD,pin_num);
		break;
		
	}
}

void DIO_Writeport(DIO_Port_type port,uint8_t data){
	switch(port)
	{
		case PA:
		PORTA=data;
		break;
		case PB:
		PORTB=data;
		break;
		case PC:
		PORTC=data;
		break;
		case PD:
		PORTD=data;
		break;
	}
}

uint8_t DIO_Readport(DIO_Port_type port){
	uint8_t dataout=0;
	switch(port)
	{
		case PA:
		dataout=PORTA;
		break;
		case PB:
		dataout=PORTB;
		break;
		case PC:
		dataout=PORTC;
		break;
		case PD:
		dataout=PORTD;
		break;
	}
	return dataout;
}
void SET_Value_4LSB(DIO_Port_type port, uint8_t value){
	switch(port)
	{
		case PA:
		PORTA&=0xF0;
		PORTA|=value;
		break;
		case PB:
		PORTB&=0xF0;
		PORTB|=value;
		break;
		case PC:
		PORTC&=0xF0;
		PORTC|=value;
		break;
		case PD:
		PORTD&=0xF0;
		PORTD|=value;
		break;
	}

}
void SET_Value_4MSB(DIO_Port_type port, uint8_t value){
	switch(port)
	{
		case PA:
		PORTA&=0x0F;
		PORTA|=value<<4;
		break;
		case PB:
		PORTB&=0x0F;
		PORTB|=value<<4;
		break;
		case PC:
		PORTC&=0x0F;
		PORTC|=value<<4;
		break;
		case PD:
		PORTD&=0x0F;
		PORTD|=value<<4;
		break;
	}
}


void Init_Pins(void)
{
	for(DIO_PIN_type i=PINA0;i<Total_Pins;i++)
	{
		DIO_Initpin(i, PinStatusArray[i]);
	}
}

/*
void DIO_InitPort(DIO_Port_type port,DIO_PINstatus_type status){
	switch(port)
	{
		case PA:
		for(DIO_PIN_type i=PINA0;i<pins_per_port;i++)
		{
			DIO_Initpin(i,status);
		}
		break;
		case PB:
		for(DIO_PIN_type i=PINB0;i<pins_per_port;i++)
		{
			DIO_Initpin(i,status);
		}
		break;
		case PC:
		for(DIO_PIN_type i=PINC0;i<pins_per_port;i++)
		{
			DIO_Initpin(i,status);
		}
		break;
		case PD:
		for(DIO_PIN_type i=PIND0;i<pins_per_port;i++)
		{
			DIO_Initpin(i,status);
		}
		break;
	}
}
*/
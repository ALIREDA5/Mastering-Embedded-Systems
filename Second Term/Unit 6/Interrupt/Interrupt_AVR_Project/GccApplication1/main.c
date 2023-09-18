/*
 * GccApplication1.c
 *
 * Created: 9/18/2023 6:55:29 PM
 * Author : Ali Reda
 */ 

#define F_CPU 8000000ul


#include <avr/interrupt.h>
#include <util/delay.h>

// Macros
#define SET_BIT(reg,bit) (reg=reg|(1<<bit))
#define CLEAR_BIT(reg,bit) (reg=reg&(~(1<<bit)))
#define READ_BIT(reg,bit) ((reg>>bit)&1)
#define TOGGLE_BIT(reg,bit)  (reg=reg^(1<<bit))
#define WRITE_BIT(reg,bit,value)  (reg=(reg&(~(1<<bit)))|(value<<bit))

 /*External Interrupt registers */
 
// External Interrupt is activated by the external pin INT2
#define MCUCSR   (*(volatile unsigned char*)0x54)
#define ISC2 6  // If ISC2 is written to zero, a falling edge on INT2 activates the interrupt.
				// If ISC2 is written to one, a rising edge on INT2 activates the interrupt.

//  MCU Control Register controls bits for interrupt sense (edge)
#define MCUCR   (*(volatile unsigned char*)0x55)
#define ISC00 0  
#define ISC01 1  
#define ISC10 2
#define ISC11 3

// to enable interrupt for different pins
#define GICR     (*(volatile unsigned char*)0x5B)
#define INT1 7   // if INT1 bit is set (one), external pin interrupt is enabled
#define INT0 6   // if INT0 bit is set (one), external pin interrupt is enabled
#define INT2 5   // if INT2 bit is set (one), external pin interrupt is enabled

// to set flag when interrupt happens in ISR
#define GIFR    (*(volatile unsigned char*)0x5A)
#define INTF1 7  // When an edge or logic change on the INT1 pin triggers an interrupt request, INTF1 becomes set(one).
#define INTF0 6  // the flag can be cleared by writing a logical one to it.
#define INTF2 5

	/* GPIO registers */
#define PORTA (*(volatile unsigned char*)0x3B)
#define DDRA (*(volatile unsigned char*)0x3A)
#define PINA (*(volatile unsigned char*)0x39)
#define PORTB (*(volatile unsigned char*)0x38)
#define DDRB (*(volatile unsigned char*)0x37)
#define PINB (*(volatile unsigned char*)0x36)
#define PORTC (*(volatile unsigned char*)0x35)
#define DDRC (*(volatile unsigned char*)0x34)
#define PINC (*(volatile unsigned char*)0x33)
#define PORTD (*(volatile unsigned char*)0x32)
#define DDRD (*(volatile unsigned char*)0x31)
#define PIND (*(volatile unsigned char*)0x30)

	/* initialize external interrupt */
void Init_EXI()
{
	// enable external pins for INT0,1,2
	SET_BIT(GICR,INT1);
	SET_BIT(GICR,INT0);
	SET_BIT(GICR,INT2);
	// Any logical change on INT0
	SET_BIT(MCUCR,ISC00);
	CLEAR_BIT(MCUCR,ISC01);
	// rising edge on INT1
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	// Falling edge on INT2
	CLEAR_BIT(MCUCSR,ISC2);
}

int main(void)
{
	
	// enable global interrupt
	sei();
	Init_EXI();
	// set pins as output
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
	
    
    while (1) 
    {
		// reset output pins
		CLEAR_BIT(PORTD,5);
		CLEAR_BIT(PORTD,6);
		CLEAR_BIT(PORTD,7);
    }
}

ISR(INT0_vect)
{
	SET_BIT(PORTD,5);
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	SET_BIT(PORTD,6);
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	SET_BIT(PORTD,7);
	_delay_ms(1000);
}


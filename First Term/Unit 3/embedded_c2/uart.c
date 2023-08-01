#include "UART.h"
//uart data register
#define  UART0DR    *((volatile unsigned int* const)((unsigned int *)0x101f1000))
void UART_SEND_STRING (unsigned char *p_tx_string)
{
	while(*p_tx_string != '\0')
	{
		// loop until the end of the string
		UART0DR = (unsigned int )(*p_tx_string );
		p_tx_string ++;
	}
}


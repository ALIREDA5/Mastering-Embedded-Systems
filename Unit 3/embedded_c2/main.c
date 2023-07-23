#include "UART.h"
unsigned char str[100]= "learn-in-depth : <Ali Reda>";
int main(void)
{
	UART_SEND_STRING(str);


}

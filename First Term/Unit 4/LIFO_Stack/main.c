/*
 * main.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Ali Reda
 */


#include "lifo1.h"
#include "stdio.h"
#include "stdlib.h"

// Test program to LIFO
void Display(StackEntry s)
{
	printf("%d",s);
}
int main()
{
    int x=5;
	int y=0;
	LIFO_BUF_t uart_buf;
	LIFO_INIT(&uart_buf);
	printf("add x to Lifo\n");
	if(LIFO_ADD_ITEM(&uart_buf,x)==LIFO_full)
	{
		printf("Lifo is full");
	}

	if(LIFO_COPY_ITEM(&uart_buf, &y)==LIFO_empty)
	{
		printf("Lifo is empty");
	}
	printf("copy %d to y\n ", y);
	LIFO_Traverse(&uart_buf, &Display);



	return 0;
}


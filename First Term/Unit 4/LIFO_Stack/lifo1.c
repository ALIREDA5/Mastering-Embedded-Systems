/*
 * lifo.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Ali Reda
 */
#include "lifo1.h"
#include "stdio.h"
#include "stdlib.h"

// push element to top of stack
buffer_status_t  LIFO_ADD_ITEM(LIFO_BUF_t *buf, StackEntry item)
{
	if((buf->base)!=NULL && (buf->head)!=NULL){
		buf->buffer[buf->count]=item;
		buf->count++;
		buf->head++;
		return LIFO_no_error;
	}
	return LIFO_full;
}
// pop element from top of stack
buffer_status_t  LIFO_POP_ITEM(LIFO_BUF_t *buf, StackEntry *item)
{
	if((buf->base)!=NULL && (buf->head)!=NULL){
		buf->count--;
		buf->head--;
		*item=buf->buffer[buf->count];
		return LIFO_no_error;
	}
	return LIFO_empty;
}
// copy top item
buffer_status_t  LIFO_COPY_ITEM(LIFO_BUF_t *buf, StackEntry *item)
{
	if((buf->base)!=NULL && (buf->head)!=NULL){
		*item=buf->buffer[(buf->count) -1];
		return LIFO_no_error;
	}
	return LIFO_empty;
}
// initialize Stack
void  LIFO_INIT(LIFO_BUF_t *buf)
{
	buf->length=MAXSTACK;
	buf->count=0;
	buf->base=buf->buffer;
	buf->head=buf->buffer;
}
void LIFO_Traverse(LIFO_BUF_t *buf, void(*pf)(StackEntry e))
{
	int i;
	for(i=(buf->count)-1; i>=0; i--)
	{
		(*pf)(buf->buffer[i]);
	}
}

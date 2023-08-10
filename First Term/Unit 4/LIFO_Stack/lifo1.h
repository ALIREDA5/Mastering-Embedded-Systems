/*
 * lifo.h
 *
 *  Created on: Aug 9, 2023
 *      Author: Ali Reda
 */

#ifndef LIFO_H_
#define LIFO_H_

#define  MAXSTACK  100
typedef   int   StackEntry;

typedef struct LIFO{
	 int length;
	 int count;
	int *base;
	int *head;
	StackEntry buffer[MAXSTACK];
}LIFO_BUF_t;

typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_not_full,
	LIFO_empty,
	LIFO_not_empty,
	LIFO_null
}buffer_status_t;

buffer_status_t  LIFO_ADD_ITEM(LIFO_BUF_t *buf,StackEntry item);
buffer_status_t  LIFO_POP_ITEM(LIFO_BUF_t *buf,StackEntry *item);
buffer_status_t  LIFO_COPY_ITEM(LIFO_BUF_t *buf, StackEntry *item);
void  LIFO_INIT(LIFO_BUF_t *buf);
void LIFO_Traverse(LIFO_BUF_t *buf, void(*pf)(StackEntry e));

#endif /* LIFO_H_ */

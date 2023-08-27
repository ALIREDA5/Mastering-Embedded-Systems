/*
 * FIFO.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Ali Reda
 */
#include <stdio.h>
#include <stdlib.h>
#include "FIFO.h"
#include "string.h"

// initialize Queue fun
Queue_Status  Queue_Create(Queue *pq)
{
	pq->head=pq->entry;
	pq->base=pq->entry;
	pq->tail=pq->entry;
	pq->size=0;
	return Queue_no_error;
}

// check if Queue is full
Queue_Status  Queue_Full(Queue *pq)
{
	if(pq->size == MaxQueue)
		return Queue_full;
	else
		return Queue_not_full;
}

void  Queue_SWAP(Queue* pq, Queue_Type* e1)
{
	Queue_Type temp;
	temp.GPA=e1->GPA;
	int i=0;
	while(i < 10)
	{
		temp.course_ID[i]=e1->course_ID[i];
		i++;
	}
	temp.ncourses=e1->ncourses;
	temp.student_ID=e1->student_ID;
	strcpy(temp.fname,e1->fname);
	strcpy(temp.lname,e1->lname);

	e1->GPA=pq->tail->GPA;
	i=0;
	while(i < 10)
	{
		e1->course_ID[i]=pq->tail->course_ID[i];
		i++;
	}
	e1->ncourses=pq->tail->ncourses;
	e1->student_ID=pq->tail->student_ID;
	strcpy(e1->fname,pq->tail->fname);
	strcpy(e1->lname,pq->tail->lname);

	pq->tail->GPA=temp.GPA;
	i=0;
	while(i < 10)
	{
		pq->tail->course_ID[i]=temp.course_ID[i];
		i++;
	}
	pq->tail->ncourses=temp.ncourses;
	pq->tail->student_ID=temp.student_ID;
	strcpy(pq->tail->fname,temp.fname);
	strcpy(pq->tail->lname,temp.lname);

}

// enqueue an element
Queue_Status  Queue_Append(Queue* pq, Queue_Type e)
{

	if(pq->base == pq->entry)
	{
		*(pq->head)=e;
		pq->head ++;
		if(pq->size < MaxQueue)
		{
			pq->size ++;
		}
		else
		{
			pq->head=pq->base;
		}
		return Queue_no_error;
	}
	else
	{
		printf("Failed to enqueue\n");
		return  Queue_fail;
	}
}

// get element from queue
Queue_Status  Queue_Serve(Queue *pq, Queue_Type *e)
{
	if(pq->base == pq->entry && Queue_Empty(pq)==Queue_non_empty)
	{
		*e=*(pq->tail);
		pq->tail++;
		pq->size--;
		if(pq->tail == pq->base + MaxQueue*sizeof(Queue_Type))
			pq->tail=pq->base;
		return Queue_no_error;
	}
	else
	{
		printf("Failed to dequeue\n");
		return  Queue_fail;
	}
}

Queue_Status  Queue_Delete_Element( Queue *pq, Queue_Type *e, int pos)
{
	for(int n=pos-1; n<(pq->size)-1; n++)
	{
		pq->entry[n]=pq->entry[n+1];
	}
	*e=pq->entry[pos-1];
	pq->size--;
	return Queue_no_error;
}

int Queue_Size (Queue *pq)
{
	return pq->size;
}

// check if queue is empty
Queue_Status  Queue_Empty(Queue *pq)
{
	if(pq->size == 0)
		return Queue_empty;
	else
		return Queue_non_empty;
}

// delete all queue elements
Queue_Status  Queue_clear(Queue *pq)
{
	pq->head=pq->base;
	pq->tail=pq->base;
	pq->size=0;
	return Queue_no_error;
}

// allow the user to go through all elements and apply any fun on the queue
void Queue_Traverse1(Queue* pq, void(*pf)(Queue_Type* e, void* x), void* x)
{

	if(pq->size==0) printf("Queue is empty\n");
	Queue_Type *pos;
	for(pos=pq->tail; pos!=pq->head; pos++)
	{
		(*pf)(pos, x);
		if(pos==pq->base+MaxQueue*sizeof(Queue_Type))
			pos=pq->base;
	}
}

void Queue_Traverse0(Queue* pq, void(*pf)(Queue_Type* e))
{

	if(pq->size==0) printf("Queue is empty\n");
	Queue_Type *pos;
	for(pos=pq->tail; pos!=pq->head; pos++)
	{
		(*pf)(pos);
		if(pos==pq->base+MaxQueue*sizeof(Queue_Type))
			pos=pq->base;
	}

}


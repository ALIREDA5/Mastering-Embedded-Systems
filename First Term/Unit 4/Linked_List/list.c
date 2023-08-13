/*
 * list.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Ali Reda
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void  List_Create(List_t *pq)
{
	pq->head=NULL;
	pq->size=0;
}

void  List_Destroy(List_t *pq)
{
	Node_t *pn;
	while(pq->head)
	{
		pn=pq->head->next;
		free(pq->head);
		pq->head=pn;
	}
	pq->size=0;
}

List_Status  List_Insert_Element(int pos, List_t *pq, Entry_t e)
{
	Node_t *pn =(Node_t*)malloc(sizeof(Node_t));
	if(pn != NULL)
	{
		pn->entry=e;
			pn->next=NULL;
			Node_t *q;
			if(pos==0)
			{
				pn->next=pq->head;
				pq->head=pn;
			}
			else
			{
				int i;
				for(q=pq->head, i=0; i<(pq->size)-(pos+1); i++)
					q=q->next;
				pn->next=q->next;
				q->next=pn;
			}
			pq->size++;
			return List_no_error;
	}
	else
	{
		return List_fail;
	}


}

List_Status  List_Add_Element(List_t *pq, Entry_t e)
{
	Node_t *pn =(Node_t*)malloc(sizeof(Node_t));
	if(pn != NULL)
	{
		pn->entry=e;
		pn->next=pq->head;
		pq->head=pn;
		pq->size++;
		return List_no_error;
	}
	else
	{
		return List_fail;
	}


}
List_Status  List_Delete_Element(int pos, List_t *pq, Entry_t *e)
{
	 int i;
	 Node_t *pn, *temp;

	 if(pos==0)
	 {
		 *e=pq->head->entry;
		 temp=pq->head->next;
		 free(pq->head);
		 pq->head=temp;
	 } // it works also for one node in the list
	 else
	 {
		 for(pn=pq->head, i=0; i<(pq->size)-(pos+2); i++)
		 {
			 pn=pn->next;
		 }
		 *e=pn->next->entry;
		 temp=pn->next->next;
		 free(pn->next);
		 pn->next=temp;
	 }
	 pq->size --;
	 return List_no_error;
}

List_Status  List_Empty(List_t *pq)
{
	if(pq->size==0) return List_empty;
	else return List_non_empty;
}

List_Status  List_Full(List_t *pq)
{
	return List_no_error;
}

int  List_Size(List_t *pq)
{
	return pq->size;
}

List_Status  List_Traverse(List_t *pq, void(*pf)(Entry_t e))
{
	Node_t *pn= pq->head;
	while(pn)
	{
		(*pf)(pn->entry);
		pn=pn->next;
	}
	return List_no_error;
}


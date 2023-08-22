
#include "fifo.h"
#include "stdio.h"
#include "stdlib.h"

// initialize the queue
void  Queue_Create(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
// add element to queue
void  Queue_Append(Queue *pq, Queue_Type e)
{
        if(pq->rear == MaxQueue-1)
        pq->rear=0;
    else
        pq->rear++;
    pq->entry[pq->rear]= e;
    pq->size++;
}
void  Queue_Serve(Queue *pq, Queue_Type *e)
{
    if( Queue_Empty(&pq) == Queue_non_empty){
        *e=  pq->entry[pq->front] ;
        if(pq->front == MaxQueue-1)
        pq->front=0;
    else
        pq->front++;
    pq->size--;
    return Queue_no_error;
    }
    else
        return Queue_empty;
}
Queue_Status Queue_Empty(Queue *pq)
{
    if(pq->size == 0)
        return Queue_empty;
    else
        return Queue_non_empty;
}
void Queue_Traverse(Queue *pq, void(*pf)(Queue_Type e))
{
        int x ,s;
        for(x=pq->front, s=1; s<=pq->size; s++)
        {
             (*pf)(pq->entry[x]) ;
             x=(x+1)%MaxQueue;
        }
}

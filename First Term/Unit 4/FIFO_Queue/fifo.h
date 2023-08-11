#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

#define MaxQueue  20
typedef  int Queue_Type;

// FIFO data types
typedef struct que {
    Queue_Type* head;
    Queue_Type* tail;
    Queue_Type* base;
    int size;
    Queue_Type entry[MaxQueue];
}Queue;

// Queue status
typedef enum{
Queue_no_error,
Queue_full,
Queue_not_full,
Queue_empty,
Queue_non_empty,
Queue_fail,
Queue_un_init
}Queue_Status;

// FIFO APIs
Queue_Status  Queue_Create(Queue *pq);
Queue_Status  Queue_Append(Queue *pq, Queue_Type e);
Queue_Status  Queue_Serve(Queue *pq, Queue_Type *e);
Queue_Status  Queue_Empty(Queue *pq);
Queue_Status  Queue_clear(Queue *pq);
Queue_Status  Queue_Full(Queue *pq);
void  Queue_Traverse(Queue *pq, void(*pf)(Queue_Type e));


#endif // FIFO_H_INCLUDED

#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

#define MaxQueue  20
typedef  int Queue_Type;

typedef struct queue {
    int front;
    int rear;
    int size;
    Queue_Type entry[MaxQueue];
}Queue;

typedef enum{
Queue_no_error,
Queue_empty,
Queue_non_empty,
Queue_un_init
}Queue_Status;

void  Queue_Create(Queue *pq);
void  Queue_Append(Queue *pq, Queue_Type e);
void  Queue_Serve(Queue *pq, Queue_Type *e);
Queue_Status Queue_Empty(Queue *pq);
void  Queue_Traverse(Queue *pq, void(*pf)(Queue_Type e));


#endif // FIFO_H_INCLUDED

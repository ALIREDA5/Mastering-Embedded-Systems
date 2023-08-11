#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

// Display fun
void display(Queue_Type e)
{
    printf("element = %d\n", e);
}
int main()
{
    int y;
    Queue q;
    Queue_Create(&q);
    for(int i=1; i<4 ; i++)
    {
        Queue_Append(&q, i);
    }
    Queue_Serve(&q, &y);
    Queue_Traverse(&q, &display);
    Queue_clear(&q);
    Queue_Traverse(&q, &display);
    return 0;
}

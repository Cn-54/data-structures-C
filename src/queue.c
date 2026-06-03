#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

struct queue{
    int *items;
    int front;
    int back;
    int size;
};

que *createEmptyQueue(int size){
    que *q = malloc(sizeof(que));

    q->items = malloc(size * sizeof(int));
    q->size = size;
    q->front = -1;
    q->back = -1;

    return q;
}

static int isempty(que *q){
    return q->front == -1;
}
static int isfull(que *q){
    return q->back == q->size-1;
}

int enQueue(que *q, int item){
    if(isfull(q)){
        if(q->front > 0){
            int j = 0;
            for(int i = q->front; i <= q->back; i++){
                q->items[j++] = q->items[i];
            }

            q->back = q->back - q->front;
            q->front = 0;
        }
        else {
            return 0;
        }
    }

    if(q->front == -1)
        q->front = 0;

    q->back++;
    q->items[q->back] = item;

    return 1;
}

int deQueue(que *q, int *var){
    if(isempty(q))
        return 0;
    else{
        *var = q->items[q->front];
        q->front++;
        if(q->front>q->back)
            q->front = q->back = -1;
        return 1;
    }
}

void printQueue(que *q){
    if(isempty(q))
        printf("Queue is Empty");
    else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = q->front; i <= q->back; i++)
      printf("%d  ", q->items[i]);
  }
  printf("\n");
}
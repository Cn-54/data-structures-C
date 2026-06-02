#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct queue que ;
que *createEmptyQueue(int maxSize);
int enQueue(que *q, int item);
int deQueue(que *q,int *var);
void destroyQueue(que *q);
void printQueue(que *q);

#endif
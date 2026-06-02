#include "queue.h"
#include "stack.h"
#include "queue.h"

int main(){
    st *stack = createEmptyStack(10);
    push(stack,10);
    push(stack,15);

    printStack(stack);

    que *queue = createEmptyQueue(3);
    enQueue(queue,1);
    enQueue(queue,2);
    enQueue(queue,3);
    enQueue(queue,4);
    printQueue(queue);
    int var;
    deQueue(queue, &var);
    deQueue(queue, &var);
    enQueue(queue,5);
    printQueue(queue);

    return 0;
}
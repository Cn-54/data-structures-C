#include "stack.h"

int main(){
    st *stack = createEmptyStack(10);
    push(stack,10);
    push(stack,15);

    printStack(stack);


    return 0;
}
#ifndef STACK_H_
#define STACK_H_

typedef struct stack st ;
st *createEmptyStack(int maxSize);
int push(st *s, int item);
int pop(st *s,int *var);
int peek(st *s, int *var);
void destroyStack(st *s);
void printStack(st *s);

#endif
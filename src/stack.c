#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


struct stack {
    int *items;
    int top;
    int size;
};


st *createEmptyStack(int maxSize)
{
    st *s = malloc(sizeof(st));

    s->items = malloc(maxSize * sizeof(int));
    s->size = maxSize;
    s->top = -1;

    return s;
}

int isempty(st *s){
    if(s->top == -1)
        return 1;
    else
        return 0;
}

int isfull(st *s){
    if(s->top == s->size-1)
        return 1;
    else
        return 0;
}

int push(st *s, int item){
    if(isfull(s))
        return 0;
    else{
        s->top++;
        s->items[s->top] = item;
        return 1;
    }
}

int pop(st *s,int *var){
    if(isempty(s)){
        return 0;
    }
    else{
        *var = s->items[s->top];
        s->top--;
        return 1;
    }
}

int peek(st *s, int *var)
{
    if(isempty(s))
        return 0;

    *var = s->items[s->top];
    return 1;
}

void destroyStack(st *s)
{
    free(s->items);
    free(s);
}

void printStack(st *s) {
  printf("Stack: ");
  for (int i = 0; i < s->top+1; i++) {
    printf("%d ", s->items[i]);
  }
  printf("\n");
}
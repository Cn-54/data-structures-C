#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
    int value;
    struct node *next;
};
struct list{
    struct node *head;
    struct node *tail;
    int size;
};

ll *createLinkedList(){
    ll *l = malloc(sizeof(ll));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return l;
}

void append(struct list *l, int value){
    node *new = malloc(sizeof(node));
    new->value = value;
    new->next = NULL;

    if(l->head == NULL){
        l->head = new;
        l->tail = new;
    }
    else {
        l->tail->next = new;
        l->tail = new;
    }

    l->size++;
}

void prepend(ll *l, int value){
    node *new = malloc(sizeof(node));

    new->value = value;
    new->next = l->head;

    if(l->head == NULL){
        l->tail = new;
    }

    l->head = new;
    l->size++;
}

void deleteHead(ll *l){
    if(l->head == NULL)
        return;

    node *temp = l->head;

    l->head = l->head->next;

    if(l->head == NULL){
        l->tail = NULL;
    }

    free(temp);
    l->size--;
}

void deleteTail(ll *l){
    if(l->head == NULL)
        return;

    if(l->head == l->tail){
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        l->size--;
        return;
    }

    node *temp = l->head;

    while(temp->next != l->tail){
        temp = temp->next;
    }

    free(l->tail);
    l->tail = temp;
    l->tail->next = NULL;

    l->size--;
}

void deleteValue(ll *l, int value){
    if(l->head == NULL)
        return;

    node *curr = l->head;
    node *prev = NULL;

    while(curr != NULL){
        if(curr->value == value){

            if(curr == l->head){
                l->head = curr->next;

                if(l->head == NULL){
                    l->tail = NULL;
                }
            }
            else {
                prev->next = curr->next;

                if(curr == l->tail){
                    l->tail = prev;
                }
            }

            free(curr);
            l->size--;
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}

node *find(ll *l, int value){
    node *curr = l->head;

    while(curr != NULL){
        if(curr->value == value)
            return curr;
        curr = curr->next;
    }

    return NULL;
}

void clear(ll *l){
    node *curr = l->head;
    node *next = NULL;

    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

void destroyList(ll *l){
    clear(l);
    free(l);
}

void printList(ll *l){
    node *curr = l->head;

    while(curr != NULL){
        printf("%d -> ", curr->value);
        curr = curr->next;
    }

    printf("NULL\n");
}
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


typedef struct node node;
typedef struct list ll;

ll *createLinkedList(void);
void clear(ll *l);
void destroyList(ll *l);

void append(ll *l, int value);
void prepend(ll *l, int value);

void deleteHead(ll *l);
void deleteTail(ll *l);
void deleteValue(ll *l, int value);

node *find(ll *l, int value);

void printList(ll *l);

#endif
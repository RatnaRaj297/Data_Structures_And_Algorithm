#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

extern long long HEAPSPACE;

// structure of a linked list node. 
typedef struct node {
    int element;
    struct node * next;
} Node;

// structure of a linked list 
typedef struct linkedList {
    int count;
    Node * first;
} Linkedlist;


void myfree(void* ptr);
void* myalloc(int size);

Linkedlist* createList(int N);
Linkedlist* createCycle(Linkedlist* head);
void freeLinkedlist(Linkedlist * head);

void insertFirst (Linkedlist * head, int ele);/* inserts a given element at the beginning of the list */
void deleteFirst(Linkedlist * head);/* deletes the first element of the list and returns pointer to the deleted node. */


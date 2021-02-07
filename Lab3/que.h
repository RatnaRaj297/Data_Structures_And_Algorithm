#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int ele;
    struct node * next;
} Node;

typedef struct{
    Node * first;
    Node * last;
    int size;
} Queue;


Queue newQ();// returns an empty Queue

bool isEmptyQ(Queue q); // tests whether q is empty

Queue delQ(Queue q); // deletes the element from the front of the Queue;

int front(Queue q); // returns the element from the front of the Queue;

Queue addQ(Queue q, int ele);// adds e to the rear of the Queue; returns the modified Queue

int lengthQ(Queue q); // returns the length of the Queue




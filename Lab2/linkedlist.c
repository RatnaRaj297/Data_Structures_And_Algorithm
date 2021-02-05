/* linkedlist.c */
#include <stdlib.h>
#include "linkedlist.h"

void insertFirst (struct linkedList * head, int ele){
    struct node  *link = (struct node *) malloc(sizeof(struct node));
    link->element = ele;
    link->next = head->first;
    head->first = link;
    head->count++;
}

struct node * deleteFirst(struct linkedList * head){
    if(head->count == 0){
        return NULL;
    }

    struct node *temp = head->first;
    head->first = head->first->next;
    head->count--;

    return temp;
}


void printList(struct linkedList * head){
    struct node *ptr = head->first;
    printf("\n[ ");

    // starting from the beginning
    while(ptr != NULL){
        printf("%d, ", ptr->element);
        ptr = ptr->next;
    }

    printf("]\n");
}


int search(struct linkedList * head, int ele){
    struct node * ptr = head->first;

    while(ptr!=NULL){
        if (ptr->element == ele){
            return 1;
        }        
        ptr = ptr->next;
    }

    return 0;
}


struct node * delete_(struct linkedList * head, int ele){
    if(head->first == NULL){
        printf("List is Empty\n");
        return NULL;
    }

    // The first element is to be deleted 
    if(head->first->element == ele){
        head->count--;
        struct node * temp = head->first ;
        head->first = temp->next;
        return temp; 
    }

    struct node * prev = head->first;
    struct node * next = head->first->next;

    while(next!=NULL){
        // Element Found
        if(next->element == ele){
            prev->next = next->next;
            head->count--;
            return next;
        }

        prev = next;
        next = next->next;

    }

    // Element not found 
    printf("Element not found!\n");
    return NULL;
}

#include "cycle.h"

int testCycle(Linkedlist * head){
    Node* hare = head->first;
    Node* tort = head->first;

    if(hare == NULL){
        return 0;
    }

    while(hare->next != NULL && hare->next->next!=NULL){
        tort = tort->next;
        hare = hare->next->next;
        if(tort == hare){
            return 1;
        }
    }

    return 0;

}
#include "linkedlist.h"

long long HEAPSPACE = 0;

void* myalloc(int size){
	HEAPSPACE+= size;
	int* ptr = malloc(size + sizeof(int));
	*ptr = size;
	return ( ((void*)ptr) + sizeof(int));
}

void myfree(void* ptr){
	int* toread = (int*)(ptr - sizeof(int));
	int size = *toread;
	HEAPSPACE-=size;
	free(toread);
}

Linkedlist * createLinkedlist(){
    Linkedlist * head = (Linkedlist *)myalloc(sizeof(Linkedlist));
    head->count = 0;
    head->first = NULL;
    return head;
}


void insertFirst (Linkedlist* head, int ele){
    Node *link = (Node *) myalloc(sizeof(Node));
    link->element = ele;
    link->next = head->first;
    head->first = link;
    head->count++;
}


void deleteFirst(Linkedlist * head){
    if(head->count == 0){
        return;
    }
    Node *temp = head->first;
    head->first = head->first->next;
    head->count--;

    myfree(temp);
}



Linkedlist * createList(int N){
    Linkedlist * list = createLinkedlist();
    int random;
    for(int i = 0; i < N; i++ ){
        random = rand();
        insertFirst(list, random);
    }
    return list;
}


Linkedlist* createCycle(Linkedlist* head){
    // printf("\n\nInside createCycle function\n");

    int random = rand();
    if (head->count == 0){
        return head;
    }
    
    if (random > RAND_MAX/2){
        // printf("NOT Cyclic.\n");
    }

    else{
        // printf("Cyclic.\n");
        Node* last = head->first;
        Node* circ = NULL;

        random = rand();
        double ratio = ((double)(head->count - 1)) / RAND_MAX;
        random *= ratio;
        int i = 0;


        while(last!=NULL && last->next!=NULL){
            if(i == random){
                circ = last;
            }
            i += 1;
            last = last->next;
        }
        
     
        if(random == head->count -1){
            last->next = last;    
            return head;
        }

  
        last -> next = circ;
    }
    // printf("\nExiting createCycle function\n\n");


    return head;
}

void freeLinkedlist(Linkedlist* head){
    while(head->count!=0){
        deleteFirst(head);
    }
    myfree(head);
}
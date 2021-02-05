#include "stack.h"
#include <stdlib.h>

struct stack * createStack(){
    struct linkedList * list = (struct linkedList*) malloc(sizeof(struct linkedList));
    struct stack * stack = (struct stack*) malloc(sizeof(struct stack));
    list->count = 0;
    list->first = NULL;
    stack->list = list;
    return stack;
}

void push(struct stack * stack, int ele){
    insertFirst(stack->list, ele);
}

int pop(struct stack  * stack){
    if(stack->list->count == 0){
        return -1;
    }
    return deleteFirst(stack->list)->element;
}

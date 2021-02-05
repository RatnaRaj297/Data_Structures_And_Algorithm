/* stack.h */

#include "linkedlist.h"

struct stack{
    struct linkedList * list;
};

struct stack * createStack();
void push(struct stack  * stack, int ele);
int pop(struct stack  * stack);







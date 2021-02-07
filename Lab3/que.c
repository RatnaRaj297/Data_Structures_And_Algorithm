#include "que.h"

Node * newNode(int ele){
    Node * node = (Node *)malloc(sizeof(Node));
    node->ele = ele;
    node->next = NULL;

    return node;
}

Queue newQ(){
    Queue q;
    q.first = NULL;
    q.last = NULL;
    q.size = 0;
    return q;
}

bool isEmptyQ(Queue q){
    if (q.size == 0) return true;
    return false;
}

Queue delQ(Queue q){
    
    if(isEmptyQ(q)){
        return q;
    }

    q.size--;
    
    if(q.size == 0){
        q.first = NULL;
        q.last = NULL;
        return q;
    }

    q.first = q.first->next;
    return q;
}

int front(Queue q){
    if(isEmptyQ(q))
        return 0;

    return q.first->ele;
}

Queue addQ(Queue q, int ele){
    
    Node * node = newNode(ele);

    if(isEmptyQ(q)){
        q.size++;
        q.first = node;
        q.last = node;        
        return q;
    }

    q.last->next = node;
    q.last = node;
    q.size++;
    
    return q;

}

int lengthQ(Queue q){
    return q.size;
}
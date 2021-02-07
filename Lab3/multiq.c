#include "multiq.h"


MultiQ createMQ(int num){
    MultiQ mq;
    mq.size = num;
    mq.multiq = (Queue *) malloc(sizeof(Queue) * num);

    for(int i = 0; i<num; i++){
        mq.multiq[i] = newQ();
    }

    return mq;
}


// adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
MultiQ addMQ(MultiQ mq, Task t) {
    mq.multiq[t.p - 1] = addQ(mq.multiq[t.p - 1], t.tid);
    return mq;
}


// returns the front of the non-empty Queue in mq with the highest priority.
Task nextMQ(MultiQ mq){
    Task t;
    for(int i = mq.size - 1; i>=0; i--){
        if(!isEmptyQ(mq.multiq[i])){
            t.tid = front(mq.multiq[i]);
            t.p = i + 1; 
            return t;
        }
    }    

    t.p = -1;
    t.tid = -1;
    return t;
}


// deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ
MultiQ delNextMQ(MultiQ mq){
    for(int i = mq.size - 1; i>=0; i--){
        // printf("\n I value is %d ", i);
        if(!isEmptyQ(mq.multiq[i])){
            mq.multiq[i] = delQ(mq.multiq[i]);
            return mq;
        }
    }   
    return mq;
} 


// tests whether all the Queues in mq are empty
bool isEmptyMQ(MultiQ mq){
    for(int i = mq.size - 1; i>=0; i--){
        if(!isEmptyQ(mq.multiq[i])){
            return false;
        }
    }   
    return true;
}



// returns the total number of items in the MultiQ
int sizeMQ(MultiQ mq){
    int count = 0;
    for(int i = mq.size - 1; i>=0; i--){
        count += lengthQ(mq.multiq[i]);
    } 
    return count;
}


// returns the number of items in mq with the priority p.
int sizeMQbyPriority(MultiQ mq, Priority p){
    return lengthQ(mq.multiq[p-1]);
}


// Returns the Queue with priority P
Queue getQueueFromMQ(MultiQ mq, Priority p){
    return mq.multiq[p-1];
} 
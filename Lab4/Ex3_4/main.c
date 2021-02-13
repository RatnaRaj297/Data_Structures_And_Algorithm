#include "cycle.h"
#include <sys/time.h>

int main(){
    srand(time(0));

    FILE* fptr = fopen("heap.txt","w");

    if(fptr == NULL){
        printf("Error!!!\n");
        exit(1);
    }
    else{
        printf("Opened Successfully\n\n");
    }

    int num = 10;
    while(num--){
        
        int temp = rand() % 1000000;
        int N = 1000000 + temp ;  
     
        
        struct timeval t1, t2;
        double elapsedTime;
        gettimeofday(&t1, NULL);

        Linkedlist * list = createList(N);
        
        list = createCycle(list);
        int isCyclic = testCycle(list);



        fprintf(fptr, "The value of N is: %d\n", N);
        if(isCyclic){
            fprintf(fptr, "Cyclic\n");
        }
        else{
            fprintf(fptr, "Linear\n");
        }

        gettimeofday(&t2, NULL);
        // compute and print the elapsed time in millisec
        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        fprintf(fptr, "Total time time taken: %f ms.\n", elapsedTime);
        fprintf(fptr, "Total Heap space used: %lld\n\n\n", HEAPSPACE);



        freeLinkedlist(list);
        
    }

    fclose(fptr);
    return 0;

}
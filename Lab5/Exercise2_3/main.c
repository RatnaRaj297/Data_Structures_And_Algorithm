#include "readRecords.h"
#include "insertionSort.h"


int main(){

    FILE *fptr = fopen("output.txt", "w");
    if(fptr == NULL){
        printf("Error with the File!\n");
        exit(1);
    }
    fprintf(fptr, "No of Records,Time Taken (in ms),Space Required\n");


    CREDIT_CARD *card;

    for(int i = 2; i <= 9; i++){
        // Getting the File Name
        int no_of_records = 10000 * i;
        int length = snprintf(NULL, 0, "%d", no_of_records);
        char* filename = (char *)malloc(length + 1);
        snprintf( filename, length + 1, "%d", no_of_records);

        CREDIT_CARD* cards = readRecords(filename, &no_of_records);
     
        // Calculating The time 
        struct timeval t1, t2;
        double elapsedTime;
        gettimeofday(&t1, NULL);

        
        // Read the Records
        insertionSort(cards, no_of_records);

        gettimeofday(&t2, NULL);
        // compute and print the elapsed time in millisec
        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        fprintf(fptr, "%d,%0.3f,%ld\n",no_of_records, elapsedTime, (topofthestack - &no_of_records));


        free(cards);
        free(filename);
    
    }



}
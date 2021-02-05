#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[]){

    // File name not entered as an argument
    if(argc < 2){
        printf("Please Enter the file name as argument\n");
        exit(1);
    }

    FILE * fptr = fopen(argv[1], "r");

    // If file does not exist
    if(fptr == NULL ){
        printf("File does not exist!\n");
    }

    struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));
    head->count = 0;
    head->first = NULL;


    // Inputting the elements of the linked list
    while(!feof(fptr)){
        int temp;
        fscanf(fptr, "%d ", &temp);

        insertFirst(head, temp);
    }

    fclose(fptr);

    printList(head);
    deleteFirst(head);
    printList(head);

    // fptr = fopen("output.txt", "w");
    // if(fptr == NULL){
    //     printf("Error writing in Output file\n");
    //     exit(1);
    // }

    return 0;
}
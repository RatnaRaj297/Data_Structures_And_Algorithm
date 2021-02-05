#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



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

   
   
    struct stack * stack = createStack();


    // Inputting the elements of the linked list
    while(!feof(fptr)){
        int temp;
        fscanf(fptr, "%d ", &temp);
        push(stack, temp);
    }

    fclose(fptr);

    int temp = pop(stack);

    while(temp != -1){
        printf("%d\n", temp);
        temp = pop(stack);
    }
    return 0;
}
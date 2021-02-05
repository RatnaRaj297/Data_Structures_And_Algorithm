#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    int num;
    FILE *fptr1; 
    FILE *fptr2;

    // Opening File 1 
    fptr1 = fopen("Program.txt", "r");

    if(fptr1 == NULL){
        printf("Error Reading File!!\n");
        exit(1);
    }

    fptr2 = fopen("Program_copy.txt", "w");

    if(fptr2 == NULL){
        printf("Error Writing File!!\n");
        exit(1);
    }

    char c;
    c = fgetc(fptr1);
    while(c!=EOF){
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    
    printf("Contents have been Successfully Copied\n");
    
    fclose(fptr1);
    fclose(fptr2);


    return 0;
}

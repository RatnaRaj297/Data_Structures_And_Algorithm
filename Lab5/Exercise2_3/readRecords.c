#include "readRecords.h"


CREDIT_CARD* readRecords(char* filename, int* no_of_records_read){
    
    int size = 4; //intitial size of 4
    CREDIT_CARD* cards = (CREDIT_CARD *)malloc(sizeof(CREDIT_CARD)*size);


// Open the File 
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL){
        printf("File does not exist!\n");
        exit(1);
    }

    CREDIT_CARD new_card;
    char string[100];
    int i = 0;
    char* tok;

    while(!feof(fptr)){
        if (i == size){
            size *= 2;
            cards = realloc(cards, sizeof(CREDIT_CARD)*size);
        }

        fscanf(fptr,"\"%llu,%[^,],%[^,],%[^,],%[^\"]\"\n",&(new_card.card_no),new_card.bank_code,new_card.expiry_date,new_card.first_name,new_card.last_name);

        cards[i++] = new_card;
    }


    fclose(fptr);
    *no_of_records_read = i;
    return cards;


}

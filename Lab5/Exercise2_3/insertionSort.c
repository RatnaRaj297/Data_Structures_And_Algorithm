#include "insertionSort.h"

void insertInOrder(CREDIT_CARD* cards, CREDIT_CARD card, int size){
    CREDIT_CARD last_card = card;
    int j = size - 2;
    
    while( j > 0 && cards[j].card_no > last_card.card_no){
        cards[j+1] = cards[j];
        j--;
    }

    cards[j+1] = last_card;
}

void insertionSort(CREDIT_CARD * cards, int size){
    if (size <= 1){
        topofthestack = &size;
        return;
    }

    insertionSort(cards, size - 1);
    insertInOrder(cards, cards[size-1], size);

}
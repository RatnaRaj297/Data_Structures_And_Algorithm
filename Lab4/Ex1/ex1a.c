#include <stdio.h>

int bits;

void callDub(){
    int dub;
    printf("\n Inside Dubai: %u", &dub);
}


void callHyd(){
    int hyd;
    printf("\n Inside Hyderabad: %u", &hyd);
    callDub();
}

void callGoa(){
    int goa;
    printf("\n Inside Goa: %u", &goa);
    callHyd();
}

void callPilani(){
    int pilani;
    printf("\n Inside Pilani: %u", &pilani);
    callGoa();
}


int main(){
    callPilani();
    printf("\nInside Bits %u", &bits);
    return 0;
}
#include <stdio.h>
#include "search.h"

int main(){
    int a[] = {2, 5 ,1, 3, 4, 9, 8, 10};
    int n = 8;
    int ele = search(a, n);

    printf("In function main, element = %d \n", ele);
    return 0;
}
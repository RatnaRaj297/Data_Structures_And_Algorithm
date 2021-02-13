#include <stdio.h>

void call(int x){
    if (x == 10){
        return;
    }

	printf("x is %d, &x is %u.\n",x,&x);
	call(x+1);
}

int main(){
	call(0);
}
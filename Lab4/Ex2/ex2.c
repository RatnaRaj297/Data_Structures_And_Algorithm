#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

long long HEAPSPACE = 0;

void* myalloc(int size){
	HEAPSPACE+= size;
	int* ptr = malloc(size + sizeof(int));
	*ptr = size;
	return ( ((void*)ptr) + sizeof(int));
}

void myfree(void* ptr){
	int* toread = (int*)(ptr - sizeof(int));
	int size = *toread;
	HEAPSPACE-=size;
	free(toread);
}

int main(){
	srand(time(0));
	int random;
	int *data;

	double ratio = 15000.0/RAND_MAX;
	while(1){
		random = rand()*ratio;
		random += 10000;

		data = myalloc(sizeof(int)*random);
		printf("First address:%p, Last address:%p, HEAPSPACE is %lld\n",data,data+random,HEAPSPACE);
	
		myfree(data);
	}

    return 0;
}

#include<stdio.h>
#include "multiq.h"
#include <sys/time.h>


// reads from f a list of pairs (task_id, priority) and adds each item to a MultiQ appropriately.
MultiQ loadData(FILE * fptr){

	MultiQ mq = createMQ(10);
	int a, b;
	Task t;
	while(!feof(fptr)){
		fscanf(fptr, "%d, %d", &a, &b);
		fgetc(fptr);
		t.tid = a;
		t.p = b;
		mq = addMQ(mq, t);
	};

	return mq;

}

MultiQ testDel(MultiQ mq, int num){

	while(num--){
		// printf("\n %d",num);
		mq = delNextMQ(mq);
	}

	return mq;

}


int main(int argc, char * argv[]){


	struct timeval t1, t2;
	double elapsedTime;

	// start timer
	gettimeofday(&t1, NULL);


	// start of loading the file
	if(argc < 2){
		printf("\nPlease input the file name as command line argument\n");
		exit(1);
	}

	FILE * fptr = fopen(argv[1], "r");
	if(fptr == NULL){
		printf("\nFile does not exist! Please input the name correctly\n");
		exit(1);
	}

	MultiQ mq = loadData(fptr);
	fclose(fptr);


	// stop timer
	gettimeofday(&t2, NULL);
	// compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time for loading is %0.3f ms.\n", elapsedTime);



	// start timer
	gettimeofday(&t1, NULL);
	

	int deleteNo = sizeMQ(mq);
	mq = testDel(mq, deleteNo);

	// start timer
	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time for %d deletions is %0.3f ms.\n",deleteNo,elapsedTime);



	return 0;

}
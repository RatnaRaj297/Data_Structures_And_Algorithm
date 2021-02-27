exe : readRecords.o insertionSort.o main.o
	gcc readRecords.o insertionSort.o main.o -o exe

readRecords.o : readRecords.c readRecords.h
	gcc -c readRecords.c 

insertionSort.o: insertionSort.c insertionSort.h
	gcc -c insertionSort.c

main.o: main.c
	gcc -c main.c
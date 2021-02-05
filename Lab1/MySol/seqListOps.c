/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"

int nextfreeloc = 0;
Store st;


SeqList createlist()
{
 SeqList sl;
 sl.head = -1;
 sl.size = 0;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list) //initialize_elements
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID: ");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2): ");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time: ");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time: ");
  scanf ("%d",&list[i].at);
 }
 return size;
}


SeqList insert(Job j , SeqList sl)
{

    st[nextfreeloc].ele = j;
    sl.size++;


    // if the list is uninitialized 
    if(sl.head == -1){        
        st[nextfreeloc].next = -1;
        sl.head = nextfreeloc++;
        sl.size++;       
        return sl; 
    }
    

    // if it is the smaller than head (the first element)
    if(compare(j, st[sl.head].ele) == LESSER || compare(j, st[sl.head].ele) == EQUAL){
        st[nextfreeloc].next = sl.head;
        sl.head = nextfreeloc++;
        return sl;
    }
    
    int prev = sl.head;
    int next = st[sl.head].next;


    // find ideal position of insertion by traversing linearly
    while(1){

        // reached the end of list 
        if(next == -1){
            st[prev].next = nextfreeloc;
            st[nextfreeloc++].next = -1;
            return sl;
        }

        // found ideal position  
        if(compare(j , st[next].ele) == LESSER || compare(j , st[next].ele) == EQUAL){
            st[prev].next = nextfreeloc;
            st[nextfreeloc++].next = next;
            return sl;
        }

        prev = next;
        next = st[next].next;
    }

    // not required 
    return sl;

}
  
void insertelements (JobList list , int size, SeqList s[3])
{  
    for(int j = 2; j>=0; j--){
        for(int i = 0; i<size; i++){
            if(list[i].pri == j){
                s[j] = insert(list[i], s[j]);
            }
        }
    }
}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{   int ele_ptr = 0;

    for(int i = 2; i>=0; i--){
 
        int next = s[i].head;
 
        while(next!=-1){
            ele[ele_ptr++] = st[next].ele;
            next = st[next].next;
        }
 
    }

}

void printlist(SeqList sl)
{
    int next = sl.head;
    printf("\nPrinting SeqList \n");

    while(next!=-1){
        printJob(st[next].ele);
        next = st[next].next;
    }


}

void printJobList(JobList list, int size)
{
    for(int i = 0; i< size; i++){
        printJob(list[i]);
    }

}

void sortJobList(JobList list, int size)
{
    SeqList seq[3];
    seq[0] = createlist();
    seq[1] = createlist();
    seq[2] = createlist();
    insertelements (list, size, seq);
    printlist(seq[0]);   
    printlist(seq[1]);
    printlist(seq[2]);
    copy_sorted_ele (seq , list); 
}

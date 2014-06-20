#include <stdio.h>
#include <conio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Constant variable
#define SIZE 10
#define MAXVALUE 10

//interface
void Count_Sort(int A[], int B[], int n);
void Print_Array(int A[], int n);



void main(int argc, char* argv[])
{

	int i=0;
	int *A=(int*)malloc(sizeof(int)*SIZE);
	int *B=(int*)malloc(sizeof(int)*SIZE);

	//init the Array A
	srand(time(NULL));
	for(i=0;i<SIZE;i++)
		A[i]= rand()%MAXVALUE;
	//init the Array B
	memset(B,0,SIZE);

	//print the sorted array
	Print_Array(A,SIZE);

	//sort
	Count_Sort(A,B,MAXVALUE);

	//print the sorted array
	Print_Array(B,SIZE);

	free(B);
	free(A);

	//pause
	getch();

	return;
}

//implementation
//n = max value from array A - min value from array A
//A is the source array
//B is the destination array
void Count_Sort(int A[], int B[], int n)
{
	int i;
	int *Count=NULL;
	assert(A!=NULL&B!=NULL);

	//allocate the C array
	Count = (int *)malloc(sizeof(int)*n);
	//init the C array
	for(i=0;i<n;i++)
	{
		Count[i]=0;
	}


	//debug
	Print_Array(Count,MAXVALUE);

	//read the Array A and count the A[i]
	for(i=0;i<SIZE;i++)
	{
		Count[A[i]]++;
	}

    //debug
	Print_Array(Count,MAXVALUE);



	//read the array A and calculate the position of the A[i]
	//Count[i] means position, so Count[i]-1 means the index of the array of that position
	for(i=1;i<n;i++)
	{
		Count[i]+=Count[i-1];
	}

	//debug
	Print_Array(Count,MAXVALUE);

	//output the DEST array based on the position from the Count Arry
	for(i=SIZE-1;i>=0;i--)
	{
		B[Count[A[i]]-1] = A[i]; //assign to A[i] to the B array based on the position of Count
		Count[A[i]]--;
	}

	return;
}

void Print_Array(int A[], int n)
{
	int i=0;
	int count = 0;
	for(i=0;i<n;i++)
	{
		if(count == 0){
			printf("%d", A[i]);
		}else{
			printf(" %d", A[i]);
		}
	count++;

	}
	printf("\n");
	return;
}
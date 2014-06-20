#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//constant variable
#define RADIX 3
#define SIZE 10

//interface
void Print(int A[],int size);
void Radix_Sort(int A[], int B[], int radix, int size);


void main(int argc, char* argv)
{
	int i=0;
	int *A = (int *)malloc(sizeof(int)*SIZE);
	int *B = (int *)malloc(sizeof(int)*SIZE);

	//init the A and B
	for(i=0;i<SIZE;i++)
	{
		A[i]=0;
		B[i]=0;
	}
	//assign the A
	srand(time(NULL));
	for(i=0;i<SIZE;i++)
		A[i]=rand()%1000;

	//print the array before radix sort
	Print(A,SIZE);

	//radix sort the array A and put the sorted result to array B
	Radix_Sort(A,B,RADIX,SIZE);

	//print the array after radix sort
	Print(B,SIZE);

	//pause on the console to see the result
	getch();
	free(B);
	free(A);
	return;
}


//implementation
void Print(int A[],int size)
{
	int i=0;
	int count=0;

	for(i=0;i<size;i++)
	{
		if(count==0){
			printf("%d", A[i]);
		}else{
			printf(" %d", A[i]);
		}
		count++;
	}
	printf("\n");

	return;
}

void Radix_Sort(int A[], int B[], int radix, int size)
{

	int i=0;
	int max=0;
	int exp=1;
	int *tmp=NULL;
	int *count=(int*)malloc(sizeof(int)*size);
	
	//find the max value
	for(i=0;i<size;i++)		
	{
		if(A[i]>max)
			max=A[i];
	}

	while(max/exp)
	{
		//init the count array
		for(i=0;i<size;i++)
			count[i]=0;
		//init the B array
		for(i=0;i<size;i++)
			B[i]=0;

		//count sort the A compute the position of A[i]
		for(i=0;i<size;i++)
			count[(A[i]/exp)%10]++;
		for(i=1;i<size;i++)
			count[i]+=count[i-1];
		for(i=size-1;i>=0;i--)
		{
			B[count[(A[i]/exp)%10]-1] = A[i];
			count[(A[i]/exp)%10]--;
		}

		//swap the A and B
		tmp = A;
		A = B;
		B = tmp;
		
		//increase step
		exp*=10;
	}

	
	free(count);
	return;
}
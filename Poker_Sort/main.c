#include <stdio.h>
#include <conio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

//define the data structure for radix sort
#define SIZE 10
#define RADIX_SIZE 2
const int RADIX[RADIX_SIZE]={4,13};//radix for the color and value

typedef enum _Color
{
	DEFAULT_COLOR = -1,
	RED_HEARTS = 0,
	BLACK_HEARTS = 1,
	CLUBS = 2,
	DIAMONDS = 3
}Color;

typedef enum _Value{
	DEFAULT_VALUE = -1,
	A = 0,
	TWO = 1,
	THREE = 2,
	FOUR = 3,
	FIVE = 4,
	SIX = 5,
	SEVEN = 6,
	EIGHT = 7,
	NINE = 8,
	TEN = 9,
	J = 10,
	Q = 11,
	K = 12
}Value;

typedef struct _Node{
	Color p1;				//color is range from red hearts, black hearts, clubs, diamonds
	Value p2;				//value is Range from A,2,3,4...10,J,Q,K
	struct _Node * next;    //next pointer
}Node;


//interface
void Print(Node *A);
void Poker_Sort(Node A[], Node B[], const int Radix[], int Radix_size, int size);


void main(int argc, char* argv[])
{
	int i=0;
	Node *tmp=NULL;
	Node *A=(Node *)malloc(sizeof(Node)*SIZE);
	Node *B=(Node *)malloc(sizeof(Node)*SIZE);

	//init the original poker array
	srand(time(NULL));
	for(i=0;i<=SIZE-2;i++)
	{
		A[i].p1 = (Color)rand()%4;
		A[i].p2 = (Value)rand()%13;
		A[i].next = &A[i+1];
	}
    A[SIZE-1].p1 = (Color)rand()%4;
	A[SIZE-1].p2 = (Value)rand()%13;
	A[SIZE-1].next = NULL;

	for(i=0;i<SIZE-1;i++)
	{
		B[i].p1 = DEFAULT_COLOR;
		B[i].p2 = DEFAULT_VALUE;
		B[i].next = &B[i+1];
	}
    B[SIZE-1].p1 = DEFAULT_COLOR;
	B[SIZE-1].p2 = DEFAULT_VALUE;
	B[SIZE-1].next = NULL;
	//debug before Poker sort
	Print(A);
	
	//Poker Sort
	Poker_Sort(A,B,RADIX,RADIX_SIZE,SIZE);

	//debug after Poker sort
	//Print(B);

	free(B);
	free(A);
	//pause on console
	getch();
	return;
}

//implementation
void Print(Node *A)
{
	int i=0;
	int count=0;
	Node *p=A;
	assert(A!=NULL);

	while(p!=NULL)
	{
		if(count==0){
			printf("%d,%d",p->p1,p->p2);
		}else{
			printf("| %d,%d",p->p1,p->p2);
		}
		p=p->next;
		count++;
	}
	printf("\n");

	return;
}

void Poker_Sort(Node A[], Node B[], const int Radix[], int Radix_size, int size)
{
	int i=0;
	int j=0;
	int k=0;
	int *Count = NULL; //Count Array, which is very important for the poker sort
	Node *tmp=NULL;

	
	while(i<Radix_size)
	{
		Count = (int*)malloc(sizeof(int)*Radix[i]);

		//init the Count array
		for(j=0;j<Radix[i];j++)
			Count[j]=0;
		//Accumulate the Count Array
		for(k=0;k<size;k++)
		{
			if(i==0)	//first pass
				Count[A[k].p1]++;
			else		//second pass
				Count[A[k].p2]++;
		}
		//compute the position of that element
		for(j=1;j<Radix[i];j++)
		{
			Count[j]+=Count[j-1];
		}

		for(k=size-1;k>=0;k--)
		{
			if(i==0){	//first pass
				B[Count[A[k].p1]-1]=A[k];
				Count[A[k].p1]--;
			}else{		//second pass
				B[Count[A[k].p2]-1]=A[k];
				Count[A[k].p2]--;
			}
		}

		for(k=size-1;k>0;k--)
			B[k-1].next = &B[k];
		B[size-1].next = NULL;

		//debug
		Print(B);

		//swap the A and B
		tmp = A;
		A = B;
		B = tmp;

		free(Count);
		i++;
	}

	return;
}
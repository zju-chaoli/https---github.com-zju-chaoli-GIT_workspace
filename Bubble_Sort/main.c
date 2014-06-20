#include <stdio.h>
#include <conio.h>

//constant
#define SIZE 10
int S[SIZE];
//interface
void init(int s[],int size);
void print(int s[], int size);
void bubbleSort(int s[], int size);

void main(int argc, char* argv[])
{
	//input
	init(S,SIZE);
	//before sorted
	print(S,SIZE);

	//calling sort interface
	bubbleSort(S,SIZE);

	//after sorted
	print(S,SIZE);

	//pause on console
	getch();
	return;

}

void init(int s[],int size)
{
	int i;
	for(i=0;i<size;i++)
		scanf("%d", s+i);
}
void print(int s[], int size)
{
	int i=0;
	for(i=0;i<size;i++)
		printf("%d ", s[i]);
	printf("\n");
}
void bubbleSort(int s[], int size)
{
	int i,j;
	int temp=0;
	for(i=0;i<size;i++)
		for(j=size-1;j>i;j--)
		{
			if(s[j]<s[j-1])
			{
				temp=s[j];
				s[j]=s[j-1];
				s[j-1]=temp;
			}
		}

	return;
}


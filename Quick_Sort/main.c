#include <stdio.h>
#include <conio.h>

//constant
#define SIZE 10
int S[SIZE];
//interface
void init(int s[],int size);
void print(int s[], int size);
void bubbleSort(int s[], int size);
void insertSort(int s[],int left, int right);
void quickSort(int s[], int left, int right);
void swap(int *a, int *b);
int media(int s[], int left, int right);

void main(int argc, char* argv[])
{
	//input
	init(S,SIZE);
	//before sorted
	print(S,SIZE);

	//calling sort interface
	quickSort(S,0,SIZE-1);
	//insertSort(S,0,SIZE-1);

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
void insertSort(int s[],int left, int right)
{
	int i,k;
	int temp=0;

	for(i=left+1;i<=right;i++)
	{
		temp=s[i];
		for(k=i;k>left;k--)
		{
			if(temp<s[k-1])
				s[k]=s[k-1];
			else
				break;
		}
		s[k]=temp;
	}

	return;
}

void quickSort(int s[], int left, int right)
{
	int i,j;
	int centerValue=0;

	if(right-left>2)		//more than 3 element
	{

		centerValue=media(s,left,right);
		i=left;
		j=right-2;
		while(1)
		{
			while(s[i]<centerValue){i++;}
			while(s[j]>centerValue){j--;}
			if(i>j)
				break;
			else
				swap(&s[i],&s[j]);
		}
		//recover the right-1
		swap(&s[right-1],&s[i]);
		quickSort(s,left,i-1);
		quickSort(s,i+1,right);

	}
	else					//less than 3 element using insertSort, bubbleSort or others sort algorithms
							//based on swap, count sort is an exception.
	{
		insertSort(s,left,right);
	}

	return;
}
void swap(int *a, int *b)
{
	int temp=0;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}
int media(int s[], int left, int right)
{
	int center=0;
    
	center=(left+right)/2;
	//make sure s[left]<=s[center]<=s[right]
	if(s[left]>s[center])
		swap(&s[left],&s[center]);
	if(s[left]>s[right])
		swap(&s[left],&s[right]);
	if(s[center]>s[right])
		swap(&s[center],&s[right]);

	//retain the media value in right-1
	swap(&s[right-1],&s[center]);
	
	return s[right-1];

}
#include <stdio.h>
#include <conio.h>

//define the constant
#define SIZE 10
int S[SIZE];
//define the interface
void shellSort(int s[],int size);
void print(int s[],int size);

void main(int argc, char* argv[])
{

	//input 
	int i;
	for(i=0;i<SIZE;i++)
		scanf("%d", &S[i]);

	//debug
	print(S,SIZE);

	shellSort(S,SIZE);

	//debug
	print(S,SIZE);

	//pause on console
	getch();
	return;
}

//implementation
void shellSort(int s[],int size)
{
	int increment=0;
	int temp=0;
	int i,j;
	i=j=0;

	for(increment=size/2;increment>0;increment/=2)
	{
		for(i=increment;i<size;i++)
		{
			temp=s[i];
			for(j=i;j>0;j-=increment)
			{
				if(temp<s[j-increment])
					s[j]=s[j-increment];
				else
					break;
			}
			s[j]=temp;
		}
	}
	return;
}

void print(int s[],int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
}
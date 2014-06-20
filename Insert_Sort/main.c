#include <stdio.h>
#include <conio.h>

//define the constant
#define SIZE 5
int S[SIZE];
//define the interface
void print(int s[], int size);
void insertSort_1(int s[], int size);
void insertSort_2(int s[], int size);

void main(int argc, char *argv)
{
	//input 
	int i;
	for(i=0;i<SIZE;i++)
		scanf("%d", &S[i]);

	//debug
	printf("++++++++++before sorted++++++++++++\n");
	print(S,SIZE);

	//insert sort
	insertSort_2(S,SIZE);

	//debug
	printf("++++++++++after sorted++++++++++++\n");
	print(S,SIZE);
	
	//pause on console
	getch();
	return;
}

void print(int s[],int size)
{
	int i=0;
	for(i=0;i<size;i++)
		printf("%d ", s[i]);
	printf("\n");
}

void insertSort_1(int s[], int size)
{
	int i=0;
	int j=0;
	int temp=0;
	for(i=1;i<size;i++)
	{
		temp=s[i];
		for(j=i-1;j>=0;j--)
		{
			if(temp<s[j])
				s[j+1]=s[j];
			else
			{
				s[j+1]=temp;
				break;
			}
		}
		//exception case
		if(j<0)
			s[0]=temp;
	}
	return;
}

//recursive calling the insert sort
void insertSort_2(int s[], int size)
{
	int i=0;
	int temp=0;
	//base step
	if(size==1)
		return;
	else
	{
		insertSort_2(s,size-1);
		temp=s[size-1];
		//two exit condition, one is the i<0, the other is we reach the condition.
		for(i=size-1;i>0;i--)
		{
			if(temp<s[i-1])
				s[i]=s[i-1];
			else
				break;
		}
		s[i]=temp;
	}
	return;
}
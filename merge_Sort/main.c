#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//define the constant
#define SIZE 10
int S[SIZE];
//define the interface
void mergeSort(int s[],int size, int left, int right);
void print(int s[],int size);

void main(int argc, char* argv[])
{

	//input 
	int i;
	for(i=0;i<SIZE;i++)
		scanf("%d", &S[i]);

	//debug
	print(S,SIZE);

	mergeSort(S,SIZE, 0,SIZE-1);

	//debug
	print(S,SIZE);

	//pause on console
	getch();
	return;
}

//implementation
void mergeSort(int s[],int size, int left, int right)
{
	int mid=0;
	int lpos,rpos,pos;
	int *tmpArray=NULL;
	lpos=rpos=pos=0;
	//protect code
	if(s==NULL)
		return;
	//base step
	if(left>=right)
		return;
	else
	{
		mid=(left+right)/2;
		mergeSort(s,mid-left+1,left,mid);
		mergeSort(s,right-mid,mid+1,right);
		//post code after the recursive call
		tmpArray=(int*)malloc(sizeof(int)*size);
		assert(tmpArray!=NULL);
		for(lpos=left,pos=0,rpos=mid+1;pos<size&&lpos<=mid&&rpos<=right;)
		{
			if(s[lpos]<s[rpos])
				tmpArray[pos++]=s[lpos++];
			else
				tmpArray[pos++]=s[rpos++];
		}

		//copy the remaining 
		while(lpos<=mid)
		{
			tmpArray[pos++]=s[lpos++];
		}
		while(rpos<=right)
		{
			tmpArray[pos++]=s[rpos++];
		}

		//copy the tmpArray back to S array
		memcpy(&s[left],tmpArray,sizeof(int)*size);
		free(tmpArray);
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
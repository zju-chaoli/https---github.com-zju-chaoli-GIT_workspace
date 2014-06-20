#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <assert.h>

//define the data structure
typedef struct _HEAPSTRUCT{
	int Capacity;
	int Size;
	int *Queue;
}HEAPSTRUCT;

//define constant
#define MAXELEMENT 1026			//2^10+1+1, 10 is the height of the Priority Tree
#define MINDATA -1
//define the interface
HEAPSTRUCT *initialize(int maxelement);
int height(HEAPSTRUCT *H,int pos);
int isFull(HEAPSTRUCT *H);
int isEmpty(HEAPSTRUCT *H);
int MAX(int a, int b); 
void insertItem(HEAPSTRUCT *H, int element);
void deleteMIN(HEAPSTRUCT *H);
int findItem(HEAPSTRUCT *H, int element);
void print(HEAPSTRUCT *H,int pos);	


void main(int argc, char *argv[])
{
	int i;
	int temp=0;
	HEAPSTRUCT *H=initialize(MAXELEMENT);
	
	//insert
	scanf("%d", &temp);
	while(temp>=0)
	{
		insertItem(H,temp);
		print(H,1);
		scanf("%d", &temp);
	}

	//delete
	temp=3;
	while(temp>=0)
	{
		deleteMIN(H);
		print(H,1);
		scanf("%d", &temp);
	}

	//debug and print
	printf("\n");
	for(i=1;i<=H->Size;i++)
		printf("%d ", H->Queue[i]);
	printf("\n");

	//pause on console
	getch();
	return;
}



//define the implementation
HEAPSTRUCT *initialize(int maxelement)
{
	int i=0;
	HEAPSTRUCT *H=NULL;
	H=(HEAPSTRUCT*)malloc(sizeof(HEAPSTRUCT));
	assert(H!=NULL);

	H->Capacity=maxelement;
	H->Size=0;
	H->Queue=(int*)malloc(sizeof(int)*maxelement); 
	assert(H->Queue!=NULL);
	H->Queue[0]=MINDATA;
	for(i=0;i<=maxelement;i++)
		H->Queue[i]=MINDATA;
	return H;
}

void insertItem(HEAPSTRUCT *H, int element)
{
	int tmp=0;;
	if(isFull(H))
		return;
	tmp=++H->Size;
	while(element<H->Queue[tmp/2])
	{
		H->Queue[tmp]=H->Queue[tmp/2];
		tmp=tmp/2;
	}
	H->Queue[tmp]=element;
	return;
}
void deleteMIN(HEAPSTRUCT *H)
{
	int parent=0;
	int child=0;
	int lastelement=0;
	if(isEmpty(H))
		return;
	lastelement=H->Queue[H->Size];
	H->Queue[H->Size--]=MINDATA;

	for(parent=1;2*parent<=H->Size;parent=child)
	{
		child=parent*2;
		if(child!=H->Size&&H->Queue[child]>H->Queue[child+1])
			child++;
		if(H->Queue[child]<lastelement)
			H->Queue[parent]=H->Queue[child];
		else
			break;
	}
	H->Queue[parent]=lastelement;
		return;
}

int findItem(HEAPSTRUCT *H, int element)
{
	return 0;
}

void print(HEAPSTRUCT *H,int pos)
{
	if(H==NULL)
		return;
	if(pos>H->Size)
		return;
	if(2*pos<=H->Size)
	{
		print(H,2*pos);
	}
	printf("%d ", H->Queue[pos]);

	if(2*pos+1<=H->Size)
	{
		print(H,2*pos+1);
	}
}


int height(HEAPSTRUCT *H, int pos)
{
	int LHeight=0;
	int RHeight=0;
	if(H==NULL)
		return 0;
	if(H->Queue[pos*2]!=MINDATA)
		LHeight=height(H,pos*2);
	if(H->Queue[pos*2+1]!=MINDATA)
		RHeight=height(H,pos*2+1);
	return MAX(LHeight,RHeight)+1;

}

int isFull(HEAPSTRUCT *H)
{
	return H->Size>=H->Capacity-1;
}

int isEmpty(HEAPSTRUCT *H)
{
	return H->Size<=0;
}

int MAX(int a, int b)
{
	return a>b?a:b;
}
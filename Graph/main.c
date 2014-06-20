#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//data structure
#define VEDEX_SIZE 10
typedef struct _VEDEX{
	int value;
	int weight;
	struct _VEDEX * next;
}VEDEX;

typedef struct _GRAPH{
	int indegree;
	VEDEX *child;
}GRAPH;

GRAPH G[VEDEX_SIZE];
int R[VEDEX_SIZE];

//Queue
int Queue[VEDEX_SIZE];
int qSize=0;
int Front=0;
int Rear=0;


//define the interface
void init(GRAPH G[], int size);
void print(GRAPH G[], int size);
void insert(GRAPH G[], int size);
void topSort_1(GRAPH G[], int size);
void topSort_2(GRAPH G[], int size);
void enQueue(int Q[], int value, int size);
int deQueue(int Q[], int size);
int isFull(int Q[],int size);
int isEmpty(int Q[],int size);


//main function
void main(int argc, char *argv[])
{
	int i=0;
	//init the GRAPH
	init(G,VEDEX_SIZE);
	insert(G,VEDEX_SIZE);
	//before sort
	print(G,VEDEX_SIZE);

	//sort
	topSort_1(G,VEDEX_SIZE);

	//print the result
	for(i=0;i<VEDEX_SIZE;i++)
		printf("%d ", R[i]);
	printf("\n");

	//before sort
	//print(G,VEDEX_SIZE);

	//pause on console
	getch();
	return;
}

//define the implementation
void init(GRAPH G[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		G[i].indegree=-1;
		G[i].child=NULL;
	}
	return;
}
void print(GRAPH G[], int size)
{
	int i;
	VEDEX *tmp=NULL;
	for(i=0;i<size;i++)
	{
		printf("G[%d|indegree=%d]-->[", i,G[i].indegree);
		tmp=G[i].child;
		while(tmp!=NULL)
		{
			printf("value=%d|weight=%d]-->", tmp->value,tmp->weight);
			tmp=tmp->next;
		}
		printf("\n");
	}
	return;
}

void insert(GRAPH G[], int size)
{
	int i;
	int temp;
	int tempchild;
	VEDEX *tmp=NULL;
	VEDEX *tmpchild=NULL;
	temp=tempchild=0;

	for(i=0;i<size;i++)
	{
		printf("input the value of vedex, enter -1 to exit:  ");
		scanf("%d", &temp);
		if(temp<0)				//if less than 0 then stop construct the GRAPH
			break;
		if(G[temp].indegree<0)	//new linked node
			G[temp].indegree=0;

		printf("\n input the vedex value linked from the G[%d], enter -1 to goto next VEDEX: ", temp);
		scanf("%d", &tempchild);
		while(tempchild>=0)
		{
			//init the VEDEX linked node
			if(G[tempchild].indegree<0)
				G[tempchild].indegree=0;
			tmpchild=(VEDEX*)malloc(sizeof(VEDEX));
			tmpchild->value=tempchild;
			tmpchild->weight=0;
			tmpchild->next=NULL;
			//insert into the list
			if(G[temp].child==NULL)
				G[temp].child=tmpchild;
			else
			{
				tmpchild->next=G[temp].child;
				G[temp].child=tmpchild;
			}
			//adjust the indegree of the VEDEX tempchild
			G[tempchild].indegree++;
			//next children linked node
			scanf("%d", &tempchild);
		}
	}

	return;
}

void topSort_1(GRAPH G[], int size)
{
	int i=0;
	int count=0;
	int j=0;
	VEDEX* tmp=NULL;

	while(i<size&&count<size)
	{
		if(G[i].indegree==0){
			R[j++]=i;		//retain the result in global array
			G[i].indegree=-1;//marked as deleted
			tmp=G[i].child;
			while(tmp!=NULL)
			{
				G[tmp->value].indegree--;
				tmp=tmp->next;
			}
			//reset the i and count for another round of search
			i=0;
			count=0;
		}else{
			i++;
			count++;
			continue;
		}
	}

	return;
}

void topSort_2(GRAPH G[], int size)
{
	int i=0;
	int j=0;
	VEDEX *T=NULL;
	//enqueu all indegree which equal to 0
	for(i=0;i<size;i++)
		if(G[i].indegree==0)
			enQueue(Queue,i,size);
	while(!isEmpty(Queue,size))
	{
		i=deQueue(Queue,size);
		R[j++]=i;
		//decrease all the indegree linked to i
		T=G[i].child;
		while(T!=NULL)
		{
			G[T->value].indegree--;
			if(G[T->value].indegree==0)
				enQueue(Queue,T->value,size);
			T=T->next;
		}
	}

	return;
}

void enQueue(int Q[], int value, int size)
{
	int temp=0;
	if(isFull(Q,size))
		return;
	Q[Rear++]=value;
	qSize++;
	if(Rear>=size)
		Rear=0;
	return;
}

int deQueue(int Q[], int size)
{
	int result=0;
	if(isEmpty(Q,size))	//empty
		return -1;
	result=Queue[Front++];
	qSize--;
	if(Front>=size)
		Front=0;

	return result;
}

int isEmpty(int Q[],int size)
{
	return qSize==0?1:0;
}
int isFull(int Q[],int size)
{
	return qSize==size?1:0;
}
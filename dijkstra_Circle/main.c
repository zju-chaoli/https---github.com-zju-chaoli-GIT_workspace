#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//data structure
#define MAXVALUE 9999
#define VEDEX_SIZE 10
typedef struct _VEDEX{
	int value;
	int weight;
	struct _VEDEX * next;
}VEDEX;

typedef struct _GRAPH{
	int indegree;		//only used by GRAPH without circle
	int known;			//already being processed
	int dist;           //distance
	int element;		//retain the previous node
	VEDEX *child;
}GRAPH;

GRAPH G[VEDEX_SIZE];
int R[VEDEX_SIZE];

//if we use dijkstra in circle GRAPH, we have to use a priority Queue to store the VEDEX
int Queue[VEDEX_SIZE];
int qSize=0;
int Front=0;
int Rear=0;


//define the interface
void init(GRAPH G[], int size);
void print(GRAPH G[], int size);
void insert(GRAPH G[], int size);
void topSort_1(GRAPH G[], int size);
void enQueue(GRAPH G[], int Q[], int value, int size);
void enQueue_base(int Q[], int value, int size);
int deQueue(GRAPH G[], int Q[], int size);
int isFull(int Q[],int size);
int isEmpty(int Q[],int size);
void dijkstra(GRAPH G[], int element, int size);

//main function
void main(int argc, char *argv[])
{
	int temp=0;
	int i=0;
	//init the GRAPH
	init(G,VEDEX_SIZE);
	insert(G,VEDEX_SIZE);
	//before sort
	print(G,VEDEX_SIZE);

	//dijkstra to compute the shortest route from VEDEX 
	printf("please Enter the element you want to compute the shortest route for:");
	scanf("%d", &temp);
	printf("\n");
	dijkstra(G,temp,VEDEX_SIZE);

	//print the result
	//for(i=0;i<VEDEX_SIZE;i++)
	//	printf("%d ", R[i]);
	//printf("\n");

	//before sort
	print(G,VEDEX_SIZE);

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
		G[i].known=0;				//1 is true, 0 is false since the boolean is not supported in C
		G[i].dist=MAXVALUE;
		G[i].element=-1;
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
		printf("G[%d|known=%d|indegree=%d|dist=%d|element=%d]-->[", i,G[i].known,G[i].indegree,G[i].dist,G[i].element);
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
	int tempweight;
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
		scanf("%d,%d", &tempchild, &tempweight);
		while(tempchild>=0)
		{
			//init the VEDEX linked node
			if(G[tempchild].indegree<0)
				G[tempchild].indegree=0;
			tmpchild=(VEDEX*)malloc(sizeof(VEDEX));
			tmpchild->value=tempchild;
			tmpchild->weight=tempweight;
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
			scanf("%d,%d", &tempchild, &tempweight);
		}
	}

	return;
}


//is not applicable in Graph with Circle
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

void enQueue_base(int Q[], int value, int size)
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


//insert the value at first step, then adjust the queue, like the insert sort
void enQueue(GRAPH G[], int Q[], int value, int size)
{
	int temp1=0;
	int temp2=0;
	int tempvalue=0;
	int count=0;
	if(isFull(Q,size))
		return;
	//basic step
	enQueue_base(Q,value,size);

	//adjust the priority Queue
	temp1=Rear-1;
	if(temp1<0)
		temp1=size-1;
	temp2=temp1-1;
	if(temp2<0)
		temp2=size-1;
	//retain the last element
	tempvalue=Q[temp1];

	while(G[Q[temp2]].dist>G[tempvalue].dist&&count<qSize-1)
	{
		Q[temp1]=Q[temp2];
		temp1--;
		if(temp1<0)
			temp1=size-1;
		temp2=temp1-1;
		if(temp2<0)
			temp2=size-1;
		count++;
	}
	Q[temp1]=tempvalue;
	return;
}


int deQueue(GRAPH G[], int Q[], int size)
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

void dijkstra(GRAPH G[], int element, int size)
{
	int i=0;
	int j=0;
	VEDEX *T=NULL;

	//put the element in the priority queue
	G[element].dist=0;
	enQueue(G,Queue,element,size);
	
	while(!isEmpty(Queue,size))
	{
		i=deQueue(G,Queue,size);
		G[i].known=1;
		//result of top sort
		R[j++]=i;								
		//decrease all the indegree linked to i
		T=G[i].child;
		while(T!=NULL)
		{
			//greedy algorithm to get the shortest route from i to the linked node
			if(G[T->value].dist>G[i].dist+T->weight&&G[T->value].known==0)
			{
				G[T->value].dist=G[i].dist+T->weight;
				G[T->value].element=i;
				//Top sort
				G[T->value].indegree--;
				enQueue(G,Queue,T->value,size);			//priority will make sure the shortest dist will be the first one
			}

			T=T->next;
		}
	}

	return;
}
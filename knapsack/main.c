#include <stdio.h>
#include <conio.h>


//data struct
#define SIZE 3
#define CAPACITY 50
int W[SIZE];
int V[SIZE];
float P[SIZE];
float RESULT[SIZE];

//interface
void init(int w[], int v[], float p[], float result[], int size);
void print(int w[], int v[], float p[], float result[], int size);
void insertSort(int w[],int v[], float p[], int size); 
float knapsack(int w[], int v[], float p[], float result[], int capacity, int size);

//main
void main(int argc, char* argv[])
{
	int i=0;
	init(W,V,P,RESULT,SIZE);
	print(W,V,P,RESULT,SIZE);

	//non 0-1 knapsack
	printf("the max value is: %f\n",knapsack(W,V,P,RESULT,CAPACITY,SIZE));
	
	for(i=0;i<SIZE;i++)
		printf("result[%d]=%f ", i,RESULT[i]);
	printf("\n");

	//pause
	getch();
	return;
}

//implementation
void init(int w[], int v[], float p[],float result[], int size)
{
	int i=0;
	w[0]=20;
	v[0]=100;
	w[1]=10;
	v[1]=60;
	w[2]=30;
	v[2]=120;
	for(i=0;i<size;i++)
	{
		p[i]=(float)v[i]/w[i];
		result[i]=0.0;
	}
	//sort based on the P[i]
	insertSort(w,v,p,size);
	return;
}

void print(int w[], int v[], float p[], float result[], int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		printf("W[%d]=%d ", i,w[i]);
	}
	printf("\n");
	for(i=0;i<size;i++)
	{
		printf("V[%d]=%d ", i,v[i]);
	}
	printf("\n");
	for(i=0;i<size;i++)
	{
		printf("P[%d]=%f ", i,p[i]);
	}
	printf("\n");
}

//modified insert sort based on P, adjust the position of the w and v array accordingly
void insertSort(int w[],int v[], float p[], int size)
{
	int i=0;
	int j=0;
	int tempw=0;
	int tempv=0;
	float tempp=0;

	for(i=1;i<size;i++)
	{
		tempp=p[i];
		tempw=w[i];
		tempv=v[i];
		for(j=i;j>0;j--)
		{
			if(tempp>p[j-1]){
				p[j]=p[j-1];
				w[j]=w[j-1];
				v[j]=v[j-1];
			}else{
				break;
			}
		}
		p[j]=tempp;
		w[j]=tempw;
		v[j]=tempv;
	}

	return;
}

//non 0-1 knapsack
//pre-condition of this knapsack is all three w,v,p is sorted.
float knapsack(int w[], int v[], float p[], float result[], int capacity, int size)
{
	int i=0;
	int tmpcapacity=0;
	float tmpvalue=0;
	float pi=0.0;
	for(i=0;i<size;i++)
	{
		if(tmpcapacity+w[i]<=capacity)
		{
			tmpcapacity+=w[i];
			tmpvalue+=v[i];
			result[i]=1.0;
		}
		else
			break;
	}
	//last step
	if(i<size)
	{
		pi=(float)(capacity-tmpcapacity)/w[i];
		tmpvalue+=pi*v[i];
		result[i]=pi;

	}

	return tmpvalue;
}
#include <stdio.h>
#include <conio.h>


//data struct
#define SIZE 3
#define CAPACITY 3
int W[SIZE];
int V[SIZE];
int VW[SIZE][CAPACITY+1];
int S[SIZE];

//interface
void init(int w[], int v[], int vw[][CAPACITY+1], int capacity, int size);
void print(int w[], int v[], int vw[][CAPACITY+1], int capacity, int size);
int knapsack_cursive(int w[], int v[], int vw[][CAPACITY+1],int row, int col, int capacity, int size);
int knapsack_noncursive(int w[], int v[], int vw[][CAPACITY+1], int row, int col, int capacity, int size);
int max(int a,int b);

//main
void main(int argc, char* argv[])
{
	int i=0;
	init(W,V,VW,CAPACITY,SIZE);

	//non 0-1 knapsack
	//printf("the max value is: %d\n",knapsack_cursive(W,V,VW,0,CAPACITY,CAPACITY,SIZE));
	printf("the max value is: %d\n",knapsack_noncursive(W,V,VW,0,CAPACITY,CAPACITY,SIZE));
	print(W,V,VW,CAPACITY,SIZE);

	for(i=0;i<SIZE;i++)
		printf("S[%d]=%d ",i,S[i]);
	printf("\n");
	
	//pause
	getch();
	return;
}

//implementation
void init(int w[], int v[], int vw[][CAPACITY+1], int capacity, int size)
{
	int i=0;
	int j=0;
	w[0]=2;
	v[0]=100;
	w[1]=3;
	v[1]=120;
	w[2]=1;
	v[2]=60;
	for(i=0;i<size;i++)
		for(j=0;j<=capacity;j++)
			vw[i][j]=0;
	return;
}

void print(int w[], int v[], int vw[][CAPACITY+1], int capacity, int size)
{
	int i=0;
	int j=0;
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
		for(j=0;j<=capacity;j++)
		{
			printf("vw[%d][%d]=%d ", i,j,vw[i][j]);
		}
		printf("\n");
	}
}


//0-1 knapsack
//recursive algorithm
int knapsack_cursive(int w[], int v[], int vw[][CAPACITY+1], int row, int col, int capacity, int size)
{
	int i=0;
	int j=0;
	int result=0;

	//base step vw[row][0]=0
	if(col==0)
		return 0;
	//base step vw[size-1][col]
	if(row==size-1)
	{
		if(w[row]<=col)
			return v[row];
		else
			return 0;
	}
	//recursive
	if(w[row]>col)
	{
		return knapsack_cursive(w,v,vw,row+1,col,capacity,size);
	}else{
		return max(knapsack_cursive(w,v,vw,row+1,col-w[row],capacity,size)+v[row],knapsack_cursive(w,v,vw,row+1,col,capacity,size));
	}
}

int max(int a,int b)
{
	return a>b?a:b;
}

//0-1 knapsack
//non-recursive algorithm
//note that this is more better than the recursive algorithm
int knapsack_noncursive(int w[], int v[], int vw[][CAPACITY+1], int row, int col, int capacity, int size)
{
	int i=0;
	int j=0;
	int k=0;
	int result=0;

	//init step
	for(i=0;i<size;i++)
		vw[i][0]=0;
	for(j=0;j<=capacity;j++)
	{
		if(w[size-1]<=j)
		{
			vw[size-1][j]=v[size-1];
		}
		else
			vw[size-1][j]=0;
	}
	for(i=size-2;i>=0;i--)
	{
		for(j=capacity;j>=0;j--)
		{
			if(w[i]>j)
				vw[i][j]=vw[i+1][j];
			else
			{
				vw[i][j]=max(vw[i+1][j],vw[i+1][j-w[i]]+v[i]);
			}
		}
	}

	//trace back to get the item which comprise the knapsack
	k=0;
	j=capacity;
	for(i=0;i<size;i++)
	{
		if(vw[i][j]==vw[i+1][j])
			S[i]=0;
		else
		{
			S[i]=1;
			j-=w[i];
		}
	}

	return vw[0][capacity];
}
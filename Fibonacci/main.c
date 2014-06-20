#include <stdio.h>
#include <conio.h>
#include <time.h>

//data structure
#define SIZE 50
int DATA[SIZE];

//interface
int Fibonacci_1(int N);

void main(int argc, char* argv[])
{
	time_t t_start;
	time_t t_end;
	int temp=0;
	printf("Enter the value of Fibonacci:");
	scanf("%d", &temp);

	//t_start=time(NULL);
	//temp=Fibonacci_1(temp);
	//t_end=time(NULL);
	//printf("the Fibonacci result is %d using time %f\n", temp,difftime(t_end,t_start));

	t_start=time(NULL);
	temp=Fibonacci_2(temp);
	t_end=time(NULL);
	printf("the Fibonacci result is %d using time %f\n", temp,difftime(t_end,t_start));

	//pause on console
	getch();
	
	return;
}


//implementation
int Fibonacci_1(int N)
{
	if(N<=1)
		return 1;
	else
	{
		return Fibonacci_1(N-1)+Fibonacci_1(N-2);
	}
}

int Fibonacci_2(int N)
{
	
	int i=0;
	DATA[0]=DATA[1]=1;
	for(i=2;i<N;i++)
	{
		DATA[i]=DATA[i-1]+DATA[i-2];
	}
	return DATA[N-1];
}
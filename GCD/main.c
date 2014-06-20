#include<stdio.h>
#include<conio.h>

//@interface
int GCD_1(int m, int n);
int GCD_2(int m, int n);

void main(int argc, char* argv[])
{


	printf("the GCD value for 50 and 15 is: %d\n", GCD_1(15,16));
	//pause on console
	getch();
	return;
}

//@implementation
int GCD_1(int m, int n)
{
	int i = (m>=n?m:n);
	while(i>=1)
	{
		if(m%i==0 &&n%i==0){
			return i;
		}else{
			i--;
		}
	}
	//failed
	return -1;
}


int GCD_2(int m, int n)
{	
	int temp=0;
	int rem=0;

	//check the m and n to make sure m is larger than n
	if(m<n){
		temp = m;
		m = n;
		n = temp;
	}

	//loop
	while(n>0)
	{
		rem=m%n;
		m = n;
		n = rem;
	}
	return m;
}

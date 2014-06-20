#include <stdio.h> 
#include <conio.h>

char converse(int a);

int main(void) 
{ 
	int a=0,b=0;
	char c[20]={0};
	int j=0;

	int div=0;
	int rem=0;

	printf("enter the HEX value\n");
	scanf("%x", &a);

	//please note the HEX is representing in BINary format in a, so we can change the binary to HEX
	while(a)
	{
		rem=a&0x0000000f;
		a>>=4;
		c[j++]=converse(rem);
	}

	//print out the result with hex
	while(j>=0)
	{
		printf("%c ", c[j]);
		j--;
	}
	printf("\n");


	//pause on the console
	getch();
} 

char converse(int a)
{
	if(a>=10&&a<=15)
		return a+'a'-10;
	else
		return a+'0'-0;
}




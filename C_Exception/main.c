#include <stdio.h>
#include <setjmp.h>
#include <conio.h>

//global variable
jmp_buf buf;
int errorno;


//interface
void my_throw(int errorno);
void my_catch(int errorno);


void main(int argc, char* argv[])
{
	int errorno;
	int temp;

	//return point
	errorno=setjmp(buf);

	//catch procedure
	my_catch(errorno);

	getch();
	return;
}

//implementation
void my_catch(int errorno)
{
	switch(errorno)
	{
	//here is the normal case
	case 0:					//normal case, throw the error number if it has
		printf("the error Number is %d\n",errorno);
		my_throw(-1);
			break;
	case -1:
		printf("the error Number is %d\n",errorno);
		my_throw(-2);
			break;
	case -2:
		printf("the error Number is %d\n",errorno);
			break;
	case -3:
		printf("the error Number is %d\n",errorno);
			break;
	default:
		printf("undefined error\n");
		break;
	}
}

void my_throw(int errorno)
{
	longjmp(buf,errorno);
	return;
}
#include <iostream>
#include <conio.h>
#include "IntArray.h"
#include <ctime>
using namespace std;


void main(int argc, char *argv[])
{

	IntArray A(10);
	IntArray B(10);
	cout<<"array is below"<<endl;
	A.print();
	int i;
	srand(time(NULL));
	for(i=0;i<10;i++)
		A[i]=rand()%100;
	cout<<"copy A to B"<<endl;
	B=A;
	B.print();
	B.sort();
	cout<<"B is sorted"<<endl;
	B.print();

	//pause on the console
	getch();

	return;
}
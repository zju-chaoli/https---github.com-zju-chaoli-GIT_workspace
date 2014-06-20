#include <stdio.h>
#include <conio.h>

//interface
int binarySearch_1(int pA[], int value, int low, int high);
int binarySearch_2(int pA[], int value, int low, int high);

void main(int argc, char* argv[])
{

	int A[]={1,2,3,4,5,6,7,8,9,10};
	printf("the value 4 is on index: %d\n", binarySearch_2(A,1,0,9));


	//pause on the console
	getch();
	return;
}


//implementation
//pre-condition: should be ordered array
int binarySearch_1(int pA[], int value, int low, int high)
{
	int i=0;
	int mid=(low+high)/2;
	if(low<=high){
		if(value<pA[mid]){
			return binarySearch_1(pA, value, low, mid-1);
		}else if(value>pA[mid]){
			return binarySearch_1(pA,value, mid+1,high);
		}else{
			return mid;
		}
	}else{

		//basic step
		return -1;
	}

}

int binarySearch_2(int pA[], int value, int low, int high)
{
	int i=0;
	int mid=0;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(value<pA[mid]){
			high = mid-1;
		}else if(value>pA[mid]){
			low = mid+1;
		}else{
			return mid;
		}
	}
	//there is no value in ordered array
	return -1;
}
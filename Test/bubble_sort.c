#include <stdio.h>

int bubble_sort( int a[], int len)
{
	int i,j;
	int temp;

	if( a==NULL || len ==0) return 0; 
	
	for(i=0; i<len; i++)
	{
		for(j=i+1; j<len; j++)
		{
			if( a[i]<a[j] ){
			
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	//return 1 for successfully
	return 1;
}

int print_array(int a[], int len)
{
	int i;
	if( a==NULL || len==0) return 0;

	printf("the array is:\n");
	for(i=0; i<len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 1;

}


int insert_array(int a[], int len, int n)
{
	int i, j, temp;
	i = j = temp = 0;
	if(a==NULL || len==0) return 0;

	//find the index of where to insert the value
	for(i=0; i<len; i++)
	{
		if( n>a[i] ){
			j = i;
			break;
		}
	}
	//move the remaining array
	for(i=10; i>=j; i--)
	{
		a[i]=a[i-1];
	}

	a[j] = n;
	
	return 1;
}
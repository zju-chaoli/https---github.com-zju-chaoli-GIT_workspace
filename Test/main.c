#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//#include "bubble_sort.h"


int main(int argc, char **argv)
{
	

	FILE *fp=NULL;
	FILE *fp2=NULL;
	char tempchar;

	//open the ASCII file
	if((fp=fopen("..\\1.txt", "rb+"))==NULL){
		printf("open file error\n");
		return 0;
	}
	//open another ASCII file
	if((fp2=fopen("..\\2.txt", "t+"))==NULL){
		printf("open 2.txt error\n");
		return 0;
	}

	
	//read the file and put it on screen
	while((tempchar=fgetc(fp))!=EOF)
	{
		putchar(tempchar);
		fputc(tempchar,fp2);
		
	}

	//pause on the console to facilitate the command line tool
    getch();
    return 1;
}


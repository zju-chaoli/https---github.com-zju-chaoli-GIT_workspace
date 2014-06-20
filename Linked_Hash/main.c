#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//define the linked node
#define STR_SIZE 20
#define HASH_TABLE_SIZE 10007
typedef struct _NODE{
	char address[STR_SIZE];
	struct _NODE *next;
}NODE;
NODE* Hash_Table[HASH_TABLE_SIZE];

//define the interface
int Insert(NODE* HashTable[],char *address);
int Delete(NODE* HashTable[], char *address);
NODE* Find(NODE* HashTable[], char *address);
unsigned int Hash(char *address, int table_size);
void Print(NODE* HashTable[],int table_size);

void main(int argc, char *argv[])
{
	char s[STR_SIZE];
	NODE input;

	//insert
	scanf("%s", s);
	while(strcmp(s,"exit")!=0)
	{
		Insert(Hash_Table,s);
		scanf("%s", s);
	}

	//debug
	Print(Hash_Table,HASH_TABLE_SIZE);

	
	//delete
	scanf("%s", s);
	while(strcmp(s,"exit")!=0)
	{
		Delete(Hash_Table,s);
		Print(Hash_Table,HASH_TABLE_SIZE);
		scanf("%s", s);
	}


	//pause on the console
	getch();
	return;
}

int Insert(NODE* HashTable[],char *address)
{
	NODE *result=NULL;
	unsigned int hashvalue=0;
	if(HashTable==NULL||address==NULL)
		return -1;
	result = Find(HashTable, address);
	if(result!=NULL)
		return 0;     //duplicate
	hashvalue = Hash(address,HASH_TABLE_SIZE);
	result=(NODE*)malloc(sizeof(NODE));
	result->next=HashTable[hashvalue];
	strcpy(result->address,address);
	HashTable[hashvalue]=result;

	return 1;
}
int Delete(NODE* HashTable[], char *address)
{
	NODE *result=NULL;
	NODE *parent=NULL;
	NODE *child = NULL;
	unsigned int hashvalue=0;
	if(HashTable==NULL||address==NULL)
		return -1;
	result=Find(HashTable,address);
	if(result==NULL)
		return -1;
	hashvalue=Hash(address,HASH_TABLE_SIZE);
	parent=HashTable[hashvalue];
	child=parent;
	while(child!=NULL)
	{
		if(strcmp(child->address,address)==0)
			break;
		parent=child;
		child=parent->next;
	}
	//free the child
	if(parent==child)
		HashTable[hashvalue]=child->next;
	else
		parent->next=child->next;
	free(child);
	return 1;
}
NODE* Find(NODE* HashTable[], char *address)
{
	NODE *result=NULL;
	unsigned int hashvalue = 0;
	if(HashTable==NULL||address==NULL)
		return NULL;
	hashvalue=Hash(address,HASH_TABLE_SIZE);
	result=HashTable[hashvalue];
	while(result!=NULL)
	{
		if(strcmp(result->address,address)==0)
			break;
		result = result->next;
	}

	return result;
	
}
unsigned int Hash(char *address, int table_size)
{
	char *key=NULL;
	unsigned int hashvalue=0;
	key=address;
	if(key==NULL)
		return -1;
	while(*key!='\0')
	{
		hashvalue=(hashvalue<<5)+*key;
		key++;
	}
	return hashvalue%table_size;
}

void Print(NODE* HashTable[],int table_size)
{
	int i=0;
	NODE *temp=NULL;
	while(i<table_size)
	{
		temp=HashTable[i];
		printf("HashTable[%d]->",i);
		while(temp!=NULL)
		{
			printf("%s->",temp->address);
			temp=temp->next;
		}
		printf("\n");
		i++;
	}
	return;
}
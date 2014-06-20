#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

//define the data structure
#define SIZE 7
typedef struct _NODE{
	int value;
	int depth;
	struct _NODE* left;
	struct _NODE* right;
}NODE;

//interface
void print(NODE *T);
NODE* insert(NODE *T, int value);
NODE* deleteNode(NODE *T, int value);
NODE* find(NODE *T,int value); 
NODE* findMIN_1(NODE *T);
NODE* findMIN_2(NODE *T);
NODE* findMAX_1(NODE* T);
NODE* findMAX_2(NODE* T);
int MAX(int a, int b);


void main(int argc, char* argv[])
{

	NODE *Tree=NULL;
	NODE *TMP=NULL;
	int i=0;
	int temp=0;
	for(i=0;i<SIZE;i++)
	{
		scanf("%d", &temp);
		Tree = insert(Tree, temp);
	}
	//print
	printf("\n +++++++before delete++++++++\n");
	print(Tree);

	printf("enter the value you want to delete:");
	scanf("%d",&temp);
	printf("\n");
	deleteNode(Tree,temp);

	printf("\n +++++++after delete++++++++\n");
	print(Tree);
	//pause on the console
	getch();
	return;
}

NODE* insert(NODE *T, int value)
{
	int ldepth = 0;
	int rdepth = 0;
	if(T==NULL){
		T = (NODE *)malloc(sizeof(NODE));
		T->value = value;
		T->depth = 1;
		T->left = NULL;
		T->right = NULL;
	}else{
		//left tree
		if(value < T->value){
			T->left = insert(T->left,value);
			ldepth = T->left->depth;
		}
		//right tree
		if(value > T->value){
			T->right = insert(T->right,value);
			rdepth = T->right->depth;
		}
		T->depth = MAX(ldepth, rdepth)+1;
	}
	return T;
}

NODE* deleteNode(NODE *T, int value)
{
	NODE *TMP = NULL;
	//find the Node
	if(T==NULL)
		return NULL;
	if(value<T->value)
		T->left=deleteNode(T->left,value);
	else if(value>T->value)
		T->right=deleteNode(T->right,value);
	else
	{
		if(T->left!=NULL&&T->right!=NULL)
		{
			TMP = findMIN_2(T->right);
			T->value=TMP->value;
			T->right=deleteNode(T->right,T->value);
		}
		else
		{
			TMP=T;
			if(T->left==NULL)
				T=T->right;
			else if(T->right==NULL)
				T=T->left;
			free(TMP);
		}
	}
	return T;
}


NODE* find(NODE *T,int value)
{
	if(T==NULL)
		return NULL;
	if(value<T->value){
		return find(T->left,value);
	}else if(value>T->value){
		return find(T->right,value);
	}else{
		return T;
	}
}

NODE* findMIN_1(NODE *T)
{
	NODE* Root=NULL;
	NODE* Child=NULL;
	if(T==NULL)
		return NULL;
	Root = T;
	Child = Root->left;
	while(Child!=NULL)
	{
		Root = Child;
		Child = Root->left;
	}
	return Root;
}

NODE* findMIN_2(NODE *T)
{
	if(T==NULL)
		return NULL;
	else
	{
		if(T->left!=NULL)
			return findMIN_2(T->left);
		else
			return T;
	}
}
NODE* findMAX_1(NODE* T)
{
	NODE* Root=NULL;
	NODE* Child=NULL;
	if(T==NULL)
		return NULL;
	Root = T;
	Child = Root->right;
	while(Child!=NULL)
	{
		Root = Child;
		Child = Root->right;
	}
	return Root;
}

NODE* findMAX_2(NODE* T)
{
	if(T==NULL)
		return NULL;
	else
	{
		if(T->right!=NULL)
			return findMAX_2(T->right);
		else
			return T;
	}
}

void print(NODE *T)
{
	if(T==NULL)
		return;
	//right-order print the Binary Tree
	if(T->left != NULL){
		print(T->left);
	}
	printf(" %d", T->value);

	if(T->right != NULL){
		print(T->right);
	}
	return;
}

int MAX(int a, int b)
{
	return  a>=b?a:b;
}
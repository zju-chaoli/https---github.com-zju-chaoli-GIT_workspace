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
NODE* SingleRotateWithLeft(NODE* T);
NODE* DoubleRotateWithLeft(NODE* T);
NODE* SingleRotateWithRight(NODE* T);
NODE* DoubleRotateWithRight(NODE* T);
NODE* find(NODE *T,int value); 
NODE* findMIN_1(NODE *T);
NODE* findMIN_2(NODE *T);
NODE* findMAX_1(NODE* T);
NODE* findMAX_2(NODE* T);
int MAX(int a, int b);
int Height(NODE* T);



void main(int argc, char* argv[])
{

	NODE *Tree=NULL;
	NODE *TMP=NULL;
	int i=0;
	int temp=0;
	
	printf("Enter the value you want to insert, negative value to exit:");
	scanf("%d", &temp);	
	while(temp>0)
	{
		Tree = insert(Tree, temp);
		print(Tree);
		printf("\n");
		printf("Input:");
		scanf("%d", &temp);
	}
	printf("\n");


	printf("enter the value you want to delete, negative value to exit:");
	scanf("%d", &temp);	
	while(temp>0)
	{
		Tree=deleteNode(Tree,temp);
		print(Tree);
		printf("\n");
		printf("Input:");
		scanf("%d", &temp);
	}
	printf("\n");

	//pause on the console
	//getch();
	return;
}

NODE* insert(NODE *T, int value)
{
	if(T==NULL){
		T = (NODE *)malloc(sizeof(NODE));
		T->value = value;
		T->depth = 0;
		T->left = NULL;
		T->right = NULL;
	}else{
		//left tree
		if(value < T->value){
			T->left = insert(T->left,value);
			if(abs(Height(T->left)-Height(T->right))>=2)
			{
				if(value<T->left->value)
					T=SingleRotateWithLeft(T);
				else
					T=DoubleRotateWithLeft(T);
			}
		}
		//right tree
		else if(value > T->value){
			T->right = insert(T->right,value);
			if(abs(Height(T->left)-Height(T->right))>=2)
			{
				if(value>T->right->value)
					T=SingleRotateWithRight(T);
				else
					T=DoubleRotateWithRight(T);
			}

		}
		T->depth = MAX(Height(T->left),Height(T->right))+1;
	}
	return T;
}

NODE* SingleRotateWithLeft(NODE* T)
{
	NODE *K2=T;
	NODE *K1=NULL;
	if(K2==NULL)
		return NULL;

	K1=K2->left;
	K2->left=K1->right;
	K1->right=K2;
	K2->depth = MAX(Height(K2->left), Height(K2->right))+1;
	K1->depth = MAX(Height(K1->left), K2->depth)+1;

	return K1;

}
NODE* DoubleRotateWithLeft(NODE* T)
{
	NODE *K3=T;
	if(K3==NULL)
		return NULL;
	K3->left=SingleRotateWithRight(K3->left);
	K3=SingleRotateWithLeft(K3);
	return K3;
	

}
NODE* SingleRotateWithRight(NODE* T)
{
	NODE *K2=T;
	NODE *K1=NULL;
	if(K2==NULL)
		return NULL;

	K1=K2->right;
	K2->right=K1->left;
	K1->left=K2;
	K2->depth = MAX(Height(K2->left), Height(K2->right))+1;
	K1->depth = MAX(Height(K1->right), K2->depth)+1;

	return K1;

}
NODE* DoubleRotateWithRight(NODE* T)
{
	NODE *K3=T;
	if(K3==NULL)
		return NULL;
	K3->right=SingleRotateWithLeft(K3->right);
	K3=SingleRotateWithRight(K3);
	return K3;
	

}

NODE* deleteNode(NODE *T, int value)
{
	NODE *TMP = NULL;
	//find the Node
	if(T==NULL)
		return NULL;
	if(value<T->value)
	{
		T->left=deleteNode(T->left,value);
		if(abs(Height(T->left)-Height(T->right))>=2)	
		{
			if(T->right->right!=NULL)
				T=SingleRotateWithRight(T);
			else
				T=DoubleRotateWithRight(T);
		}
	}
	else if(value>T->value)
	{
		T->right=deleteNode(T->right,value);
		if(abs(Height(T->left)-Height(T->right))>=2)	
		{
			if(T->left->left!=NULL)
				T=SingleRotateWithLeft(T);
			else
				T=DoubleRotateWithLeft(T);
		}
	}
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
	if(T!=NULL)
		T->depth=MAX(Height(T->left),Height(T->right))+1;      //re-evaluate the depth from left subtree and right subtree
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

int Height(NODE* T)
{
	if(T==NULL)
		return -1;
	else
		return T->depth;
}

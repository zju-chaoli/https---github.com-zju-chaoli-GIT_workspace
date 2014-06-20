#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//@data structure
typedef struct _Node
{
	int Element;
	struct _Node* Next;
}Node;
//global simple linked list
Node* Header = NULL;
Node* SimpleLinkedList = NULL;

//interface and implementation
int IsEmpty(Node* List)
{
	return List->Next == NULL;
}

int IsLast(Node *Position, Node *List)
{
	return Position->Next == NULL;
}

Node* Find_1(int Element, Node* List)
{
	Node *temp= List;
	while(temp)
	{
		if(temp->Element == Element)
		{
			return temp;
		}
		temp = temp->Next;
	}
	return NULL;
}

Node* Find_2(int Element, Node* List)
{
	Node *temp= List;
	
	while(temp!=NULL && temp->Element!=Element)
	{
		temp = temp->Next;
	}

	return temp;
}

Node* FindPrevious(int Element, Node* List)
{
	Node *TempCurr = List;

	while(TempCurr->Next!=NULL && TempCurr->Next->Element!=Element)
	{
		TempCurr = TempCurr->Next;
	}
	return TempCurr;
}

void Delete(int Element, Node* List)
{
	Node* Position, *Temp;
	Position = NULL;
	Temp = NULL;

	Position = FindPrevious(Element, List);

	if(!IsLast(Position, List)){
		Temp = Position->Next;
		Position->Next = Position->Next->Next;
		free((void*)Temp);
	}

	return;
}

Node* Previous(Node* Position, Node* List)
{
	Node *tempPrev=List;
	Node *tempCurr=List;

	while(tempCurr!=NULL&&tempCurr!=Position)
	{
		tempPrev = tempCurr;
		tempCurr = tempCurr->Next;
	}
	return tempPrev;
}

void main(int argc, char* argv[])
{
	return;
}

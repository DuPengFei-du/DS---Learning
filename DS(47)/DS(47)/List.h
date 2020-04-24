#pragma once 

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef struct SListNode
{
	int data;
	struct SListNode* next;
}Node;

typedef struct SList
{
	Node* head;
}List;

void SListInit(List* pl);

void SListDestroy(List* pl);

void SListPushBack(List* pl,int data);

void SListPushFront(List* pl, int data);

void SListPopBack(List* pl);

void SListPopFront(List* pl);

Node* SListFind(List* pl, int data);

void SListInsert(Node *pos,int data);

void SListErase(List* pl,Node* pos);

void SListPrint(List* pl);

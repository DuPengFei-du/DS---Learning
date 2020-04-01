#pragma once 

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

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
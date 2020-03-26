#pragma once 

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SListNode
{
	int data;
	struct SListNode* next;
}Node;

typedef struct List
{
	Node* head;
}List;

void SListInit(List* list);

void SListDestroy(List* list);

void SListPushBack(List* list,int data);

void SListPrint(List* list);
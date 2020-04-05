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

void SListSDestroy(List* pl);

void SListPushBack(List* pl,int data);

void SListPushFront(List* pl, int data);

void SListPopBack(List* pl);

void SListPopFront(List* pl);

void SListPrint(List* pl);
#pragma once 

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef struct DListNode
{
	int data;
	struct DListNode* next;
}Node;

typedef struct DList
{
	Node* head;
}DList;

void DListInit(DList* pl);

void DListDestroy(DList* pl);

void DListPushBack(DList* pl,int data);

void DListPushFront(DList* pl, int data);

void DListPopBack(DList* pl);

void DListPopFront(DList* pl);

void DListPrint(DList* pl);

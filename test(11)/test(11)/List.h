#pragma once


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef struct DLNode
{
	int data;
	struct DLNode* next;
}Node;


typedef struct DList
{
	Node* head;
}List;


void DListInit(List* pl);

void DListDestroy(List* pl);

void DListPushBack(List* pl,int data);

void DListPushFront(List* pl, int data);

void DListPopFront(List* pl);

void DListPopBack(List* pl);

void DListPrint(List* pl);

void DListInsert(List* pos,int data);

void DListErase(List* pl, Node* pos);

Node* Find(List* pl, int data);
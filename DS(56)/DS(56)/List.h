#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct ListNode
{
	int data;
	struct ListNode* next;
}Node;

typedef struct List
{
	Node* head;
}List;

void DListInit(List* pl);

void DListDestroy(List* pl);

void DListPushBack(List* pl, int data);

void DListPushFront(List* pl, int data);

void DListPopBack(List* pl);

void DListPopFront(List* pl);

void DListPrint(List* pl);

void DListInsert(Node* pos, int data);

void DListErase(List* pl, Node* pos);

#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<assert.h>


typedef struct DListNode
{
	int data;
	struct DListNode* next;
}Node;


typedef struct DList
{
	Node* head;
}List;


void DListInit(List* pl);

void DListDestroy(List* pl);

void DListPushBack(List* pl,int data);

void DListPushFront(List* pl, int data);

void DListPopBack(List* pl);

void DListPopFront(List* pl);

void DListPrint(List* pl);

void DListInsert(Node *pos,int data);


Node* Find(List* pl, int data);



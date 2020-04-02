#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


//���ṹ
typedef struct SListNode
{
	int data;
	struct SListNode* next;
}Node;

//����ṹ
typedef struct SList
{
	Node* head;
}List;

void SListInit(List* pl);

void SListDestroy(List* pl);

void SListPrint(List* pl);

void SListPushBack(List* pl,int data);

void SListPushFront(List* pl, int data);

void SListPopBack(List* pl);

void SListPopFront(List* pl);


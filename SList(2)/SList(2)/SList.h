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
}SList;

void SListInit(SList* pl);

void SListDestroy(SList* pl);

void SListPushBack(SList* pl,int data);

void SListPushFront(SList* pl,int data);

void SListPopBack(SList* pl);

void SListPopFront(SList* pl);

void SListpPrint(SList* pl);

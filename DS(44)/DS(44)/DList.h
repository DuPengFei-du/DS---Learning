#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef struct DListNode
{
	int data;
	struct DListNode* prev;
	struct DListNode* next;
}Node;

void DListInit(Node** phead);

void DListDestroy(Node** phead);

void DListPushBack(Node* phead,int data);

void DListPrint(Node* phead);

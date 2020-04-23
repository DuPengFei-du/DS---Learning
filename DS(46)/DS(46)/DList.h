#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct DLNode
{
	int data;
	struct DLNode* prev;
	struct DLNode* next;
}Node;

void DLNodeInit(Node** phead);

void DLNodeDestroy(Node** phead);

void DLNodePushBack(Node* phead,int data);

void DLNodePushFront(Node* phead, int data);

void DLNodePopBack(Node* phead);

void DLNodePopFront(Node* phead);

void DLNodeInsert(Node *pos,int data);

void DLNodeErase(Node *pos);

void DLNodePirnt(Node* phead);






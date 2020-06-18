#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef struct DLNode
{
	int data;
	struct DLNode* next;
	struct DLNode* prev;
}DLNode;


void DLNodeInit(DLNode** head);

void DLNodeDestroy(DLNode** head);

void DLNodePushBack(DLNode* head,int data);

void DLNodePushFront(DLNode* head, int data);

void DLNodePopFront(DLNode* head);

void DLNodePopBack(DLNode* head);

DLNode* DLNodeFind(DLNode* head, int data);
DLNode DLNodeInsert(DLNode* pos, int data);

DLNode DLNodeErase(DLNode* head, DLNode* pos);

void DLNodePrint(DLNode* head);

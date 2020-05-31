#pragma once 


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
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

void DLNodePopBack(DLNode* head);

void DLNodePopFront(DLNode* head);

void DLNodePrint(DLNode* head);

void DLNodeInsert(DLNode* pos,int data);

DLNode *DLNodeFind(DLNode* head, int data);
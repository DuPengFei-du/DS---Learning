#pragma once 


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

typedef struct DListNode
{
	int data;
	struct DListNode* next;
	struct DListNode* prev;
}Node;

void DLNodeInit(Node** head);

void DLNodeDestroy(Node** head);

void DLNodePrint(Node* head);

void DLNodePushBack(Node* head,int data);

void DLNodePushFront(Node* head, int data);

void DLNodePopBack(Node* head);

void DLNodePopFront(Node* head);

void DLNodeInsert(Node* pos, int data);

void DLNodeErase(Node* pos);







#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef struct DListNode
{
	int data;
	struct DListNode* next;
	struct DListNode* prev;
}Node;


void DLNodeInit(Node** head);

void DLNodeDestroy(Node** head);

void DLNodePushBack(Node* head,int data);

void DLNodePushFront(Node* head, int data);

void DLNodePopBack(Node* head);

void DLNodePopFront(Node* head);

void DLNodePrint(Node* head);

void DLNodeInsert(Node* pos,int data);

void DLNodeErase(Node* pos);

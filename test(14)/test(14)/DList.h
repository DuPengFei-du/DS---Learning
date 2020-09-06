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
}Node;


void DLNodeInit(Node** head);

void DLNodeDestroy(Node** head);

void DLNodePushBack(Node* head,int data);

void DLNodePushFront(Node* head, int data);

void DLNodePopFront(Node* head);

void DLNodePopBack(Node* head);

void DLNodePrint(Node* head);

void DLNodeInsert(Node* pos,int data);

void DLNodeErase(Node* pos);

Node* DLNodeFind(Node* head, int data);
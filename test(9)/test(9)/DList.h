#pragma once 


#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>


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

Node* DLNodeFind(Node* head,int data);

void DLNodeErase(Node* pos);

void DLNodeInsert(Node* pos,int data);
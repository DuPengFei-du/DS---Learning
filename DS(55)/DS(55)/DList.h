#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


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

void DLNodePopBack(Node* head);

void DLNodePopFront(Node* head);

void DLNodePrint(Node* head);

Node *DLNodeFind(Node* head,int data);



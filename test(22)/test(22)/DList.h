#pragma once


#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


typedef struct DListNode
{
	int data;
	struct DListNode* prev;
	struct DListNode* next;
}Node;

void DListNodeInit(Node** head);

void DListNodeDestroy(Node** head);

void DListNodePushBack(Node* head,int data);

void DListNodePushFront(Node* head, int data);

void DListNodePopBack(Node* head);

void DListNodePopFront(Node* head);

void DListNodePrint(Node* head);

void DListNodeErase(Node* pos);

Node *DListNodeFind(Node* pos,int data);
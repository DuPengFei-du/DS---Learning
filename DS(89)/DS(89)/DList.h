#pragma once


#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


typedef struct DLNode
{
	int data;
	struct DLNode* next;
	struct DLNode* prev;
}Node;


void DListInit(Node** head);

void DListDestroy(Node** head);

void DListPushBack(Node* head,int data);

void DListPushFront(Node* head, int data);

void DListPopFront(Node* head);

void DListPopBack(Node* head);

void DListPrint(Node* head);

void DListErase(Node* pos);

Node *DListFind(Node* head,int data);
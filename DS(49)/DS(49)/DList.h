#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//Ë«ÏòÁ´±í
typedef struct DListNode
{
	int data;
	struct DListNode* next;
	struct DListNode* prev;

}Node;


void DListInit(Node** head);

void DListDestroy(Node** head);

void DListPushBack(Node* head,int data);

void DListPushFront(Node* head, int data);

void DListPopBack(Node* head);

void DListPopFront(Node* head);

void DListPrint(Node* head);

void DListInsert(Node *pos,int data);

void DListErase(Node* head,Node* pos);

Node* Find(Node* head, int data);

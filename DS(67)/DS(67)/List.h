#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct ListNode
{
	int data;
	struct ListNode* next;
}Node;

typedef struct List
{
	Node* head;
}List;

void ListInit(List* pl);

void ListDestroy(List* pl);

void ListPushBack(List* pl,int data);

void ListPushFront(List* pl, int data);

void ListPopFront(List* pl);

void ListPopBack(List* pl);

void ListPrint(List* pl);

void ListInsert(Node *pos,int data);

void ListErase(List* pl, Node* pos);

Node* ListFind(List* pl, int data);


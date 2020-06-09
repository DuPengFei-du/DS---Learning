#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdlib.h>


typedef struct ListNode
{
	int data;
	struct ListNode* next;
}Node;


typedef struct List
{
	Node* head;
}List;


void ListInit(List* s);

void ListDestroy(List* s);

void ListPrint(List* s);

void ListPushBack(List* s,int data);

void ListPushFront(List* s, int data);

void ListPopBack(List* s);

void ListPopFront(List* s);

void ListInsert(Node *pos,int data);

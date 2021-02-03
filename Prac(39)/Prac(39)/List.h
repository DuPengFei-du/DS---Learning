#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
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


void NodeInit(List* pl);

void NodeDestroy(List* pl);

void NodePushBack(List* pl,int data);

void NodePushFront(List* pl, int data);

void NodePopFront(List* pl);

void NodePopBack(List* pl);

void NodePrint(List* pl);
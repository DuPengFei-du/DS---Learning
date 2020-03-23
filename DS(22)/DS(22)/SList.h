#pragma once //保证头文件不被重复包含
 
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

//结点结构
typedef struct SListNode
{
	int data;
	struct SListNode* next;
}Node;


//链表结构
typedef struct SList
{
	Node* head;
}List;

void SListInit(List* pl);

void SListDestroy(List* pl);

void SListPushBack(List* pl, int data);

void SListPrint(List* pl);

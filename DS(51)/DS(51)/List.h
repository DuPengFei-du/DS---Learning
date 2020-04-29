#pragma once 


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


typedef struct SListNode
{
	int data;
	struct SListNode *next;
}Node;

//为了操作简单，在把链表的结构给出来
//如果想要找到一个链表，那么只需要知道链表的头节点就可以了
typedef struct SList
{
	Node *head;
}SList;


void ListInit(SList* pl);

void ListDestroy(SList* pl);

void ListPushBack(SList* pl,int data);

void ListPushFront(SList* pl, int data);

void ListPopBack(SList* pl);

void ListPopFront(SList* pl);

void ListInsert(Node *pos,int data);

void ListErase(SList* pl,Node* pos);

void ListPrint(SList* pl);

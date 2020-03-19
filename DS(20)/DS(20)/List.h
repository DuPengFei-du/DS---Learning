#pragma once   //保证头文件不会被重复包含

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

//结点结构
typedef struct ListNode
{
	int data;
	struct ListNode* next;
}Node;

//链表结构
typedef struct List
{
	Node* head;
}List;


//初始化
void ListInit(List* s);

//尾插
void ListPushBack(List* s, int data);

//打印
void ListPrint(List* s);

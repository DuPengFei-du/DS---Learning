#pragma once

#include<stdio.h>
#include<stdlib.h>

// 1. 结点

typedef struct DNode {
	int val;
	struct DNode* prev;   //为他的前驱结点
	struct DNode* next;   //为他的后继结点
}	DNode;

// 2. 链表

typedef struct DList {
	DNode* head;	// 头结点（没有有效值）
}	DList;

// 初始化
void DListInit(DList* list) {
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->val = 0;		// 可以利用头结点的 val 保存链表中的有效结点个数
	node->next = node;
	node->prev = node;

	list->head = node;
}

//头插
void DListPushFront(DList* list, int val) {
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->val = val;
	//在这里还要考虑前驱指针的变化，一开始我忘记考虑了。
	node->prev = list->head;
	node->next = list->head->next;
	list->head->next->prev = node;
	list->head->next = node;
}

//尾插
void DListPushBack(DList* list, int val)
{
	//首先要有一个结点出来
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node ->val = val;
	//尾插就不需要再遍历了。因为head->prev 就是原先链表的最后一个结点
	node->prev = list->head->prev;
	node->next = list->head;
	list->head->prev->next = node;
	list->head->prev = node;
}

void DListInsertAfterPos(DNode* pos, int val)
{
	//在位置为pos的结点后面插入一个值
	//首先还是一样，先创造出一个节点来
	DNode* node = (DNode*)malloc(sizeof(DNode));
	node->val = val;
	node->prev = pos;
	node->next = pos->next;
	pos->next->prev = node;
	pos->next = node;
}

void DListInsertBeforePos(DNode* pos, int val)
{
	DListInsertAfterPos(pos->prev,val);
}

void DListPushFront(DList* list, int val) {
	DListInsertAfterPos(list->head, val);
}

void DListPushBack(DList* list, int val) {
	DListInsertAfterPos(list->head->prev, val);
}
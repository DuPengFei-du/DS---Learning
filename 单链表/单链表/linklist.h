#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//先定义结点的结构体
typedef struct Node
{
	int val;
	struct Node* next;
}Node;

//然后在定义一个链表的结构体
//单向不带头不循环链表中最特殊的就是第一个结点。
typedef struct List
{
	Node* head;   //链表的第一个结点
}List;


//初始化
void ListInit(List* list)
{
	list->head = NULL;
}

//销毁
void Destroy(List* list)
{
	//释放一条链表，就是要把链表中的每一个结点
	//都要释放掉，所以我们去遍历链表
	//释放掉链表中的结点
	Node* cur = list->head;
	while (cur != NULL)
	{
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	list->head = NULL;
}

//头插
//这个跟之前是有一点去别的
//之前的头插，最后是return，因为这个单向不带头不循环的链表
//已经把头结点放在结构体中了，就不用在return了
void ListPushFront(List* list, int val)
{
	//先装在一个结点里面
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = list->head;
	list->head = node;
}

//尾插
void PushBack(List* list, int val)
{
	//现装进结点
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	Node* cur = list->head;
	while (cur != NULL)
	{
		cur = cur->next;
	}
	//现在为最后一个结点
	//可以进行尾插了.
	cur->next = node;
	node->next = NULL;
}

//头删
void ListPopFront(List* list)
{
	//如果要删除，首先要确保链表是非空的
	assert(list->head != NULL);
	Node* second = list->head->next;
	free(list->head);
	list->head = second;
}

//尾删
void ListPopBack(List* list)
{
	//确保链表不是空的
	assert(list->head != NULL);
	//至少要有两个结点
	//假如只有一个结点的话
	if (list->head->next == NULL)
	{
		free(list->head);
		list->head = NULL;
	}
	else
	{
		Node* cur = list->head;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

//根据下标做插入
//index肯定是合法的下标的前提下
void ListInsert(List* list, int index, int val)
{
	//做插入，首先也要找的下标为index的元素的前驱结点
	Node* prev = list->head;
	for (int i = 0; i < index - i; i++)
	{
		prev = prev->next;
	}
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = prev->next;
	prev->next = node;
}

//求长度
int ListLength(List* list)
{
	int count = 0;
	for (Node* cur = list->head; cur != NULL; cur = cur->next)
	{
		count++;
	}
	return count;
}
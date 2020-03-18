//用链表来写队列
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//先定义结点
typedef struct Node
{
	int val;
	struct Node* next;
}Node;

//再定义队列
typedef struct Queue
{
	Node* front;     //相当于是之前的head
	Node* rear;      //相当于是之前的last
};

//初始化
void QueueInit(Queue* q)
{
	q->front = q->rear = NULL;
}

//插入
void QueuePush(Queue* q,int val)
{
	//在队列中的插入，其实就是之前的尾插操作
	//先定义一个节点出来
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL)
	{
		assert(0);
		return;
	}
	node->val = val;
	if (q->front == NULL)
	{
		q->front = node;
	}
	else
	{
		q->rear->next = node;
	}
	q->rear = node;
}

//删除
int QueuePop(Queue* q)
{
	assert(q->front != NULL);
	Node* second = q->front->next;
	int val = q->front->val;
	free(q->front);
	q->front = second;
	if (q->front = NULL)
	{
		q->rear = NULL;
	}
	return q->front->val;
}

//返回队首元素的值
int QueueFront(Queue* q)
{
	assert(q->front != NULL);
	return q->front->val;
}


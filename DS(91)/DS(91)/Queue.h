#pragma once


#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


typedef struct QueueNode
{
	int data;
	struct QueueNode* next;
}Node;


typedef struct Queue
{
	Node* front;
	Node* rear;
}Queue;


void QueueInit(Queue* q);

//销毁
void QueueDestroy(Queue* q);

//入队
void QueuePush(Queue* q, int data);

//出队
void QueuPop(Queue* q);

//元素个数
int QueueSize(Queue* q);

//是否为空
int QueueEmpty(Queue* q);
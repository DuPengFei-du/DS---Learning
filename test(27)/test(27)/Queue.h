#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


typedef struct QueueNode
{
	struct QueueNode* next;
	int data;
}QNode;



typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;


//初始化
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
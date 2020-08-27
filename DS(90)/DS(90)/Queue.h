#pragma once 


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


typedef struct QueueNode
{
	int _data;
	struct QueueNode* _pNext;
}QNode;


typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;


void QueueInit(Queue* q);

void QueueDestroy(Queue* q);

void QueuePush(Queue* q,int data);

void QueuePop(Queue* q);

int QueueSize(Queue* q);

int QueueEmpty(Queue* q);
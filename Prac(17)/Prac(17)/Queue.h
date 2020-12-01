#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef struct QListNode
{
	int data;
	struct QListNode* next;
}Node;



typedef struct Queue
{
	Node* front;
	Node* rear;
}Queue;


void QueueInit(Queue* q);

void QueueDestroy(Queue* q);

void QueuePush(Queue* q,int data);

void QueuePop(Queue* q);

int QueueEmpty(Queue* q);

int QueueSize(Queue* q);
#pragma once 


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>


typedef struct QueueNode
{
	int data;
	struct QueueNode* next;
}Node;

typedef struct Queue
{

	Node* rear;
	Node* front;
}Queue;

void QListNodeInit(Queue* q);

void QListNodeDestroy(Queue* q);

void QListNodePush(Queue* q,int data);

void QListNodePop(Queue* q);

int QListNodeEmpty(Queue* q);

int QListNodeSize(Queue* q);
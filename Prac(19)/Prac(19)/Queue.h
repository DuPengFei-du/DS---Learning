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
	Node* front;
	Node* rear;
}Queue;


void NodeInit(Queue* q);

void NodeDestroy(Queue* q);

void NodePush(Queue* q,int data);

void NodePop(Queue* q);

int NodeEmpty(Queue* q);

int NodeSize(Queue* q);
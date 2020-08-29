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

//����
void QueueDestroy(Queue* q);

//���
void QueuePush(Queue* q, int data);

//����
void QueuPop(Queue* q);

//Ԫ�ظ���
int QueueSize(Queue* q);

//�Ƿ�Ϊ��
int QueueEmpty(Queue* q);
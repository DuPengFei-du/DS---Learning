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


//��ʼ��
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
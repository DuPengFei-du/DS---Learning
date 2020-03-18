//��������д����
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//�ȶ�����
typedef struct Node
{
	int val;
	struct Node* next;
}Node;

//�ٶ������
typedef struct Queue
{
	Node* front;     //�൱����֮ǰ��head
	Node* rear;      //�൱����֮ǰ��last
};

//��ʼ��
void QueueInit(Queue* q)
{
	q->front = q->rear = NULL;
}

//����
void QueuePush(Queue* q,int val)
{
	//�ڶ����еĲ��룬��ʵ����֮ǰ��β�����
	//�ȶ���һ���ڵ����
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

//ɾ��
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

//���ض���Ԫ�ص�ֵ
int QueueFront(Queue* q)
{
	assert(q->front != NULL);
	return q->front->val;
}


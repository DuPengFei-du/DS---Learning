#pragma once      //��֤ͷ�ļ�ֻ��������

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef int QDataType;
//����һ����ʽ�Ľ��ṹ
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

//���еĽṹ
typedef struct Queue
{
	QNode* _front;   //����������͵�ָ��
	QNode* _rear;   //����������͵�ָ��
}Queue;

//��ʼ��
void QueueInit(Queue* q);

//����
void QueueDestroy(Queue* q);

//���
void QueuePush(Queue* q, QDataType data);

//����
void QueuPop(Queue* q);

//��һ��Ԫ��
QDataType QueueFront(Queue* q);

//���һ��Ԫ��
QDataType QueueBack(Queue* q);

//Ԫ�ظ���
int QueueSize(Queue* q);

//�Ƿ�Ϊ��
int QueueEmpty(Queue* q);



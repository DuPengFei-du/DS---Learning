#pragma once      //保证头文件只包含依次

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef int QDataType;
//给出一个链式的结点结构
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

//队列的结构
typedef struct Queue
{
	QNode* _front;   //给出结点类型的指针
	QNode* _rear;   //给出结点类型的指针
}Queue;

//初始化
void QueueInit(Queue* q);

//销毁
void QueueDestroy(Queue* q);

//入队
void QueuePush(Queue* q, QDataType data);

//出队
void QueuPop(Queue* q);

//第一个元素
QDataType QueueFront(Queue* q);

//最后一个元素
QDataType QueueBack(Queue* q);

//元素个数
int QueueSize(Queue* q);

//是否为空
int QueueEmpty(Queue* q);



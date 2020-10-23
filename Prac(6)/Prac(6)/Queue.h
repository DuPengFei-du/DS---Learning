#pragma once


#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


//���ṹ
typedef struct QListNode
{
	struct QListNode* next;
	int data;
}Node;


//����ṹ
typedef struct QList
{
	Node* front;
	Node* rear;
}QList;



void QListInit(QList* q);

void QListDestroy(QList* q);

void QListPush(QList* q,int data);

void QListPop(QList* q);

int QListEmpty(QList* q);

int QListSize(QList* q);



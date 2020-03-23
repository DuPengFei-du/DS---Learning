#pragma once //��֤ͷ�ļ������ظ�����
 
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

//���ṹ
typedef struct SListNode
{
	int data;
	struct SListNode* next;
}Node;


//����ṹ
typedef struct SList
{
	Node* head;
}List;

void SListInit(List* pl);

void SListDestroy(List* pl);

void SListPushBack(List* pl, int data);

void SListPrint(List* pl);

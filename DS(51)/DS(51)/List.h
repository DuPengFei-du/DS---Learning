#pragma once 


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


typedef struct SListNode
{
	int data;
	struct SListNode *next;
}Node;

//Ϊ�˲����򵥣��ڰ�����Ľṹ������
//�����Ҫ�ҵ�һ��������ôֻ��Ҫ֪�������ͷ�ڵ�Ϳ�����
typedef struct SList
{
	Node *head;
}SList;


void ListInit(SList* pl);

void ListDestroy(SList* pl);

void ListPushBack(SList* pl,int data);

void ListPushFront(SList* pl, int data);

void ListPopBack(SList* pl);

void ListPopFront(SList* pl);

void ListInsert(Node *pos,int data);

void ListErase(SList* pl,Node* pos);

void ListPrint(SList* pl);

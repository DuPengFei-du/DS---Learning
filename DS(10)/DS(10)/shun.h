#pragma once

#include<assert.h>
#include<string.h>
#include<stdio.h>

//��̬˳���Ľṹ
//typedef struct SeqList
//{
//	int array[100];
//	int size = 0;
//	int capacity = 0;
//}SeqList;

//��̬˳���ṹ
#define Default_Capacity 100
typedef struct SeqList
{
	int* array;
	int _size;
	int _capacity;
}SeqList;


//���Խ��в�����
//��ʼ������
void SeqListInit(SeqList* seq);

//���ٲ���
void SeqListDestroy(SeqList* seq);

//β�����--ʱ�临�Ӷ�ΪO(1)
void SeqListPushBack(SeqList* seq,int val);

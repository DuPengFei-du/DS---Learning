#pragma once 

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//��̬˳���
//typedef struct SeqList
//{
//	int arr[10];
//	int _size;
//	int _capacity;
//}SeqList;


//��̬˳���
#define Default_Capacity 100


typedef struct SeqList
{
	int* array;
	int _size;
	int _capacity;
}SeqList;


//��ʼ������
void SeqListInit(SeqList* seq);

//���ٲ���
void SeqListDestroy(SeqList* seq);

//β�����
void SeqListPushBack(SeqList* seq,int val);

//βɾ
void SeqListPopBack(SeqList* seq);

//��ӡ
void SeqListPrint(SeqList* seq);

//ͷ��
void SeqListPushFront(SeqList* seq, int val);

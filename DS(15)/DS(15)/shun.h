#pragma once

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//��̬˳���
//typedef struct SeqList
//{
//	int arr[100];
//	int size;
//	int capacity
//}SeqList;


//��̬˳���
#define Dafault_Capacity 100

typedef struct SeqList
{
	int* array;
	int _size;
	int _capacity;
}SeqList;


//��ʼ��
void SeqListInit(SeqList* seq);

//����
void SeqListDestroy(SeqList* seq);

//β��
void SeqListPushBack(SeqList* seq, int val);

//��ӡ
void SeqListPrint(SeqList* seq);

//ͷ��
void SeqListPushFront(SeqList* seq, int val);

//ͷɾ
void SeqListPopFront(SeqList* seq);

//����λ�õĲ���
void SeqListInsert(SeqList* seq,int index,int val);

//����λ�õ�ɾ��
void SeqListErase(SeqList* seq, int index);

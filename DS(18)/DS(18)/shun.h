#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

//��̬˳���
//typedef struct SeqList
//{
//	int arr[100];
//	int _size;
//	int _capacity;
//}SeqList;

//��̬˳��� 
#define Default_Capacity 100

typedef struct SeqList
{
	int* array;
	int _size;
	int capacity;
}SeqList;

//��ʼ��
void SeqListInit(SeqList* seq);

//����
void SeqDestroy(SeqList* seq);

//β��
void SeqListPushBack(SeqList* seq,int data);

//��ӡ
void SeqListPrint(SeqList* seq);

//βɾ
void SeqListPopBack(SeqList* seq);

//ͷ��
void SeqListPushFront(SeqList* seq, int data);

//ͷɾ
void SeqListPopFront(SeqList* seq);

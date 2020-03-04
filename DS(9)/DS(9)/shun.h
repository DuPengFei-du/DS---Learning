#pragma once

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>


//��̬˳���Ľṹ
//typedef struct SeqList
//{
//	int array[10];
//	int size;          //��ЧԪ�صĸ���
//	int capacity;      //�����Ĵ�С
//}SeqList;


//��̬˳���Ľṹ
#define Default_Capacity 100
typedef struct SeqList
{
	int* array;   //����int���͵����ݣ���Ȼ�ˣ�Ҳ�����Ǳ�����͵�����
	int size;
	int capacity;
}SeqList;
//��̬˳���Ľṹ�Ѿ��������ˣ��������˳���Ĳ���

//��ʼ������
void SeqListInit(SeqList* seq);

//���ٲ���
void SeqListDestroy(SeqList* seq);

#pragma once  //��ֹͷ�ļ�����ΰ���

#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>

//SeqList  ---  �洢�������Ŀռ���  --->����

#define MAX_SIZE 100
typedef int DataType;

//��̬˳���
//struct SeqList
//{
//	DataType array[MAX_SIZE];   //����˳�������ЧԪ�صĸ���
//	DataType size;              //˳�������ЧԪ�صĸ���
//};


//��̬˳���
#define Dafault_Capacity 10
typedef struct SeqList
{
	DataType* _array;     //����˳�������ЧԪ�صĸ���
	int _size;	         //��ЧԪ�صĸ���
	int _capacity;       //�ռ��ܴ�С
}SeqList;//*PSeqList;      //PSeqList�ǽṹ���Ǻ����͵�ָ�룬Ҳ����˵��
//�ҿ���ֱ������������ָ��

//��ʼ������
void SeqListInit(SeqList *ps);  //������ôд�Ļ����Ҿ���Ҫ֪��ps��ָ����

//���ٲ���
void SeqListDestroy(SeqList* ps);  //������ôд�Ļ����Ҿ���Ҫ֪��ps��ָ����

//β��
void SeqListPushBack(SeqList* ps,DataType data);

//βɾ
void SeqListPopBack(SeqList* ps);

//ͷ��
void SeqListPushFront(SeqList* ps, DataType data);

//ͷɾ
void SeqListPopFront(SeqList* ps);

//��ӡ
void SeqListPrint(SeqList* ps);

//����λ�õĲ���
void SeqListInsert(SeqList* ps, int pos, DataType data);

//����λ�õ�ɾ��
void SeqListErase(SeqList* ps, int pos);

//��զԪ��
int SeqListFind(SeqList* ps, DataType data);

//�Ƴ�����һ��ֵΪdata��Ԫ��
void SeqListRemove(SeqList* ps,DataType data);

//�Ƴ�ȫ��ֵΪData��Ԫ��
void SeqListRemoveAll(SeqList* ps,DataType data);

//Ԫ�صĸ���
int SeqListSize(SeqList* ps);

//����
int SeqLisCapacity(SeqList* ps);

//�ж��Ƿ�Ϊ��
int SeqLisEmpty(SeqList* ps);

//���ص�һ��Ԫ��
DataType SeqListFront(SeqList* ps);

//�������һ��Ԫ��
DataType SeqListBack(SeqList* ps);
#pragma once   //��ֹ�ļ����ظ�����

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//#define MAXSIZE 20
#define DefaultCapacity 20 
typedef int DataType;   //��Ϊ�洢�Ŀ��ܲ�ֻ�����Σ�����ʹ��ͨ�õ�����
//  SeqList�洢�������Ŀռ�֮��  ---   ����
//��̬˳���
//struct SeqList
//{
//	DataType array[MAXSIZE];   //����˳���������Ԫ��ĸ���
//	int size;             //˳�������ЧԪ�صĸ���
//};
//��̬˳���
//���Խṹ���еĶ�̬�ռ䲻�ܸ���
typedef struct SeqList
{
	DataType* array;   //����˳�������ЧԪ�ظ���
	int _size;         //��¼��ЧԪ�صĸ���
	int _capacity;     //�ռ��ܴ�С
}SeqList;

void SeqListInit(SeqList* seq);  //��ָ���ԭ���ǣ��ṹ����ܱȽϴ�
//���ô�ֵ�ķ�ʽ���ͻ���Щ�˷ѿռ�

void SeqListPrint(SeqList* seq);

void SeqListDestroy(SeqList* seq);  //��̬���ٵĿռ���Ҫ�ֶ��Ľ����ͷ�

void SeqListPushBack(SeqList* seq, DataType data);  //����β��Ĳ���

void SeqListPopBack(SeqList* seq);   //βɾ
  
void SeqListPushFront(SeqList* seq, DataType data);  //ͷ��

void SeqListPopFront(SeqList* seq);   //ͷɾ

void SeqListInsert(SeqList* seq, int index, DataType data);//������λ�ý��в���

void SeqListErase(SeqList* seq, int index); //������λ�ý���ɾ��

int SeqListFind(SeqList* seq, DataType data);    //����Ԫ��

void SeqListRemove(SeqList* seq, DataType data);  //�Ƴ���һ��ֵΪdata��Ԫ��

void SeqListRemoveAll(SeqList* seq, DataType data);  //�Ƴ�����ֵΪdata��Ԫ��

int SeqSize(SeqList* seq);  //��ȡ˳�����Ԫ�صĸ���

int SeqCapacity(SeqList* seq);  //��ȡ˳��������

int SeqListEmpty(SeqList* seq);   //�ж�˳����Ƿ�Ϊ��

DataType SeqListFront(SeqList* seq);  //��ȡ˳���ĵ�һ��Ԫ��

DataType SeqListLast(SeqList* seq);   //��ȡ˳�������һ��Ԫ��
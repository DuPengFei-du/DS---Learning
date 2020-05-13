//����ͷ���ĵ�����   
//����ͷ���Ļ�����ô������еĵ�һ���ڵ�һ���洢������ЧԪ��

#pragma once  //��֤ͷ�ļ������ظ�����


#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
//�����Ҫ��������в�������ô������Ҫһ�����Ľṹ��

typedef int SDataType;

typedef struct SListNode
{
	SDataType data;
	struct SListNode* _pNext;
}Node;

//Ϊ�˲����򵥣��ڰ�����Ľṹ������
//�����Ҫ�ҵ�һ��������ôֻ��Ҫ֪�������ͷ�ڵ�Ϳ�����
typedef struct SList
{
	Node* _pHead;
}SList;

//��ʼ��
void SListInit(SList* pl);

//β��
void SListPushBack(SList* pl, SDataType data);

//βɾ
void SListPopBack(SList* pl);

//����
void SListDestroy(SList* pl);

//��ӡ
void PrintSList(SList* pl);

//����
void TestList();

//ͷ��
void SListPushFront(SList* pl, SDataType data);

//ͷɾ
void SListPopFront(SList* pl);

//����λ�õĲ���
void SListInsert(Node* pos, SDataType data);

//����λ�õ�ɾ��
void SListErase(SList* pl, Node* pos);   //��Ҫ����ȥ�ҵ�pos��ǰһ��λ��

//����
Node* SListFind(SList* pl, SDataType data);

//����
int SListSize(SList* pl);


//�������һ�����
Node* SListBack(SList* pl);


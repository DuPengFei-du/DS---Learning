//����ͷ�ڵ�ĵ�����

#pragma once      //��ֹͷ�ļ�����ΰ���

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataType;   //����������

//�������Ľṹ��
typedef struct SListNode
{
	DataType data;
	struct SListNode* next;
}Node;

//��������Ľṹ��
//����ֻҪ֪���������һ��Ԫ�صĵ�ַ���Ϳ������ҵ���������������
typedef struct SList
{
	Node* _pHead;
}SList;


//����ͷ�ڵ�ĵ�����
//����ͷ���ĵ������һ������д洢������Ч��Ԫ��(��ͷ�Ͳ���ͷ������)

void SListInit(SList* p1);     //��ʼ��

void SListPushBack(SList* p1, DataType data);   //β��

void SListPopBack(SList* p1);   //βɾ

void SListDestroy(SList* p1);

void SListPrint(SList* p1);

void SListPopFront(SList* p1);

void SListPushFront(SList* p1, DataType data);   //β��

void SListInsertAfter(Node* pos, DataType data);  //������λ�õĲ���
 
void SListErase(SList* p1,Node* pos);     //������λ�õ�ɾ��

Node* SListFind(SList* p1, DataType data);

int SListSize(SList* p1);    //Ԫ�ظ���

int SListEmpty(SList* p1);   //�ж��Ƿ�Ϊ��

Node* SListFront(SList* p1);  //��һ��Ԫ��

Node* SListBack(SList* p1);     //���һ��Ԫ��

void SListRemove(SList* p1, DataType data);    //�Ƴ�

void SListRemoveAll(SList* p1, DataType data);  //�Ƴ�����


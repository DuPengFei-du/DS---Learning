#pragma once//����ͷ�ļ�ֻ����һ��

typedef struct SeqList
{
	int *array;     //��¼���ݴ��λ��
	int capacity;   //��¼������
	int size;       //��¼�������ݵĸ���
}SeqList;
//Ϊ�ṹ����һ������
//typedef struct SeqList SeqList;
void SeqListInit(SeqList* seq);
void SeqListDestroy(SeqList* seq);
void SeqListPushFront(SeqList* seq, int val);
void SeqListPushBack(SeqList* seq, int val);
void SeqListPrint(SeqList* seq);
//�����±�������
void SeqListInsert(SeqList* seq, int index, int val);
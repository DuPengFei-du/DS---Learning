#pragma once//����ͷ�ļ�ֻ����һ��

typedef struct SeqList
{
	int* array;     //��¼���ݴ��λ��
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
//ͷɾ
void SeqListPopFront(SeqList* seq);
//βɾ
void SeqListPopBack(SeqList* seq);
//�����±�ɾ��
void SeqListErase(SeqList* seq, int index);
//����Ԫ��
int SeqListFind(SeqList* seq, int val);
//���ҵ�һ��������val
void SeqListRemove(SeqList* seq, int val);
//ɾ��˳��������е�val
void SeqListRemoveAll(SeqList* seq, int val);
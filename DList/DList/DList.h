//��ͷ�ڵ��˫��ѭ������


//ΪʲôҪ��ͷ
//ԭ������Ϊ�������ͷ�Ļ�����ôͷ�����ͷɾ��Ƚ��鷳
//���Ҳ���ͷ�Ļ���Ҫ���ݶ���ָ�룬��ͷ�Ļ���ֻ��Ҫ����һ��ָ��
//Ϊʲô����˫��ģ�
//(��һ�������ǿ��������ӡ����)
//Ҳ���Ƕ���Щ�������һЩ

#pragma once  // ��֤ͷ�ļ����ᱻ�ظ�����

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef int DLDataType;

//����Ľ��ṹ
typedef struct DListNode
{
	struct DListNode* _pNext;
	struct DListNode* _pPre;
	DLDataType data;
}DLNode;

//��ʼ��
void DListInit(DLNode** pHead);

//β��
void DListPushBack(DLNode* pHead, DLDataType data);

//βɾ
void DListPopBack(DLNode* pHead);

//ͷ��
void DListPushFront(DLNode* pHead, DLDataType data);

//ͷɾ
void DListPopFront(DLNode* pHead);

//����
void DListDestroy(DLNode** pHead);

//�����µĽ��
DLNode* BuyDLNode(DLDataType data);

//��ӡ����
void PrintList(DLNode* pHead);

//����
DLNode* DListFind(DLNode* pHead, DLDataType data);

//����λ�õĲ���
void DListInsert(DLNode* pos, DLDataType data);

//����λ�õ�ɾ��
void DListErase(DLNode* pos);

//����������Ч�ڵ�ȫ�����
void DListClear(DLNode* pos);














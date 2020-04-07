#include"DList.h"


int main()
{
	DLNode* pHead = NULL;

	DListInit(&pHead);

	DListPushBack(pHead, 1);      //���뺯������Ҫ�ı�ͷָ���ָ�����Բ���Ҫȡ��ַ�ķ���
	DListPushBack(pHead, 2);
	DListPushBack(pHead, 3);
	DListPushBack(pHead, 4);
	DListPushBack(pHead, 5);

	PrintList(pHead);

	DListPopBack(pHead);
	DListPopBack(pHead);

	PrintList(pHead);

	DListPushFront(pHead, 10);
	DListPushFront(pHead, 20);
	DListPushFront(pHead, 30);
	DListPushFront(pHead, 40);
	DListPushFront(pHead, 50);

	PrintList(pHead);

	DListPopFront(pHead);
	DListPopFront(pHead);

	PrintList(pHead);

	DListDestroy(&pHead);
}
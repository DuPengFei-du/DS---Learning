#include"DList.h"


int main()
{
	DLNode* pHead = NULL;

	DListInit(&pHead);

	DListPushBack(pHead, 1);      //插入函数不需要改变头指针的指向，所以不需要取地址的符号
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
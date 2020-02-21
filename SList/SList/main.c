#include"SList.h"


int main()
{
	SList s;

	SListInit(&s);

	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);

	SListPrint(&s);

	SListPopBack(&s);
	SListPopBack(&s);

	SListPrint(&s);

	SListPushFront(&s, 10);
	SListPushFront(&s, 20);
	SListPushFront(&s, 30);
	SListPushFront(&s, 40);
	SListPushFront(&s, 50);

	SListPrint(&s);

	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);

	SListPrint(&s);

	SListDestroy(&s);

	return 0;

}
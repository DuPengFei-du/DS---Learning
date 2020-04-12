#include"List.h"

int main()
{
	List s;

	SListInit(&s);

	SListPushBack(&s, 10);
	SListPushBack(&s, 20);
	SListPushBack(&s, 30);
	SListPushBack(&s, 40);
	SListPushBack(&s, 50);

	SListPrint(&s);

	SListPushFront(&s, 1);
	SListPushFront(&s, 2);
	SListPushFront(&s, 3);
	SListPushFront(&s, 4);
	SListPushFront(&s, 5);

	SListPrint(&s);

	SListPopBack(&s);
	SListPopBack(&s);

	SListPrint(&s);

	SListPopFront(&s);
	SListPopFront(&s);

	SListPrint(&s);

	SListSDestroy(&s);
}
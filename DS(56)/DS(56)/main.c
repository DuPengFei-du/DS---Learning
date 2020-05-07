#include"List.h"


int main()
{
	List s;

	DListInit(&s);

	DListPushBack(&s, 1);
	DListPushBack(&s, 2);
	DListPushBack(&s, 3);
	DListPushBack(&s, 4);
	DListPushBack(&s, 5);

	DListPrint(&s);

	DListPushFront(&s, 10);
	DListPushFront(&s, 20);
	DListPushFront(&s, 30);
	DListPushFront(&s, 40);
	DListPushFront(&s, 50);

	DListPrint(&s);

	DListPopBack(&s);
	DListPopBack(&s);

	DListPrint(&s);

	DListPopFront(&s);
	DListPopFront(&s);

	DListPrint(&s);

	DListDestroy(&s);
}
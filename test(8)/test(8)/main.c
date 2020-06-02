#include"List.h"


int main()
{
	List s;

	ListInit(&s);

	ListPushBack(&s, 2);
	ListPushBack(&s, 4);
	ListPushBack(&s, 6);
	ListPushBack(&s, 8);
	ListPushBack(&s, 10);


	ListPrint(&s);

	ListPushFront(&s, 1);
	ListPushFront(&s, 3);
	ListPushFront(&s, 5);
	ListPushFront(&s, 7);
	ListPushFront(&s, 9);


	ListPrint(&s);

	ListPopFront(&s);
	ListPopFront(&s);

	ListPrint(&s);

	ListPopBack(&s);
	ListPopBack(&s);

	ListPrint(&s);

	ListInsert(ListFind(&s, 5), 46);

	ListPrint(&s);

	ListErase(&s, ListFind(&s, 46));

	ListPrint(&s);


	ListDestroy(&s);
}
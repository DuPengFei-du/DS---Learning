#include"List.h"


int main()
{
	List s;

	ListInit(&s);

	ListPushBack(&s, 1);
	ListPushBack(&s, 2);
	ListPushBack(&s, 3);
	ListPushBack(&s, 4);
	ListPushBack(&s, 5);

	ListPrint(&s);

	ListPushFront(&s, 10);
	ListPushFront(&s, 20);
	ListPushFront(&s, 30);
	ListPushFront(&s, 40);
	ListPushFront(&s, 50);

	ListPrint(&s);

	ListPopFront(&s);
	ListPopFront(&s);

	ListPrint(&s);

	ListPopBack(&s);
	ListPopBack(&s);

	ListPrint(&s);

	ListDestroy(&s);
}
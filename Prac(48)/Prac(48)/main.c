#include"List.h"


int main()
{
	List s;

	ListInit(&s);

	ListPushBack(&s, 10);
	ListPushBack(&s, 20);
	ListPushBack(&s, 30);
	ListPushBack(&s, 40);
	ListPushBack(&s, 50);

	ListPrint(&s);

	ListPushFront(&s, 1);
	ListPushFront(&s, 2);
	ListPushFront(&s, 3);
	ListPushFront(&s, 4);
	ListPushFront(&s, 5);

	ListPrint(&s);

	ListPopFront(&s);
	ListPopFront(&s);

	ListPrint(&s);

	ListPopBack(&s);
	ListPopBack(&s);

	ListPrint(&s);

	ListDestroy(&s);
}

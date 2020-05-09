#include"DList.h"

int main()
{
	DList s;

	DListInit(&s);

	DListPushBack(&s, 10);
	DListPushBack(&s, 20);
	DListPushBack(&s, 30);
	DListPushBack(&s, 40);
	DListPushBack(&s, 50);

	DListPrint(&s);

	DListPushFront(&s, 1);
	DListPushFront(&s, 2);
	DListPushFront(&s, 3);
	DListPushFront(&s, 4);
	DListPushFront(&s, 5);
	
	DListPrint(&s);

	DListPopFront(&s);
	DListPopFront(&s);

	DListPrint(&s);

	DListPopBack(&s);
	DListPopBack(&s);

	DListPrint(&s);

	DListDestroy(&s);
}
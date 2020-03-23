#include"SList.h"

int main()
{
	List s;

	SListInit(&s);

	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);

	SListPrint(&s);

	SListDestroy(&s);
}
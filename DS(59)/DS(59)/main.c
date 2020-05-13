#include"DList.h"

void TestList1()
{
	SList s;  //创建一个对象

	SListInit(&s);

	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);

	PrintSList(&s);

	SListPopBack(&s);

	PrintSList(&s);

	SListPushFront(&s, 10);
	SListPushFront(&s, 20);
	SListPushFront(&s, 30);
	SListPushFront(&s, 40);
	SListPushFront(&s, 50);

	PrintSList(&s);

	SListPopFront(&s);
	SListPopFront(&s);

	PrintSList(&s);

	SListInsert(SListFind(&s, 2), 66);

	PrintSList(&s);

	SListErase(&s, SListFind(&s, 66));

	PrintSList(&s);

	SListDestroy(&s);
}

void TestList()
{
	TestList1();
}

int main()
{
	TestList();
	return 0;
}

#include"shun.h"

int main()
{
	SeqList s;

	SeqListInit(&s);

	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 10);

	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPrint(&s);

	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 5);
	SeqListPushFront(&s, 7);
	SeqListPushFront(&s,9);

	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPrint(&s);

	SeqListInsert(&s, 2, 46);

	SeqListPrint(&s);

	SeqListErase(&s, 2);

	SeqListPrint(&s);

	SeqListDestroy(&s);
}
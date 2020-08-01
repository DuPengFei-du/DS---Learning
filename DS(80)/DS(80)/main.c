#include"Seq.h"


int main()
{
	SeqList s;

	SeqListInit(&s);

	SeqListPushBack(&s, 10);
	SeqListPushBack(&s, 20);
	SeqListPushBack(&s, 30);
	SeqListPushBack(&s, 40);
	SeqListPushBack(&s, 50);

	SeqListPrint(&s);

	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 5);

	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPrint(&s);

	SeqListInsert(&s, 2, 46);

	SeqListPrint(&s);

	SeqListErase(&s, 2);

	SeqListPrint(&s);

	SeqListDestroy(&s);
}
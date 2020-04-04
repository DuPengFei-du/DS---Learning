#include"Seq.h"

int main()
{
	SeqList s;

	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);

	SeqListPrint(&s);

	SeqListPushFront(&s, 10);
	SeqListPushFront(&s, 20);
	SeqListPushFront(&s, 30);
	SeqListPushFront(&s, 40);
	SeqListPushFront(&s, 50);

	SeqListPrint(&s);

	SeqListInsert(&s, 3, 46);

	SeqListPrint(&s);

	SeqListErase(&s, 3);

	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPrint(&s);

	printf("%d", SeqListFind(&s,20));

	SeqListDestroy(&s);
}
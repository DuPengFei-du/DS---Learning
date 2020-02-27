#include"Seq.h"

int main()
{
	SeqList seq;

	SeqListInit(&seq);

	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 5);

	SeqListPrint(&seq);

	SeqListPopBack(&seq);
	SeqListPopBack(&seq);

	SeqListPrint(&seq);

	SeqListPushFront(&seq, 10);
	SeqListPushFront(&seq, 20);
	SeqListPushFront(&seq, 30);
	SeqListPushFront(&seq, 40);
	SeqListPushFront(&seq, 50);

	SeqListPrint(&seq);

	SeqListPopFront(&seq);
	SeqListPopFront(&seq);

	SeqListPrint(&seq);

	SeqListInsert(&seq, 3, 46);
	SeqListInsert(&seq, 5, 66);

	SeqListPrint(&seq);

	SeqListErase(&seq, 3);
	SeqListErase(&seq, 4);

	SeqListPrint(&seq);

	SeqListFind(&seq, 30);

	SeqListDestroy(&seq);
	return 0;
}
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

	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 5);

	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPrint(&s);

	SeqListDestroy(&s);
}
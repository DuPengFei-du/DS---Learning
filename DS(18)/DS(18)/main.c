#include"shun.h"

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

	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPrint(&s);

	SeqListPushFront(&s, 10);
	SeqListPushFront(&s, 20);
	SeqListPushFront(&s, 30);
	SeqListPushFront(&s, 40);
	SeqListPushFront(&s, 50);

	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);

	SeqListPrint(&s);

	SeqDestroy(&s);
}
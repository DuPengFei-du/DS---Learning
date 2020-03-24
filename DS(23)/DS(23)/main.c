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

	SeqListDestroy(&s);
}
#include"SeqList.h"

int main()
{
	SeqList Seq;   //给一个顺序表的结构，也就是结构体类型的变量

	SeqListInit(&Seq);

	SeqListPushBack(&Seq, 1);
	SeqListPushBack(&Seq, 2);
	SeqListPushBack(&Seq, 3);
	SeqListPushBack(&Seq, 4);
	SeqListPushBack(&Seq, 5);

	SeqListPrint(&Seq);

	SeqListPopBack(&Seq);
	SeqListPopBack(&Seq);

	SeqListPrint(&Seq);

	SeqListPushFront(&Seq, 10);
	SeqListPushFront(&Seq, 20);
	SeqListPushFront(&Seq, 30);
	SeqListPushFront(&Seq, 40);
	SeqListPushFront(&Seq, 50);

	SeqListPrint(&Seq);

	SeqListPopFront(&Seq);
	SeqListPopFront(&Seq);
	SeqListPopFront(&Seq);

	SeqListPrint(&Seq);

	SeqListInsert(&Seq, 3, 46);

	SeqListPrint(&Seq);

	SeqListErase(&Seq,3);

	SeqListPrint(&Seq);

	SeqListFind(&Seq, 30);

	printf("%d\n", SeqListSize(&Seq));  //5
	printf("%d\n", SeqListCapacity(&Seq));  //20


	SeqListDestroy(&Seq);
	return 0;
}
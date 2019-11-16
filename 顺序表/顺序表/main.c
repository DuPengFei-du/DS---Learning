#include"SeqList.h"
void TestSeqList()
{
	SeqList seqlist;   //seqList这个变量并没有初始化
	SeqListInit(&seqlist);
	//要传的是地址
	/*
	原因：
	(1)如果要初始化的话，肯定要改变他们的值，
	如果要改变值的话，那么就只能传递指针了，不然只是一份临时拷贝，
	实际上并没有改变
	(2)传递的话，最好还是穿指针，因为传结构体不知道需要多少空间，
	相比之下，还是指针的所占的空间小一点。指针比结构体大小要小
	*/

	//尾插
	SeqListPushBack(&seqlist,1);
	SeqListPushBack(&seqlist,2);
	SeqListPushBack(&seqlist,3);
	SeqListPushBack(&seqlist,4);
	SeqListPrint(&seqlist);//这里是打印，这一步的打印结果应该为1，2，3，4;

	//头插
	SeqListPushFront(&seqlist, 10);
	SeqListPushFront(&seqlist, 20);
	SeqListPushFront(&seqlist, 30);//这一次打印的结果是30,20,10,1，2，3，4;
	SeqListPrint(&seqlist);

	SeqListInsert(&seqlist, 4, 100);
	SeqListPrint(&seqlist);

	//释放
	SeqListDestroy(&seqlist);
}

int main()
{
	TestSeqList();
	return 0;
}
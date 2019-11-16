#include"SeqList.h"
void TestSeqList()
{
	SeqList seqlist;   //seqList���������û�г�ʼ��
	SeqListInit(&seqlist);
	//Ҫ�����ǵ�ַ
	/*
	ԭ��
	(1)���Ҫ��ʼ���Ļ����϶�Ҫ�ı����ǵ�ֵ��
	���Ҫ�ı�ֵ�Ļ�����ô��ֻ�ܴ���ָ���ˣ���Ȼֻ��һ����ʱ������
	ʵ���ϲ�û�иı�
	(2)���ݵĻ�����û��Ǵ�ָ�룬��Ϊ���ṹ�岻֪����Ҫ���ٿռ䣬
	���֮�£�����ָ�����ռ�Ŀռ�Сһ�㡣ָ��Ƚṹ���СҪС
	*/

	//β��
	SeqListPushBack(&seqlist,1);
	SeqListPushBack(&seqlist,2);
	SeqListPushBack(&seqlist,3);
	SeqListPushBack(&seqlist,4);
	SeqListPrint(&seqlist);//�����Ǵ�ӡ����һ���Ĵ�ӡ���Ӧ��Ϊ1��2��3��4;

	//ͷ��
	SeqListPushFront(&seqlist, 10);
	SeqListPushFront(&seqlist, 20);
	SeqListPushFront(&seqlist, 30);//��һ�δ�ӡ�Ľ����30,20,10,1��2��3��4;
	SeqListPrint(&seqlist);

	SeqListInsert(&seqlist, 4, 100);
	SeqListPrint(&seqlist);

	//�ͷ�
	SeqListDestroy(&seqlist);
}

int main()
{
	TestSeqList();
	return 0;
}
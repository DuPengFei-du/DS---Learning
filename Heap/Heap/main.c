#include"Heap.h"

int main()
{
	Heap hp;

	int array[] = { 9,0,1,7,8,2,5,3,6,4 };
	HeapSort(array, sizeof(array) / sizeof(array[0]));

	//CreatHeap(&hp, array, sizeof(array) / sizeof(array[0]),Less);   //��Less����˼����Ҫ����һ��С��

	//EraseHeap(&hp);

	//printf("%d\n", TopHeap(&hp));

	//InsertHeap(&hp, 0);

	//printf("%d\n", TopHeap(&hp));

	//printf("%d\n", SizeHeap(&hp));


	DestroyHeap(&hp);
	//�����㷨��ʱ�临��Ϊnlogn
	//��һ��nΪ�߹��ڵ�ĸ��������Ǳ���ʵ����ΪN/2�����ô�O��������ʾ
	//�������ĸ߶�
}


#include"Heap.h"

int main()
{
	Heap hp;

	int array[] = { 9,0,1,7,8,2,5,3,6,4 };
	HeapSort(array, sizeof(array) / sizeof(array[0]));

	//CreatHeap(&hp, array, sizeof(array) / sizeof(array[0]),Less);   //传Less的意思就是要创建一个小堆

	//EraseHeap(&hp);

	//printf("%d\n", TopHeap(&hp));

	//InsertHeap(&hp, 0);

	//printf("%d\n", TopHeap(&hp));

	//printf("%d\n", SizeHeap(&hp));


	DestroyHeap(&hp);
	//调整算法的时间复杂为nlogn
	//第一个n为走过节点的个数，但是本身实际上为N/2，利用大O渐进法表示
	//就是树的高度
}


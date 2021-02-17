#include"Heap.h"


void HeapInit(Heap* hp, int init)
{
	//创建一个空的堆出来
	assert(hp);
	init = init < 10 ? 10 : init;
	hp->array = (HPDataType*)malloc(sizeof(HPDataType) * init);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}
	hp->_capacity = init;
	hp->_size = 0;
}

void Swap(HPDataType* left, HPDataType* right)
{
	HPDataType temp = *left;
	*left = *right;
	*right = temp;
}

void AdjustDown(HPDataType* array, int size, int parent)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] < array[child])
		{
			child += 1;
		}
		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			return;
	}
}

void AdjustUp(HPDataType* array, int size, int child)
{
	int parent = (child - 1) >> 1;
	while (child < size)
	{
		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
			return;
	}
}

void HeapCreate(Heap* hp, HPDataType* array, int size)
{
	//首先，需要调用函数创建一个空的堆出来
	HeapInit(hp, size);
	//空的堆创建出来之后，就需要进行元素的搬移的
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	//元素搬移完成之后，就可以开始建堆了
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp->array, hp->_size, root);
	}
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

void HeapPush(Heap* hp, HPDataType data)
{
	assert(hp);
	//在进行元素插入的时候，需要检测一下空间是否够用
	//当空间检测完毕之后，从而进行元素的插入
	hp->array[hp->_size++] = data;
	AdjustUp(hp->array, hp->_size, hp->_size - 1);
}

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->array[0], &hp->array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->array, hp->_size, 0);
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->array[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}





////////////////////////////////////////////
void TestHeap()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,0 };

	Heap hp;

	HeapCreate(&hp, arr, sizeof(arr) / sizeof(arr[0]));

	printf("size is %d\n", HeapSize(&hp));

	printf("top is %d\n", HeapTop(&hp));

	HeapPop(&hp);
	HeapPop(&hp);

	printf("size is %d\n", HeapSize(&hp));

	printf("top is %d\n", HeapTop(&hp));

	HeapPush(&hp, -1);

	printf("size is %d\n", HeapSize(&hp));

	printf("top is %d\n", HeapTop(&hp));

	HeapDestroy(&hp);
}
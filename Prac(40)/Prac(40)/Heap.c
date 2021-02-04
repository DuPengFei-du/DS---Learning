#include"Heap.h"


void HeapInit(Heap* hp, int init)
{
	assert(hp);
	//然后开始去创建一个空堆的出来
	init = init < 10 ? 10 : init;  //确保至少有10个空间
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
		if (child + 1 < size && array[child] > array[child + 1])
			child += 1;
		if (array[parent] > array[child])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			return;
	}
}

void HeapCreate(Heap* hp, HPDataType* array, int size)
{
	//先要调用函数的方法，创建一个空的堆出来
	HeapInit(hp, size);
	//一个空的堆有了之后，我们需要开始
	//进行元素的搬移
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->_size = size;
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

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->array[0];
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

void AdjustUp(HPDataType* array, int size, int child)
{
	int parent = (child - 1) >> 1;
	while (child)
	{
		if (array[parent] > array[child])
		{
			Swap(&array[parent], &array[child]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
			return;
	}
}

void HeapPush(Heap* hp, int data)
{
	assert(hp);
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




/////////////////////////////////////
void TestHeap()
{
	int array[] = { 3,6,9,1,5,0,7,8,4,2 };

	Heap hp;

	HeapCreate(&hp, array, sizeof(array) / sizeof(array[0]));

	printf("heap size =%d\n", HeapSize(&hp));

	printf("heap top =%d\n", HeapTop(&hp));

	HeapPop(&hp);

	printf("heap size =%d\n", HeapSize(&hp));

	printf("heap top =%d\n", HeapTop(&hp));

	HeapPush(&hp,-1);

	printf("heap size =%d\n", HeapSize(&hp));

	printf("heap top =%d\n", HeapTop(&hp));

	HeapDestroy(&hp);
}

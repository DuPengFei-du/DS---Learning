#include"Heap.h"


void HeapInit(Heap* hp, int init)
{
	assert(hp);
	init = init < 10 ? 10 : init;
	hp->array = (HPDataType*)malloc(sizeof(HPDataType) * init);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}
	hp->capacity = init;
	hp->size = 0;
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
		if (child+1<size && array[child] > array[child + 1])
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

void HeapCreate(Heap* hp, HPDataType* array, int size)
{
	assert(hp);
	//先去开辟空间，然后去搬移元素
	HeapInit(hp, size);
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->size = size;
	//然后开始建堆
	//建堆需要用到向下调整
	for (int root = (size - 2) / 2; root >= 0; --root)
	{
		AdjustDown(hp->array, hp->size, root);
	}
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->array[0];
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->array, hp->size, 0);
}


///////////////////////////////////////////////////////////////////
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

	HeapDestroy(&hp);
}
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
	hp->_size = 0;
	hp->capacity = init;
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
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
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (array[child + 1] < array[child])
		{
			child += 1;
		}
		if (child + 1 < size && array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			return;
	}
}

void HeapCreate(Heap* hp, int* array, int size)
{
	int root = 0;
	assert(hp);
	//要进行数组元素的拷贝
	HeapInit(hp, size);
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	for (int root = (size - 2) / 2; root >= 0; --root)
	{
		AdjustDown(hp->array, hp->_size, root);
	}
}

HPDataType HeapTop(Heap* hp)
{
	//堆顶元素就是数组0号位置得元素
	assert(hp);
	return hp->array[0];
}

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->array[0], &hp->array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->array, hp->_size, 0);   //开始向下调整
}

int HeapEmpty(Heap* hp)
{
	assert(0);
	return 0 == hp->_size;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}


///////////////////////////////////////////
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
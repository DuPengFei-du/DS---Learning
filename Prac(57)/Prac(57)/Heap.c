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
	hp->_capacity = init;
	hp->_size = 0;
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->_capacity = 0;
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
	while(child)
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
	HeapInit(hp, size);
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp->array, hp->_size, root);
	}
}

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->array[0], &hp->array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->array, hp->_size, 0);
}

void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		int newcapacity = 2 * hp->_capacity;
		HPDataType* temp = (HPDataType*)malloc(sizeof(HPDataType) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		for (int i = 0; i < hp->_size; i++)
		{
			temp[i] = hp->array[i];
		}
		free(hp->array);
		hp->array = temp;
		hp->_capacity = newcapacity;
	}
}

void HeapPush(Heap* hp, int data)
{
	assert(hp);
	CheckCapacity(hp);
	hp->array[hp->_size++] = data;
	AdjustUp(hp->array, hp->_size, hp->_size - 1);
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



///////////////////////////
void TestHeap()
{
	int array[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Heap hp;

	HeapCreate(&hp, array, sizeof(array) / sizeof(array[0]));

	printf("size = %d\n", HeapSize(&hp));

	printf("top = %d\n", HeapTop(&hp));

	HeapPop(&hp);
	HeapPop(&hp);

	printf("size = %d\n", HeapSize(&hp));

	printf("top = %d\n", HeapTop(&hp));

	HeapPush(&hp, 0);

	printf("size = %d\n", HeapSize(&hp));

	printf("top = %d\n", HeapTop(&hp));

	HeapDestroy(&hp);
}
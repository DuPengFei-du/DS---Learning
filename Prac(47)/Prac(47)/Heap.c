#include"Heap.h"


int Less(HPDataType left, HPDataType right)
{
	return left < right;
}

int Greater(HPDataType left, HPDataType right)
{
	return left > right;
}

void HeapInit(Heap* hp, int init, CMP cmp)
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
	hp->Cmp = cmp;
}

void Swap(HPDataType* left, HPDataType* right)
{
	HPDataType temp = *left;
	*left = *right;
	*right = temp;
}

void AdjustDown(Heap* hp, int parent)
{
	int child = 2 * parent + 1;
	int size = hp->_size;
	int* array = hp->array;
	while (child < size)
	{
		if (child + 1 < size && hp->Cmp(array[child + 1] ,array[child]))
		{
			child += 1;
		}
		if (hp->Cmp(array[child], array[parent]))
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			return;
	}
}

void AdjustUp(Heap *hp, int child)
{
	int parent = (child - 1) >> 1;
	int size = hp->_size;
	int* array = hp->array;
	while (child < size)
	{
		if (hp->Cmp(array[child],array[parent]))
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
			return;
	}
}

void HeapCreate(Heap* hp, HPDataType* array, int size, CMP cmp)
{
	//先调用函数创建一个空堆出来
	HeapInit(hp, size,cmp);
	//空的堆创建出来之后，我就可以开始进行元素搬移了
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	//元素搬移完成之后，就可以开始进行建堆的操作了
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp, root);
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
		//空间开辟完成之后，就需要进行元素的搬移了
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
	AdjustUp(hp,hp->_size-1);
}

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->array[0], &hp->array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp, 0);
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

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->array[0];
}





////////////////////////////////////
void TestHeap()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Heap hp;

	HeapCreate(&hp, arr, sizeof(arr) / sizeof(arr[0]),Less);

	printf("size = %d\n", HeapSize(&hp));

	printf("top = %d\n", HeapTop(&hp));

	HeapPush(&hp, 0);

	printf("size = %d\n", HeapSize(&hp));

	printf("top = %d\n", HeapTop(&hp));

	HeapPop(&hp);
	HeapPop(&hp);

	printf("size = %d\n", HeapSize(&hp));

	printf("top = %d\n", HeapTop(&hp));

	HeapDestroy(&hp);
}
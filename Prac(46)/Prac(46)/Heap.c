#include"Heap.h"


int Less(HPDataType left, HPDataType right)
{
	return left < right;
}

int Greater(HPDataType left, HPDataType right)
{
	return left > right;
}

void HeapInit(Heap* hp,int init, CMP cmp)
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

void AdjustDown(Heap *hp,int parent)
{
	int* array = hp->array;
	int size = hp->_size;
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && hp->Cmp(array[child + 1],array[child]))
		{
			child += 1;
		}
		if (hp->Cmp(array[child],array[parent]))
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			return;
	}
}

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->array[0], &hp->array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp,0);
}

void AdjustUp(Heap *hp,int child)
{
	int size = hp->_size;
	int* array = hp->array;
	int parent = (child - 1) >> 1;
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

void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_capacity = hp->_size)
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
	//插入之前需要检测一下容量是否够用
	CheckCapacity(hp);
	hp->array[hp->_size++] = data;
	AdjustUp(hp,hp->_size-1);
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
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

void HeapCreate(Heap* hp, int* array, int size, CMP cmp)
{
	//调用函数，先创建一个空的堆出来
	HeapInit(hp, size,cmp);
	//空的堆创建好了之后，就需要进行元素的搬移了
	memcpy(hp->array, array , sizeof(HPDataType) * size);
	hp->_size = size; 
	//可以开始建堆的操作了
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp, root);
	}
}




//////////////////////////////////////////////////////
void TestHeap()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	
	Heap hp;

	HeapCreate(&hp, arr, sizeof(arr) / sizeof(arr[0]),Less);

	printf("size %d\n", HeapSize(&hp));

	printf("top %d\n", HeapTop(&hp));

	HeapPop(&hp);

	printf("size %d\n", HeapSize(&hp));

	printf("top %d\n", HeapTop(&hp));

	HeapPush(&hp, -1);

	printf("size %d\n", HeapSize(&hp));

	printf("top %d\n", HeapTop(&hp));

	HeapDestroy(&hp);
}
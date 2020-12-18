#include"Heap.h"


void HeapInit(Heap* hp, int init)
{
	assert(hp);
	init = init < 10 ? 10 : init;
	hp->array = (int*)malloc(sizeof(HPDataType) * init);
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

void AdjustDown(HPDataType *array,int size,int parent)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child] > array[child + 1])
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

void HeapCreate(Heap* hp, int* array, int size)
{
	assert(hp);
	HeapInit(hp, size);
	//空间创建好了之后就要开始进行运算的搬移了
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->size = size;
	//然后就要通过向下调整，开始建堆了
	for (int root = (size - 2) / 2; root >= 0; --root)
	{
		AdjustDown(hp->array, hp->size, root);
	}
}

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->array, hp->size, 0);
}

void AdjustUP(HPDataType* array, int size, int child)
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

void CheckCapacity(Heap* hp)
{
	//现在来检测一下我是否需要对这个堆进行扩容的操作
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = 2 * hp->capacity;
		HPDataType* temp = (HPDataType*)malloc(sizeof(HPDataType) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		//拷贝元素的方式其实是有两种形式的
		//1.memcpy(temp, hp->array, sizeof(HDataType) * hp->size);
		for (int i = 0; i < hp->size; ++i)
		{
			temp[i] = hp->array[i];
		}
		free(hp->array);
		hp->array = temp;
		hp->capacity = newcapacity;
	}
}

void HeapPush(Heap* hp, HPDataType data)
{
	//向堆中进行元素的插入
	assert(hp);
	CheckCapacity(hp);
	//需要检测一下容量是否是够用的
	hp->array[hp->size] = data;
	hp->size++;
	AdjustUP(hp->array, hp->size, hp->size - 1);
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->array[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->size = 0;
	hp->capacity = 0;
}




///////////////////////////////////////////////////////////
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
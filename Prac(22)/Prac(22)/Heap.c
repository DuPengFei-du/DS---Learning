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
	//�ռ䴴������֮���Ҫ��ʼ��������İ�����
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->size = size;
	//Ȼ���Ҫͨ�����µ�������ʼ������
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
	//���������һ�����Ƿ���Ҫ������ѽ������ݵĲ���
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
		//����Ԫ�صķ�ʽ��ʵ����������ʽ��
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
	//����н���Ԫ�صĲ���
	assert(hp);
	CheckCapacity(hp);
	//��Ҫ���һ�������Ƿ��ǹ��õ�
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
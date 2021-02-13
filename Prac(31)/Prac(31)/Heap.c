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

void HeapCreate(Heap* hp, HPDataType* array, int size)
{
	HeapInit(hp,size);
	//���ھ��Ѿ�������һ���ն��ˣ�Ȼ�����ھͿ��Կ�ʼ����Ԫ����
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	//Ԫ��Ҳ���ƽ���֮�󣬾Ϳ��Կ�ʼ������
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

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->array[0], &hp->array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->array, hp->_size, 0);
}

void CheckCapacity(Heap* hp)
{
	//���������һ�����Ƿ���Ҫ������ѽ������ݵĲ���
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		int newcapacity = 2 * hp->_capacity;
		HPDataType* temp = (HPDataType*)malloc(sizeof(HPDataType) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		//����Ԫ�صķ�ʽ��ʵ����������ʽ��
		//1.memcpy(temp, hp->array, sizeof(HDataType) * hp->size);
		for (int i = 0; i < hp->_size; ++i)
		{
			temp[i] = hp->array[i];
		}
		free(hp->array);
		hp->array = temp;
		hp->_capacity = newcapacity;
	}
}


void HeapPush(Heap* hp, HPDataType data)
{
	assert(hp);
	//�ڽ���Ԫ�صĲ���֮ǰ��������Ҫ�Ƚ���һ�������ļ�⣬ȷ��һ��
	//�����Ƿ��ǹ��õ�
	CheckCapacity(hp);

	hp->array[hp->_size] = data;
	hp->_size++;

	AdjstUp(hp->array, hp->_size, hp->_size - 1);
}


//////////////////////////////////

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
#include"Heap.h"

void HeapInit(Heap* hp, int init)   //��һ����ʼ���������Ϳ���
{
	//��������һ���նѣ���һ�仰��˵����ʵ���Ǹ������ռ�Ϳ�����
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
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child+1 < size && array[child] > array[child + 1])
		{
			child += 1;
		}
		//Ȼ��ȥ���˫���Ƿ���������
		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void HeapCreate(Heap* hp, int* array, int size)
{
	//�������е�Ԫ��ȥ��������һ����
	//�ڶѴ�����������Ҫ�õ����µ������㷨
	HeapInit(hp,size);
	//һ���յĶѴ���������֮�󣬾���Ҫ����Ԫ�صİ�����
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp->array, hp->_size, root);
		//Ҫѭ����ȥ�������µ����ķ���
	}

}

void HeapPush(Heap* hp, HPDataType data);

void HeapPop(Heap* hp)
{
	//���ڽ���Ԫ��ɾ����ʱ��ɾ���Ķ��ǶѶ���Ԫ��
	assert(hp);
	Swap(&hp->array[0], &hp->array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->array, hp->_size, 0);
}

HPDataType HeapTop(Heap* hp)
{
	//��ȡ�Ѷ�Ԫ��
	assert(hp);
	return hp->array[0];
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}



/////////////////////////////////////////////////////
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
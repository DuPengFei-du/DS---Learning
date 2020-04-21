#include"Heap.h"

void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

int Less(HPDataType left, HPDataType right)
{
	return left < right;
}

int Greater(HPDataType left, HPDataType right)
{
	return left > right;
}

void AdjustDown(HPDataType* array, int size, int parent,PFC pFC)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//�ҳ����Һ�������С�ĺ���
		//�����Ҫȥ�Ƚ����Ӻ��Һ������ĸ����ӱȽ�С�Ļ�
		//������Ҫȷ���Һ����Ǵ��ڵģ���ô����ôȷ���Һ����Ǵ��ڵ���
		//����child+1<sizeȥȷ���Һ����Ǵ��ڵ�
		//��child��������Һ����н�С��һ������
		if (child + 1 < size && pFC(array[child+1],array[child]))
		{
			child += 1;
		}
		//���˫���Ƿ��������
		if (pFC(array[child] , array[parent]))
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void CreatHeap(Heap* hp, HPDataType* array, int size, PFC pFC)
{
	int root = -1;
	//���ٿռ�
	hp->array = malloc(sizeof(HPDataType) * size);
	assert(hp);
	hp->_capacity = size;
	hp->_size = size;
	hp->_pFC = pFC;
	//������Ԫ�ؿ������ѿռ���ȥ
	memcpy(hp->array, array, size * sizeof(HPDataType));
	//�ҵ�����һ����Ҷ�ӽ��
	//����
	root = (size - 2) / 2;
	for (; root >= 0; --root)
	{
		AdjustDown(hp->array, size, root,pFC);
	}
}

void DestroyHeap(Heap* hp)
{
	if (hp->array)
	{
		free(hp->array);
		hp->_capacity = 0;
		hp->_size = 0;
	}
}

HPDataType TopHeap(Heap* hp)
{
	assert(!EmptyHeap(hp));
	return hp->array[0];
}

int EmptyHeap(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}

int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->_size;
}


void EraseHeap(Heap* hp)
{
	//�öѶ�Ԫ�غ����һ��Ԫ�ؽ���
	//Ȼ�����µ���
	if (EmptyHeap(hp))
		return;
	Swap(&hp->array[0], &hp->array[hp->_size - 1]);
	hp->_size -= 1;
	AdjustDown(hp->array, hp->_size, 0,hp->_pFC);
}

void AdjustUp(HPDataType* array, int size, int child)
{
	int parent = ((child - 1) >> 1);
	while (child)
	{
		if (array[parent] > array[child])
		{
			Swap(&array[parent], &array[child]);
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else
			return;
	}
}

void CheckCapacity(Heap* hp)
{
	if (hp->_size == hp->_capacity)
	{
		int capacity = 2 * hp->_capacity;
		HPDataType *pTemp = (HPDataType*)malloc(sizeof(HPDataType) * capacity);
		if (NULL == pTemp)
		{
			assert(0);
			return;
		}
		memcpy(pTemp, hp->array, sizeof(HPDataType) * hp->_size);
		free(hp->array);
		hp->array = pTemp;
		hp->_capacity = capacity;
	}
}

void InsertHeap(Heap* hp, HPDataType data)
{
	//Ҫ���룬����Ҫ��֤�ռ���㣬Ҫ�ȼ��һ��
	CheckCapacity(hp);
	hp->array[hp->_size++] = data;
	AdjustUp(hp->array, hp->_size, hp->_size - 1);
}

void HeapAdjust(int* array, int size, int parent)
{
	//Ĭ��parent�����ӱȽ�С
	int child = parent * 2 + 1;
	//�����Һ�������С�ĺ���
	if (child + 1 < size && array[child + 1] < array[child])
		child += 1;
	//���˫���Ƿ�����ѵ�����
	if (array[parent] > array[child])
	{
		Swap(&array[parent], &array[child]);
		parent = child;
		child = parent * 2 + 1;
	}
	else
	{
		//����ѵ�����
		return;
	}
}

void HeapSort(int* array, int size)
{
	//�����õ��Ƕ�����ɾ���ķ���
	//�������˼��
	//�ȴ����ѣ������Ҫ�������ǽ���ģ���ô�ʹ���һ��С��
	//�����Ҫ������������ģ���ô����һ�����
	//����
	int root = (size - 2) >> 1;
	for (; root >= 0; --root)
	{
		HeapAdjust(array, size, root);
	}
	//����--->��ɾ��ԭ��
	for (int last = size - 1; last >= 0; last--)
	{
		Swap(&array[0], &array[last]);
		HeapAdjust(array, last, 0);
	}
}
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
		//找出左右孩子中最小的孩子
		//如果想要去比较左孩子和右孩子中哪个孩子比较小的话
		//我首先要确定右孩子是存在的，那么我怎么确定右孩子是存在的呢
		//就用child+1<size去确定右孩子是存在的
		//用child来标记左右孩子中较小的一个孩子
		if (child + 1 < size && pFC(array[child+1],array[child]))
		{
			child += 1;
		}
		//检查双亲是否满足情况
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
	//开辟空间
	hp->array = malloc(sizeof(HPDataType) * size);
	assert(hp);
	hp->_capacity = size;
	hp->_size = size;
	hp->_pFC = pFC;
	//把数组元素拷贝到堆空间中去
	memcpy(hp->array, array, size * sizeof(HPDataType));
	//找倒数第一个非叶子结点
	//建堆
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
	//用堆顶元素和最后一个元素交换
	//然后向下调整
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
	//要插入，首先要保证空间充足，要先检测一下
	CheckCapacity(hp);
	hp->array[hp->_size++] = data;
	AdjustUp(hp->array, hp->_size, hp->_size - 1);
}

void HeapAdjust(int* array, int size, int parent)
{
	//默认parent的左孩子比较小
	int child = parent * 2 + 1;
	//找左右孩子中最小的孩子
	if (child + 1 < size && array[child + 1] < array[child])
		child += 1;
	//检测双亲是否满足堆的性质
	if (array[parent] > array[child])
	{
		Swap(&array[parent], &array[child]);
		parent = child;
		child = parent * 2 + 1;
	}
	else
	{
		//满足堆的性质
		return;
	}
}

void HeapSort(int* array, int size)
{
	//排序用的是堆里面删除的方法
	//堆排序的思想
	//先创建堆，如果需要的序列是降序的，那么就创建一个小堆
	//如果需要的序列是升序的，那么创建一个大堆
	//建堆
	int root = (size - 2) >> 1;
	for (; root >= 0; --root)
	{
		HeapAdjust(array, size, root);
	}
	//排序--->堆删除原理
	for (int last = size - 1; last >= 0; last--)
	{
		Swap(&array[0], &array[last]);
		HeapAdjust(array, last, 0);
	}
}
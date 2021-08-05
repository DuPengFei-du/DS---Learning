#include"Heap.h"

void HeapInit(Heap* hp, int init)   //传一个初始化的容量就可以
{
	//用来创建一个空堆，换一句话来说，其实就是给出来空间就可以了
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
		//然后去检查双亲是否满足特性
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
	//用数组中的元素去创建出来一个堆
	//在堆创建过程中需要用到向下调整的算法
	HeapInit(hp,size);
	//一个空的堆创建出来了之后，就需要进行元素的搬移了
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp->array, hp->_size, root);
		//要循环的去调用向下调整的方法
	}

}

void HeapPush(Heap* hp, HPDataType data);

void HeapPop(Heap* hp)
{
	//堆在进行元素删除的时候，删除的都是堆顶的元素
	assert(hp);
	Swap(&hp->array[0], &hp->array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->array, hp->_size, 0);
}

HPDataType HeapTop(Heap* hp)
{
	//获取堆顶元素
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
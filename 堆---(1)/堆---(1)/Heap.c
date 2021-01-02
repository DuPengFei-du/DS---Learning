#include"Heap.h"


//初始化一个空堆
void HeapInit(Heap* hp,int init)
{
	assert(hp);
	init = init < 10 ? 10 : init; 
	//如果小于10的话，就给成10，否则的话，就给成容量本身就可以了
	//保证最少开辟10个内存空间
	hp->array = (HDataType*)malloc(sizeof(HDataType)* init);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}
	hp->size = init;
	hp->capacity = 10;
}

void Swap(HDataType* left, HDataType* right)
{
	HDataType temp = *left;
	*left = *right;
	*right = temp;
}

int Less(HDataType left, HDataType right)
{
	return left < right;
}

int Greater(HDataType left, HDataType right)
{
	return left < right;
}

void AdjustDown(HDataType* array, int size, int parent)
{
	//用child标记parent中较小的孩子---默认先标记左边的孩子
	//因为如果由孩子的话，那么肯定是先有左孩子
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child+1<size&&array[child + 1] < array[child])
		{
			child += 1;
		}
		//然后检测双亲是否满足堆的性质
		if (array[parent] > array[child])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

//用数组中的元素创建堆
void HeapCreate(Heap* hp, int* array, int size)
{
	int root = 0;
	//1.先将数组中的元素放在堆结构里面
	HeapInit(hp, size);  //先来开辟内存空间，开辟size个空间的大小
	//空间开辟好了之后，只需要将数组中的元素放进来就好了
	memcpy(hp->array, array, sizeof(HDataType) * size);
	hp->size = size;

	//2.开始进行调整
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp->array, hp->size, root);   //要调整的就是hp的那个数组
		//要调整的元素个数就是hp->size个元素
	}
}

HDataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];   //数组0号位置元素其实就是堆顶的元素
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

void AdjustUp(HDataType* array, int size, int child)
{
	int parent  = ((child - 1) >> 1);
	while (child)   //循环条件是因为，只要child没有走到根结点的位置上，循环就会一直的进行下去
	{
		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
			return;  //不满足情况的话，直接return就可以了
	}

}

void CheckCapacity(Heap* hp)
{
	//现在来检测一下我是否需要对这个堆进行扩容的操作
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = 2 * hp->capacity;
		HDataType* temp = (HDataType*)malloc(sizeof(HDataType) * newcapacity);
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

void HeapPush(Heap* hp, HDataType data)
{
	//0.毕竟堆底层的空间是有限的，我们不能永无休止的去插入
	//所以我们还需要对堆底层空间的容量进行检测
	//检测是否需要扩容

	CheckCapacity(hp);
	//1.首先，我们需要将新元素进行插入的操作
	//所插入到的位置在数组的末尾
	hp->array[hp->size] = data;
	hp->size++;

	//当然，因为存在有新元素的插入，那么，新元素的插入时很有可能
	//导致堆的性质被破坏的
	//那么，这个时候，需要将这个结点进行向上调整
	AdjustUp(hp->array, hp->size, hp->size - 1);
}

void HeapPop(Heap* hp)   //删除其实所要删除的就是堆顶的元素
{
	//将堆顶元素和最后一个元素进行交换
	//然后将元素的个数减少一个
	Swap(&hp->array[0], &hp->array[hp->size-1]);
	hp->size--;
	AdjustDown(hp->array, hp->size, 0);   //0的意思是所要调整额元素是堆顶元素
}

void HeapDestroy(Heap* hp)  //销毁
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}

//////////////////////////////////////////////////
void TestHeap()
{
	int array[] = { 3,6,9,1,5,0,7,8,4,2 };

	Heap hp;

	HeapCreate(&hp, array, sizeof(array) / sizeof(array[0]));

	printf("heap size =%d\n", HeapSize(&hp));

	printf("heap top =%d\n",HeapTop(&hp));

	HeapPop(&hp);

	printf("heap size =%d\n", HeapSize(&hp));

	printf("heap top =%d\n", HeapTop(&hp));

	HeapPush(&hp,-1);

	printf("heap size =%d\n", HeapSize(&hp));

	printf("heap top =%d\n", HeapTop(&hp));

	HeapDestroy(&hp);
}

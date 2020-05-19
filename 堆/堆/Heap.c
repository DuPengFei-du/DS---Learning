#include"Heap.h"

void Swap(HPDataType* x, HPDataType* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//向下调整，那么我们要向下调整的是谁呢？其实就是hp的这个堆
//假设我们现在创建的是小堆
//那么，我们就需要先去检测parent是否比孩子小
//parent的孩子可能有两个，如果parent比较小的那个孩子还小的话，那么
//parent肯定比两个孩子都要小
//如果parent比两个孩子要大，那么就不满足堆的特性，那么就要进行向下调整
//的操作，把较大的双亲往下进行移动，可能会导致子树不满足条件，那么
//就需要继续向下进行调整
void AdjustDown(Heap* hp, int parent)
{
	//parent代表需要调整的元素在堆结构中的下标
	//child代表parent的两个孩子中较小的一个，默认child表示的是
	//parent的左孩子，因为再完全二叉树中，一个结点可能有左孩子的同时没有右孩子
	int child = parent * 2 + 1;
	//while循环条件的判断：保证左孩子存在，如果左孩子不存在，说明parent没有孩子
	while (child < hp->_size)
	{
		//首先需要保证右孩子也存在，然后再去找两个孩子中较小的孩子
		if (child+1 < hp->_size && hp->array[child + 1] < hp->array[child])
		{
			child = child + 1;
		}
		//如果双亲大的话，就进行交换
		if (hp->array[child] < hp->array[parent])
		{
			Swap(&hp->array[parent], &hp->array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
//向下调整的时间复杂度，单纯的看向下调整的话，假设是最坏情况，最坏的情况就是从最上面的那个结点开始调整
//那么调整的次数，也其实就是树的高度，树的高度的求法就是log2(n+1)，向上取整
//所以向下调整的时间复杂度就是log2(N)

void AdjustUp(Heap* hp, int child)
{
	int parent = (child - 1) >> 1;
	while (child)
	{
		if (hp->array[child] < hp->array[parent])
		{
			Swap(&hp->array[child], &hp->array[parent]);

			//小的元素往上移动，可能会导致上层不满足堆的特定
			//所以要继续向上调整
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			return;
		}
	}
}


//建堆就是在不断地调用向下调整的方法，调整的是非叶子结点，几乎占了所有结点的一般
//就么就是调用了所有结点一半的次数次向下调整
//所以建堆的时间复杂度为---------------------nlog2(N)   但是最好还是查一下建堆的时间复杂度
void HeapCreate(Heap* hp, HPDataType arr[], int size)
{
	assert(hp);
	//1.先将arr中的元素放到堆的结构中
	hp->array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}
	hp->_capacity = size;
	memcpy(hp->array, arr, sizeof(HPDataType) * size);
	hp->_size = size;

	//2.然后去初始化堆的结构
	//从最后一个非叶子结点开始进行调整
	for (int root = (size - 2) >> 1; root >= 0; root--)
	{
		AdjustDown(hp, root);
	}
}

void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_size >= hp->_capacity)
	{
		int newcapacity = 2 * hp->_capacity;
		HPDataType* temp = (HPDataType*)malloc(sizeof(HPDataType) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		memcpy(temp, hp->array, sizeof(HPDataType) * hp->_size);
		//两种方法进行元素的拷贝都可以
		/*for (int i = 0; i < hp->_size; ++i)
		{
			temp[i] = hp->array[i];
		}
		*/
		free(hp->array);
		hp->array = temp;
		hp->_capacity = newcapacity;
	}
}

void HeapPush(Heap* hp, HPDataType data)
{
	assert(hp);
	CheckCapacity(hp);
	hp->array[hp->_size ++] = data;
	AdjustUp(hp, hp->_size - 1);
}

//堆的删除，删除的是堆顶的元素，因为堆顶的元素是最值(不是最大值，就是最小值)
//一开始会想到顺序表头删的方法，但是其实那样子删除是不可以的，因为会破坏堆原有的结构
//所以就像出来了把堆的最后一个元素和堆的第一个元素先交换位置，然后堆的有效元素的个数-1
//然后对堆顶元素进行调整就可以了
void HeapPop(Heap* hp)
{
	assert(hp);
	if (HeapEmpty(hp))
		return;
	Swap(&hp->array[0], &hp->array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp, 0);
}

//获取堆顶元素
HPDataType HeapTop(Heap* hp)
{
	assert(hp && !HeapEmpty(hp));  //要获取堆顶元素的话，要保证堆存在，同时要保证堆是非空的
	return hp->array[0];
}

//获取堆中元素的个数
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

void HeapDestroy(Heap* hp)
{
	assert(hp);
	if (hp->array)
	{
		free(hp->array);
		hp->array = NULL;
		hp->_capacity = 0;
		hp->_size = 0;
	}
}

void HeapAdjust(int array[], int size, int parent)
{
	//向下调整
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] < array[child])
			child += 1;
		if (array[child] < array[parent])
		{
			int temp = array[child];
			array[child] = array[parent];
			array[parent] = temp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;  //孩子比双亲大
		}
	}
}

void HeapSort(int array[], int size)
{
	//1.建堆
	//建堆要先找到倒数第一个非叶子结点
	for (int root = (size - 2) >> 1; root >= 0; --root)
	{
		HeapAdjust(array, size, root);   //堆调整
	}
	//2.采用堆删除的思想来进行排序
	int end = size - 1;  //代表最后一个元素
	while (end)
	{
		int temp = array[0];
		array[0] = array[end];
		array[end] = temp;
		HeapAdjust(array, end, 0);
		end--;
	}

}

void TestFunc()
{
	int arr[] = { 5,3,8,4,2,7,6,1,0 };

	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));

	Heap hp;

	HeapCreate(&hp,arr,sizeof(arr)/sizeof(arr[0]));

	printf("size == %d\n", HeapSize(&hp));

	printf("top == %d\n", HeapTop(&hp));

	HeapPop(&hp);

	printf("size == %d\n", HeapSize(&hp));

	printf("top == %d\n", HeapTop(&hp));

	HeapPush(&hp,9);

	printf("size == %d\n", HeapSize(&hp));

	printf("top == %d\n", HeapTop(&hp));

	HeapPush(&hp, 0);

	printf("size == %d\n", HeapSize(&hp));

	printf("top == %d\n", HeapTop(&hp));
}
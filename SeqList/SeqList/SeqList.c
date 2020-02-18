#include"SeqList.h"

static void CheckCapacity(SeqList *seq)
{
	assert(seq != NULL);
	if (seq->_size == seq->_capacity)
	{
		int newCapacity = 2 * DefaultCapacity;
		DataType* newArray = (DataType*)malloc(sizeof(DataType) * newCapacity);
		if (NULL == newArray)
		{
			assert(0);
			return ;
		}
		memcpy(newArray, seq->array, seq->_size * sizeof(DataType));
		//释放就空间
		free(seq->array);
		seq->array = newArray;
		seq->_capacity = newCapacity;
	}
}

void SeqListInit(SeqList* seq)
{
	assert(seq != NULL);  //先检测参数的合法性，然后再给出算法的功能
	seq->array = (DataType*)malloc(sizeof(DataType) * DefaultCapacity);
	if (NULL == seq->array)
	{
		assert(0);  //assert是调试宏，只有在Debug版本才能起作用
		return;
	}
	//如果if不成立，说明申请空间已经成功了
	seq->_size = 0;
	seq->_capacity = DefaultCapacity;
}

void SeqListDestroy(SeqList* seq)
{
	free(seq->array);
	seq->array = NULL;
	seq->_size = 0;
	seq->_capacity = 0;
}

void SeqListPushBack(SeqList* seq, DataType data)  //尾插
{
	assert(seq != NULL);
	CheckCapacity(seq);
	seq->array[seq->_size] = data;
	seq->_size++;
	//但是在动态顺序表中还需要考虑是否需要扩容的问题
	//看容量是否够用，然后，是否需要扩容
}

void SeqListPopBack(SeqList* seq)   //尾删
{
	assert(seq != NULL);
	if (0 == seq->_size)
		return;
	seq->_size--;
}

void SeqListPrint(SeqList* seq)
{
	assert(seq);
	int i = 0;
	for (i = 0; i < seq->_size; i++)
	{
		printf("%d ", seq->array[i]);
	}
	printf("\n");
}

void SeqListPushFront(SeqList* seq, DataType data)
{
	assert(seq != NULL);
	//还需要检测空间是否充足
	CheckCapacity(seq);
	//进行元素的插入
	for (int i = seq->_size-1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = data;
	seq->_size++;
}

void SeqListPopFront(SeqList* seq)
{
	assert(seq != NULL);
	if (0 == seq->_size)
		return;
	else
	{
		for (int i = 0; i < seq->_size; i++)
		{
			seq -> array[i] = seq->array[i + 1];
		}
	}
	seq->_size--;
}

void SeqListInsert(SeqList* seq,int index,DataType data)
{
	assert(seq != NULL);
	//还需要判断一下所输入下标的合法性
	if (index<0 || index>seq->_size)
	{
		printf("所输入的下标为非法下标，请重新输入!");
		return;
	}
	//然后还需要检测容量是否够用
	CheckCapacity(seq);
	for (int i = seq->_size - 1; i >= index; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[index] = data;
	seq->_size++;
}

void SeqListErase(SeqList* seq, int index)
{
	assert(seq != NULL);
	if (index<0 || index>seq->_size)
	{
		printf("所输入的下标为非法下标，请重新输入!");
		return;
	}
	for (int i = index; i <= seq->_size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->_size--;
}

int SeqListFind(SeqList* seq, DataType data)
{
	assert(seq != NULL);
	for (int i = 0; i < seq->_size; i++)
	{
		if (seq->array[i] == data)
			return i;
	}
	return -1;
}

void SeqListRemove(SeqList* seq, DataType data)
{
	assert(seq != NULL);
	SeqListErase(seq, SeqListFind(seq, data));
}

void SeqListRemoveAll(SeqList* seq, DataType data)
{
	//但是这种方法的时间复杂度接近N^2
	assert(seq != NULL);
	int index = -1;
	while (-1 == SeqListFind(seq, data))
	{
		SeqListErase(seq, index);
	}
	//还可以通过一遍遍历，单独调用Erase
	//还可以通过提供辅助空间，此时空间复杂度为O(N),时间复杂度为0(N)
	/*
	int count=0;   //记录待删除元素的个数
	for(int i=0;i<seq->_size;i++)
	{
	  if(data==seq->array[i])
	     count++;
	  else
	     seq->array[i-cout]=seq->array[i];
     }
	 //这种方法的时间复杂度为O(N),空间复杂度为O(1)
	*/
}

int SeqListSize(SeqList* seq)
{
	assert(seq != NULL);
	return seq->_size;
}

int SeqListCapacity(SeqList* seq)
{
	assert(seq != NULL);
	return seq->_capacity;
}

int SeqListEmpty(SeqList* seq)
{
	assert(seq != NULL);
	if (0 == seq->_size)
		return 0;
	else
		return 1;
}

DataType SeqListFront(SeqList* seq)
{
	assert(seq != NULL);
	return seq->array[0];
}

DataType SeqListLast(SeqList* seq)
{
	assert(seq != NULL);
	return seq->array[seq->_size - 1];   //不能用前置--和后置--，使用的话，顺序表的元素个数就会少1
}
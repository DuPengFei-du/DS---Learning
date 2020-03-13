#include"shun.h"

void SeqListInit(SeqList* seq)
{
	assert(seq);
	seq->array = (int*)malloc(sizeof(int) * Dafault_Capacity);
	if (NULL == seq)
	{
		assert(0);
		return;
	}
	seq->_capacity = Dafault_Capacity;
	seq->_size = 0;
}

void SeqListDestroy(SeqList* seq)
{
	assert(seq);
	free(seq->array);
	seq->array = NULL;
	seq->_capacity = 0;
	seq->_size = 0;
}

void CheckCapacity(SeqList* seq)
{
	assert(seq);
	if (seq->_capacity == seq->_size)
	{
		int newcapacity = 2 * Dafault_Capacity;
		int* temp = (int*)malloc(sizeof(int) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		//元素拷贝
		memcpy(temp, seq->array, sizeof(int) * seq->_size);
		free(seq->array);
		seq->array = temp;
		seq->_capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* seq, int val)
{
	assert(seq);
	CheckCapacity(seq);
	seq->array[seq->_size] = val;
	seq->_size++;
}

void SeqListPrint(SeqList* seq)
{
	assert(seq);
	for (int i = 0; i < seq->_size; i++)
	{
		printf("%d ", seq->array[i]);
	}
	printf("\n");
	return;
}

void SeqListPushFront(SeqList* seq, int val)
{
	assert(seq);
	CheckCapacity(seq);
	for (int i = seq->_size - 1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = val;
	seq->_size++;
}

void SeqListPopFront(SeqList* seq)
{
	assert(seq);
	for (int i = 0; i <= seq->_size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->_size--;
}

void SeqListInsert(SeqList* seq, int index, int val)
{
	assert(seq);
	//需要判断一下所输入下标的合法性
	if (index<0 || index>seq->_size)
	{
		printf("输入下标非法，请重新输入!");
		return;
	}
	else
	{
		//先去检测容量是否够用
		CheckCapacity(seq);
		for (int i = seq->_size - 1; i >= index; i--)
		{
			seq->array[i + 1] = seq->array[i];
		}
		seq->array[index] = val;
		seq->_size++;
	}
}

void SeqListErase(SeqList* seq, int index)
{
	//确保顺序表存在
	assert(seq);
	for (int i = index; i <= seq->_size - 2; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->_size--;
}

int SeqListSize(SeqList* seq)
{
	assert(seq);
	if (0 == seq->_size)
		return 0;
	else
		return seq->_size;
}

int SeqListCapacity(SeqList* seq)
{
	assert(seq);
	return seq->_size;
}

int SeqListFind(SeqList* seq, int data)
{
	assert(seq);
	for (int i = 0; i < seq->_size; i++)
	{
		if (seq->array[i] == data)
			return i;
	}
	return -1;
}

int SeqListEmpty(SeqList* seq)
{
	return seq->_size == 0 ? 1 : 0;
}

void SeqListRemove(SeqList* seq, int data)
{
	assert(seq);
	SeqListErase(seq, SeqListFind(seq, data));
}

void SeqListRemoveAll(SeqList* seq, int data)
{
	//但是这种方法的时间复杂度接近N^2
	assert(seq != NULL);
	int index = -1;
	while (-1 != SeqListFind(seq, data))  //不等于说明是找到了
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
		 seq->array[i-count]=seq->array[i];
	 }
	 //这种方法的时间复杂度为O(N),空间复杂度为O(1)
	*/
}
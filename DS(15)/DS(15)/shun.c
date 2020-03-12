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

void SeqListPushBack(SeqList* seq,int val)
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

void SeqListPushFront(SeqList* seq,int val)
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
			seq->array[i+1] = seq->array[i];
		}
		seq->array[index] = val;
		seq->_size++;
	}
}

void SeqListErase(SeqList* seq, int index)
{
	//确保顺序表存在
	assert(seq);
	for (int i = index;i<=seq->_size-2;i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->_size--;
}
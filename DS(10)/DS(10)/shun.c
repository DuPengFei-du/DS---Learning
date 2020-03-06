#include"shun.h"


void SeqListInit(SeqList* seq)
{
	//先看看这个顺序表是否存在
	assert(seq);
	seq->array = (int*)malloc(sizeof(int) * Default_Capacity);
	//查看申请的空间是否成功
	if (NULL == seq->array)
	{
		assert(0);
		return;
	}
	seq->_capacity = Default_Capacity;
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

//扩容操作
void CheckCapacity(SeqList* seq)
{
	assert(seq);
	if (seq->_capacity == seq->_size)
	{
		//证明已经满了
		int newcapacity = 2 * Default_Capacity;
		int* NewArray = (int*)malloc(sizeof(int) * Default_Capacity);
		//查看是否开辟成功
		if (NULL == NewArray)
		{
			assert(0);
			return;
		}
		memcpy(NewArray, seq->array, sizeof(int) * seq->_size);
		free(seq->array);
		seq->array = NewArray;
		seq->_capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* seq, int val)
{
	assert(seq);
	//查看一下容量是否够用
	CheckCapacity(seq);  //括号中参数的问题
	seq->array[seq->_size] = val;
	seq->_size++;
}

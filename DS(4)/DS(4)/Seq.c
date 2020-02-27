#include"Seq.h"

void SeqListInit(SeqList* ps)
{
	//ps是指针，所以我序言检测指针的合法性
	assert(ps);  //用assert会好一些，要确保首先传入的顺序表不是空的顺序表
	//或者使用 
	/*
	if(NULL==ps)
	return ;
	*/
	//默认情况：顺序表中可以存放10个元素
	ps->_array = (DataType*)malloc(sizeof(DataType) * Dafault_Capacity);
	if (NULL == ps->_array)
	{
		//assert的作用是让断言触发
		//放断言的好处是可以知道申请空间到底有没有成功
		//同时assert是一个调试宏
		//它只会在Debug版本下才会起作用
		//我们一般发布的版本都是Release版本
		//Release版本会进行一系列的优化，其中有一个就是会把assert删掉
		assert(0);
		return;
	}
	ps->_capacity = Dafault_Capacity;
	ps->_size = 0;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

//检测容量的函数不需要给外界的人知道，所以我不需要把这个函数放在头文件中
//直接放在定义文件中就可以了
void CheckCapaciy(SeqList* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		//先给一段新的空间，然后拷贝元素，在删除旧空间就可以了
		int newCapacity = 2 * Dafault_Capacity;
		//开辟新的空间
		DataType* temp = (DataType*)malloc(sizeof(DataType) * newCapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		//拷贝元素
		memcpy(temp, ps->_array, ps->_size * sizeof(DataType));
		free(ps->_array);
		ps->_array = temp;
		ps->_capacity = newCapacity;
	}
}

void SeqListPushBack(SeqList* ps, DataType data)
{
	assert(ps);
	//检查容量是否够用
	CheckCapaicty();
	ps->_array[ps->_size] = data;
	ps->_size++;
	//但是如果没有空间了的话怎么办
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (0 == ps->_size)
		return;
	ps->_size--;
}
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

void SeqListPushFront(SeqList* ps, DataType data)
{
	assert(ps);
	//需要检测空间是否够用
	CheckCapacity();
	for (int i = ps->_size - 1; i >= 0; i--)
	{
		//将顺序表中有效元素整体向后搬移一位
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[0] = data;
	ps->_size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	if (0 == ps->_size)
		return;
	for (int i = 0; i < ps->_size-1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

void SeqListInsert(SeqList* ps, int pos, DataType data)
{
	assert(ps);
	//先判断下标的合法性
	if (pos<0 || pos>ps->_size)
		printf("插入元素位置非法\n");
	//然后检测容量是否够用
	CheckCapacity();
	for (int i = ps->_size - 1; i >= pos; i--)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[pos] = data;
	ps->_size++;
}

void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	if (pos < 0 || pos >= ps->_size)
		printf("删除元素位置非法\n");
	for (int i = pos; i <= ps->_size - 2; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

int SeqListFind(SeqList* ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
			return i;
	}
	return -1;
}

int SeqListSize(SeqList* ps)
{
	assert(ps);
	return ps->_size;
}

int SeqLisCapacity(SeqList* ps)
{
	assert(ps);
	return ps->_capacity;
}

int SeqLisEmpty(SeqList* ps)
{
	assert(ps);
	if (0 == ps->_size)
		return 1;
	else
		return 0;
}

DataType SeqListFront(SeqList* ps)
{
	assert(ps);
	return ps->_array[0];
}

DataType SeqListBack(SeqList* ps)
{
	assert(ps);
	return ps->_array[ps->_size];
}

void SeqListRemove(SeqList* ps, DataType data)
{
	SeqListErase(ps,SeqListFind(ps, data));   //查找
}

void SeqListRemoveAll(SeqList* ps, DataType data)
{
	/*
	int pos=-1;
	while(-1!=(pos=SeqListFind(ps,data)))
	{
	   SeqListErase(ps,pos);
	}
	*/

	/*
	int i = 0;
	for (i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			SeqListErase(ps, i);
		}
	}
	*/

	int count = 0;   //记录待删除元素的个数
	for (int i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == data)
			count++;
		else
			ps->_array[i - count] = ps->_array[i];
	}
}

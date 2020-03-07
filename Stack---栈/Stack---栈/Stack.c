#include"Stack.h"

void StackInit(Stack* ps)
{
	//先看这个栈是否存在
	assert(ps);
	//然后去开辟空间
	ps->array = (int*)malloc(sizeof(int) * DefaultCapacity);
	//然后去判断是否申请空间成功
	if (NULL == ps->array)
	{
		assert(0);
		return;
	}
	ps->_capacity = DefaultCapacity;
	ps->_top = 0;   //相当于是顺序表中的size
}

void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		//表明容量已经不够用了
		int newcapacity = 2 * DefaultCapacity;
		SDataType* temp = (SDataType*)malloc(sizeof(SDataType) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		memcpy(temp, ps->array, sizeof(SDataType) * ps->_top);
		free(ps->array);
		ps->array = temp;
		ps->_capacity = newcapacity;
	}
}

void StackPush(Stack* ps, SDataType data)
{
	//进来需要先判断一下栈是否存在
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->_top] = data;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	if (0 == ps->_top)
		return;
	ps->_top--;   //就算是出栈了
}

SDataType StackTop(Stack* ps)
{
	//先检测是否存在
	assert(ps);
	return ps->array[ps->_top - 1];
}

int StackSize(Stack* ps)
{
	assert(ps);
	return  ps->_top;
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->_top;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->array)
	{
		free(ps->array);
		ps->array = NULL;
		ps->_capacity = 0;
		ps->_top = 0;
	}
}
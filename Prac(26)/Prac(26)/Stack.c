#include"Stack.h"


void StackInit(Stack* s)
{
	assert(s);
	s->array = (int*)malloc(sizeof(int) * Default_Capacity);
	if (NULL == s->array)
	{
		assert(0);
		return;
	}
	s->_capacity = Default_Capacity;
	s->_size = 0;
}

void StackDestory(Stack* s)
{
	assert(s);
	free(s->array);
	s->array = NULL;
	s->_capacity = 0;
	s->_size = 0;
}

void CheckCapacity(Stack* s)
{
	assert(s);
	if (s->_capacity == s->_size)
	{
		int newcapacity = 2 * Default_Capacity;
		int* temp = (int*)malloc(sizeof(int) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
	}
 }

void StackPush(Stack* s, int data)
{
	assert(s);
	CheckCapacity(s);
	s->array[s->_size] = data;
	s->_size++;
}

void StackPop(Stack* s)
{
	assert(s);
	if (s->_size == 0)
		return 0;
	s->_size--;
}

int StackEmpty(Stack* s)
{
	assert(s);
	return 0 == s->_size;
}

int StackTop(Stack* s)
{
	assert(s);
	return s->array[s->_size-1];
}

int StackSize(Stack* s)
{
	assert(s);
	return s->_size;
}
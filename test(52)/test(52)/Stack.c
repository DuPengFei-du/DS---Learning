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
	s->_top = 0;
}

void StackDestroy(Stack* s)
{
	assert(s);
	free(s->array);
	s->array = NULL;
	s->_capacity = 0;
	s->_top = 0;
}

void CheckCapacity(Stack* s)
{
	if (s->_capacity == s->_top)
	{
		int newcapacity = 2 * Default_Capacity;
		int* temp = (int*)malloc(sizeof(int) * newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		memcpy(temp, s->array, sizeof(int) * s->_top);
		free(s->array);
		s->array = temp;
		s->_capacity = newcapacity;
	}
}

void StackPush(Stack* s, int data)
{
	assert(s);
	CheckCapacity(s);
	s->array[s->_top] = data;
	s->_top++;
}

void StackPop(Stack* s)
{
	assert(s);
	if (s->_top == 0)
		return;
	s->_top--;
}

int StackTop(Stack* s)
{
	assert(s);
	return s->array[s->_top-1];
}

int StackEmpty(Stack* s)
{
	assert(s);
	if (s->_top == 0)
		return 1;
	return 0;
}

int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}
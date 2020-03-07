#include"Stack.h"

void StackInit(Stack* ps)
{
	//�ȿ����ջ�Ƿ����
	assert(ps);
	//Ȼ��ȥ���ٿռ�
	ps->array = (int*)malloc(sizeof(int) * DefaultCapacity);
	//Ȼ��ȥ�ж��Ƿ�����ռ�ɹ�
	if (NULL == ps->array)
	{
		assert(0);
		return;
	}
	ps->_capacity = DefaultCapacity;
	ps->_top = 0;   //�൱����˳����е�size
}

void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		//���������Ѿ���������
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
	//������Ҫ���ж�һ��ջ�Ƿ����
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
	ps->_top--;   //�����ǳ�ջ��
}

SDataType StackTop(Stack* ps)
{
	//�ȼ���Ƿ����
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
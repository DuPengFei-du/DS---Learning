#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Stack
{
	int array[100];  //Ϊ�˷���д�ɾ�̬��˳���
	int capacity;
	int top;  //��ʵ���൱����size
}Stack;

//��ʼ��
void StackInit(Stack* s)
{
	s->top = 0;
}

//����
void Destroy(Stack* s)
{
	s->top = 0;
}

//ѹջ
void StackPush(Stack* s)
{
	s->array[s->top++];
}

//��ջ
//һ���Ϊ�����������ջ������ջ��Ԫ��
//��  ��ջ��������ջ��Ԫ��.
//��ջ��Ҫ�󷵻�ջ��Ԫ��

int StackPop(Stack* s)
{
	//ҪҪ��ջ��������Ԫ�ش��ڵ�
	assert(s->top > 0);
	//����Ϊ��ǰ��ջ��Ԫ�ص�λ�ô���top--��λ��
	//��������Ҫ����s->array[--s->top]���λ�õ�Ԫ��
	return s->array[--s->top];
}

//����ջ��Ԫ��
int StackTop(Stack* s)
{
	//ȷ��ջ������Ԫ�ش��ڵ�
	assert(s->top > 0);
	return s->array[s->top - 1];
}

int StackSize(Stack* s)
{
	return s->top;
}

int StackIsEmpty(Stack* s)
{
	return s->top == 0 ? 1 : 0;
}
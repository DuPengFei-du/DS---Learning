#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define DefaultCapacity 100

typedef int SDataType;

typedef struct Stack
{
	SDataType* array;
	int _capacity;
	int _top;          //���ջ����λ��
}Stack;


//��ʼ������
void StackInit(Stack* ps);

//��ջ
void StackPush(Stack* ps, SDataType data);

//��ջ
void StackPop(Stack* ps);

//����ջ��Ԫ��
SDataType StackTop(Stack* ps);

//����ջ��Ԫ�صĸ���
int StackSize(Stack* ps);

//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps);

//����
void StackDestroy(Stack* ps);

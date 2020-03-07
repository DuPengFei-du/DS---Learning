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
	int _top;          //标记栈顶的位置
}Stack;


//初始化操作
void StackInit(Stack* ps);

//入栈
void StackPush(Stack* ps, SDataType data);

//出栈
void StackPop(Stack* ps);

//返回栈顶元素
SDataType StackTop(Stack* ps);

//返回栈中元素的个数
int StackSize(Stack* ps);

//判断栈是否为空
int StackEmpty(Stack* ps);

//销毁
void StackDestroy(Stack* ps);

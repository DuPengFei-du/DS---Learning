#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Stack
{
	int array[100];  //为了方便写成静态的顺序表
	int capacity;
	int top;  //其实就相当于是size
}Stack;

//初始化
void StackInit(Stack* s)
{
	s->top = 0;
}

//销毁
void Destroy(Stack* s)
{
	s->top = 0;
}

//压栈
void StackPush(Stack* s)
{
	s->array[s->top++];
}

//出栈
//一般分为两钟情况：出栈，返回栈顶元素
//和  出栈，不返回栈顶元素.
//出栈且要求返回栈顶元素

int StackPop(Stack* s)
{
	//要要求栈里面是由元素存在的
	assert(s->top > 0);
	//又因为当前的栈顶元素的位置处于top--的位置
	//所以我们要返回s->array[--s->top]这个位置的元素
	return s->array[--s->top];
}

//返回栈顶元素
int StackTop(Stack* s)
{
	//确保栈中是有元素存在的
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
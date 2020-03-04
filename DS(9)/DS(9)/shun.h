#pragma once

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>


//静态顺序表的结构
//typedef struct SeqList
//{
//	int array[10];
//	int size;          //有效元素的个数
//	int capacity;      //容量的大小
//}SeqList;


//动态顺序表的结构
#define Default_Capacity 100
typedef struct SeqList
{
	int* array;   //给成int类型的数据，当然了，也可以是别的类型的数据
	int size;
	int capacity;
}SeqList;
//动态顺序表的结构已经给出来了，下面给出顺序表的操作

//初始化操作
void SeqListInit(SeqList* seq);

//销毁操作
void SeqListDestroy(SeqList* seq);

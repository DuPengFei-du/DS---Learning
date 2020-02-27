#pragma once  //防止头文件被多次包含

#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>

//SeqList  ---  存储在连续的空间中  --->数组

#define MAX_SIZE 100
typedef int DataType;

//静态顺序表
//struct SeqList
//{
//	DataType array[MAX_SIZE];   //保存顺序表中有效元素的个数
//	DataType size;              //顺序表中有效元素的个数
//};


//动态顺序表
#define Dafault_Capacity 10
typedef struct SeqList
{
	DataType* _array;     //保存顺序表中有效元素的个数
	int _size;	         //有效元素的个数
	int _capacity;       //空间总大小
}SeqList;//*PSeqList;      //PSeqList是结构体星号类型的指针，也就是说，
//我可以直接用它来定义指针

//初始化操作
void SeqListInit(SeqList *ps);  //但是这么写的话，我就需要知道ps是指针了

//销毁操作
void SeqListDestroy(SeqList* ps);  //但是这么写的话，我就需要知道ps是指针了

//尾插
void SeqListPushBack(SeqList* ps,DataType data);

//尾删
void SeqListPopBack(SeqList* ps);

//头插
void SeqListPushFront(SeqList* ps, DataType data);

//头删
void SeqListPopFront(SeqList* ps);

//打印
void SeqListPrint(SeqList* ps);

//任意位置的插入
void SeqListInsert(SeqList* ps, int pos, DataType data);

//任意位置的删除
void SeqListErase(SeqList* ps, int pos);

//查咋元素
int SeqListFind(SeqList* ps, DataType data);

//移除掉第一个值为data的元素
void SeqListRemove(SeqList* ps,DataType data);

//移除全部值为Data的元素
void SeqListRemoveAll(SeqList* ps,DataType data);

//元素的个数
int SeqListSize(SeqList* ps);

//容量
int SeqLisCapacity(SeqList* ps);

//判断是否为空
int SeqLisEmpty(SeqList* ps);

//返回第一个元素
DataType SeqListFront(SeqList* ps);

//返回最后一个元素
DataType SeqListBack(SeqList* ps);
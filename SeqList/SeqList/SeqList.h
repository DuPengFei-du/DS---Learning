#pragma once   //防止文件被重复包含

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//#define MAXSIZE 20
#define DefaultCapacity 20 
typedef int DataType;   //因为存储的可能不只是整形，所以使用通用的类型
//  SeqList存储在连续的空间之中  ---   数组
//静态顺序表
//struct SeqList
//{
//	DataType array[MAXSIZE];   //保存顺序表中有序元组的个数
//	int size;             //顺序表中有效元素的个数
//};
//动态顺序表
//所以结构体中的动态空间不能给死
typedef struct SeqList
{
	DataType* array;   //保存顺序表中有效元素个数
	int _size;         //记录有效元素的个数
	int _capacity;     //空间总大小
}SeqList;

void SeqListInit(SeqList* seq);  //用指针的原因是，结构体可能比较大
//利用传值的方式，就会有些浪费空间

void SeqListPrint(SeqList* seq);

void SeqListDestroy(SeqList* seq);  //动态开辟的空间需要手动的进行释放

void SeqListPushBack(SeqList* seq, DataType data);  //进行尾插的操作

void SeqListPopBack(SeqList* seq);   //尾删
  
void SeqListPushFront(SeqList* seq, DataType data);  //头插

void SeqListPopFront(SeqList* seq);   //头删

void SeqListInsert(SeqList* seq, int index, DataType data);//在任意位置进行插入

void SeqListErase(SeqList* seq, int index); //在任意位置进行删除

int SeqListFind(SeqList* seq, DataType data);    //查找元素

void SeqListRemove(SeqList* seq, DataType data);  //移除第一个值为data的元素

void SeqListRemoveAll(SeqList* seq, DataType data);  //移除所有值为data的元素

int SeqSize(SeqList* seq);  //获取顺序表中元素的个数

int SeqCapacity(SeqList* seq);  //获取顺序表的容量

int SeqListEmpty(SeqList* seq);   //判断顺序表是否为空

DataType SeqListFront(SeqList* seq);  //获取顺序表的第一个元素

DataType SeqListLast(SeqList* seq);   //获取顺序表的最后一个元素
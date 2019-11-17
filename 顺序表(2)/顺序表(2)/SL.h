#pragma once//包含头文件只包含一次

typedef struct SeqList
{
	int* array;     //记录数据存放位置
	int capacity;   //记录总容量
	int size;       //记录已有数据的个数
}SeqList;
//为结构体起一个别名
//typedef struct SeqList SeqList;
void SeqListInit(SeqList* seq);
void SeqListDestroy(SeqList* seq);
void SeqListPushFront(SeqList* seq, int val);
void SeqListPushBack(SeqList* seq, int val);
void SeqListPrint(SeqList* seq);
//根据下标做插入
void SeqListInsert(SeqList* seq, int index, int val);
//头删
void SeqListPopFront(SeqList* seq);
//尾删
void SeqListPopBack(SeqList* seq);
//根据下标删除
void SeqListErase(SeqList* seq, int index);
//查找元素
int SeqListFind(SeqList* seq, int val);
//查找第一个遇到的val
void SeqListRemove(SeqList* seq, int val);
//删除顺序表中所有的val
void SeqListRemoveAll(SeqList* seq, int val);
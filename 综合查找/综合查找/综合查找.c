#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<memory.h>
#include<stdbool.h>
#include<time.h>

#define DATA_TYPE int 
#define default_capacity 99

typedef struct Seqlist
{
	DATA_TYPE* data;
	int capacity;
	int sz;
}Seqlist;

typedef struct BinTreeNode
{
	DATA_TYPE value;
	struct BinTreeNode* left;
	struct BinTreeNode* right;
}BinTreeNode;


//创建并初始化顺序表
void CreateSeqlist(Seqlist* sq, int sz)
{
	sq->capacity = default_capacity > sz ? default_capacity : sz;
	DATA_TYPE* tmp = (DATA_TYPE*)malloc(sizeof(DATA_TYPE) * sq->capacity);
	assert(tmp != NULL);
	sq->data = tmp;
	memset(sq->data, 0, sq->capacity);
	sq->sz = 0;
}

//随机数法产生和顺序表容量相同个数的随机数存储到文件seqlistdata.txt中
void GetRandomDigitWrite2File(const Seqlist* sq)
{
	FILE* fp = fopen("seqlistdata.txt", "w");
	int count = sq->capacity - 1;  //刚开始没有减1,导致会多获取一个随机数到文件中
	srand((unsigned int)time(NULL));
	while (count)
	{
		fprintf(fp, "%d ", rand() % 100);
		//printf("%d", count);
		--count;
	}
	fclose(fp);
}

//从打开的seqlistdata.txt文件中获取数据,对顺序表赋值
void SeqlistGetValue(Seqlist* sq)
{
	int i = 0;
	FILE* fp = fopen("seqlistdata.txt", "r");
	assert(fp != NULL);
	int c = 0;
	//printf("EOF = %d\n", EOF);
	while (i < sq->capacity && fgetc(fp) != EOF)  //用fgetc()函数判断文件是否读到结尾   c = fgetc(fp) != EOF
	{
		(void)fscanf(fp, "%d", (sq->data) + i);
		sq->sz++;
		//printf("%d %d ", i, *(sq->data + i));
		++i;
	}
	fclose(fp);
}

//在顺序表中查找所有与指定元素相同的元素下标
void SeqlistSearchElement(Seqlist* sq, DATA_TYPE element)
{
	//printf("sq->sz = %d\n", sq->sz);
	int flag = 1;
	int NumOfElement = sq->sz;
	for (int i = 0; i < NumOfElement; ++i)
	{
		if (sq->data[i] == element) {
			//return i;
			printf("找到了,%d元素在顺序表中的下标是:%d\n", element, i);
			flag = 0;
		}
	}
	if (flag)
		printf("%d元素未找到\n", element);
}
/*
int SeqlistSearchElement(Seqlist* sq, DATA_TYPE element)
{
	//printf("sq->sz = %d\n", sq->sz);
	int flag = 1;
	int NumOfElement = sq->sz;
	for (int i = 0; i < NumOfElement; ++i)
	{
		if (sq->data[i] == element) {
			return i;
		}
	}
	return -1;
}
*/

//元素比较函数
int cmp(const void* a, const void* b)
{
	return(*((int*)a) - *((int*)b));
}

//对顺序表快排序
void SeqlistQsort(Seqlist* sq)
{
	qsort((void*)sq->data, sq->sz, sizeof(DATA_TYPE), cmp);
	/*int NumOfElement = sq->sz;
	for (int i = 0; i < NumOfElement; ++i)
	{
		printf(" %d ", *(sq->data+i));
	}
	printf("\n");*/
}

int SeqlistBinSearch(Seqlist* sq, DATA_TYPE element)
{
	int left = 0, right = sq->sz - 1, mid = 0;
	while (left <= right)
	{
		mid = left + ((right - left) >> 1);
		if (element == sq->data[mid])
			return mid;
		else if (element > sq->data[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}


bool BinTreeInsert_(BinTreeNode** heap, DATA_TYPE c);
void BinTreeInsert(BinTreeNode** heap, DATA_TYPE c);

//从打开的seqlistdata.txt文件中获取数据,创建一个堆
void CreateHeap(Seqlist* sq, BinTreeNode** heap)
{
	int i = 0;
	FILE* fp = fopen("seqlistdata.txt", "r");
	assert(fp != NULL);
	DATA_TYPE c = 0;
	while (fgetc(fp) != EOF)
	{
		(void)fscanf(fp, "%d", &c);
		//printf("%d ", c);
		BinTreeInsert(heap, c);
	}
	fclose(fp);
}


void BinTreeInsert(BinTreeNode** heap, DATA_TYPE c)
{
	(void)BinTreeInsert_(heap, c);
}

bool BinTreeInsert_(BinTreeNode** heap, DATA_TYPE c)
{
	if (*heap == NULL)
	{
		BinTreeNode* tmp = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(tmp != NULL);
		*heap = tmp;
		(*heap)->left = (*heap)->right = NULL;
		(*heap)->value = c;
		return true;
	}
	else if (c < (*heap)->value)
	{
		BinTreeInsert_(&(*heap)->left, c);
	}
	else if (c > (*heap)->value)
	{
		BinTreeInsert_(&(*heap)->right, c);
	}
	else
		return false;
}


//排序二叉树的核心查找方法
BinTreeNode* HeapSearch(BinTreeNode** heap, DATA_TYPE element)
{
	if (*heap == NULL)
		return NULL;
	if (element == (*heap)->value)
		return *heap;
	else if (element < (*heap)->value)
		return HeapSearch(&(*heap)->left, element);
	else
		return HeapSearch(&(*heap)->right, element);
}




void menu()
{
	printf("请输入要选择的查找方式:>\n");
	printf("1. 顺序查找\n");
	printf("2. 二分查栈\n");
	printf("3. 二叉排序树查找\n");
	printf("0. 退出\n");
}

int main()
{
	Seqlist sq;
	BinTreeNode* heap = NULL;
	int findvalue = 0;
	int ResIndex = 0;
	BinTreeNode* ResDirection = NULL;

	int input = 0;
	do
	{
		menu();
		(void)scanf("%d", &input);
		switch (input)
		{
		case 1:
			CreateSeqlist(&sq, 0);
			GetRandomDigitWrite2File(&sq);
			SeqlistGetValue(&sq);
			printf("请输入要查找的元素值:>\n");
			(void)scanf("%d", &findvalue);
			SeqlistSearchElement(&sq, findvalue);
			/*if (ResIndex == -1)
				printf("%d元素未找到\n", findvalue);
			else
				printf("找到了,%d元素在顺序表中的下标是:%d\n", findvalue, ResIndex);*/
			break;
		case 2:
			SeqlistQsort(&sq);
			printf("请输入要查找的元素值:>\n");
			(void)scanf("%d", &findvalue);
			ResIndex = SeqlistBinSearch(&sq, findvalue);
			if (ResIndex == -1)
				printf("%d元素未找到\n", findvalue);
			else
				printf("找到了,%d元素在顺序表中的下标是:%d\n", findvalue, ResIndex);
			break;
		case 3:
			CreateHeap(&sq, &heap);
			printf("请输入要查找的元素值:>\n");
			(void)scanf("%d", &findvalue);
			ResDirection = HeapSearch(&heap, findvalue);
			if (ResDirection == NULL)
				printf("%d元素未找到\n", findvalue);
			else
				printf("找到了,%d元素在顺序表中的地址是:%p\n", findvalue, ResDirection);
			break;
			break;
		default:
			printf("选项输入不合法,请重新输入\n");
		}
	} while (input != 0);
	return 0;
}

/*
需求分析:
题目叫做综合查找,要求实现的是顺序查找,二分查找和二叉排序树查找
顺序查找中:设计一个顺序表实现顺序存储,从而实现顺序查找
二分查栈中:在顺序表实现顺序存储的基础上,直接对顺序表进行快排,然后用二分查找对一个元素进行查找
二叉排序树查找:首先实现一个二叉树,然后对二叉树进行堆排,再实现二叉树排序树查找的核心算法
*/
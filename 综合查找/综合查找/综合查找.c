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


//��������ʼ��˳���
void CreateSeqlist(Seqlist* sq, int sz)
{
	sq->capacity = default_capacity > sz ? default_capacity : sz;
	DATA_TYPE* tmp = (DATA_TYPE*)malloc(sizeof(DATA_TYPE) * sq->capacity);
	assert(tmp != NULL);
	sq->data = tmp;
	memset(sq->data, 0, sq->capacity);
	sq->sz = 0;
}

//�������������˳���������ͬ������������洢���ļ�seqlistdata.txt��
void GetRandomDigitWrite2File(const Seqlist* sq)
{
	FILE* fp = fopen("seqlistdata.txt", "w");
	int count = sq->capacity - 1;  //�տ�ʼû�м�1,���»���ȡһ����������ļ���
	srand((unsigned int)time(NULL));
	while (count)
	{
		fprintf(fp, "%d ", rand() % 100);
		//printf("%d", count);
		--count;
	}
	fclose(fp);
}

//�Ӵ򿪵�seqlistdata.txt�ļ��л�ȡ����,��˳���ֵ
void SeqlistGetValue(Seqlist* sq)
{
	int i = 0;
	FILE* fp = fopen("seqlistdata.txt", "r");
	assert(fp != NULL);
	int c = 0;
	//printf("EOF = %d\n", EOF);
	while (i < sq->capacity && fgetc(fp) != EOF)  //��fgetc()�����ж��ļ��Ƿ������β   c = fgetc(fp) != EOF
	{
		(void)fscanf(fp, "%d", (sq->data) + i);
		sq->sz++;
		//printf("%d %d ", i, *(sq->data + i));
		++i;
	}
	fclose(fp);
}

//��˳����в���������ָ��Ԫ����ͬ��Ԫ���±�
void SeqlistSearchElement(Seqlist* sq, DATA_TYPE element)
{
	//printf("sq->sz = %d\n", sq->sz);
	int flag = 1;
	int NumOfElement = sq->sz;
	for (int i = 0; i < NumOfElement; ++i)
	{
		if (sq->data[i] == element) {
			//return i;
			printf("�ҵ���,%dԪ����˳����е��±���:%d\n", element, i);
			flag = 0;
		}
	}
	if (flag)
		printf("%dԪ��δ�ҵ�\n", element);
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

//Ԫ�رȽϺ���
int cmp(const void* a, const void* b)
{
	return(*((int*)a) - *((int*)b));
}

//��˳��������
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

//�Ӵ򿪵�seqlistdata.txt�ļ��л�ȡ����,����һ����
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


//����������ĺ��Ĳ��ҷ���
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
	printf("������Ҫѡ��Ĳ��ҷ�ʽ:>\n");
	printf("1. ˳�����\n");
	printf("2. ���ֲ�ջ\n");
	printf("3. ��������������\n");
	printf("0. �˳�\n");
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
			printf("������Ҫ���ҵ�Ԫ��ֵ:>\n");
			(void)scanf("%d", &findvalue);
			SeqlistSearchElement(&sq, findvalue);
			/*if (ResIndex == -1)
				printf("%dԪ��δ�ҵ�\n", findvalue);
			else
				printf("�ҵ���,%dԪ����˳����е��±���:%d\n", findvalue, ResIndex);*/
			break;
		case 2:
			SeqlistQsort(&sq);
			printf("������Ҫ���ҵ�Ԫ��ֵ:>\n");
			(void)scanf("%d", &findvalue);
			ResIndex = SeqlistBinSearch(&sq, findvalue);
			if (ResIndex == -1)
				printf("%dԪ��δ�ҵ�\n", findvalue);
			else
				printf("�ҵ���,%dԪ����˳����е��±���:%d\n", findvalue, ResIndex);
			break;
		case 3:
			CreateHeap(&sq, &heap);
			printf("������Ҫ���ҵ�Ԫ��ֵ:>\n");
			(void)scanf("%d", &findvalue);
			ResDirection = HeapSearch(&heap, findvalue);
			if (ResDirection == NULL)
				printf("%dԪ��δ�ҵ�\n", findvalue);
			else
				printf("�ҵ���,%dԪ����˳����еĵ�ַ��:%p\n", findvalue, ResDirection);
			break;
			break;
		default:
			printf("ѡ�����벻�Ϸ�,����������\n");
		}
	} while (input != 0);
	return 0;
}

/*
�������:
��Ŀ�����ۺϲ���,Ҫ��ʵ�ֵ���˳�����,���ֲ��ҺͶ�������������
˳�������:���һ��˳���ʵ��˳��洢,�Ӷ�ʵ��˳�����
���ֲ�ջ��:��˳���ʵ��˳��洢�Ļ�����,ֱ�Ӷ�˳�����п���,Ȼ���ö��ֲ��Ҷ�һ��Ԫ�ؽ��в���
��������������:����ʵ��һ��������,Ȼ��Զ��������ж���,��ʵ�ֶ��������������ҵĺ����㷨
*/
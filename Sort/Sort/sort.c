#include"sort.h"

void PrintArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

//插入排序是稳定的排序算法
//时间复杂度为O(N^2)
//空间复杂度为0(1),没有借助辅助的空间
//最优场景为：待排序的数组已经基本有序了，时间复杂度为O(N)
//适用场景：数组的顺序已经基本有序了，数据量不是很大(比较的次数明显减少)
void InsertSort(int* array, int size)
{
	for (int i = 1; i < size; ++i)
	{
		//记录当前所要比较的元素
		int key = array[i];
		int end = i - 1;  //是当前元素的前一个元素
		//招待插入的位置
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = key;
	}
}

//希尔排序的空间复杂度是O(1)
//稳定性:希尔排序是不稳定的排序方法
//因为希尔排序在进行插入的时候他是随着分组进行插入的，所以其性质是不稳定的
//希尔排序的适用场景：数据量大，比较杂乱
void ShellSort(int* array, int size)
{
	int gap = size;
	//gap的选取有多种之前的人所提出的方法
	//(1)gap取一系列的素数; (2)gap/3+1;
	//希尔排序具体的时间复杂度是不好给的，因为希尔排序的时间复杂度
	//受到gap取值的影响
	//根据大量的计算得出：gap=gap/3+1的时间复杂度可以处于
	//N^1.25~1.6N^1.25 之间的这样一个时间复杂度
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; ++i)
		{
			//记录当前所要比较的元素
			int key = array[i];
			int end = i - gap;  //是当前元素的前一个元素
			//招待插入的位置
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		gap -= 1;
	}
}

void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void SelectSort(int* array, int size)
{
	for (int i = 0; i < size - 1 ; ++i)
	{
		int maxPos = 0;    //maxPos用来标记最大的元素所在的位置
		for (int j = 0; j < size - i ; ++j)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}
		Swap(&array[maxPos], &array[size-i - 1]);
	}
}
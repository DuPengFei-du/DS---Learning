#define _CRT_SECURE_NO_WARNINGS 1



int fib(int n)
{
	if (n < 3)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
//这个算法的时间复杂度为O(N^2)


void Func1(int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			++count;
		}
	}
	for (int k = 0; k < 2 * N; k++)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d", count);
}
/*
常数1取代运行时间中的所有加法常数
在修改后的运行次数函数中，只保留最高阶
如果最高阶存在且不是1，则去除与这个项目相乘的常数，得到的结果就是大O阶。
*/


#include<stdio.h>
int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
	}
	return 0;
}


#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int find = 0;//这里的数字可以随便给
	for (i = 0; i < sz; i++)
	{
		if (arr[i] == find)
			return i;
	}
	return -1;
}


void Func2(int N)
{
	int count = 0;
	for (int k = 0; k < 2 * N; k++)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d", count);
}


void Func3(int N, int M)
{
	int count = 0;
	for (int k = 0; k < M; k++)
	{
		++count;
	}
	for (int k = 0; k < N; k++)
	{
		++count;
	}
}


void Func4(int N)
{
	int count = 0;
	for (int k = 0; k < 100; k++)
	{
		++count;
	}
	printf("%d", count);
	return 0;
}


#include<stdio.h>
int main()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int i = 0;
	int j = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


#include<stdio.h>
int main()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int i = 0;
	int j = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr)[0];
	int key = 8;
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了，下标为:%d", mid);
			break;
		}
	}
	return 0;
}


int Fac(int N)
{
	if (0 == N || 1 == N)
		return 1;
	else
		return N * Fac(N - 1);
}
//单次比较总共进行了1次，递归一共是N+1次


#include<stdio.h>
long long Fib(int N)
{
	long long a = 1;
	long long b = 1;
	long long c = 1;
	for (int i = 3; i <= N; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
int main()
{
	printf("%lld", Fib(10));
	return 0;
}


#include<stdio.h>
long long Fib(long long a, long long b, int N)
{
	if (N < 3)
		return 1;
	else if (3 == N)
		return a + b;
	else
		return Fib(b, a + b, N - 1);
}
int main()
{
	printf("%lld", Fib(1, 1, 10));
	return 0;
}


//合并有序数组
void Merge(int arr1[], int arr2[], int size1, int size2)
{
	int index1 = 0;
	int index2 = 0;
	int index = 0;
	int* temp = (int*)malloc(sizeof(int) * (size1 + size2));   //temp为动他开辟的辅助空间
	//保证index1和index2下标合法
	while (index1 < size1 && index2 < size2)
	{
		if (arr1[index1] < arr2[index2])
			temp[index++] = arr1[index1++];
		else
			temp[index++] = arr2[index2++];
	}
	while (index1 < size1)  //说明数组1还有剩余而数组2没有剩余了
	{
		temp[index++] = arr1[index1++];
	}
	while (index2 < size2)
	{
		temp[index++] = arr2[index2++];
	}
	return temp;
}
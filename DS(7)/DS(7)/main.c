#define _CRT_SECURE_NO_WARNINGS 1



//斐波那契数列
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}


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
//时间复杂度为0(N^2)


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
//时间复杂度为O(1)


#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int find = 0;//这里的数字可以随便给
	//所要查找的数字可以决定出来到底是哪种情况
	//最好情况
	//最坏情况
	//平均情况
	for (i = 0; i < sz; i++)
	{
		if (arr[i] == find)
			return i;
	}
	return -1;   //如果找不到的话，那么就返回-1
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
//时间复杂度为O(1)


//冒泡排序
#include<stdio.h>
int main()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz-1; i++)
	{
		for (int j = 0; j < sz - i - 1; j++)
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


//二分查找
#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int right = sz - 1;
	int key = 5;
	while (left <= right)
	{
		int mid = left + (right - left / 2);
		if (arr[mid] == key)
		{
			printf("找到了，下标为:%d", mid);
			break;
		}
		else if (arr[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;
}
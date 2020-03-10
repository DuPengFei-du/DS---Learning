#define _CRT_SECURE_NO_WARNINGS 1


//斐波那契问题的来源就是兔子生小孩
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
//这个算法的时间复杂度为O(2^N)


//求阶乘的问题
int fac(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return fac(n - 1) * n;
}
//这个算法的时间复杂度为O(N)
//递归问题的算法：单词递归的比较次数*递归的总次数(或者说是递归的深度)


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
//将时间复杂度转换为基本语句的执行次数


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


//冒泡排序
#include<stdio.h>
int main()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0;j < sz - i - 1; j++)
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
//冒泡排序的时间复杂度为O(n^2)


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

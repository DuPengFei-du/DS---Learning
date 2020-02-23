#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
	//斐波那契数列来源于兔子生小孩的问题
	//第一个月是一对兔子，第二个月还是一对兔子
	//直到第三个月，兔子生孩子了，所以第三个月，一共有2对兔子
	//到了第四个月，一共有三对兔子，一次类推
	printf("%d", fib(10));
	return 0;
}


#include<stdio.h>
int fac(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return fac(n - 1) * n;
}
int main()
{
	//求阶乘
	//程序中函数在进行使用的时候都需要创建自己的函数栈帧
	printf("%d", fac(5));
	return 0;
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
	//通过这里所要查找的数字
	//我们就可以知道到底是哪种情况
	//是最好情况
	//最坏情况
	//还是平均情况
	for (i = 0; i < sz; i++)
	{
		if (arr[i] == find)
			return i;
	}
	return -1;
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


//优化的斐波那契数列
#include<stdio.h>
long long fib(int n)
{
	long long a = 1;
	long long b = 1;
	long long c = 1;
	for (int i = 3; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
int main()
{
	int n = 0;
	long long ret = 0;
	(void)scanf("%d", &n);
	ret = fib(n);
	printf("%lld", ret);
	return 0;
}


#include<stdio.h>
long long  fib(long long a,long long b,int n)
{
	if (n < 3)
		return 1;
	else if (n == 3)
		return a + b;
	else
		return fib(b, a + b, n - 1);
}
int main()
{
	int n = 0;
	long long  ret = 0;
	(void)scanf("%d", &n);
	ret = fib(1, 1, n);
	printf("%lld", ret);
	return 0;
}


//合并两个有序数组
void MergeList(int size1, int size2, int arr1[], int arr2[])
{
	int index1 = 0;
	int index2 = 0;
	int index = 0;
	int* temp = (int*)malloc(sizeof(int) * (size1 + size2));
	while (index1 < size1 && index2 < size2)
	{
		if (arr1[index1] < arr2[index2])
		{
			temp[index++] = arr1[index1++];
		}
		else
		{
			temp[index++] = arr2[index2++];
		}
	}
	while (index1 < size1)
	{
		temp[index++] = arr1[index1++];
	}
	while (index2 < size2)
	{
		temp[index++] = arr2[index2++];
	}
	return temp;
}
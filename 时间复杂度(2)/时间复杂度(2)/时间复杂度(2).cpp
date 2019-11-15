//计算时间复杂度
void func4(int n)
{
	int count = 0;
	for (int k = 0; k < 100; k++)
	{
		++count;
	}
	printf("%d\n", count);
}
//时间复杂度为0(1)


//冒泡排序
#include<stdio.h>
void BubbleSort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
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
}
int main()
{
	int i = 0;
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	for (i=0;i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
//普通算法下的冒泡排序的时间复杂度为0(n^2)


//优化版本的冒泡排序
#include<stdio.h>
void BubbleSort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		假设已经有序
		int flag = 1;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;
				如果发生了交换就不是有序的
			}
		}
		if (flag == 1)
			break;
	}
}
int main()
{
	int i = 0;
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
//时间复杂度为0(n),遍历一遍，如果不发生交换，那么就是有序的



//二分查找
//#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int right = sz - 1;
	int key = 7;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
			right = mid - 1;
		else if (arr[mid] < key)
			left = mid + 1;
		else
		{
			printf("找到了，下标为%d", mid);
			break;
		}
	}
	return 0;
}


//封装成函数的二分查找
#include<stdio.h>
void BinarySearch(int arr[], int sz)
{
	int key = 7;
	int left = 0;
	int right = sz - 1;
	while(left<=right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
			right = mid - 1;
		else if (arr[mid] < key)
			left = mid + 1;
		else
		{
			printf("找到了，下标为%d",mid);
			break;
		}
	}
}
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9,};
	int sz = sizeof(arr) / sizeof(arr[0]);
	BinarySearch(arr, sz);
	return 0;
}


#include<stdio.h>
int BinarySearch(int arr[], int sz)
{
	int key = 7;
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
			right = mid - 1;
		else if (arr[mid] < key)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9, };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret=BinarySearch(arr, sz);
	if (ret == -1)
	{
		printf("找不到");
	}
	else
	{
		printf("找到了，下标为%d", ret);
	}
	return 0;
}
//时间复杂度为0(logn)


//递归函数求时间复杂度
#include<stdio.h>
int fac(int n)
{
	if (n == 1)
		return 1;
	else
		return fac(n - 1) * n;
}
int main()
{
	int n = 0;
	int ret = 0;
	(void)scanf("%d", &n);
	ret = fac(n);
	printf("%d", ret);
	return 0;
}
//求阶乘的时间复杂度为0(n)


//斐波那契数列的时间复杂度
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
	int n = 0;
	int ret = 0;
	(void)scanf("%d", &n);
	ret = fib(n);
	printf("%d", ret);
	return 0;
}
//斐波那契数列的时间复杂度为0(2^n)
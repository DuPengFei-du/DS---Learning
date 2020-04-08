#define _CRT_SECURE_NO_WARNINGS 1


//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; k++)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d", count);
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int find = 0;//这里的数字可以随便给
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == find)
//			return i;
//	}
//	return -1;
//}
////平均情况：任意输入规模所期望的平均次数


//void Func2(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; k++)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d", count);
//}


//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; k++)
//	{
//		++count;
//	}
//	for (int k = 0; k < N; k++)
//	{
//		++count;
//	}
//}


//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; k++)
//	{
//		++count;
//	}
//	printf("%d", count);
//	return 0;
//}


//冒泡排序
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//			break;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr)[0];
//	int key = 8;
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标为:%d", mid);
//			break;
//		}
//	}
//	return 0;
//}


////fib的循环形式
//#include<stdio.h>
//long long fib(int n)
//{
//	long long a = 1;
//	long long b = 1;
//	long long c = 1;
//	for (int i = 3; i <= n; i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return b;
//}
//int main()
//{
//	int n = 0;
//	(void)scanf("%d", &n);
//	printf("%lld", fib(n));
//	return 0;
//}


//fib的递归形式
//#include<stdio.h>
//long long fib(long long a,long long b,int n)
//{
//	if (n < 3)
//		return 1;
//	else if (n == 3)
//		return a + b;
//	else
//		return fib(b, a + b, n - 1);
//}
//int main()
//{
//	int n = 0;
//	(void)scanf("%d", &n);
//	printf("%lld", fib(1,1,n));
//	return 0;
//}
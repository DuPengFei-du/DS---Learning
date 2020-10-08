#define _CRT_SECURE_NO_WARNINGS 1


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
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
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				flag = 0;
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//		if (flag == 1)
//			break;
//	}
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int key = 6;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] > key)
//			right = mid - 1;
//		else if (arr[mid] < key)
//			left = mid + 1;
//		else
//		{
//			printf("找到了，下标为:%d", mid);
//			break;
//		}
//	}
//	return -1;
//}


//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int i = 1;
//	int sum = 1;
//	(void)scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	printf("%d", sum);
//	return 0;
//}


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


//#include<stdio.h>
//long long fib(long long a, long long b,int n)
//{
//	if (n == 3)
//		return a + b;
//	else if (n < 3)
//		return 1;
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


//#include<stdio.h>
//void BubbleSort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr, sz);
//	Print(arr, sz);
//	return 0;
//}


//void Merge(int arr1[], int arr2[], int size1, int size2)
//{
//	int index1 = 0;
//	int index2 = 0;
//	int index = 0;
//	int* temp = (int*)malloc(sizeof(int) * (size1 + size2));   //temp为动他开辟的辅助空间
//	//保证index1和index2下标合法
//	while (index1 < size1 && index2 < size2)
//	{
//		if (arr1[index1] < arr2[index2])
//			temp[index++] = arr1[index1++];
//		else
//			temp[index++] = arr2[index2++];
//	}
//	while (index1 < size1)  //说明数组1还有剩余而数组2没有剩余了
//	{
//		temp[index++] = arr1[index1++];
//	}
//	while (index2 < size2)
//	{
//		temp[index++] = arr2[index2++];
//	}
//	return temp;
//}
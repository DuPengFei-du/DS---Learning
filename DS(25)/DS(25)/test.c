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
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int i = 0;
//	int j = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz-1 ; i++)
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
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int i = 0;
//	int j = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;
//		for (j = 0; j < sz - i - 1; j++)
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


//二分查找
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int key = 4;
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
//	return 0;
//}

//
//int Fac(int N)
//{
//	if (0 == N || 1 == N)
//		return 1;
//	else
//		return N * Fac(N - 1);
//}
////单次比较总共进行了1次，递归一共是N+1次


//#include<stdio.h>
//long long Fib(int N)
//{
//	long long a = 1;
//	long long b = 1;
//	long long c = 1;
//	for (int i = 3; i <= N; i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return c;
//}
//int main()
//{
//	printf("%lld", Fib(10));
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

#define _CRT_SECURE_NO_WARNINGS 1


//int fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}

//
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


//冒泡排序
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int i = 0;
//	int j = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz-1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
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
//		for (j = 0; j < sz - 1 - i; j++)
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
//	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	int key = 3;
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] == key)
//		{
//			printf("找到了，下标为:%d", mid);
//			break;
//		}
//		else if (arr[mid] > key)
//			right = mid - 1;
//		else
//			left = mid + 1;
//	}
//	return 0;
//}


//合并有序数组
//void Merge(int* arr1 , int* arr2 , int size1, int size2)
//{
//	int index1 = 0;
//	int index2 = 0;
//	int index = 0;
//	int* temp = (int*)malloc(sizeof(int) * (size1 + size2));
//	while (index1 < size1 && index2 < size2)
//	{
//		if (arr1[index1] < arr2[index2])
//			temp[index++] = arr1[index1++];
//		else
//			temp[index++] = arr2[index2++];
//	}
//	while (index1 < size1)
//	{
//		temp[index++] = arr1[index1++];
//	}
//	while (index2 < size2)
//	{
//		temp[index++] = arr1[index1++];
//	}
//	return temp;
//}
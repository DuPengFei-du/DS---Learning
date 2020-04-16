#define _CRT_SECURE_NO_WARNINGS 1

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
//	printf("%lld", fib(10));
//	return 0;
//}


//#include<stdio.h>
//long long fib(long long a,long long b, int n)
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


//合并有序数组
//void Merge(int arr1[], int arr2[], int size1, int size2)
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
//		temp[index++] = arr2[index2++];
//	}
//	return temp;
//}
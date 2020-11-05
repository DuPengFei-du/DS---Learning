#define _CRT_SECURE_NO_WARNINGS 1


//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	int key = 7;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < key)
//			left = mid + 1;
//		else if (arr[mid] > key)
//			right = mid - 1;
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
//	int i = 1;
//	int n = 0;
//	int sum = 1;
//	(void)scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	printf("%d", sum);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	(void)scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//		sum += ret;
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
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
//	printf("%lld", fib(n));
//	return 0;
//}


//#include<stdio.h>
//long long fib(long long a, long long b, int n)
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
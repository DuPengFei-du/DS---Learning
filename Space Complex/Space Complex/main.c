//阶乘的复杂度
//递归程序
//int Fac(int N)
//{
//	if (0 == N || 1 == N)
//		return 1;
//	else
//		return N * Fac(N - 1);
//}


//斐波那契数列
//int Fib(int N)
//{
//	if (N < 3)
//		return 1;
//	else
//		return Fib(N - 1) + Fib(N - 2);
//}


//斐波那契数列的递归和循环形式
//循环形式
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


//递归形式
//#include<stdio.h>
//long long Fib(long long a, long long b, int N)
//{
//	if (N < 3)
//		return 1;
//	else if (3 == N)
//		return a + b;
//	else
//		return Fib(b, a + b, N - 1);
//}
//int main()
//{
//	printf("%lld", Fib(1, 1, 10));
//	return 0;
//}
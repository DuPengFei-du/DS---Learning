#define _CRT_SECURE_NO_WARNINGS 1



//���ݽṹ
int fib(int N)
{
	if (N <= 2)
		return 1;
	else
		return fib(N - 2) + fib(N - 1);
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
//��ʵ�ʵļ����У����ǲ���һ��Ҫ�������ȷ�����֣�ֻ��Ҫ֪����ŵ����־Ϳ����ˣ���������ʹ�ô�0������ʾ��


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
//ʱ�临�Ӷ�ΪO(1)


#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int find = 0;//��������ֿ�������
	for (i = 0; i < sz; i++)
	{
		if (arr[i] == find)
			return i;
	}
	return -1;
}
//ʱ�临�Ӷ�ΪO(n)


void Func2(int N)
{
	int count = 0;
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
//ʱ�临�Ӷ�ΪO(n)


void Func3(int N, int M)
{
	int count = 0;
	for (int k = 0; k < M; k++)
	{
		++count;
	}
	for (int k = 0; k < N; k++)
	{
		++count;
	}
}
//ʱ�临�Ӷ�ΪO(M+N)


void Func4(int N)
{
	int count = 0;
	for (int k = 0; k < 100; k++)
	{
		++count;
	}
	printf("%d", count);
	return 0;
}
//O(1)


//ð��������Ż�
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


//�����쳲��������е�ʱ�临�Ӷȱ�ΪO(1)
//����ѭ���ķ���
#include<stdio.h>
long long  fib(int n)
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
	long long  ret = 0;
	(void)scanf("%d", &n);
	ret = fib(n);
	printf("%lld", ret);
	return 0;
}


//�ݹ���ʽ
#include<stdio.h>
long long fib(long long a, long long b, int n)
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
	long long ret = 0;
	(void)scanf("%d", &n);
	ret = fib(1, 1, n);
	printf("%lld", ret);
	return 0;
}
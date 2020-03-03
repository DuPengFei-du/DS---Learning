#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
int fib(int n)
{
	if (n < 3)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
	printf("%d", fib(10));
	return 0;
}


//�㷨��ʱ�临�ӶȺͿռ临�Ӷ�
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
  //����Ҫ���ҵ����ֲ�ͬ���ͻ���ֲ�ͬ�ĸ��Ӷ����
	for (i = 0; i < sz; i++)
	{
		if (arr[i] == find)
			return i;
	}
	return -1;
}
//�����в������ֵ�ʱ�临�Ӷ�ΪO(N)


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


#include<stdio.h>
int main()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int i = 0;
	int j = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
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
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
//ð�������ʱ�临�Ӷ�ΪO(n^2)


#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr)[0];
	int key = 8;
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			printf("�ҵ��ˣ��±�Ϊ:%d", mid);
			break;
		}
	}
	return 0;
}
//���ֲ��ҵ�ʱ�临�Ӷ�ΪO(logn)


int Fac(int N)
{
	if (0 == N || 1 == N)
		return 1;
	else
		return N * Fac(N - 1);
}
//���αȽ��ܹ�������1�Σ��ݹ�һ����N+1��


//쳲�������ѭ����ʽ
#include<stdio.h>
long long fib(int n)
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
	return b;
}
int main()
{
	int n = 0;
	(void)scanf("%d", &n);
	printf("%lld", fib(n));
	return 0;
}


#include<stdio.h>
long long fib(long long a,long long b,int n)
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
	(void)scanf("%d", &n);
	printf("%lld", fib(1, 1, n));
	return 0;
}


void Merge(int arr1[], int arr2[], int size1, int size2)
{
	int index1 = 0;
	int index2 = 0;
	int index = 0;
	int* temp = (int*)malloc(sizeof(int) * (size1 + size2));   //tempΪ�������ٵĸ����ռ�
	//��֤index1��index2�±�Ϸ�
	while (index1 < size1 && index2 < size2)
	{
		if (arr1[index1] < arr2[index2])
			temp[index++] = arr1[index1++];
		else
			temp[index++] = arr2[index2++];
	}
	while (index1 < size1)  //˵������1����ʣ�������2û��ʣ����
	{
		temp[index++] = arr1[index1++];
	}
	while (index2 < size2)
	{
		temp[index++] = arr2[index2++];
	}
	return temp;
}
//�ռ临�Ӷ�ΪO(n+m)
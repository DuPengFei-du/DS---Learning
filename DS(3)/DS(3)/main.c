#define _CRT_SECURE_NO_WARNINGS 1


//ð������
#include<stdio.h>
int main()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}


//�Ż�
#include<stdio.h>
int main()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < sz - i - 1; j++)
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
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int right = sz - 1;
	int key = 8;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == key)
		{
			printf("�ҵ��ˣ��±�Ϊ%d:", mid);
			break;
		}
		else if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return 0;
}


//��׳�
int fac(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return fac(n - 1) * n;
}
//ʱ�临�Ӷ�ΪO(n)
//����ִ�д���*�ܵĵݹ����


//쳲�����
int fib(int n)
{
	if (n < 3)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}


//�����Ż�
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
	(void)scanf("%d", &n);
	printf("%lld", fib(n));
	return 0;
}


#include<stdio.h>
long long fib(long long a, long long b, int n)
{
	if (n == 3)
		return a + b;
	else if (n < 3)
		return 1;
	else
		return fib(b, a + b,n-1);
}
int main()
{
	int n = 0;
	(void)scanf("%d", &n);
	printf("%lld", fib(1, 1, n));
	return 0;
}


//�ϲ���������
void Merge(int array1[], int size1, int array2[], int size2)
{
	int index1 = 0;
	int index2 = 0;
	int index = 0;
	int* temp = (int*)malloc(sizeof(int) * (size1 + size2));
	while (index1 < size1 && index2 < size2)  //��֤�±�ĺϷ���
	{
		if (array1[index1] < array2[index2])
			temp[index++] = array1[index1++];
		else
			temp[index++] = array2[index2++];
	}
	while(index1<size1)
		temp[index++] = array1[index1++];  //˵������1����ʣ��
	while (index2 < size2)
		temp[index++] = array2[index2++];  //˵������2����ʣ��
	return temp;
}
//����ʱ�临�Ӷ�
void func4(int n)
{
	int count = 0;
	for (int k = 0; k < 100; k++)
	{
		++count;
	}
	printf("%d\n", count);
}
//ʱ�临�Ӷ�Ϊ0(1)


//ð������
#include<stdio.h>
void BubbleSort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
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
}
int main()
{
	int i = 0;
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	for (i=0;i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
//��ͨ�㷨�µ�ð�������ʱ�临�Ӷ�Ϊ0(n^2)


//�Ż��汾��ð������
#include<stdio.h>
void BubbleSort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		�����Ѿ�����
		int flag = 1;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;
				��������˽����Ͳ��������
			}
		}
		if (flag == 1)
			break;
	}
}
int main()
{
	int i = 0;
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
//ʱ�临�Ӷ�Ϊ0(n),����һ�飬�����������������ô���������



//���ֲ���
//#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int right = sz - 1;
	int key = 7;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
			right = mid - 1;
		else if (arr[mid] < key)
			left = mid + 1;
		else
		{
			printf("�ҵ��ˣ��±�Ϊ%d", mid);
			break;
		}
	}
	return 0;
}


//��װ�ɺ����Ķ��ֲ���
#include<stdio.h>
void BinarySearch(int arr[], int sz)
{
	int key = 7;
	int left = 0;
	int right = sz - 1;
	while(left<=right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
			right = mid - 1;
		else if (arr[mid] < key)
			left = mid + 1;
		else
		{
			printf("�ҵ��ˣ��±�Ϊ%d",mid);
			break;
		}
	}
}
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9,};
	int sz = sizeof(arr) / sizeof(arr[0]);
	BinarySearch(arr, sz);
	return 0;
}


#include<stdio.h>
int BinarySearch(int arr[], int sz)
{
	int key = 7;
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] > key)
			right = mid - 1;
		else if (arr[mid] < key)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9, };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret=BinarySearch(arr, sz);
	if (ret == -1)
	{
		printf("�Ҳ���");
	}
	else
	{
		printf("�ҵ��ˣ��±�Ϊ%d", ret);
	}
	return 0;
}
//ʱ�临�Ӷ�Ϊ0(logn)


//�ݹ麯����ʱ�临�Ӷ�
#include<stdio.h>
int fac(int n)
{
	if (n == 1)
		return 1;
	else
		return fac(n - 1) * n;
}
int main()
{
	int n = 0;
	int ret = 0;
	(void)scanf("%d", &n);
	ret = fac(n);
	printf("%d", ret);
	return 0;
}
//��׳˵�ʱ�临�Ӷ�Ϊ0(n)


//쳲��������е�ʱ�临�Ӷ�
#include<stdio.h>
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
	int n = 0;
	int ret = 0;
	(void)scanf("%d", &n);
	ret = fib(n);
	printf("%d", ret);
	return 0;
}
//쳲��������е�ʱ�临�Ӷ�Ϊ0(2^n)
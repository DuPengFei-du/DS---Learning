//��O��������ʾ��
//#include<stdio.h>
//void fun1(int n)
//{
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; i < n; j++)
//		{
//			++count;
//		}
//	}
//}
////�������ʱ�临�Ӷ�ΪO(n),�ڲ�һ��n���ⲿһ��n�����Ը��Ӷ�Ϊn*n,Ϊn^2;
//for (k = 0; k < 2 * n; k++)
//{
//	++count;
//}
////�������ʱ�临�Ӷ�Ϊ2*n
//int m = 10;
//while (m--)
//{
//	++count;
//}
////�������ʱ�临�Ӷ�Ϊ10;


//��һ������������в���һ����
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int key = 7;
//	for (int i = 0; i < 10; i++)
//	{
//		if (arr[i] == key)
//		{
//			printf("%d", i);
//		}
//	}
//	return 0;
//}


//����ʱ�临�Ӷ�
//int func2(int n)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * n; k++)
//	{
//		++count;
//	}
//	int m = 10;
//	while (m--)
//	{
//		++count;
//	}
//	printf("%d", count);
//	return 0;
//}
//�����ʱ�临�Ӷ�Ϊ0(n)


//����ʱ�临�Ӷ�
//int func3(int n, int m)
//{
//	int count = 0;
//	for(int k = 0; k < m; ++k)
//	{
//		++count;
//	}
//	for (int k = 0; k < n; k++)
//	{
//		++count;
//	}
//	printf("%d", count);
//	return 0;
//}
//ʱ�临�Ӷ�Ϊ0(m+n)


//����ʱ�临�Ӷ�
//void func4(int n)
//{
//	int count = 0;
//	for (int k = 0; k < 100; k++)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//ʱ�临�Ӷ�Ϊ0(1)
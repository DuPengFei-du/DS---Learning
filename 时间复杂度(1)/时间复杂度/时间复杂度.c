//大O渐进法表示：
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
////这个语句的时间复杂度为O(n),内部一个n，外部一个n，所以复杂度为n*n,为n^2;
//for (k = 0; k < 2 * n; k++)
//{
//	++count;
//}
////这个语句的时间复杂度为2*n
//int m = 10;
//while (m--)
//{
//	++count;
//}
////这个语句的时间复杂度为10;


//在一个无序的数组中查找一个数
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


//计算时间复杂度
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
//这个的时间复杂度为0(n)


//计算时间复杂度
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
//时间复杂度为0(m+n)


//计算时间复杂度
//void func4(int n)
//{
//	int count = 0;
//	for (int k = 0; k < 100; k++)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//时间复杂度为0(1)
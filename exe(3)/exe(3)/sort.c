#include"sort.h"



void InsertSort(int arr[], int sz)
{
	//≤Â»Î≈≈–Ú
	for (int i = 1; i < sz; i++)
	{
		int key = arr[i];
		int end = i - 1;
		while (end >= 0 && key < arr[end])
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = key;
	}
}

void ShellSortI(int arr[], int sz)
{
	int gap = 3;
	while (gap >= 1)
	{
		for (int i = gap; i < sz; i++)
		{
			int key = arr[i];
			int end = i - gap;
			while (end >= 0 && key < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
		gap--;
	}
}

void ShellSortII(int arr[], int sz)
{
	int gap = sz;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < sz; i++)
		{
			int key = arr[i];
			int end = i - gap;
			while (end >= 0 && key < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
		gap--;
	}
}

void ShellSortIII(int arr[], int sz)
{
	int gap = sz/2;
	while (gap > 1)
	{
		gap >>= 1;
		for (int i = gap; i < sz; i++)
		{
			int key = arr[i];
			int end = i - gap;
			while (end >= 0 && key < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
		gap--;
	}
}


void Print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
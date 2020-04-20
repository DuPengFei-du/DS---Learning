#include"sort.h"

int main()
{
	int array[] = { 2,5,4,9,3,6,8,7,1,0 };
	int sz = sizeof(array) / sizeof(array[0]);
	InsertSort(array, sz);
	PrintArray(array, sz);
	ShellSort(array, sz);
	PrintArray(array, sz);
	SelectSort(array, sz);
	PrintArray(array, sz);
	return 0;
}
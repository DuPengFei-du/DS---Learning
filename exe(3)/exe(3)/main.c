#include"sort.h"


int main()
{
	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };

	int sz = sizeof(arr) / sizeof(arr[0]);

	//InsertSort(arr, sz);

	//Print(arr, sz);

	//ShellSortI(arr, sz);

	//Print(arr, sz);

	//ShellSortII(arr, sz);

	//Print(arr, sz);

	ShellSortIII(arr, sz);

	Print(arr, sz);

	return 0;
}
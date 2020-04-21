#include"DList.h"

int main()
{
	Node* phead = NULL;

	DListInit(&phead);

	DListPushBack(phead, 1);
	DListPushBack(phead, 2);
	DListPushBack(phead, 3);
	DListPushBack(phead, 4);
	DListPushBack(phead, 5);

	DListPrint(phead);

	DListDestroy(&phead);
}
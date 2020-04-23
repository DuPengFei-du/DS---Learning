#include"DList.h"


int main()
{
	Node* phead = NULL;


	DLNodeInit(&phead);

	DLNodePushBack(phead, 10);
	DLNodePushBack(phead, 20);
	DLNodePushBack(phead, 30);
	DLNodePushBack(phead, 40);
	DLNodePushBack(phead, 50);

	DLNodePirnt(phead);

	DLNodePushFront(phead, 1);
	DLNodePushFront(phead, 2);
	DLNodePushFront(phead, 3);
	DLNodePushFront(phead, 4);
	DLNodePushFront(phead, 5);

	DLNodePirnt(phead);

	DLNodePopFront(phead);
	DLNodePopFront(phead);

	DLNodePirnt(phead);

	DLNodePopBack(phead);
	DLNodePopBack(phead);

	DLNodePirnt(phead);

	DLNodeDestroy(&phead);
}
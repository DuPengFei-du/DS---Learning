#include"DList.h"


int main()
{
	Node* head;

	DLNodeInit(&head);

	DLNodePushBack(head, 2);
	DLNodePushBack(head, 4);
	DLNodePushBack(head, 6);
	DLNodePushBack(head, 8);
	DLNodePushBack(head, 10);

	DLNodePrint(head);

	DLNodePushFront(head, 1);
	DLNodePushFront(head, 3);
	DLNodePushFront(head, 5);
	DLNodePushFront(head, 7);
	DLNodePushFront(head, 9);

	DLNodePrint(head);

	DLNodePopFront(head);
	DLNodePopFront(head);

	DLNodePrint(head);

	DLNodePopBack(head);
	DLNodePopBack(head);

	DLNodePrint(head);

	DLNodeDestroy(&head);
}
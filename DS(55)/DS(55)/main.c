#include"DList.h"

int main()
{
	Node* head;

	DLNodeInit(&head);

	DLNodePushBack(head, 1);
	DLNodePushBack(head, 2);
	DLNodePushBack(head, 3);
	DLNodePushBack(head, 4);
	DLNodePushBack(head, 5);

	DLNodePrint(head);

	DLNodePushFront(head, 10);
	DLNodePushFront(head, 20);
	DLNodePushFront(head, 30);
	DLNodePushFront(head, 40);
	DLNodePushFront(head, 50);

	DLNodePrint(head);

	DLNodePopBack(head);
	DLNodePopBack(head);

	DLNodePrint(head);

	DLNodePopFront(head);
	DLNodePopFront(head);

	DLNodePrint(head);

	DLNodeDestroy(&head);
}
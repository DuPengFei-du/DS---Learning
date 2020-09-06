#include"DList.h"


int main()
{
	Node* head;

	DLNodeInit(&head);

	DLNodePushBack(head, 10);
	DLNodePushBack(head, 20);
	DLNodePushBack(head, 30);
	DLNodePushBack(head, 40);
	DLNodePushBack(head, 50);

	DLNodePrint(head);

	DLNodePushFront(head, 1);
	DLNodePushFront(head, 2);
	DLNodePushFront(head, 3);
	DLNodePushFront(head, 4);
	DLNodePushFront(head, 5);

	DLNodePrint(head);

	DLNodePopFront(head);
	DLNodePopFront(head);

	DLNodePrint(head);

	DLNodePopBack(head);
	DLNodePopBack(head);

	DLNodePrint(head);

	DLNodeDestroy(&head);
}
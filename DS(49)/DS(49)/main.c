#include"DList.h"

int main()
{
	Node* head;

	DListInit(&head);

	DListPushBack(head, 1);
	DListPushBack(head, 2);
	DListPushBack(head, 3);
	DListPushBack(head, 4);
	DListPushBack(head, 5);

	DListPrint(head);

	DListPushFront(head, 10);
	DListPushFront(head, 20);
	DListPushFront(head, 30);
	DListPushFront(head, 40);
	DListPushFront(head, 50);

	DListPrint(head);

	DListPopBack(head);
	DListPopBack(head);

	DListPrint(head);

	DListPopFront(head);
	DListPopFront(head);

	DListPrint(head);

	DListDestroy(&head);
}
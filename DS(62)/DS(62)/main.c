#include"DList.h"


int main()
{
	Node* head;

	DListInit(&head);

	DListPushBack(head, 10);
	DListPushBack(head, 20);
	DListPushBack(head, 30);
	DListPushBack(head, 40);
	DListPushBack(head, 50);

	DListPrint(head);

	DListPushFront(head, 1);
	DListPushFront(head, 2);
	DListPushFront(head, 3);
	DListPushFront(head, 4);
	DListPushFront(head, 5);

	DListPrint(head);

	DListPopFront(head);
	DListPopFront(head);

	DListPrint(head);

	DListPopBack(head);
	DListPopBack(head);

	DListPrint(head);

	DListDestroy(&head);
}
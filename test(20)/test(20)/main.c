#include"DList.h"

int main()
{
	Node* head;

	ListInit(&head);

	ListPushBack(head, 10);
	ListPushBack(head, 20);
	ListPushBack(head, 30);
	ListPushBack(head, 40);
	ListPushBack(head, 50);

	ListPrint(head);

	ListPushFront(head, 1);
	ListPushFront(head, 2);
	ListPushFront(head, 3);
	ListPushFront(head, 4);
	ListPushFront(head, 5);

	ListPrint(head);

	ListPopFront(head);
	ListPopFront(head);

	ListPrint(head);

	ListPopBack(head);
	ListPopBack(head);

	ListPrint(head);

	ListDestroy(&head);
}
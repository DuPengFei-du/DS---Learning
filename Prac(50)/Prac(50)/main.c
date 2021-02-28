#include"List.h"


int main()
{
	Node* head;

	NodeInit(&head);

	NodePushBack(head, 10);
	NodePushBack(head, 20);
	NodePushBack(head, 30);
	NodePushBack(head, 40);
	NodePushBack(head, 50);

	NodePrint(head);

	NodePushFront(head, 1);
	NodePushFront(head, 2);
	NodePushFront(head, 3);
	NodePushFront(head, 4);
	NodePushFront(head, 5);

	NodePrint(head);

	NodePopBack(head);
	NodePopBack(head);

	NodePrint(head);

	NodePopFront(head);
	NodePopFront(head);

	NodePrint(head);

	NodeDestroy(&head);
}
#include"DList.h"


int main()
{
	Node* head;

	NodeInit(&head);

	NodePushBack(head, 1);
	NodePushBack(head, 2);
	NodePushBack(head, 3);
	NodePushBack(head, 4);
	NodePushBack(head, 5);

	NodePrint(head);

	NodePushFront(head, 10);
	NodePushFront(head, 20);
	NodePushFront(head, 30);
	NodePushFront(head, 40);
	NodePushFront(head, 50);

	NodePrint(head);

	NodePopFront(head);
	NodePopFront(head);

	NodePrint(head);

	NodePopBack(head);
	NodePopBack(head);

	NodePrint(head);

	NodeDestroy(&head);

}
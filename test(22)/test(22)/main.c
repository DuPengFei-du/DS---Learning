#include"DList.h"


int main()
{
	Node* head;

	DListNodeInit(&head);

	DListNodePushBack(head, 10);
	DListNodePushBack(head, 20);
	DListNodePushBack(head, 30);
	DListNodePushBack(head, 40);
	DListNodePushBack(head, 50);

	DListNodePrint(head);

	DListNodePushFront(head, 1);
	DListNodePushFront(head, 2);
	DListNodePushFront(head, 3);
	DListNodePushFront(head, 4);
	DListNodePushFront(head, 5);

	DListNodePrint(head);

	DListNodePopBack(head);
	DListNodePopBack(head);

	DListNodePrint(head);

	DListNodePopFront(head);
	DListNodePopFront(head);

	DListNodePrint(head);

	DListNodeDestroy(&head);

}
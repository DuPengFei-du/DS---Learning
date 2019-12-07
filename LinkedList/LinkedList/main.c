#include"LinkedList.h"

void TestLinkList()
{
	Node* head = NULL;

	ListPrint(head);
	head = ListPushFront(head, 1);
	ListPrint(head);
	head = ListPushFront(head, 2);
	ListPrint(head);
	head = ListPushFront(head, 3);
	ListPrint(head);
	head = ListPushFront(head, 4);
	ListPrint(head);

	head=ListPushBack(head, 10);
	ListPrint(head);
	head = ListPushBack(head, 20);
	ListPrint(head);
	head = ListPushBack(head, 30);
	ListPrint(head);

	head = ListPopFront(head);
	ListPrint(head);
	head = ListPopFront(head);
	ListPrint(head);

	head = ListPopBack(head);
	ListPrint(head);
	head = ListPopBack(head);
	ListPrint(head);
}
int main()
{
	TestLinkList();
}
#include"List.h"


int main()
{
	List s;

	NodeInit(&s);

	NodePushBack(&s, 1);
	NodePushBack(&s, 2);
	NodePushBack(&s, 3);
	NodePushBack(&s, 4);
	NodePushBack(&s, 5);

	NodePrint(&s);

	NodePushFront(&s, 10);
	NodePushFront(&s, 20);
	NodePushFront(&s, 30);
	NodePushFront(&s, 40);
	NodePushFront(&s, 50);

	NodePrint(&s);

	NodePopFront(&s);
	NodePopFront(&s);

	NodePrint(&s);

	NodePopBack(&s);
	NodePopBack(&s);

	NodePrint(&s);

	NodeDestroy(&s);
}
#include"List.h"


int main()
{
	List s;

	NodeInit(&s);

	NodePushBack(&s, 10);
	NodePushBack(&s, 20);
	NodePushBack(&s, 30);
	NodePushBack(&s, 40);
	NodePushBack(&s, 50);

	NodePrint(&s);

	NodePushFront(&s, 1);
	NodePushFront(&s, 2);
	NodePushFront(&s, 3);
	NodePushFront(&s, 4);
	NodePushFront(&s, 5);

	NodePrint(&s);

	NodePopFront(&s);
	NodePopFront(&s);

	NodePrint(&s);

	NodePopBack(&s);
	NodePopBack(&s);

	NodePrint(&s);

	NodeDestroy(&s);

}
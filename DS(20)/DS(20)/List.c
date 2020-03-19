#include"List.h"

int main()
{
	List l;

	ListInit(&l);

	ListPushBack(&l, 1);
	ListPushBack(&l, 2);
	ListPushBack(&l, 3);
	ListPushBack(&l, 4);
	ListPushBack(&l, 5);

	ListPrint(&l);


}
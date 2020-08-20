#include"Stack.h"


int main()
{
	Stack ps;

	StackInit(&ps);

	StackPush(&ps, 10);
	StackPush(&ps, 20);
	StackPush(&ps, 30);
	StackPush(&ps, 40);
	StackPush(&ps, 50);

	printf("%d\n", StackTop(&ps));

	printf("%d\n", StackSize(&ps));

	StackPop(&ps);
	StackPop(&ps);
	StackPop(&ps);

	printf("%d\n", StackTop(&ps));

	printf("%d\n", StackSize(&ps));

	StackDestroy(&ps);
}
#include"Stack.h"


int main()
{
	Stack s;

	StackInit(&s);

	StackPush(&s, 10);
	StackPush(&s, 20);
	StackPush(&s, 30);
	StackPush(&s, 40);
	StackPush(&s, 50);

	printf("%d\n", StackTop(&s));
	printf("%d\n", StackEmpty(&s));
	printf("%d\n", StackSize(&s));

	StackPop(&s);
	StackPop(&s);

	printf("%d\n", StackTop(&s));
	printf("%d\n", StackEmpty(&s));
	printf("%d\n", StackSize(&s));

	StackDestroy(&s);
}
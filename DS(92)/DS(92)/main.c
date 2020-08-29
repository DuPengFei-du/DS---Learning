#include"Stack.h"


int main()
{
	Stack s;

	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);

	printf("%d\n", StackSize(&s));
	printf("%d\n", StackEmpty(&s));
	printf("%d\n", StackTop(&s));

	StackPop(&s);
	StackPop(&s);

	printf("%d\n", StackSize(&s));
	printf("%d\n", StackEmpty(&s));
	printf("%d\n", StackTop(&s));

	StackPop(&s);
	StackPop(&s);
	StackPop(&s);

	printf("%d\n", StackSize(&s));
	printf("%d\n", StackEmpty(&s));

	StackDestoy(&s);
}
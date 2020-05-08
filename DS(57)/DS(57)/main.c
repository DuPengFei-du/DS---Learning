#include"Stack.h"

int main()
{
	Stack s;

	StakcInit(&s);

	StakcPush(&s, 1);
	StakcPush(&s, 2);
	StakcPush(&s, 3);
	StakcPush(&s, 4);
	StakcPush(&s, 5);

	printf("%d\n", StakcTop(&s));

	StakcPop(&s);
	StakcPop(&s);

	printf("%d\n", StakcTop(&s));

	StakcPush(&s, 10);
	StakcPush(&s, 20);

	printf("%d\n", StakcTop(&s));

	printf("%d\n", StakcSize(&s));

	StakcDestroy(&s);
}
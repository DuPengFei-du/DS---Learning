#include"Queue.h"


int main()
{
	Queue q;

	NodeInit(&q);

	NodePush(&q, 10);
	NodePush(&q, 20);
	NodePush(&q, 30);
	NodePush(&q, 40);
	NodePush(&q, 50);

	printf("%d\n", NodeSize(&q));

	NodePop(&q);
	NodePop(&q);

	printf("%d\n", NodeSize(&q));

	NodeDestroy(&q);
}
#include"Queue.h"


int main()
{
	Queue q;

	QueueInit(&q);

	QueuePush(&q, 10);
	QueuePush(&q, 10);
	QueuePush(&q, 10);
	QueuePush(&q, 10);
	QueuePush(&q, 10);

	printf("%d\n", QueueEmpty(&q));
	printf("%d\n", QueueSize(&q));

	QueuePop(&q);
	QueuePop(&q);


	printf("%d\n", QueueEmpty(&q));
	printf("%d\n", QueueSize(&q));

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);

	printf("%d\n", QueueEmpty(&q));

	QueueDestroy(&q);
}
#include"Queue.h"


int main()
{
	Queue q;

	QueueInit(&q);

	QueuePush(&q, 10);
	QueuePush(&q, 20);
	QueuePush(&q, 30);
	QueuePush(&q, 40);
	QueuePush(&q, 50);

	printf("%d\n", QueueSize(&q));

	QueuPop(&q);
	QueuPop(&q);

	printf("%d\n", QueueSize(&q));

	QueueDestroy(&q);
}
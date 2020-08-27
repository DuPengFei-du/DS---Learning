#include"Queue.h"


int main()
{
	Queue q;

	QueueInit(&q);

	QueuePush(&q, 10);
	QueuePush(&q, 20);
	QueuePush(&q, 30);

	printf("%d\n", QueueSize(&q));

	QueueDestroy(&q);

}
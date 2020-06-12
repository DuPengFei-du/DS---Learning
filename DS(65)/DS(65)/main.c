#include"Queue.h"


int main()
{
	Queue q;

	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	printf("size = %d\n", QueueSize(&q));

	printf("front = %d\n", QueueFront(&q));

	printf("rear = %d\n", QueueBack(&q));

	QueuePop(&q);
	QueuePop(&q);

	printf("size = %d\n", QueueSize(&q));

	printf("front = %d\n", QueueFront(&q));

	printf("rear = %d\n", QueueBack(&q));

	QueueDestroy(&q);

}

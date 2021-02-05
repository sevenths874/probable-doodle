#include"Queue.h"

void Test()
{
	Queue Q;
	Queue* q = &Q;

	QueueInit(q);
	QueuePush(q, 1);
	QueuePush(q, 2);
	QueuePush(q, 3);
	QueuePush(q, 4);
	QueuePush(q, 5);
	QueuePush(q, 6);
	while (!QueueEmpty(q))
	{
		printf("%d ", QueueFront(q));
		QueuePop(q);
	}
	printf("\n");
	QueueDestroy(q);
}

int main()
{
	Test();

	system("pause");
	return 0;
}
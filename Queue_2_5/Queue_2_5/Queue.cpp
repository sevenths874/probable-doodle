#include"Queue.h""

// 初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

// 队尾入队列
void QueuePush(Queue* q, QDataType x)
{
	assert(q);
	QListNode* newnode = (QListNode*)malloc(sizeof(QListNode));
	newnode->data = x;
	newnode->next = NULL;
	if (q->rear == NULL)
		q->front = q->rear = newnode;
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
}

// 队头出队列
void QueuePop(Queue* q)
{
	assert(q);
	if (q->front == NULL)    //没有结点
		return;
	if (q->front->next == NULL)    //只有一个结点
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		QListNode* tmp = q->front;
		q->front = q->front->next;
		free(tmp);
		tmp = NULL;
	}
}

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	if (q->front == NULL)
		return -1;
	return q->front->data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	if (q->rear == NULL)
		return -1;
	return q->rear->data;
}

// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	assert(q);
	if (q->front == NULL)
		return 0;
	QListNode* cur = q->front;
	int len = 0;
	while (cur)
	{
		++len;
		cur = cur->next;
	}
	return len;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue*q)
{
	assert(q);
	return (q->front == NULL ? 1 : 0);
}

// 销毁队列
void QueueDestroy(Queue*q)
{
	assert(q);
	if (q->front == NULL)
		return;
	QListNode* cur = q->front;
	QListNode* tmp = NULL;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	cur=tmp = NULL;
	q->front = q->rear = NULL;
}
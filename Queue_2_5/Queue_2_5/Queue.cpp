#include"Queue.h""

// ��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

// ��β�����
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

// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	if (q->front == NULL)    //û�н��
		return;
	if (q->front->next == NULL)    //ֻ��һ�����
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

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	if (q->front == NULL)
		return -1;
	return q->front->data;
}

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);
	if (q->rear == NULL)
		return -1;
	return q->rear->data;
}

// ��ȡ��������ЧԪ�ظ���
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue*q)
{
	assert(q);
	return (q->front == NULL ? 1 : 0);
}

// ���ٶ���
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
#include"SqList.h"

//��ʼ��
void SqListInit(SqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//����
void SqListDestroy(SqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//���˳���ռ�/����
void SqListCheck(SqList* ps)
{
	if (ps->size >= ps->capacity)
	{
		size_t newcapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		SLDataType* p = NULL;
		p = (SLDataType*)realloc(ps->a, newcapacity*sizeof(SLDataType));  //����
		if (p != NULL)
			ps->a = p;
		ps->capacity = newcapacity;
	}
}

//���
void SqListPrint(SqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; ++i)
		printf("%d ", ps->a[i]);
	printf("\n");
}

//β��
void SqListPushBack(SqList* ps, SLDataType x)
{
	assert(ps);
	SqListCheck(ps);   //���ռ�
	ps->a[ps->size++] = x;   //����
}

//βɾ
void SqListPopBack(SqList* ps)
{
	assert(ps && ps->size);
	//ps->a[ps->size-1] = 0;
	ps->size--;
}

//ͷ��
void SqListPushFront(SqList* ps, SLDataType x)
{
	assert(ps);
	SqListCheck(ps);     //���ռ�
	for (int i = ps->size - 1; i >= 0; --i)    //Ų������  --iʱ������i������Ϊint
		ps->a[i + 1] = ps->a[i];
	ps->a[0] = x;     //����
	ps->size++;
}

//ͷɾ
void SqListPopFront(SqList* ps)
{
	assert(ps && ps->size);
	for (size_t i = 0; i < ps->size - 1; ++i)
		ps->a[i] = ps->a[i + 1];
	ps->size--;
}

//����
int SqListFind(SqList* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
			return i;
	}
	return -1;
}

//��posλ�ò���
void SqListInsert(SqList* ps, int pos, SLDataType x)   //int pos  pos��ֵ��0��(size-1)
{
	assert(ps);
	SqListCheck(ps);
	for (int i = ps->size - 1; i >= pos; --i)
		ps->a[i+1] = ps->a[i];     //��Ų����
	ps->a[pos] = x;
	ps->size++;
}

//ɾ��posλ�õ�ֵ
void SqListErase(SqList* ps, size_t pos)
{
	assert(ps);
	for (size_t i = pos; i < ps->size - 1; ++i)
		ps->a[i] = ps->a[i+1];    //ǰ��
	ps->size--;
}

void SqListRemove(SqList* ps, SLDataType x)
{
	assert(ps);
	int pos = SqListFind(ps, x);
	if(pos >= 0)
		SqListErase(ps, pos);
}







#include"SqList.h"

//初始化
void SqListInit(SqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//销毁
void SqListDestroy(SqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//检查顺序表空间/扩容
void SqListCheck(SqList* ps)
{
	if (ps->size >= ps->capacity)
	{
		size_t newcapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		SLDataType* p = NULL;
		p = (SLDataType*)realloc(ps->a, newcapacity*sizeof(SLDataType));  //扩容
		if (p != NULL)
			ps->a = p;
		ps->capacity = newcapacity;
	}
}

//输出
void SqListPrint(SqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; ++i)
		printf("%d ", ps->a[i]);
	printf("\n");
}

//尾插
void SqListPushBack(SqList* ps, SLDataType x)
{
	assert(ps);
	SqListCheck(ps);   //检查空间
	ps->a[ps->size++] = x;   //插入
}

//尾删
void SqListPopBack(SqList* ps)
{
	assert(ps && ps->size);
	//ps->a[ps->size-1] = 0;
	ps->size--;
}

//头插
void SqListPushFront(SqList* ps, SLDataType x)
{
	assert(ps);
	SqListCheck(ps);     //检查空间
	for (int i = ps->size - 1; i >= 0; --i)    //挪动数据  --i时，定义i的类型为int
		ps->a[i + 1] = ps->a[i];
	ps->a[0] = x;     //插入
	ps->size++;
}

//头删
void SqListPopFront(SqList* ps)
{
	assert(ps && ps->size);
	for (size_t i = 0; i < ps->size - 1; ++i)
		ps->a[i] = ps->a[i + 1];
	ps->size--;
}

//查找
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

//在pos位置插入
void SqListInsert(SqList* ps, int pos, SLDataType x)   //int pos  pos的值域：0～(size-1)
{
	assert(ps);
	SqListCheck(ps);
	for (int i = ps->size - 1; i >= pos; --i)
		ps->a[i+1] = ps->a[i];     //后挪数据
	ps->a[pos] = x;
	ps->size++;
}

//删除pos位置的值
void SqListErase(SqList* ps, size_t pos)
{
	assert(ps);
	for (size_t i = pos; i < ps->size - 1; ++i)
		ps->a[i] = ps->a[i+1];    //前移
	ps->size--;
}

void SqListRemove(SqList* ps, SLDataType x)
{
	assert(ps);
	int pos = SqListFind(ps, x);
	if(pos >= 0)
		SqListErase(ps, pos);
}







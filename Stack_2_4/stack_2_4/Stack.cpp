#include"Stack.h"

// ��ʼ��ջ
void StackInit(Stack* ps)
{
	ps->arr = NULL;
	ps->top = 0;    //ָ��ջ������һ��λ��
	ps->capacity = 0;
}

// ��ջ
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		ps->arr = (STDataType*)realloc(ps->arr, newcapacity*sizeof(STDataType));
		ps->capacity = newcapacity;
	}
	ps->arr[ps->top++] = data;
}

// ��ջ
void StackPop(Stack* ps)
{
	assert(ps && ps->top);
		ps->arr[--ps->top]=0;
}

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	if (ps->top > 0)
		return ps->arr[ps->top-1];
}

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0 ? 1 : 0;

}

// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
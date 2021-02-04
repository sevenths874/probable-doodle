#include"Stack.h"

// 初始化栈
void StackInit(Stack* ps)
{
	ps->arr = NULL;
	ps->top = 0;    //指向栈顶的下一个位置
	ps->capacity = 0;
}

// 入栈
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

// 出栈
void StackPop(Stack* ps)
{
	assert(ps && ps->top);
		ps->arr[--ps->top]=0;
}

// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	if (ps->top > 0)
		return ps->arr[ps->top-1];
}

// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0 ? 1 : 0;

}

// 销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
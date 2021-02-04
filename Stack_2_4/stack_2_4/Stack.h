#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;
	int capacity;
}Stack;

// ��ʼ��ջ
void StackInit(Stack* ps);

// ��ջ
void StackPush(Stack* ps, STDataType data);

// ��ջ
void StackPop(Stack* ps);

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps);

// ����ջ
void StackDestroy(Stack* ps);
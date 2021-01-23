#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;
typedef struct S
{
	SLDataType* a;
	size_t size;
	size_t capacity;
}SqList;

void SqListInit(SqList* ps);    //初始化
void SqListDestroy(SqList* ps);	   //销毁	

void SqListPrint(SqList* ps);     //打印
void SqListCheck(SqList* ps);     //检查顺序表空间/扩容

void SqListPushBack(SqList* ps, SLDataType x);   //顺序表尾插
void SqListPopBack(SqList* ps);                  //顺序表尾删
void SqListPushFront(SqList* ps, SLDataType x);  //顺序表前插
void SqListPopFront(SqList* ps);                 //顺序表前删
int  SqListFind(SqList* ps, SLDataType x);        //顺序表查找
void SqListInsert(SqList* ps, int pos, SLDataType x);   //顺序表在pos位置插入x
void SqListErase(SqList* ps, size_t pos);    //顺序表删除在pos位置的值
void SqListRemove(SqList* ps, SLDataType x);   //顺序表删除值为x的元素










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

void SqListInit(SqList* ps);    //��ʼ��
void SqListDestroy(SqList* ps);	   //����	

void SqListPrint(SqList* ps);     //��ӡ
void SqListCheck(SqList* ps);     //���˳���ռ�/����

void SqListPushBack(SqList* ps, SLDataType x);   //˳���β��
void SqListPopBack(SqList* ps);                  //˳���βɾ
void SqListPushFront(SqList* ps, SLDataType x);  //˳���ǰ��
void SqListPopFront(SqList* ps);                 //˳���ǰɾ
int  SqListFind(SqList* ps, SLDataType x);        //˳������
void SqListInsert(SqList* ps, int pos, SLDataType x);   //˳�����posλ�ò���x
void SqListErase(SqList* ps, size_t pos);    //˳���ɾ����posλ�õ�ֵ
void SqListRemove(SqList* ps, SLDataType x);   //˳���ɾ��ֵΪx��Ԫ��










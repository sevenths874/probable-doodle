#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

//不带头结点的单链表
typedef struct SListNode    
{
	SLDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* L);   //打印链表
void SListPushBack(SListNode** pL, SLDataType x);   //链表尾插
void SListPushFront(SListNode** pL, SLDataType x);  //链表头插
void SListPopBack(SListNode** pL);     //链表尾删
void SListPopFront(SListNode** pL);    //链表头删
SListNode* SListFind(SListNode* L,SLDataType x);    //链表查找
void SListInsertAfter(SListNode* pos, SLDataType x);   //链表在pos位置之后插入x
void SListEraseAfter(SListNode* pos);    //链表删除pos位置之后的值



void PushBack(SListNode* L, SLDataType x);   //链表尾插




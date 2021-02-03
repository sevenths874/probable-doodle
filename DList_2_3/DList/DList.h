#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int DLDataType;
typedef struct DListNode
{
	DLDataType data;
	DListNode* next;
	DListNode* prev;
}ListNode;


// 创建返回链表的头结点
ListNode* ListCreate();

// 双向链表销毁
void DListDestory(ListNode* &phead);

// 双向链表打印
void DListPrint(ListNode* phead);

// 双向链表尾插
void DListPushBack(ListNode* phead, DLDataType x);

// 双向链表尾删
void DListPopBack(ListNode* phead);

// 双向链表头插
void DListPushFront(ListNode* phead, DLDataType x);

// 双向链表头删
void DListPopFront(ListNode* phead);

// 双向链表查找
ListNode* DListFind(ListNode* phead, DLDataType x);

// 双向链表在pos的前面进行插入
void DListInsert(ListNode* pos, DLDataType x);

// 双向链表删除pos位置的节点
void DListErase(ListNode* &pos);
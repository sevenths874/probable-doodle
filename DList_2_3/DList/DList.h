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


// �������������ͷ���
ListNode* ListCreate();

// ˫����������
void DListDestory(ListNode* &phead);

// ˫�������ӡ
void DListPrint(ListNode* phead);

// ˫������β��
void DListPushBack(ListNode* phead, DLDataType x);

// ˫������βɾ
void DListPopBack(ListNode* phead);

// ˫������ͷ��
void DListPushFront(ListNode* phead, DLDataType x);

// ˫������ͷɾ
void DListPopFront(ListNode* phead);

// ˫���������
ListNode* DListFind(ListNode* phead, DLDataType x);

// ˫��������pos��ǰ����в���
void DListInsert(ListNode* pos, DLDataType x);

// ˫������ɾ��posλ�õĽڵ�
void DListErase(ListNode* &pos);
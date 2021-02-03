#include"DList.h"

// �������������ͷ���
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->data = 0;
	head->next = head;
	head->prev = head;
	return head;
}

// ˫�������ӡ
void DListPrint(ListNode* phead)
{
	if (phead == NULL)
		return;
	printf("head<=>");
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// ˫������β��
void DListPushBack(ListNode* phead, DLDataType x)
{
	ListNode* tail = phead->prev;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;

	newnode->next = phead;
	phead->prev = newnode;
	tail->next = newnode;
	newnode->prev = tail;
}

// ˫������βɾ
void DListPopBack(ListNode* phead)
{
	if (phead->next == phead)
		return;
	ListNode* tail = phead->prev;
	ListNode* newtail = tail->prev;  //ԭβ���ǰ��
	newtail->next = phead;
	phead->prev = newtail;
	free(tail);
	tail = NULL;
}

// ˫������ͷ��
void DListPushFront(ListNode* phead, DLDataType x)
{
	ListNode* next = phead->next;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;

	newnode->next = next;
	next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
}

// ˫������ͷɾ
void DListPopFront(ListNode* phead)
{
	if (phead->next == phead)
		return;    
	ListNode* first = phead->next;
	ListNode* next = first->next;
	phead->next = next;
	next->prev = phead;
	free(first);
	first = NULL;
}

// ˫����������
void DListDestory(ListNode* &phead)
{
	ListNode* cur = phead->next;
	ListNode* tmp = NULL;
	while (cur != phead)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	cur = tmp = NULL;
	free(phead);
	phead = NULL;
}

// ˫���������
ListNode* DListFind(ListNode* phead, DLDataType x)
{
	if (phead == NULL)
	{
		printf("NULL\n");
		return NULL;
	}
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

// ˫��������pos��ǰ����в���
void DListInsert(ListNode* pos, DLDataType x)
{
	if (pos == NULL)
		return;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	ListNode* prev = pos->prev;
	newnode->data = x;
	newnode->next = pos;
	pos->prev = newnode;
	prev->next = newnode;
	newnode->prev = prev;
}

// ˫������ɾ��posλ�õĽڵ�
void DListErase(ListNode* &pos)
{
	if (pos == NULL)
	{
		printf("Error\n");
		return;
	}
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}
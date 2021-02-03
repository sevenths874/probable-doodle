#include"DList.h"

// 创建返回链表的头结点
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->data = 0;
	head->next = head;
	head->prev = head;
	return head;
}

// 双向链表打印
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

// 双向链表尾插
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

// 双向链表尾删
void DListPopBack(ListNode* phead)
{
	if (phead->next == phead)
		return;
	ListNode* tail = phead->prev;
	ListNode* newtail = tail->prev;  //原尾结点前驱
	newtail->next = phead;
	phead->prev = newtail;
	free(tail);
	tail = NULL;
}

// 双向链表头插
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

// 双向链表头删
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

// 双向链表销毁
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

// 双向链表查找
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

// 双向链表在pos的前面进行插入
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

// 双向链表删除pos位置的节点
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
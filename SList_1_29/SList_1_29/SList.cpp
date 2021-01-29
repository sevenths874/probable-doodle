#include"SList.h"

//打印
void SListPrint(SListNode* L)   
{
	assert(L);   //判空
	SListNode* cur = L;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//尾插
void SListPushBack(SListNode** pL, SLDataType x)
{
	if (*pL == NULL)    //链表为空
	{
		*pL = (SListNode*)malloc(sizeof(SListNode));
		(*pL)->data = x;
		(*pL)->next = NULL;
	}
	else
	{
		SListNode* tail = *pL;	
		while (tail->next != NULL)   //找到尾结点
			tail = tail->next;
		SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
		newnode->data = x;
		newnode->next = NULL;
		tail->next = newnode;
	}
}

void PushBack(SListNode* L, SLDataType x)
{

	SListNode* tail = L;
	while (tail->next != NULL)   //找到尾结点
		tail = tail->next;
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;
	tail->next = newnode;
}


//头插
void SListPushFront(SListNode** pL, SLDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = *pL;
	*pL = newnode;
}

//尾删
void SListPopBack(SListNode** pL)
{
	if ((*pL) == NULL)
		return;
	else if ((*pL)->next == NULL)
	{
		free(*pL);
		*pL = NULL;
	}
	else
	{
		SListNode* prev = NULL;   //尾结点前驱
		SListNode* tail = *pL;    //尾结点
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
	}
}

//头删
void SListPopFront(SListNode** pL)
{
	SListNode* head = *pL;   //头结点
	*pL = head->next;
	free(head);
}

//查找
SListNode* SListFind(SListNode* L, SLDataType x)
{
	if (L == NULL)
		return NULL;
	SListNode* cur = L;
	while (cur != NULL)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
}

//在pos位置后插入x
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
	if (pos->next == NULL)
		return;
	SListNode* tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
}



















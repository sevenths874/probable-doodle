#include"SList.h"

//��ӡ
void SListPrint(SListNode* L)   
{
	assert(L);   //�п�
	SListNode* cur = L;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//β��
void SListPushBack(SListNode** pL, SLDataType x)
{
	if (*pL == NULL)    //����Ϊ��
	{
		*pL = (SListNode*)malloc(sizeof(SListNode));
		(*pL)->data = x;
		(*pL)->next = NULL;
	}
	else
	{
		SListNode* tail = *pL;	
		while (tail->next != NULL)   //�ҵ�β���
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
	while (tail->next != NULL)   //�ҵ�β���
		tail = tail->next;
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;
	tail->next = newnode;
}


//ͷ��
void SListPushFront(SListNode** pL, SLDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = *pL;
	*pL = newnode;
}

//βɾ
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
		SListNode* prev = NULL;   //β���ǰ��
		SListNode* tail = *pL;    //β���
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
	}
}

//ͷɾ
void SListPopFront(SListNode** pL)
{
	SListNode* head = *pL;   //ͷ���
	*pL = head->next;
	free(head);
}

//����
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

//��posλ�ú����x
void SListInsertAfter(SListNode* pos, SLDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = pos->next;
	pos->next = newnode;
}

//ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos)
{
	if (pos->next == NULL)
		return;
	SListNode* tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
}



















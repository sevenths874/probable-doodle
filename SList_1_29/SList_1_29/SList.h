#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

//����ͷ���ĵ�����
typedef struct SListNode    
{
	SLDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* L);   //��ӡ����
void SListPushBack(SListNode** pL, SLDataType x);   //����β��
void SListPushFront(SListNode** pL, SLDataType x);  //����ͷ��
void SListPopBack(SListNode** pL);     //����βɾ
void SListPopFront(SListNode** pL);    //����ͷɾ
SListNode* SListFind(SListNode* L,SLDataType x);    //�������
void SListInsertAfter(SListNode* pos, SLDataType x);   //������posλ��֮�����x
void SListEraseAfter(SListNode* pos);    //����ɾ��posλ��֮���ֵ



void PushBack(SListNode* L, SLDataType x);   //����β��




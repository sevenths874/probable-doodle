#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;
typedef struct QListNode
{
	QDataType data;
	QListNode* next;
}QListNode;

typedef struct Queue
{
	QListNode* front;
	QListNode* rear;
}Queue;

// ��ʼ������
void QueueInit(Queue* q);

// ��β�����
void QueuePush(Queue* q, QDataType x);

// ��ͷ������
void QueuePop(Queue* q);

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q);

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q);

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue*q);

// ���ٶ���
void QueueDestroy(Queue*q);
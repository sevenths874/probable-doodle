#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;
	int size;   //�ѵ�ǰ��С
	int capacity;   //������
}Heap;

//�ѵ����µ���
void HeapAdjustDown(HPDataType* arr, int size, int root);

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* arr, int size);

// �ѵ�����
void HeapDestory(Heap* hp); 

//�ѵ����ϵ���
void HeapAdjustUp(Heap* hp, int child);

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);

// �ѵ����ݸ���
int HeapSize(Heap* hp);

// �ѵ��п�
int HeapEmpty(Heap* hp); 

//������
void HeapSort(Heap* hp, HPDataType* arr, int size);

//��ӡ��
void HeapPrint(Heap* hp);
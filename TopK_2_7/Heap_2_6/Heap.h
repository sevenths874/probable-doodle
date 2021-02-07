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

//��ӡ��
void HeapPrint(Heap* hp);

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

//�ں�������(N��)��ѡ��ǰ(����)K�������⣺
//����1����N�����ݽ�������ѡ��ǰK����ʱ�临�Ӷ�O(N+N*logN)���ռ临�Ӷ�O(1)�� 

//����2����N�����ݵĴ�ѣ�ɾ���Ѷ�Ԫ�أ�Ȼ�����(K-1)�����µ�����
//ʱ�临�Ӷ�O[N+(K-1)*logN])����O(N)��
//�ռ临�Ӷ�O(N)��

//����3��ѡN�������е�ǰK����С�ѣ���ʣ��(N-K)������������Ѷ�Ԫ�رȽϡ�
//����ǰʣ������С�ڶԶ�Ԫ����������
//����ǰʣ�����ݴ��ڶѶ�Ԫ�أ����õ�ǰ�����滻�Ѷ�Ԫ�أ��������µ�����
//ֱ��������ʣ�����ݣ���ʱ����С���е�K�����ݼ�Ϊ����K����
//���ʱ�临�Ӷ�O[K]���ʱ�临�Ӷ�O[K+(N-K)*logK]����O(N)��
//�ռ临�Ӷ�O(K)������3Ϊ���ŷ�����
void TopK(Heap* hp, HPDataType* arr, int n, int k);
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;
	int size;   //堆当前大小
	int capacity;   //堆容量
}Heap;

//堆的向下调整
void HeapAdjustDown(HPDataType* arr, int size, int root);

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* arr, int size);

// 堆的销毁
void HeapDestory(Heap* hp); 

//堆的向上调整
void HeapAdjustUp(Heap* hp, int child);

// 堆的插入
void HeapPush(Heap* hp, HPDataType x);

// 堆的删除
void HeapPop(Heap* hp);

// 取堆顶的数据
HPDataType HeapTop(Heap* hp);

// 堆的数据个数
int HeapSize(Heap* hp);

// 堆的判空
int HeapEmpty(Heap* hp); 

//堆排序
void HeapSort(Heap* hp, HPDataType* arr, int size);

//打印堆
void HeapPrint(Heap* hp);
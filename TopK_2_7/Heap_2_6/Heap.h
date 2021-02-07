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

//打印堆
void HeapPrint(Heap* hp);

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

//在海量数据(N个)中选出前(最大的)K个的问题：
//方案1：对N个数据进行排序，选出前K个。时间复杂度O(N+N*logN)，空间复杂度O(1)。 

//方案2：建N个数据的大堆，删除堆顶元素，然后进行(K-1)次向下调整。
//时间复杂度O[N+(K-1)*logN])，即O(N)。
//空间复杂度O(N)。

//方案3：选N个数据中的前K个建小堆，将剩余(N-K)个数据依次与堆顶元素比较。
//若当前剩余数据小于对顶元素则舍弃；
//若当前剩余数据大于堆顶元素，则用当前数据替换堆顶元素，进行向下调整；
//直到遍历完剩余数据，此时留在小堆中的K个数据即为最大的K个。
//最好时间复杂度O[K]，最坏时间复杂度O[K+(N-K)*logK]，即O(N)。
//空间复杂度O(K)。方案3为最优方案。
void TopK(Heap* hp, HPDataType* arr, int n, int k);
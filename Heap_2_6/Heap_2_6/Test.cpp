#include"Heap.h"

void Test()
{
	HPDataType arr[10] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap heap;
	Heap* hp = &heap;
	
	HeapCreate(hp, arr, 10);
	HeapPrint(hp);

	HeapPush(hp, 11);
	HeapPrint(hp);

	HeapPop(hp);
	HeapPrint(hp);
	HeapPop(hp);
	HeapPrint(hp);

	printf("\n");
	HeapSort(hp, arr, hp->size);
	HeapPrint(hp);

}

int main()
{
	Test();

	system("pause");
	return 0;
}
#include"SList.h"

void Test()
{
	SListNode* L = NULL;    //≥ı ºªØ
	SListPushBack(&L, 1);
	SListPushBack(&L, 2);
	SListPushBack(&L, 3);
	SListPushBack(&L, 4);
	SListPrint(L);

	PushBack(L, 5);
	PushBack(L, 6);
	SListPrint(L);

	SListPushFront(&L, 0);
	SListPushFront(&L, -1);
	SListPrint(L);

	SListPopBack(&L);
	SListPopBack(&L);
	SListPrint(L);

	SListPopFront(&L);
	SListPopFront(&L);
	SListPrint(L);

	SListNode* pos = SListFind(L,1);
	printf("pos=0x%p\n", pos);

	SListInsertAfter(pos,9);
	SListPrint(L);

	pos = SListFind(L, 3);
	SListEraseAfter(pos);
	SListPrint(L);
}

int main()
{
	Test();

	system("pause");
	return 0;
}
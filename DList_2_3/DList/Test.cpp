#include"DList.h"

void Test()
{
	ListNode* phead = ListCreate();
	ListNode* pos = NULL;
	DListPushBack(phead, 1);
	DListPushBack(phead, 2);
	DListPushBack(phead, 3);
	DListPushBack(phead, 4);
	DListPushBack(phead, 5);
	DListPushBack(phead, 6);
	DListPrint(phead);

	DListPopBack(phead);
	DListPopBack(phead);
	DListPrint(phead);

	DListPushFront(phead, 9);
	DListPushFront(phead, 10);
	DListPrint(phead);

	DListPopFront(phead);
	DListPrint(phead);

	//DListDestory(phead);
	//DListPrint(phead);

	pos = DListFind(phead, 9);
	printf("ret=%p\n", pos);

	DListInsert(pos, 88);
	DListPrint(phead);

	pos = DListFind(phead, 99);
	DListErase(pos);
	DListPrint(phead);

}

int main()
{
	Test();
	system("pause");
	return 0;
}


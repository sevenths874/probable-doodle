#include"SqList.h"

void Test()
{
	SqList s;
	SqList* ps = &s;
	SqListInit(ps);

	SqListPushBack(ps, 1);
	SqListPushBack(ps, 2);
	SqListPushBack(ps, 3);
	SqListPushBack(ps, 4);
	SqListPushBack(ps, 5);
	SqListPrint(ps);

	SqListPopBack(ps);
	SqListPrint(ps);

	SqListPushFront(ps, 0);
	SqListPrint(ps);

	SqListPopFront(ps);
	SqListPrint(ps);

	int tmp = SqListFind(ps, 2);
	printf("%d\n", tmp);

	SqListInsert(ps, 0, 9);
	SqListPrint(ps);

	SqListErase(ps, 2);
	SqListPrint(ps);

	SqListRemove(ps, 9);
	SqListPrint(ps);
}

int main()
{
	Test();
	system("pause");
	return 0;
}






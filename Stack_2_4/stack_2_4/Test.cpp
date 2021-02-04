#include"Stack.h"

void Test()
{
	Stack S;
	Stack* ps = &S;
	StackInit(ps);
	StackPush(ps, 1);
	StackPush(ps, 2);
	StackPush(ps, 3);
	StackPush(ps, 4);
	StackPush(ps, 5);
	StackPush(ps, 6);
	StackPush(ps, 7);
	StackPush(ps, 8);

	printf("Size=%d\n", StackSize(ps));
	while (!StackEmpty(ps))   //Èç¹ûÕ»²»¿Õ
	{
		printf("%d ", StackTop(ps));
		StackPop(ps);
	}
	StackDestroy(ps);
}

int main()
{
	Test();

	system("pause");
	return 0;
}
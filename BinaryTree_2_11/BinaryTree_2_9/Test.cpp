#include"BinaryTree.h"

void Test()
{
	//BTDataType arr[100] = "ABC##DE#G##F###";
	//BTDataType arr[100] = "A#B##";
	BTDataType arr[100] = "ABC####";

	int i = 0;
	BTNode* root = BinaryTreeCreate(arr, &i);
	/*BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");*/

	/*printf("0x%p\n", BinaryTreeFind(root, 'B'));*/

	BinaryTreeLevelOrder(root);
	BinaryTreeComplete(root);

	//BinaryTreeDestory(root);

}

int main()
{
	Test();

	system("pause");
	return 0;
}
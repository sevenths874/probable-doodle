#include"BinaryTree.h"
//递归实现

// 通过前序遍历的数组"ABC##DE#G##F###"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* arr,int* pi)
{
	BTDataType tmp = arr[(*pi)++];
	if (tmp == '#')    //如果arr[i]为空，则返回空
		return NULL;
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));  //创建根
		root->data = tmp;
		root->left = BinaryTreeCreate(arr,pi);   //递归创建左子树
		root->right = BinaryTreeCreate(arr, pi);  //递归创建右子树
		return root;
	}
}

// 二叉树销毁：采用后序遍历的方式
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
	root = NULL;
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)     
		return 0;
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	//树的第k层结点个数==左子树的第(k-1)层结点个数+右子树的第(k-1)层结点个数
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	//如果当前根结点为所找结点，则返回root
	if (root->data == x)
		return root;

	//否则到左子树去查找，如果找到了，则返回ret
	BTNode* ret = BinaryTreeFind(root->left, x);
	if (ret)
		return ret;

	//如果左子树也没找到，就到右子树找，如果找到了就返回ret
	ret = BinaryTreeFind(root->right, x);
	if(ret)
		return ret;
	
	//如果都找不到，就返回空
	return NULL;
}

// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}

// 层序遍历：借助队列实现
void BinaryTreeLevelOrder(BTNode* root)
{
	//初始化队列
	int size = 0,capacity = 0;
	int front = 0, rear = 0;
	BTNode** queue = NULL;
	capacity = (capacity == 0 ? 8 : 2 * capacity);
	queue = (BTNode**)realloc(queue, capacity*sizeof(BTNode*));
	
	//层序遍历
	if (root != NULL)
	{
		queue[rear++] = root;
		size++;
	}
	while (size > 0)     //栈不空时
	{
		BTNode* tmp = queue[front++];   //队头出队
		size--;
		printf("%c ", tmp->data);  //访问队头结点

		if (size == capacity)
		{
			capacity = (capacity == 0 ? 8 : 2 * capacity);
			queue = (BTNode**)realloc(queue, capacity*sizeof(BTNode*));
		}

		if (tmp->left != NULL)    //队头结点的左孩子不为空，则入队
		{
			queue[rear++] = tmp->left;
			size++;
		}
		if (tmp->right != NULL)   //队头结点的右孩子不为空，则入队
		{
			queue[rear++] = tmp->right;
			size++;
		}
	}
	printf("\n");
	free(queue);
	queue = NULL;
}

// 判断二叉树是否是完全二叉树：层序遍历
void BinaryTreeComplete(BTNode* root)
{
	//初始化队列
	int size = 0, capacity = 0;
	int front = 0, rear = 0;
	BTNode** queue = NULL;
	capacity = (capacity == 0 ? 8 : 2 * capacity);
	queue = (BTNode**)realloc(queue, capacity*sizeof(BTNode*));

	//层序遍历
	if (root != NULL)
	{
		queue[rear++] = root;
		size++;
	}
	while (size > 0)     //栈不空时
	{
		//如果出队遇到NULL时，就结束出队
		if (queue[front] == NULL)
			break;

		BTNode* tmp = queue[front++];   //队头出队
		size--;
		printf("%c ", tmp->data);  //访问队头结点

		if (size == capacity)
		{
			capacity = (capacity == 0 ? 8 : 2 * capacity);
			queue = (BTNode**)realloc(queue, capacity*sizeof(BTNode*));
		}
		queue[rear++] = tmp->left;
		size++;
		queue[rear++] = tmp->right;
		size++;
	}
	printf("\n");

	//如果出队遇到NULL时，就看此时队列中有无非NULL值，层序遍历完全二叉树是一个连续的序列
	//如果存在非NULL值，就不是完全二叉树
	//如果全是NULL，就是完全二叉树
	while (size > 0)     
	{
		//出队
		BTNode* tmp = queue[front++];   //队头出队
		size--;
		if (tmp != NULL)
		{
			printf("不是完全二叉树\n");
			return;
		}
	}
	printf("是完全二叉树\n");
	free(queue);
	queue = NULL;
}
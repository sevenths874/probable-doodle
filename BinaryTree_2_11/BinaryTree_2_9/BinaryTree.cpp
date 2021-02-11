#include"BinaryTree.h"
//�ݹ�ʵ��

// ͨ��ǰ�����������"ABC##DE#G##F###"����������
BTNode* BinaryTreeCreate(BTDataType* arr,int* pi)
{
	BTDataType tmp = arr[(*pi)++];
	if (tmp == '#')    //���arr[i]Ϊ�գ��򷵻ؿ�
		return NULL;
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));  //������
		root->data = tmp;
		root->left = BinaryTreeCreate(arr,pi);   //�ݹ鴴��������
		root->right = BinaryTreeCreate(arr, pi);  //�ݹ鴴��������
		return root;
	}
}

// ���������٣����ú�������ķ�ʽ
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
	root = NULL;
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)     
		return 0;
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	//���ĵ�k�������==�������ĵ�(k-1)�������+�������ĵ�(k-1)�������
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	//�����ǰ�����Ϊ���ҽ�㣬�򷵻�root
	if (root->data == x)
		return root;

	//����������ȥ���ң�����ҵ��ˣ��򷵻�ret
	BTNode* ret = BinaryTreeFind(root->left, x);
	if (ret)
		return ret;

	//���������Ҳû�ҵ����͵��������ң�����ҵ��˾ͷ���ret
	ret = BinaryTreeFind(root->right, x);
	if(ret)
		return ret;
	
	//������Ҳ������ͷ��ؿ�
	return NULL;
}

// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}

// �����������������ʵ��
void BinaryTreeLevelOrder(BTNode* root)
{
	//��ʼ������
	int size = 0,capacity = 0;
	int front = 0, rear = 0;
	BTNode** queue = NULL;
	capacity = (capacity == 0 ? 8 : 2 * capacity);
	queue = (BTNode**)realloc(queue, capacity*sizeof(BTNode*));
	
	//�������
	if (root != NULL)
	{
		queue[rear++] = root;
		size++;
	}
	while (size > 0)     //ջ����ʱ
	{
		BTNode* tmp = queue[front++];   //��ͷ����
		size--;
		printf("%c ", tmp->data);  //���ʶ�ͷ���

		if (size == capacity)
		{
			capacity = (capacity == 0 ? 8 : 2 * capacity);
			queue = (BTNode**)realloc(queue, capacity*sizeof(BTNode*));
		}

		if (tmp->left != NULL)    //��ͷ�������Ӳ�Ϊ�գ������
		{
			queue[rear++] = tmp->left;
			size++;
		}
		if (tmp->right != NULL)   //��ͷ�����Һ��Ӳ�Ϊ�գ������
		{
			queue[rear++] = tmp->right;
			size++;
		}
	}
	printf("\n");
	free(queue);
	queue = NULL;
}

// �ж϶������Ƿ�����ȫ���������������
void BinaryTreeComplete(BTNode* root)
{
	//��ʼ������
	int size = 0, capacity = 0;
	int front = 0, rear = 0;
	BTNode** queue = NULL;
	capacity = (capacity == 0 ? 8 : 2 * capacity);
	queue = (BTNode**)realloc(queue, capacity*sizeof(BTNode*));

	//�������
	if (root != NULL)
	{
		queue[rear++] = root;
		size++;
	}
	while (size > 0)     //ջ����ʱ
	{
		//�����������NULLʱ���ͽ�������
		if (queue[front] == NULL)
			break;

		BTNode* tmp = queue[front++];   //��ͷ����
		size--;
		printf("%c ", tmp->data);  //���ʶ�ͷ���

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

	//�����������NULLʱ���Ϳ���ʱ���������޷�NULLֵ�����������ȫ��������һ������������
	//������ڷ�NULLֵ���Ͳ�����ȫ������
	//���ȫ��NULL��������ȫ������
	while (size > 0)     
	{
		//����
		BTNode* tmp = queue[front++];   //��ͷ����
		size--;
		if (tmp != NULL)
		{
			printf("������ȫ������\n");
			return;
		}
	}
	printf("����ȫ������\n");
	free(queue);
	queue = NULL;
}
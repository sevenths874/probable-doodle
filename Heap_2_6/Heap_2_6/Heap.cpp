#include"Heap.h"

//�ѵ����µ����㷨(С����)
//���㷨���������������������������Ƕ�
void HeapAdjustDown(HPDataType* arr, int size, int root)
{
	int parent = root;  //��ʼ�±�Ϊ0
	int child = parent * 2 + 1;  //����
	HPDataType tmp = 0;
	while (child < size)  //�����rootΪ����������ȫ�����
	{   //�Һ��Ӵ��ڵ�����£�������Ӵ����Һ���
		if (child+1 < size && arr[child] > arr[child + 1])   
			++child;      //�ҳ����Һ����н�С�ĺ���

		//����������ڽ�С����
		if (arr[parent] > arr[child])
		{
			//������������С���ӽ���ֵ
			tmp = arr[parent];
			arr[parent] = arr[child];
			arr[child] = tmp;
			//�������µ���
			parent = child;
			child = child * 2 + 1;
		}
		//��������Ƚ�С���Ӷ�С������ֹ
		else
			break;
	}
}

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* arr, int size)
{
	//��ʼ��
	hp->arr = (HPDataType*)malloc(size*sizeof(HPDataType));
	memcpy(hp->arr, arr, size*sizeof(HPDataType));
	hp->size = size;
	hp->capacity = size;

	//����,�����һ����֧���(�±�Ϊ(size-1)-1/2)��ʼ������ǰ����
	for (int i = (size - 1) - 1 / 2; i >= 0; --i)
		HeapAdjustDown(hp->arr, size, i);
}

// �ѵ�����
void HeapDestory(Heap* hp)
{
	free(hp->arr);
}

//�ѵ����ϵ���
void HeapAdjustUp(Heap* hp, int child)
{
	HPDataType parent = (child - 1) / 2;
	HPDataType tmp = 0;
	//while (parent >= 0) ����������ж�ʱ��ûдbreak�ᵼ����ѭ��  
	while(child > 0)   //���ϵ���ֱ���������
	{
		//������ӽ��ȸ����С���򽻻�
		if (hp->arr[child] < hp->arr[parent])
		{
			tmp = hp->arr[child];
			hp->arr[child] = hp->arr[parent];
			hp->arr[parent] = tmp;

			//�������ϵ���
			child = parent;
			parent = (parent - 1) / 2;
		}
		//������ӽ����ڸ���㣬����ֹ
		else
			break;
	}
}

// �ѵĲ��룺���뵽�ѵף�Ȼ�����ϵ���
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->size == hp->capacity)
	{
		hp->capacity *= 2;
		hp->arr = (HPDataType*)realloc(hp->arr,(hp->capacity)*sizeof(HPDataType));
	}
	hp->arr[hp->size] = x;
	hp->size++;
	HeapAdjustUp(hp,hp->size-1);    //���ϵ���
}

// �ѵ�ɾ����ɾ���Ѷ�Ԫ��->���Ѷ�Ԫ����ѵ�Ԫ�ػ�����ɾ���ѵ�Ԫ�أ�Ȼ�����µ���
void HeapPop(Heap* hp)
{
	//�����Ѷ��Ͷѵ�Ԫ��
	HPDataType tmp = hp->arr[0];
	hp->arr[0] = hp->arr[hp->size - 1];
	hp->arr[hp->size - 1] = tmp;

	//ɾ���ѵ�Ԫ��
	hp->size--;

	//���µ���
	HeapAdjustDown(hp->arr, hp->size, 0);
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	return hp->arr[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	return hp->size;
}

// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	return (hp->size == 0 ? 1 : 0);
}

//��ӡ��
void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->size; ++i)
		printf("%d ", hp->arr[i]);
	printf("\n");
}

//������
void HeapSort(Heap* hp, HPDataType* arr, int size)
{
	//��С��
	//HeapCreate(hp, arr, size);

	//������(����)
	int end = size - 1;   //ָ��ѵ�
	int tmp = 0;
	while (end > 0)   //size��Ԫ�أ����µ���(size-1)��
	{
		//���Ѷ�Ԫ����ѵ�Ԫ�ؽ���
		tmp = hp->arr[0];
		hp->arr[0] = hp->arr[end];
		hp->arr[end] = tmp;

		//���µ���
		HeapAdjustDown(hp->arr, end, 0);   //�����¶�ʱ��ȥ�ѵ�Ԫ��
		end--;
	}
}


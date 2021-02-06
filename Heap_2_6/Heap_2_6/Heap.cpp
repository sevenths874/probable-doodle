#include"Heap.h"

//堆的向下调整算法(小根堆)
//该算法条件：所给定结点的左右子树都是堆
void HeapAdjustDown(HPDataType* arr, int size, int root)
{
	int parent = root;  //起始下标为0
	int child = parent * 2 + 1;  //左孩子
	HPDataType tmp = 0;
	while (child < size)  //检查以root为根的子树的全部结点
	{   //右孩子存在的情况下，如果左孩子大于右孩子
		if (child+1 < size && arr[child] > arr[child + 1])   
			++child;      //找出左右孩子中较小的孩子

		//如果父结点大于较小孩子
		if (arr[parent] > arr[child])
		{
			//交换父结点与较小孩子结点的值
			tmp = arr[parent];
			arr[parent] = arr[child];
			arr[child] = tmp;
			//继续向下调整
			parent = child;
			child = child * 2 + 1;
		}
		//如果父结点比较小孩子都小，则终止
		else
			break;
	}
}

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* arr, int size)
{
	//初始化
	hp->arr = (HPDataType*)malloc(size*sizeof(HPDataType));
	memcpy(hp->arr, arr, size*sizeof(HPDataType));
	hp->size = size;
	hp->capacity = size;

	//建堆,从最后一个分支结点(下标为(size-1)-1/2)开始依次向前调整
	for (int i = (size - 1) - 1 / 2; i >= 0; --i)
		HeapAdjustDown(hp->arr, size, i);
}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	free(hp->arr);
}

//堆的向上调整
void HeapAdjustUp(Heap* hp, int child)
{
	HPDataType parent = (child - 1) / 2;
	HPDataType tmp = 0;
	//while (parent >= 0) 用这个条件判断时，没写break会导致死循环  
	while(child > 0)   //向上调整直至到根结点
	{
		//如果孩子结点比父结点小，则交换
		if (hp->arr[child] < hp->arr[parent])
		{
			tmp = hp->arr[child];
			hp->arr[child] = hp->arr[parent];
			hp->arr[parent] = tmp;

			//继续向上调整
			child = parent;
			parent = (parent - 1) / 2;
		}
		//如果孩子结点大于父结点，则终止
		else
			break;
	}
}

// 堆的插入：插入到堆底，然后向上调整
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->size == hp->capacity)
	{
		hp->capacity *= 2;
		hp->arr = (HPDataType*)realloc(hp->arr,(hp->capacity)*sizeof(HPDataType));
	}
	hp->arr[hp->size] = x;
	hp->size++;
	HeapAdjustUp(hp,hp->size-1);    //向上调整
}

// 堆的删除：删除堆顶元素->将堆顶元素与堆底元素互换，删除堆底元素，然后向下调整
void HeapPop(Heap* hp)
{
	//交换堆顶和堆底元素
	HPDataType tmp = hp->arr[0];
	hp->arr[0] = hp->arr[hp->size - 1];
	hp->arr[hp->size - 1] = tmp;

	//删除堆底元素
	hp->size--;

	//向下调整
	HeapAdjustDown(hp->arr, hp->size, 0);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	return hp->arr[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	return hp->size;
}

// 堆的判空
int HeapEmpty(Heap* hp)
{
	return (hp->size == 0 ? 1 : 0);
}

//打印堆
void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->size; ++i)
		printf("%d ", hp->arr[i]);
	printf("\n");
}

//堆排序
void HeapSort(Heap* hp, HPDataType* arr, int size)
{
	//建小堆
	//HeapCreate(hp, arr, size);

	//堆排序(降序)
	int end = size - 1;   //指向堆底
	int tmp = 0;
	while (end > 0)   //size个元素，向下调整(size-1)次
	{
		//将堆顶元素与堆底元素交换
		tmp = hp->arr[0];
		hp->arr[0] = hp->arr[end];
		hp->arr[end] = tmp;

		//向下调整
		HeapAdjustDown(hp->arr, end, 0);   //构建新堆时除去堆底元素
		end--;
	}
}


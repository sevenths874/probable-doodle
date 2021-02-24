#include<iostream>
using namespace std;

class A
{
private:
	int _a;

public:
	A()
	{
		_a = 0;
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

};

int main()
{
	////C语言内存操作
	//int* p1 = (int*)malloc(sizeof(int));
	//int* p2 = (int*)malloc(sizeof(int) * 10);
	//free(p1);
	//free(p2);

	////C++
	//int* p3 = new int;
	////int* p3 = new int(1);   //初始化
	//int* p4 = new int[10];
	//delete p3;
	//delete[] p4;

	//对于内置类型来说，malloc和new没有区别
	//对于自定义类型来说，new会调用类的构造函数进行初始化,delete会调用类的析构函数
	A* pa = (A*)malloc(sizeof(A));
	free(pa);

	A* paa = new A;
	delete paa;

	system("pause");
	return 0;
}
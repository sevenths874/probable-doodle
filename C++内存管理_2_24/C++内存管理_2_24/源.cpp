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
	////C�����ڴ����
	//int* p1 = (int*)malloc(sizeof(int));
	//int* p2 = (int*)malloc(sizeof(int) * 10);
	//free(p1);
	//free(p2);

	////C++
	//int* p3 = new int;
	////int* p3 = new int(1);   //��ʼ��
	//int* p4 = new int[10];
	//delete p3;
	//delete[] p4;

	//��������������˵��malloc��newû������
	//�����Զ���������˵��new�������Ĺ��캯�����г�ʼ��,delete����������������
	A* pa = (A*)malloc(sizeof(A));
	free(pa);

	A* paa = new A;
	delete paa;

	system("pause");
	return 0;
}
//�������� 
#include<iostream>
using namespace std;

class A
{
private:
	int _a;
	int _b;

public:
	A()
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

};

int main()
{
	A a;  //a����������������main������
	A();  //�����������������ֻ����һ��
	//system("pause");
	return 0;
}

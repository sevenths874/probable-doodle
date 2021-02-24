//匿名对象 
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
	A a;  //a的生命周期在整个main函数中
	A();  //匿名对象的生命周期只在这一行
	//system("pause");
	return 0;
}

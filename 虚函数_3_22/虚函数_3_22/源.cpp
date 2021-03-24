#include<iostream>
using namespace std;

//class A
//{
//public:
//	void func()
//	{
//		cout << "123" << endl;
//	}
//};
//
//class B : public A
//{
//private:
//	int _b;
//};
//
//
//int main()
//{
//	B b;
//	b.func();
//
//	system("pause");
//	return 0;
//}
//
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	/*virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}*/
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}



class Base {
private:
	virtual void fun() { std::cout << "Base Fun"<< endl; }
	friend int main();
	
};

class Derived : public Base {
public:
	void fun() { std::cout << "Derived Fun" << endl; }
};

int main()
{
	Base *ptr = new Derived;
	ptr->fun();
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

//int main()
//{
//	cout << "Hello World!!!"<<endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	/*int a = 0;
//	auto b = a;
//	int& c = a;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;*/
//
//	//C++11 范围for
//	int arr[] = { 1,2,3,4,5 };
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}


void fun(int n)
{
	cout << "整型" << endl;
}

void fun(int* n)
{
	cout << "整型指针" << endl;
}

int main()
{
	fun(0);
	fun(NULL);  //=>fun(0)
	fun(nullptr);  //=>fun((void*)0)

	system("pause");
	return 0;
}
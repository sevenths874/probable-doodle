#include<iostream>
using namespace std;

////实现一个类，计算程序中创建了多少个对象
//class A
//{
//private:
//	static int _count;
//
//public:
//	A()    //构造函数
//	{
//		++_count;
//	}
//
//	A(const A& a)   //拷贝构造函数
//	{
//		++_count;
//	}
//
//	static int Getcount()   //获取_count
//	{
//		return _count;
//	}
//};
//int A::_count = 0;   //初始化_count
//
//int main()
//{
//	A a1;
//	A a2;
//	A a3(a1);
//	A a4(a2);
//
//	cout<< A::Getcount() << endl;
//
//	system("pause");
//	return 0;
//}


//初始化列表的使用
//class A
//{
//private:
//	int _a;
//
//public:
//	A(int a)
//		:_a(a)
//	{}
//
//};
//
//class B
//{
//private:
////此处是成员变量的声明
//	const int _n;  //const
//	int& _ret;   //引用
//	A _obj;    //没有默认构造函数的自定义类型
//
//public:
////此处是成员变量的定义
//	//以上三个成员变量必须使用初始化列表进行初始化
//	//成员变量在初始化列表初始化的顺序是声明的顺序
//	B(int a,int ret)   
//		:_n(10)
//		,_ret(ret)
//		,_obj(a)
//	{}
//
//};
//
//int main()
//{
//	B b1(1, 2);
//	const B& b2 = { 3,4 };
//
//	system("pause");
//	return 0;
//}


//class Sum {
//public:
//	Sum() {
//		_sum += _i;
//		++_i;
//	}
//	static int GetSum() {
//		return _sum;
//	}
//
//private:
//	static int _i;
//	static int _sum;
//};
//int Sum::_i = 1;
//int Sum::_sum = 0;
//
//class Solution {
//public:
//	int Sum_Solution() {
//		Sum arr[5];  //创建一个类对象的数组，会调用n次构造函数
//		return Sum::GetSum();
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout << s.Sum_Solution() << endl;
//
//	system("pause");
//	return 0;
//}


//友元
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
private:
	int _year;
	int _month;
	int _day;

public:
	Date(int year = 0, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
};

// << 运算符重载
ostream& operator<<(ostream& out, const Date& d)
{
	cout << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

// >> 运算符重载
istream& operator>>(istream& in, Date& d)
{
	cin >> d._year >> d._month >> d._day;
	return in;
}


int main()
{
	Date d1;
	Date d2(2020, 2, 20);
	cout << d1 << d2 << endl;

	cin >> d1;
	cout << d1;

	system("pause");
	return 0;
}
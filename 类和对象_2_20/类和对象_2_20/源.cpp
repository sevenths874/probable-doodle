#include<iostream>
using namespace std;

////ʵ��һ���࣬��������д����˶��ٸ�����
//class A
//{
//private:
//	static int _count;
//
//public:
//	A()    //���캯��
//	{
//		++_count;
//	}
//
//	A(const A& a)   //�������캯��
//	{
//		++_count;
//	}
//
//	static int Getcount()   //��ȡ_count
//	{
//		return _count;
//	}
//};
//int A::_count = 0;   //��ʼ��_count
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


//��ʼ���б��ʹ��
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
////�˴��ǳ�Ա����������
//	const int _n;  //const
//	int& _ret;   //����
//	A _obj;    //û��Ĭ�Ϲ��캯�����Զ�������
//
//public:
////�˴��ǳ�Ա�����Ķ���
//	//����������Ա��������ʹ�ó�ʼ���б���г�ʼ��
//	//��Ա�����ڳ�ʼ���б��ʼ����˳����������˳��
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
//		Sum arr[5];  //����һ�����������飬�����n�ι��캯��
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


//��Ԫ
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

// << ���������
ostream& operator<<(ostream& out, const Date& d)
{
	cout << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

// >> ���������
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
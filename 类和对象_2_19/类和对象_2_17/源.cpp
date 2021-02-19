#include<iostream>
using namespace std;

//һ������������
class Date
{
private:
	int _year;
	int _month;
	int _day;

public:
	//��ӡ
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//��ȡÿ������
	int GetMonthDay(int year, int month)
	{
		static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//��2����������
		//����һ�򣬰��겻�򣻵��İ���Ҫ��(ÿ25�����򣬳�ÿ100��)
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			return 29;
		else
			return arr[month];
	}

	//���캯��
	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
			cout << "error!" << endl;
	}

	//�������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

    // >���������
	//d1 > d2
	//d1.operator>(&d1,d2)
	/*inline*/ bool operator>(const Date& d)    //bool operator>(Date* this,const Date& d)
	{  
		//�����ж����Ա����Ĭ����������
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day > d._day)
			return true;
		else
			return false;
	}

	// <���������
	bool operator<(const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;
		else
			return false;
	}

	// ==���������
	bool operator==(const Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
			return true;
		else
			return false;
	}

	// >=���������
	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;   //����
	}

	// <=���������
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	// !=���������
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// +���������
	//d1+10
	Date operator+(int day)
	{
		Date ret(*this);   //��������һ����ʱ����
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			++ret._month;
			if (ret._month == 13)
			{
				++ret._year;
				ret._month = 1;
			}
		}
		return ret;
	}

	// +=���������
	//d1+=10
	Date& operator+=(int day)
	{
		if (day < 0)
			return (*this -= -day);

		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}

	// -���������
	//d-10
	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;   //����

		/*ret._day -= day;
		while (ret._day < 0)
		{
			--ret._month;
			if (ret._month == 0)
			{
				--ret._year;
				ret._month= 12;
			}
			ret._day += GetMonthDay(ret._year, ret._month);
		}*/

		return ret;
	}

	// -=���������
	//d-=10
	Date& operator-=(int day)
	{
		if (day < 0)
			return (*this += -day);

		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	// =���������
	//d2 = d1
	Date& operator=(const Date& d)
	{
		if (this != &d)   //����Լ����Լ���ֵ�ļ���ж�
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// ++���������
	//++d1 -> d1.operator(&d1)
	Date& operator++()
	{
		*this += 1;     //����
		return *this;   //ǰ��++���ؼ�֮���ֵ
	}

	// ++���������
	//d1++ -> d1.operator++(&d1,0)
	Date operator++(int)   //Ϊ�˹��ɺ������أ�����һ��int�β�
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	// --���������
	//--d1 -> d1.operator(&d1)
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// --���������
	//d1-- -> d1.operator(&d1,0)
	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	// -���������
	//d1-d2(������������֮��) -> d1.operator(d2) -> operator(&d1,d2)
	//ֱ�������λ����ʵ�� -> ����ÿ����С����++��Ȼ���ж��Ƿ���ڴ����ڣ��ӵĴ�����Ϊ��������
	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int different = 0;  //��ֵ
		int flag = 1;   //��ʾ��
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		while (min != max)
		{
			++min;
			++different;
		}
		return different*flag;
	}


};

int main()
{
	//Date d1;
	//d1.Print();

	//Date d2(2021, 2, 18);
	//d2.Print();

	//Date d3(2020, 5, 32);
	//d3.Print();

	////Date d4(d1);
	//Date d4 = d1;
	//d4.Print();

	//cout << (d2 > d1) << endl;
	//cout << (d4 == d1) << endl;
	//cout << (d4 >= d1) << endl;
	//cout << (d4 != d1) << endl;
	//cout << (d4 != d2) << endl;

	//d2 += 1000;
	//d2.Print();

	/*Date d5 = d2 + 10000;
	d5.Print();*/

	/*Date d6(2020,4,11);
	d2 = d6 - 20;
	d2.Print();
	d6.Print();

	d2 -= 22;
	d2.Print();*/

	Date d7(2021, 2, 19);
	Date d8(2050, 9, 7);
	cout << (d8 - d7) << endl;
	cout << (d7 - d8) << endl;

	system("pause");
	return 0;
}






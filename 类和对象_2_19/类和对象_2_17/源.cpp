#include<iostream>
using namespace std;

//一个完整日期类
class Date
{
private:
	int _year;
	int _month;
	int _day;

public:
	//打印
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//获取每月天数
	int GetMonthDay(int year, int month)
	{
		static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//是2月且是闰年
		//四年一闰，百年不闰；但四百年要闰(每25个不闰，除每100个)
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			return 29;
		else
			return arr[month];
	}

	//构造函数
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

	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

    // >运算符重载
	//d1 > d2
	//d1.operator>(&d1,d2)
	/*inline*/ bool operator>(const Date& d)    //bool operator>(Date* this,const Date& d)
	{  
		//在类中定义成员函数默认内联函数
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day > d._day)
			return true;
		else
			return false;
	}

	// <运算符重载
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

	// ==运算符重载
	bool operator==(const Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
			return true;
		else
			return false;
	}

	// >=运算符重载
	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;   //复用
	}

	// <=运算符重载
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	// !=运算符重载
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// +运算符重载
	//d1+10
	Date operator+(int day)
	{
		Date ret(*this);   //拷贝构造一个临时对象
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

	// +=运算符重载
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

	// -运算符重载
	//d-10
	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;   //复用

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

	// -=运算符重载
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

	// =运算符重载
	//d2 = d1
	Date& operator=(const Date& d)
	{
		if (this != &d)   //针对自己给自己赋值的检查判断
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// ++运算符重载
	//++d1 -> d1.operator(&d1)
	Date& operator++()
	{
		*this += 1;     //复用
		return *this;   //前置++返回加之后的值
	}

	// ++运算符重载
	//d1++ -> d1.operator++(&d1,0)
	Date operator++(int)   //为了构成函数重载，加上一个int形参
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	// --运算符重载
	//--d1 -> d1.operator(&d1)
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// --运算符重载
	//d1-- -> d1.operator(&d1,0)
	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	// -运算符重载
	//d1-d2(两个日期天数之差) -> d1.operator(d2) -> operator(&d1,d2)
	//直接相减借位不好实现 -> 可以每次让小日期++，然后判断是否等于大日期，加的次数即为相差的天数
	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int different = 0;  //差值
		int flag = 1;   //表示正
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






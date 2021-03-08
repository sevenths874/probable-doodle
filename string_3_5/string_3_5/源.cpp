#include<iostream>
#include<string>
using namespace std;

//字符串转整型
int string2int(const string& str)
{
	int val = 0;
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		val *= 10;
		val += (*it - '0');
		++it;
	}
	return val;
}

void test1()
{
	string s("hello");
	s += ' ';
	s += "world.";
	cout << s << endl;

	//遍历
	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test2()
{
	string s1("hello.cpp");
	string s2("hello.c");
	string s3("hello.txt");

	size_t pos1 = s1.find('.');
	if (pos1 != string::npos)
	{
		cout << s1.substr(pos1)<<endl;
	}

	size_t pos2 = s2.find('.');
	if (pos2 != string::npos)
	{
		cout << s2.substr(pos2)<<endl;
	}

	size_t pos3 = s3.find('.');
	if (pos3 != string::npos)
	{
		cout << s3.substr(pos3) << endl;
	}
	cout << endl;
}

void test3(string url)
{
	//分离协议、域名、资源名称
	//string url("https://v.bitedu.vip/login");
	size_t pos1 = url.find(':');
	if (pos1 != string::npos)
	{
		cout << url.substr(0, pos1) << endl;
	}
	size_t pos2 = url.find('/', pos1 + 3);
	if (pos2 != string::npos)
	{
		cout << url.substr(pos1 + 3, pos2 - (pos1 + 3))<< endl;
	}
	cout << url.substr(pos2+1) << endl;

}

void test4()
{
	//比较字符串大小
	string s1("abcde");
	string s2("bcdef");
	cout << (s1 < s2) << endl;
	cout << (s1 < "qwrty") << endl;
}







int main()
{
	//string s1;
	//string s2("hello world");
	//string s3(s2);
	//string s4("12345");

	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s3 << endl;

	////遍历
	////1. operator[]
	//for (int i = 0; i < s2.size(); ++i)
	//{
	//	s2[i] += 1;
	//}
	//for (int i = 0; i < s2.size(); ++i)
	//{
	//	cout << s2[i] << " ";
	//}
	//cout << endl;

	////迭代器
	//string::iterator it = s2.begin();
	//while (it != s2.end())
	//{
	//	*it -= 1;
	//	++it;
	//}
	//it = s2.begin();
	//while (it != s2.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	////范围for(C++11)
	//for (auto ch : s2)
	//{
	//	cout << ch << " ";
	//}
	//cout << endl;

	////倒着遍历
	//string::reverse_iterator rit = s2.rbegin();
	//while (rit != s2.rend())
	//{
	//	cout << *rit <<" ";
	//	++rit;
	//}
	//cout << endl;

	//cout << string2int(s4) << endl;

	//test1();
	//test2();
	string url("https://v.bitedu.vip/login");
	test3(url);
	test4();



	system("pause");
	return 0;
}
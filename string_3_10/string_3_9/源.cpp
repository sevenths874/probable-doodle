#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//ģ��ʵ��string
namespace lhw
{
	class string
	{
	private:
		char* _str;

	public:
		/*string(const char* str)
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		string()
			:_str(new char[1])
		{
			_str[0] = '\0';
		}*/

		string(const char* str="")   //ȫȱʡ ""��ʾ'\0'
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		////��������(���)--��ͳд��
		//string(const string& s)
		//	:_str(new char[strlen(s._str) + 1])
		//{
		//	strcpy(_str, s._str);
		//}


		//��������(���)--�ִ�д��
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);   //���ù��캯��
			swap(_str, tmp._str);
		}

		////��ֵ���������--��ͳд��
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		char* tmp = new char[strlen(s._str) + 1];
		//		strcpy(tmp, s._str);
		//		delete[] _str;
		//		_str = tmp;
		//	}
		//	return *this;
		//}

		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);    //���ÿ�������
		//		swap(_str, tmp._str);
		//	}
		//	return *this;
		//}

		//��ֵ���������--�ִ�д��
		string operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}

		~string()
		{
			delete[] _str;	
			_str = nullptr; 
		}

		size_t size()
		{
			return strlen(_str);
		}

		char& operator[](size_t i)
		{
			return _str[i];
		}

		const char* c_str()
		{
			return _str;
		}





	};


	void test1()
	{
		string str1("hello");
		string str2;

		for (size_t i = 0; i < str1.size();++i)
		{
			cout << str1[i] << " ";
		}
		cout << endl;
		for (size_t i = 0; i < str2.size(); ++i)
		{
			cout << str2[i] << " ";
		}
		cout << endl;
	}

	void test2()
	{
		string s1("hello");
		string s2(s1);
		string s3 = s2;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;
		
	}

}


int main()
{
	//lhw::test1();
	//lhw::test2();
	
	string s("abc");

	system("pause");
	return 0;
}













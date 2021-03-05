#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

template<class T>
class vector
{
private:
	T* _arr;
	int _size;
	int _capacity;

public:
	vector()
		:_arr(nullptr)
		, _size(0)
		, _capacity(0)
	{}

	~vector()
	{}

	void PushBack(const T& data)
	{}

	void PopBack()
	{}

	int Size()
	{
		return _size;
	}

	// []���������
	T& operator[](int pos)
	{
		assert(pos < _size);
		return _arr[pos];
	}

};


int main()
{
	/*int a1 = 10, a2 = 20;
	double a3 = 10.1, a4 = 20.1;

	cout << Add<int>(a1,a2) << endl;
	cout << Add<double>(a3, a4) << endl;*/

	//vector��������vector<...>��������
	vector<int> v1;
	vector<double> v2;

	//��������
	for (int i = 0; i < v1.Size(); ++i)
	{
		cout << v1[i] <<" ";
	}
	cout << endl;

	system("pause");
	return 0;
}
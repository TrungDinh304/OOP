#include "MyIntArray.h"

MyIntArray::MyIntArray()
{
	pArr = nullptr;
	size = 0;
	cout << "Vua tao pArray = null; size =0" << endl;
}

MyIntArray::MyIntArray(int sz)
{
	pArr = new int[sz] {};
	size = sz;
	cout << "Vua tao pArray = new int[" << size << "], size = " << size << endl;
}

MyIntArray::~MyIntArray()
{
	delete[]pArr;
	cout << "Destructor" << endl;
}

int& MyIntArray::operator[](int pos)
{
	return pArr[pos];
}

MyIntArray::MyIntArray(const MyIntArray& other)
{
	size = other.size;
	pArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		pArr[i] = other.pArr[i];
	}
	cout << "Copy Constructor" << endl;
}

MyIntArray& MyIntArray::operator=(const MyIntArray& other)
{
	delete[]pArr;
	size = other.size;
	pArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		pArr[i] = other.pArr[i];
	}
	cout << "Assignment Operator Overloading." << endl;
	return *this;
}


void MyIntArray::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << pArr[i] << ' ';
	}
	cout << endl;
}

istream& operator>>(istream& in, MyIntArray& source)
{
	delete[]source.pArr;
	cout << "Nhap size: ";
	in >> source.size;
	source.pArr = new int[source.size];
	for (int i = 0; i < source.size; i++)
	{
		in >> source.pArr[i];
	}
	return in;
}


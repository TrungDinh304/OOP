/**************************************************************
* Implement vector class template using dynamic array
* Define vector class template – vector.h
***************************************************************/
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>
using namespace std;
/* vector class template */
template<typename T>
class vector {
private:
	T* ptr;
	int capacity;
	int sz;
public:
	// Constructors
	vector();
	vector(int cap);
	~vector();
	// utilities methods
	/* operator[] */
	T& operator[](int n);
	/* Expand extra memory */
	void reserve(int newalloc);
	// input, output
	void push(const T& element);
	void print();
};
#endif

template<typename T>
inline vector<T>::vector()
{
	capacity = 0;
	sz = 0;
	ptr = new T[capacity];
}

template<typename T>
inline vector<T>::vector(int cap)
{
	ptr = new T[cap];
	capacity = cap;
	sz = 0;
}

template<typename T>
inline vector<T>::~vector()
{
	delete[] ptr;
}

template<typename T>
inline T& vector<T>::operator[](int n)
{
	if (n < sz && n < capacity && n >= 0)
	{
		return ptr[n];
	}
	exit(0);	
}

template<typename T>
inline void vector<T>::reserve(int newalloc)
{
	if (newalloc > 0)
	{
		capacity += newalloc;
		T* New_vector = new T[capacity];
		if (New_vector == NULL)
		{
			cout << "Vector da day va khong con bo nho de cap phat them." << endl;
			return;
		}
		for (int i = 0; i < sz; i++)
			New_vector[i] = ptr[i];
		delete[]ptr;
		ptr = New_vector;
	}
}

template<typename T>
inline void vector<T>::push(const T& element)
{
	if(sz >= capacity)
	{
		reserve(10);
	}
	ptr[sz] = element;
	sz++;
}

template<typename T>
inline void vector<T>::print()
{
	if (sz == 0)
	{
		cout << "Vector rong\n";
		return;
	}
	for(int i=0;i<sz;i++)
	{
		cout << ptr[i] << ' ';
	}
	cout << endl;
}

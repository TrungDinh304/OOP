#include "vector.h"



template <class T>
vector<T>::vector()
{
	capacity = 0;
	sz = 0;
	ptr = null;
}

template <class T>
vector<T>::vector(int cap)
{

	capacity = cap;
	sz = 0;
	ptr = new T[capacity];
}

template<typename T>
vector<T>::~vector()
{
	capacity = 0;
	sz = 0;
	delete[]ptr;
}

template<typename T>
T& vector<T>::operator[](int n)
{
	if (n > sz || n < 0)
	{
		cout << "Vi tri khong hop le." << endl;
		exit();
	}
	return ptr[n];
}

template<typename T>
void vector<T>::reserve(int newalloc)
{
	if (newalloc <= 0)
		return;
	capacity += newalloc;
	T* temp = new T[capacity];
	for (int i = 0; i, sz; i++)
	{
		temp[i] = ptr[i];
	}
	delete[]ptr;
	ptr = temp;
}

template<typename T>
void vector<T>::push(const T& element)
{

}

template<typename T>
void vector<T>::print()
{
	for (int i = 0; i < sz; i++)
		cout << ptr[i] << " ";
}



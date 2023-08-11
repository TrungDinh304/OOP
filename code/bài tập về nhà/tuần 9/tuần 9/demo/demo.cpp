#include <iostream>
#include<string>
#include<vector>
using namespace std;


template <class T>
class Stack
{
private:
    T* list;
    int max;
    int size;
public:
    Stack();
    ~Stack();
    bool init_Stack(int a);
    bool Isempty();
    bool Isfull();
    void push(const T& a);
    T pop();
    T top();
};




int main()
{
    Stack<float> s;
    s.init_Stack(5);
    s.push(5.3);
    s.push(3.3);
    s.push(2.3);
    s.push(1.3);
    s.push(5.3);
    

    return 0;
}

template<class T>
Stack<T>::Stack()
{
    size = 0;
    max = 0;
    list = new T[size];
}

template<class T>
Stack<T>::~Stack()
{
    delete[]list;
    size = 0;
    max = 0;
}

template<class T>
bool Stack<T>::init_Stack(int a)
{
    size = 0;
    max = a;
    list = new T[size];
    if (list == NULL)
        return false;
    return true;
}

template<class T>
bool Stack<T>::Isempty()
{
    if (size == 0 || list == NULL)
        return true;
    return false;
}

template<class T>
bool Stack<T>::Isfull()
{
    return size >= max;

}

template<class T>
void Stack<T>::push(const T& a)
{
    if (size < max)
    {
        list[size] = a;
        size++;
        return;
    }
}

template<class T>
T Stack<T>::pop()
{
    if (Isempty())
        return INT16_MAX;
    size--;
    return list[size];
}

template<class T>
T Stack<T>::top()
{
    return list[0];
}

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cassert>
using namespace std;
class Stack {
private:
    int* ptr;
    int capacity;
    int size;
public:
    // Constructor
    Stack(int capacity);
    // destructor
    ~Stack();
    // Thêm phần tử vào stack, them vào cuối
    void push(const int& element);
    // Lấy phần tử khỏi stack, Lấy ra ở cuối theo LIFO
    int pop();
};
#endif

Stack::Stack(int capacity)
{
    this->capacity = capacity;
    ptr = new int[capacity];
    size = 0;
}

Stack::~Stack()
{
    delete[]ptr;
}

void Stack::push(const int& element)
{
    if (size >= capacity)
    {
        cout << "This stack is currently full. " << endl;
        return;
    }
    for (int i = size; i > 0; i--)
    {
        ptr[i] = ptr[i - 1];
    }
    ptr[0] = element;
    size++;
}

int Stack::pop()
{
    if (size <= 0)
    {
        cout << "this Stack is currently empty." << endl;
        return INT_FAST32_MIN;
    }
    int result = ptr[0];
    for (int i = 0; i < size; i++)
    {
        if (i == capacity - 1) {
            ptr[i] = 0;
            break;
        }
        ptr[i] = ptr[i + 1];
    }
    size--;
    return result;
}


int main()
{
    Stack st(10);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    st.push(1);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    return 1;

}


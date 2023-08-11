#include <iostream>
#include<random>
using namespace std;


class mystack
{
private:
    int stack[5] = { 0 };
    int size;
    bool sont(int);
public: 
    int getsize()
    {
        return size;
    }

    int* getstack()
    {
        return stack;
    }
    mystack();
    void push(int);
    int pop();

};

mystack::mystack()
{
    size = 0;
}

bool mystack::sont(int a)
{
    if (a <= 1)
        return 0;
    if (a == 2)
        return 1;
    for (int i = 2; i < a; i++)
        if (a % i == 0)
            return 0;
    return 1;
}

void mystack::push(int x)
{
    try {
        if (size >= 5)
            throw(size);
        try {
            if (x > 15 || x < 0)
                throw(x);
            if (!sont(x))
                throw(x);
            stack[size++] = x;
        }
        catch (int x)
        {
            if (x > 15 || x < 0)
                cout << "chi nhan gia tri tu 0 -> 15." << endl;
            else if (!sont(x))
                cout << "Nguoi dung vua tao ra khong la so nguyen to." << endl;
        }
    }
    catch (int)
    {
        cout << "Loi het vung nho." << endl;
        stack[size - 1] = x;
    }
}

int mystack::pop()
{
    try
    {
        if (size <= 0)
            throw(size);
        size--;
        return stack[size+1];
    }
    catch (int)
    {
        cout << "Stack rong." << endl;
    }
}

int main()
{
    mystack a;
    int n = 0;
    cout << "Nhap n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x = rand() % 15 + 1;
        cout << "so vua tao ra: " << x << endl;
        a.push(x);
    }

    cout << "final" << endl;
    for (int i = a.getsize()-1; i >= 0; i--)
        cout << a.getstack()[i] << '\n';


    return 0;
}

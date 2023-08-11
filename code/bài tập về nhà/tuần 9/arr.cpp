#include <iostream>
using namespace std;


template<class T>
class arr {
private:
    T* ptr;
    int n;
public:
    arr();
    void push(int x);
    void MySwap(int a, int b);
    void xoa_i(int i);
    void MyRe();
    int pop();
    void xuat()
    {
        cout << "=========" << n << "===========" << endl;
        for (int i = 0; i < n; i++)
            cout << ptr[i] << ' ';
    }
};




template<class T>
arr<T>::arr()
{
    n = 0;
    ptr = NULL;
}

template<class T>
void arr<T>::push(int x)
{
    T* temp = new T[n + 1];
    temp[0] = x;
    for (int i = 0; i < n; i++)
    {
        temp[i + 1] = ptr[i];
    }
    n++;
    delete[] ptr;
    ptr = temp;
}

// template<class T>
// void arr<T>::MySwap(int a, int b)
// {
//     if (a >= n || b >= n || a < 0 || b < 0)
//     {
//         cout << "Tham so khong hop le." << endl;
//         return;
//     }
//     T b = ptr[a];
//     ptr[a] = ptr[b];
//     ptr[b] = a;
// }

template<class T>
void arr<T>::xoa_i(int i)
{
    
    for (int j = i; j < n - 1; j++)
        ptr[j] = ptr[j + 1];
    n--;
    T* temp = new T[n];
    for (int j = 0; j < n; j++)
    {
        temp[j] = ptr[j];
    }
    delete[]ptr;
    ptr = temp;    
}

template<class T>
void arr<T>::MyRe()
{
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] < 0)
            xoa_i(i);
    }
}

template<class T>
int arr<T>::pop()
{
    T max1 = ptr[0];
    T max2 = ptr[0];
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] > max1)
            max1 = ptr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] == max1)
            continue;
        if (ptr[i] > max2)
            max2 = ptr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] == max2)
        {
            xoa_i(i);
        }
    }
    return max2;

}


int main()
{
    arr<int> a;
    a.push(-4);
    a.push(-3);
    a.push(6);
    a.push(4);
    a.push(-7);
    a.push(6);
    a.push(7);
    a.push(1);
    a.xuat();
    cout << endl << a.pop() << endl;
    a.xuat();
    cout << endl;
    a.MyRe();
    a.xuat();

    return 0;
}

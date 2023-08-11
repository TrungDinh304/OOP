#include <iostream>
using namespace std;


template<class T>
class arr {
private:
    T* ptr;
    int n;
public:
    arr();
    void MyPush2(int x, int pos);
    void MySwap(int a, int b);
    void xoa_i(int i);
    void MyRo();
    void MyRe();
    int pop();
    void nhap();
    void xuat()
    {
        cout << "=========" << n << "===========" << endl;
        for (int i = 0; i < n; i++)
            cout << ptr[i] << ' ';
        cout << endl;
    }
};




template<class T>
arr<T>::arr()
{
    n = 0;
    ptr = NULL;
}

template<class T>
void arr<T>::MyPush2(int x, int a)
{
    if (a > n || a < 0)
    {
        cout << "Vi tri khong hop le." << endl;
        return;
    }
    T* temp = new T[n + 1];
    temp[a] = x;

    for (int i = 0; i < a; i++)
    {
        temp[i] = ptr[i];
    }
    for (int i = a; i < n; i++)
    {
        temp[i + 1] = ptr[i];
    }
    n++;
    delete[] ptr;
    ptr = temp;
}

template<class T>
void arr<T>::MySwap(int a, int b)
{
    if (a >= n || b >= n || a < 0 || b < 0)
    {
        cout << "Tham so khong hop le." << endl;
        return;
    }
    ptr[a] = ptr[a] + ptr[b];
    ptr[b] = ptr[a] - ptr[b];
    ptr[a] = ptr[a] - ptr[b];
}

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
void arr<T>::MyRo()
{
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] < 0)
        {
            xoa_i(i);
            i--;
        }
    }
}

template<class T>
void arr<T>::MyRe()
{
    T* temp = new T[n];
    for (int i = 0;i<n;i++)
    {
        temp[i] = ptr[n - 1 - i];
    }
    delete[]ptr;
    ptr = temp;
}

template<class T>
int arr<T>::pop()
{
    T max1 = ptr[0];
    T max2 = INT16_MIN;
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
            i--;
        }
    }
    return max2;

}

template<class T>
void arr<T>::nhap()
{
    cout << "Nhap so ptu: "; cin >> n;
    while (n <= 0)
    {
        cout << "Khong hop le, Nhap lai: ";
        cin >> n;
    }
    ptr = new T[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap [" << i << "]: ";
        cin >> ptr[i];
    }
}


int main()
{
    arr<int> a;
    
    a.nhap();
    a.xuat();
    cout << "Nhap vi tri can them: ";
    int them = 0;
    cin >> them;
    cout << "Gia tri: ";
    int value = 0;
    cin >> value;
    a.MyPush2(value, them);
    a.xuat();
    cout << "Xoa phan tu lon thu 2:" << endl;
    a.pop();
    a.xuat();
    cout << "Nhap 2 vi tri hoanvi:" << endl;
    int b = 0;
    int c = 0;
    cin >> b;
    cin >> c;
    a.MySwap(b, c);
    a.xuat();
    cout << "Xoa phan tu am:" << endl;
    a.MyRo();
    a.xuat();
    cout << "Dao nguoc mang:" << endl;
    a.MyRe();
    a.xuat();

    return 0;
}

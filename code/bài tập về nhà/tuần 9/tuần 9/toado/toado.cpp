#include <iostream>
#include<vector>
using namespace std;

template <class T>
class point
{
private:
    T x, y;
public:
    point()
    {
        x = 0;
        y = 0;
    }
    point(T a, T b)
    {
        x = a;
        y = b;
    }
    T getx()
    {
        return x;
    }

    T gety()
    {
        return y;
    }

    double distance(point p) {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
    bool operator >(point other)
    {
        return y > other.y;
    }
    bool operator <(point other)
    {
        return y < other.y;
    }
    friend ostream& operator<<(ostream& out, point s)
    {
        out << "(" << s.getx() << ";" << s.gety() << ")";
        return out;
    }

    friend istream& operator>>(istream& in, point& s)
    {
        cout << "x: "; in >> s.x;
        cout << "y: "; in >> s.y;
        return in;
    }
};


template<class T>
class arr {
private:
    point<T>* ptr;
    int n;
public:
    arr();
    void push(point<T> x);
    void MySwap(int a, int b);
    void nhap()
    {
        cout << "Nhap so luong: ";
        cin >> n;
        ptr = new point<T>[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap [" << i << "]: " << endl;
            cin >> ptr[i];
        }
    }
    void xuat()
    {
        cout << "=========" << n << "===========" << endl;
        for (int i = 0; i < n; i++)
            cout << ptr[i] << ' ';
    }
    point<T>& operator[](int i)
    {
        return ptr[i];
    }

    pair<point<T>, point<T>> Max_distance()
    {
        if (n < 2)
        {
            cout << "So phan tu khong du de tim: " << endl;
        }
        double min = INT16_MAX;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)continue;
                if (ptr[i].distance(ptr[j]) < min)
                {
                    min = ptr[i].distance(ptr[j]);
                    a = i;
                    b = j;
                }
            }
        }
        /*cout << "2 diem co khoang cach gan nhat:" << endl;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j)continue;

                if (ptr[i].distance(ptr[j]) == min)
                {
                    cout << ptr[i] << ";" << ptr[j] << "| Voi khoang cach: " << ptr[i].distance(ptr[j]) << endl;
                }
            }
        }*/
        pair<point<T>, point<T>> res = { ptr[a], ptr[b] };
        return res;
    }

    void sort_y()
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i; j < n; j++)
                if (ptr[i] > ptr[j])
                    MySwap(i, j);
    }
};




template<class T>
arr<T>::arr()
{
    n = 0;
    ptr = NULL;
}

template<class T>
void arr<T>::push(point<T> x)
{
    point<T>* temp = new point<T>[n + 1];
    temp[0] = x;
    for (int i = 0; i < n; i++)
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
    swap(ptr[a], ptr[b]);
}




int main()
{
    /*point<int> a = { 0,1 };*/
    arr<int> b;
    /*a = { 2,1 }; b.push(a);
    a = { 2,3 }; b.push(a);
    a = { 2,2 }; b.push(a);
    a = { 3,1 }; b.push(a);
    a = { 1,3 }; b.push(a);*/
    b.nhap();
    b.xuat();
    cout << endl;
    pair<point<int>, point<int>> c = b.Max_distance();
    cout << "2 diem co khong cach gan nhat:" << endl;
    cout << "{" << c.first << ";" << c.second << "} | Voi khoang cach: " << c.first.distance(c.second) << endl;
    cout << "Sap xep theo tung do tang dan: " << endl;

    b.sort_y();
    b.xuat();


    return 0;
}
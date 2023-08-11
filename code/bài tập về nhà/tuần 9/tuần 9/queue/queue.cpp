#include <iostream>
#include<string>
using namespace std;

template<class T>
class node {
private:
    string maso;
    T w;
public:
    node()
    {
        maso = "";
    }
    node(string ms, T ts)
    {
        maso = ms;
        w = ts;
    }

    T getw()
    {
        return w;
    }

    bool operator>(node other)
    {
        return w > other.w;
    }
    bool operator==(node other)
    {
        return w == other.w;
    }
    bool operator<(node other)
    {
        return w < other.w;
    }
    void nhap()
    {
        cout << "Ma: "; cin >> maso;
        cout << "Trong so: "; cin >> w;
    }
    friend ostream& operator<< (ostream & out, node xuat)
    {
        out << "(" << xuat.maso << ", " << xuat.w << ")";
        return out;
    }

    friend istream& operator >> (istream& out, node& xuat)
    {
        cout << "Ma: "; out >> xuat.maso;
        cout << "Trong so: "; out >> xuat.w;
        return out;
    }
};

template<class T>
class queue {
private:
    T* arr;
    int n;
public:
    queue()
    {
        n = 0;
        arr = NULL;
    }
    void push(T a)
    {
        cout << "them: " << a << endl;
        if (n == 0)
        {
            arr = new T[1];
            n++;
            arr[0] = a;
            return;
        }
        T* temp = new T[n + 1];
        int pos = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > a)
            {
                temp[i] = arr[i];
                pos++;
            }
            else
            {
                temp[i + 1] = arr[i];
            }
        }
        temp[pos] = a;
        cout << "pos[" << pos<< "]: " << temp[pos] << endl;
        delete[]arr;
        arr = temp;
        n++;
        
    }

    T pop()
    {
        if (n == 0)
        {
            cout << "Hang doi rong." << endl;
            exit(0);
        }
        if (n == 1)
        {
            T result = arr[0];
            delete[]arr;
            arr = NULL;
            n--;
            return result;
        }
        T result = arr[0];
        T* temp = new T[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            temp[i] = arr[i + 1];
        }
        delete[] arr;
        arr = temp;
        n--;
        return result;
    }
    void tong3Lon()
    {
        if (n < 3)
        {
            cout << "Khong du phan tu: " << endl;
            return;
        }
        
        T min1 = arr[0];
        T min2 = arr[0];
        T min3 = arr[0];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < min1)
                min1 = arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == min1)
                continue;
            if (arr[i] < min2)
                min2 = arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == min1 || arr[i] == min2)
                continue;
            if (arr[i] < min3)
                min2 = arr[i];
        }
        if (min3 == min1|| min2 == min1)
        {
            cout << "Khong du phan 3 phan tu co trong so nho nhat." << endl;
            return;
        }
        string random[] = { "A","B","C","D","E","F","G" };
        T newnode(random[rand() & 7], min1.getw() + min2.getw() + min3.getw());
        push(newnode);
    }
    void nhap()
    {
        cout << "Nhap so luong: ";
        cin >> n;
        arr = new T[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    void xuat()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
    }
};


int main()
{
    queue<node<int>> a;
    /*a.push({"A",3});
    a.push({"B",1});
    a.push({"C",5});
    a.push({"D",1});
    a.push({"E",6});
    a.push({"F",2});*/
    a.nhap();
    
    
    

    a.xuat();
    cout << endl;
    cout << "POP: " << a.pop() << endl;
    a.xuat();
    a.tong3Lon();
    a.xuat();
    cout << endl;
    a.tong3Lon();
    a.xuat();
    return 0;
}


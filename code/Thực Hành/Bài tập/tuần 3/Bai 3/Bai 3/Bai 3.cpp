#include <iostream>
#include"DonThuc.h"
#include"DaThuc.h"
using namespace std;
int main()
{
    DaThuc a;
    cin >> a;
    cout << "Da Thuc a: A(x) = " << a << endl;
    DaThuc b;
    cin >> b;
    cout << "Da Thuc b: B(x) = " << b << endl;

    cout << "------------------------------------------" << endl;
    DaThuc c = a + b;
    cout << "Ket qua tong (a+b): " << c << endl;

    cout << "------------------------------------------" << endl;
    c = a - b;
    cout << "Ket qua hieu (a-b): " << c << endl;

    cout << "------------------------------------------" << endl;
    c = a * b;
    cout << "Ket qua tich (a*b): " << c << endl;

    cout << "------------------------------------------" << endl;
    c = a / b;
    cout << "Ket qua thuong (a/b): " << c << endl;
    cout << "------------------------------------------" << endl;
    return 0;
}


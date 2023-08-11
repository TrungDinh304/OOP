#include <iostream>
#include"Array.h"
using namespace std;

int main()
{
    Array a;
    cin >> a;
    cout << a;
    cout << "Tong Cac Phan So Vua Nhap: " << a.SumOfArray() << endl;

    char ghi[] = "OUTPUT.txt";
    a.sort_tang();
    cout << "Da sap xep tang dan cho mang: " << endl;
    a.Write_File(ghi);

    a.Read_File(ghi);
    return 0;
}

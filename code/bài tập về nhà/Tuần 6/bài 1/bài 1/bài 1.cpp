#include <iostream>
#include"KhachHang.h";
#include"KH_ThanThiet.h"
using namespace std;


int main()
{
    char option = '\0';
    cout << "Chon loai khach (1. thuong, 2. than): ";
    cin >> option;
    if (option == '1')
    {
        KhachHang* a = new KH_ThanThiet;
        a->nhap();
        cout << "----------Khach Hang vua nhap:------------------" << endl;
        a->xuat();
        float tienmua = 0;
        cout << "Tien mua: ";
        cin >> tienmua;
        cout << "Tien Thanh Toan: " << a->TienThanhToan(tienmua) * 1.0 << endl;
    }
    else if (option == '2')
    {
        KhachHang* b = new KhachHang;

        b->nhap();
        cout << "----------Khach Hang vua nhap:------------------" << endl;
        b->xuat();
        float tienmua = 0;
        cout << "Tien mua: ";
        cin >> tienmua;
        cout << "Tien Thanh Toan: " << b->TienThanhToan(tienmua) * 1.0 << endl;
    }
    

    return 0;
}

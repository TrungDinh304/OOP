// Bài 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include"CongTy.h"

#include <iostream>

int main()
{
    CongTy a;

    a.Nhap();
    a.Xuat();

    system("pause");
    system("cls");
    a.Xuat();


    string buffer;
    cout << "Nhap ma so nhan vien muon tim: "; cin >> buffer;
    NhanVien* b = a.Tim_NV_ma(buffer);
    cout << "==========================" << endl;
    if (b == NULL)
    {
        cout << "Hien cong ty ko co nhan vien nao co ma nhan vien la: " << buffer << endl;
    }
    else
        b->Xuat();



    cout << "Nhap ho ten nhan vien can tim: "; cin >> buffer;
    NhanVien* c = a.Tim_NV_hoten(buffer);
    cout << "==========================" << endl;
    if (c == NULL)
    {
        cout << "Hien cong ty ko co nhan vien nao co ho ten la: " << buffer << endl;
    }
    else
        c->Xuat();



    cout << "============================" << endl;
    int sanh = 0;
    cout << "Nhap thang can dem so nhan vien sinh vao thang do: "; cin >> sanh;
    int sinhthang = a.count_NgSinh_thang(sanh);
    cout << "So nhan vien sinh vao thang 2: " << sinhthang << "Nhan Vien." << endl;


    system("pause");
    system("cls");
    a.insert_NV();
    a.Xuat();



    system("pause");
    system("cls");
    a.Xuat();
    string remov;
    cout << "Nhap ma nhan vien ban muon xoa khoi danh sach: ";
    cin >> remov;
    a.remove_NV(remov);
    cout << "+========danh sach sau khi xoa===========+" << endl;
    a.Xuat();



    system("pause");
    system("cls");

    cout << "Nhan vien co luong lon nhat: " << endl;
    NhanVien* lon = a.NV_luongCaoNhat();
    if (lon == NULL)
        cout << "Cong ty chua co nhan vien." << endl;
    else
        lon->Xuat();
    cout << "-----------------------------------------" << endl;
    cout << "Luong trung binh cua cong ty: " << a.ave_luong() << endl;
    cout << "Tong luong cua tat ca nhan vien cua cong ty: " << a.tongLuong() << endl;

    cout << "------------------------------------------" << endl;


    a.write_file_lower();
    cout << "Da ghi ra file emp_LowerAvgSalary.dat cac nhan vien co luong thap hon luong trung binh cua cong ty." << endl;
    return 0;
}

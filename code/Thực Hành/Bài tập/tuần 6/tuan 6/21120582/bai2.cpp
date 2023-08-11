#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"CongTy.h"
using namespace std;



int main()
{
    CongTy a;
    char filename[] = "ds_NhanVien.dat";
    a.readfile(filename);
    NhanVien* b = a.NV_LuongCaoNhat();
    cout << "=====NVLuong cao nhat============" << endl;
    b->Xuat();
    char buffer[] = "2112";
    b = a.tim_NV_ma(buffer);
    cout << "============Nhan vien co ma 2112=========" << endl;

    b->Xuat();

    char buffer1[] = "Min Min";
    b = a.tim_NV_ten(buffer1);
    cout << "============Nhan vien co ho ten: Min Min=========" << endl;

    b->Xuat();

    cout << "So Nguoi sco sinh nhat vao thang 1: " << a.So_NV_sinh_thang(1) << endl;
    /*NhanVien* c = NULL;
    char opt = '0';
    cout << "nhap loai nhan vien ban muon them: 1. Cong Nhat; 2. San Xuat." << endl;
    cin >> opt;
    if (opt == '1')
    {
        c = new NVCongNhat;
        c->Nhap();
    }
    else if (opt == '2')
    {
        c = new NVSanXuat;
        c->Nhap();
    }
    a.them_N_capnhat(c);
    a.xuat();
    cout << "===========Xoa Nhan vien co ma nhap vao=============" << endl;
    cin >> buffer;
    a.Xoa_N_capnhat(buffer);
    a.xuat();*/
    a.xuat_file_luongthap();
    
    return 0;
}


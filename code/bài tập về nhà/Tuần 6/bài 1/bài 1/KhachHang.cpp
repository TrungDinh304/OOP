
#include "KhachHang.h"


KhachHang::KhachHang()
{
	cmt = "";
	hoten = "";
	date a(0, 0, 0);
	ngaydk = a;
	diemTL = 0;
}

KhachHang::KhachHang(string cmt_init, string hoten_init, date ngaydk_init, float diemTL_init)
{
	cmt = cmt_init;
	hoten = hoten_init;
	ngaydk = ngaydk_init;
	diemTL = diemTL_init;
}


void KhachHang::nhap()
{
	cout << "Nhap chung minh thu: ";
	cin >> cmt;
	cin.ignore();
	cout << "Nhap ho ten: ";
	getline(cin, hoten);
	cout << "Nhap Ngay dang ky: " << endl;
	cin >> ngaydk;
	cout << "Nhap diem tich luy: ";
	cin >> diemTL;
}

void KhachHang::xuat()
{
	cout << "Chung Minh Thu: " << cmt << endl;
	cout << "Ho Ten: " << hoten << endl;
	cout << "Ngay Dang Ky: " << ngaydk << endl;
	cout << "Diem tich luy: " << diemTL << endl;
}


float KhachHang::TienThanhToan(float tienmua)
{
	bool giam = (diemTL > 1000 || tienmua > 5000000);
	return tienmua - giam * 0.02 * tienmua;
}
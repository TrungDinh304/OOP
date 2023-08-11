#include "KH_ThanThiet.h"



KH_ThanThiet::KH_ThanThiet():KhachHang()
{
	capdo = 0;
}


KH_ThanThiet::KH_ThanThiet(string cmt_init, string hoten_init, date ngaydk_init, float diemTL_init, int capdo_init):KhachHang(cmt_init,hoten_init,ngaydk_init,diemTL_init)
{
	capdo = capdo_init;
}

void KH_ThanThiet::nhap()
{
	KhachHang::nhap();
	cout << "Nhap cap do than thiet: ";
	cin >> capdo;
}


void KH_ThanThiet::xuat()
{
	KhachHang::xuat();
	cout << "Cap do than thiet: " << capdo << endl;
}

float KH_ThanThiet::TienThanhToan(float tienmua)
{
	float giam = 0;
	if (capdo == 1)
		giam = 0.05;
	else if (capdo == 2)
		giam = 0.07;
	else if (capdo == 3)
		giam = 0.1;
	return tienmua * (1.0 - giam);
}
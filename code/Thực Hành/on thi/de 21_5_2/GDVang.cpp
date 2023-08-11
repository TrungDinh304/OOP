#include "GDVang.h"

GDVang::GDVang():GiaoDich()
{
	loaivang = '\0';
}

GDVang::GDVang(char* ma, date ngay, float dgia, int sl, char loai): GiaoDich(ma,ngay,dgia,sl)
{
	loaivang = loai;
}

float GDVang::thanhtien()
{
	return dongia * soluong;
}

void GDVang::nhap()
{
	GiaoDich::nhap();
	cout << "Nhap loai vang: ";
	cin >> loaivang;
}

void GDVang::xuat()
{
	GiaoDich::xuat();
	cout << "Loai Vang: " << loaivang << endl;
}

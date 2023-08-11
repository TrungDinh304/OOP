#include "GDTienTe.h"

GDTienTe::GDTienTe():GiaoDich()
{
	tigia = 1;
	LoaiTienTe = new char[10] {};
}

GDTienTe::GDTienTe(char* ma, date ngay, float dgia, int sl, float tg, char* loaitt):GiaoDich(ma,ngay,dgia,sl)
{
	tigia = tg;
	LoaiTienTe = new char[10];
	strcpy(LoaiTienTe, loaitt);
}

void GDTienTe::nhap()
{
	GiaoDich::nhap();
	cout << "Nhap ti gia: ";
	cin >> tigia;
	LoaiTienTe = new char[10];
	cout << "Nhap loai tien te (vnd, usd, euro): ";
	cin >> LoaiTienTe;
}

void GDTienTe::xuat()
{
	GiaoDich::xuat();
	cout << "Ti gia: " << tigia << endl;
	cout << "Loai tien te: " << LoaiTienTe << endl;
}

float GDTienTe::thanhtien()
{
	if (strcmp(LoaiTienTe, "vnd") == 0)
		return dongia * soluong;
	else
		return dongia * soluong * tigia;
}

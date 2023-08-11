#include "GiaoDich.h"

GiaoDich::GiaoDich()
{
	maGD = new char[30] {};
	ngayGD = { 0,0,0 };
	dongia = 0;
	soluong = 0;
}

GiaoDich::GiaoDich(char* ma, date ngay, float dgia, int sl)
{
	maGD = new char[30];
	strcpy(maGD, ma);
	ngayGD = ngay;
	dongia = dgia;
	soluong = sl;
}


GiaoDich& GiaoDich::operator=(GiaoDich other)
{
	maGD = new char[30];
	strcpy(maGD, other.maGD);
	ngayGD = other.ngayGD;
	dongia = other.dongia;
	soluong = other.soluong;
}

void GiaoDich::nhap()
{
	maGD = new char[30];
	cout << "Nhap ma giao dich: ";
	cin >> maGD;
	cout << "Nhap ngay giao dich: ";
	cin >> ngayGD;
	cout << "Nhap don gia: ";
	cin >> dongia;
	cout << "Nhap so luong: ";
	cin >> soluong;
}

void GiaoDich::xuat() const
{
	cout << "Ma giao dich: " << maGD << endl;
	cout << "Ngay giao dich: " << ngayGD << endl;
	cout << "Don gia: " << dongia << endl;
	cout << "So luong: " << soluong << endl;
}

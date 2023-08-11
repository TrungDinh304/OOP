#define _CRT_SECURE_NO_WARNINGS
#include "NVSanXuat.h"

NVSanXuat::NVSanXuat():NhanVien()
{
	sosanpham = 0;
}

NVSanXuat::NVSanXuat(const NVSanXuat& s): NhanVien(s)
{
	sosanpham = s.sosanpham;
}

NVSanXuat::NVSanXuat(char* ma, char* ht, date ns, char* dc, int ssp):NhanVien(ma,ht,ns,dc)
{
	sosanpham = ssp;
}

int NVSanXuat::getSoSP()
{
	return sosanpham;
}

void NVSanXuat::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap so san pham: ";
	cin >> sosanpham;
	while (sosanpham > 15 || sosanpham < 10)
	{
		cout << "Xin vui long nhap lai (Du lieu nhap khong hop le): ";
		cin >> sosanpham;
	}
}

void NVSanXuat::Xuat()
{
	NhanVien::Xuat();
	cout << "\tSo san pham: " << sosanpham << endl;
}

float NVSanXuat::tinhluong()
{
	luong = sosanpham * 50000.0;
	return luong;
}

NVSanXuat& NVSanXuat::operator=(const NVSanXuat& s)
{
	NhanVien::operator=(s);
	sosanpham = s.sosanpham;
	return *this;
}

ostream& NVSanXuat::xuatfile(ostream& out)
{
	NhanVien::xuatfile(out);
	out << sosanpham << endl;
	return out;
}


#define _CRT_SECURE_NO_WARNINGS
#include "NhanVien.h"

NhanVien::NhanVien()
{
	maNV = new char[5] {};
	hoten = new char[30] {};
	ngaysinh = { 0,0,0 };
	diachi = new char[50] {};
	luong = 0;
}

NhanVien::NhanVien(const NhanVien& s)
{
	maNV = new char[5];
	hoten = new char[30];
	diachi = new char[50];
	strcpy(maNV, s.maNV);
	strcpy(hoten, s.hoten);
	strcpy(diachi, s.diachi);
	ngaysinh = s.ngaysinh;
	luong = s.luong;
}

NhanVien::NhanVien(char* ma, char* _hoten, date ngs, char* dchi)
{
	maNV = new char[5] {};
	strcpy(maNV, ma);
	hoten = new char[30] {};
	strcpy(hoten, _hoten);
	ngaysinh = ngs;
	diachi = new char[50] {};
	strcpy(diachi, dchi);
	luong = 0;
}

char* NhanVien::getMa()
{
	return maNV;
}

char* NhanVien::getHoten()
{
	return hoten;
}

date NhanVien::getNgaysinh()
{
	return ngaysinh;
}

char* NhanVien::getDiachi()
{
	return diachi;
}

float NhanVien::getLuong()
{
	return luong;
}

void NhanVien::Nhap()
{
	cout << "Nhap Ma Nhan Vien: ";
	cin >> maNV;
	cout << "Nhap ho ten nhan vien: ";
	cin.ignore();
	cin.getline(hoten, 30, '\n');
	cout << "Nhap ngay sinh: \n";
	cin >> ngaysinh;
	cout << "Nhap dia chi: ";
	cin.ignore();
	cin.getline(diachi, 50, '\n');
}

void NhanVien::Xuat()
{
	cout << "\tMa Nhan Vien: " << maNV << endl;
	cout << "\tHo ten: " << hoten << endl;
	cout << "\tNgay sinh: " << ngaysinh << endl;
	cout << "\tDia chi: " << diachi << endl;
}

NhanVien& NhanVien::operator=(const NhanVien& s)
{
	if (maNV != NULL)
		delete[]maNV;
	if (hoten != NULL)
		delete[] hoten;
	if (diachi != NULL)
		delete[] diachi;

	maNV = new char[5];
	hoten = new char[30];
	diachi = new char[50];
	strcpy(maNV, s.maNV);
	strcpy(hoten, s.hoten);
	strcpy(diachi, s.diachi);
	ngaysinh = s.ngaysinh;
	luong = s.luong;
	return *this;
}

ostream& NhanVien::xuatfile(ostream& out)
{
	out << maNV << endl;
	out << hoten << endl;
	out << ngaysinh << endl;
	out << diachi << endl;
	return out;
}

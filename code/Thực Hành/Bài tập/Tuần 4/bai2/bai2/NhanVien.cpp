#include "NhanVien.h"
NhanVien::NhanVien()
{
	maNV = "";
	hoten = "";
	date a(0, 0, 0);
	ngaysinh = a;
	diachi = "";
	luong = 0;
}

NhanVien::NhanVien(string maNV_init, string hoten_init, date ngaysinh_init, string diachi_init)
{
	maNV = maNV_init;
	hoten = hoten_init;
	ngaysinh = ngaysinh_init;
	diachi = diachi_init;
}
string NhanVien::getMa()
{
	return maNV;
}


string NhanVien::getHoten()
{
	return hoten;
}


date NhanVien::getNgaysinh()
{
	return ngaysinh;
}

string NhanVien::getDiachi()
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
	getline(cin, hoten);
	cout << "Nhap ngay sinh: \n";
	cin >> ngaysinh;
	cout << "Nhap dia chi: ";
	cin.ignore();
	getline(cin, diachi);
}

void NhanVien::Xuat()
{
	cout << "Ma Nhan Vien: " << maNV << endl;
	cout << "Ho ten: " << hoten << endl;
	cout << "Ngay sinh: " << ngaysinh << endl;
	cout << "Dia chi: " << diachi << endl;
}
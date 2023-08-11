#include "NVCongNhat.h"
NVCongNhat::NVCongNhat() :NhanVien()
{
	songay = 0;
}


NVCongNhat::NVCongNhat(string maNV_init, string hoten_init, date ngaysinh_init, string diachi_init, int songay_init)
	:NhanVien(maNV_init, hoten_init, ngaysinh_init, diachi_init)
{
	songay = songay_init;
}


int NVCongNhat::getSongay()
{
	return songay;
}

void NVCongNhat::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap so ngay: ";
	cin >> songay;
}

void NVCongNhat::Xuat()
{
	NhanVien::Xuat();
	cout << "So ngay cong: " << songay << endl;
}


float NVCongNhat::tinhluong()
{
	luong = songay * 300000;
	return songay * 300000;
}


NVCongNhat& NVCongNhat::operator=(const NVCongNhat& source)
{
	maNV = source.maNV;
	hoten = source.hoten;
	ngaysinh = source.ngaysinh;
	diachi = source.diachi;
	luong = source.luong;
	songay = source.songay;
	return *this;
}

ostream& operator <<(ostream& out, const NVCongNhat& xuat)
{
	out << xuat.maNV << endl;
	out << xuat.hoten << endl;
	out << xuat.ngaysinh << endl;
	out << xuat.diachi << endl;
	out << xuat.songay << endl;
	return out;
}
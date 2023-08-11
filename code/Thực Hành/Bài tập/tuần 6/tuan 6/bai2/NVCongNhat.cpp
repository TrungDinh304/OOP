#define _CRT_SECURE_NO_WARNINGS
#include "NVCongNhat.h"

NVCongNhat::NVCongNhat():NhanVien()
{
	luong = 0;
}

NVCongNhat::NVCongNhat(const NVCongNhat& s):NhanVien(s)
{
	songay = s.songay;
}

NVCongNhat::NVCongNhat(char* ma, char* _hoten, date ns, char* dc, int sng): NhanVien(ma,_hoten,ns,dc)
{
	songay = sng;
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
	while (songay > 26 || songay < 22)
	{
		cout << "Xin vui long nhap lai (Du lieu nhap khong hop le): ";
		cin >> songay;
	}
}

void NVCongNhat::Xuat()
{
	NhanVien::Xuat();
	cout << "\tSo ngay cong: " << songay << endl;
}

float NVCongNhat::tinhluong()
{
	luong = songay * 500000.0;
	return luong;
}

NVCongNhat& NVCongNhat::operator=(const NVCongNhat& s)
{
	NhanVien::operator = (s);
	songay = s.songay;
	return *this;
}

ostream& NVCongNhat::xuatfile(ostream& out)
{
	NhanVien::xuatfile(out);
	out << songay << endl;
	return out;
}



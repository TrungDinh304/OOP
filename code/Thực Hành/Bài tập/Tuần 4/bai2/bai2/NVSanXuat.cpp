#include "NVSanXuat.h"


NVSanXuat::NVSanXuat() :NhanVien()
{
	sosanpham = 0;
}

NVSanXuat::NVSanXuat(string maNV_init, string hoten_init, date ngaysinh_init, string diachi_init, int sosanpham_init)
	:NhanVien(maNV_init, hoten_init, ngaysinh_init, diachi_init)
{
	sosanpham = sosanpham_init;
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
}


void NVSanXuat::Xuat()
{
	NhanVien::Xuat();
	cout << "So san pham: " << sosanpham << endl;
}



float NVSanXuat::tinhluong()
{
	luong = sosanpham * 20000;
	return sosanpham * 20000;
}

ostream& operator<<(ostream& out, const NVSanXuat& xuat)
{
	out << xuat.maNV << endl;
	out << xuat.hoten << endl;
	out << xuat.ngaysinh << endl;
	out << xuat.diachi << endl;
	out << xuat.sosanpham << endl;
	return out;
}


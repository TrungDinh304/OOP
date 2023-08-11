#pragma once
#include"NhanVien.h"
class NVSanXuat : public NhanVien
{
private:
	int sosanpham;
	bool hople();
public:
	NVSanXuat();
	NVSanXuat(const NVSanXuat& s);
	NVSanXuat(char*, char*, date, bool, char*, int);
	

	int getSoSP();

	void Nhap();
	void Xuat();
	float tinhluong();

	NVSanXuat& operator = (const NVSanXuat&);
	ostream& xuatfile(ostream& out);
	ostream& write_binary_file(ostream& out);
	istream& read_binary_file(istream& in);
};



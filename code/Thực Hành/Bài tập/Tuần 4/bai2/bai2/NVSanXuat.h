#pragma once
#include"NhanVien.h"
class NVSanXuat : public NhanVien
{
private:
	int sosanpham;
public:
	NVSanXuat();
	NVSanXuat(string, string, date, string, int);


	int getSoSP();

	void Nhap();
	void Xuat();
	float tinhluong();

	friend ostream& operator<<(ostream&, const NVSanXuat&);

};


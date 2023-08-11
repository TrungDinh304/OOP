#pragma once
#include"NhanVien.h"
class NVCongNhat : public NhanVien
{
private:
	int songay;
public:
	NVCongNhat();
	NVCongNhat(const NVCongNhat& s);
	NVCongNhat(char*, char*, date, char*, int);


	int getSongay();
	void Nhap();
	void Xuat();
	float tinhluong();

	NVCongNhat& operator = (const NVCongNhat&);
	ostream& xuatfile(ostream& out);
};


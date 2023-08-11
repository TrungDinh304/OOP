#pragma once
#include"NhanVien.h"
class NVCongNhat : public NhanVien
{
private:
	int songay;
public:
	NVCongNhat();
	NVCongNhat(string, string, date, string, int);


	int getSongay();
	void Nhap();
	void Xuat();
	float tinhluong();

	NVCongNhat& operator = (const NVCongNhat&);

	friend ostream& operator<<(ostream&, const NVCongNhat&);
};


#pragma once
#include "KhachHang.h"
class KH_ThanThiet : public KhachHang
{
private:
	int capdo;
public:
	KH_ThanThiet();
	KH_ThanThiet(string, string, date, float, int);
	void xuat();
	void nhap();
	float TienThanhToan(float);
};


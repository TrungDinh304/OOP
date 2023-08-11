#pragma once
#include"GiaoDich.h"
class GDVang: public GiaoDich
{
private:
	char loaivang;
public:
	GDVang();
	GDVang(char* ma, date ngay, float dgia, int sl, char loai);
	float thanhtien();
	void nhap();
	void xuat();
};


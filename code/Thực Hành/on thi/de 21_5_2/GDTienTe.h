#pragma once
#include"GiaoDich.h"
class GDTienTe: public GiaoDich
{
private:
	float tigia;
	char* LoaiTienTe;
public:
	GDTienTe();
	GDTienTe(char* ma, date ngay, float dgia, int sl, float tg, char*loaitt);
	void nhap();
	void xuat();
	char* getLoaitt()
	{
		return LoaiTienTe;
	}
	float thanhtien();
};


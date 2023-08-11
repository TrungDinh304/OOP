#pragma once
#include"date.h"
#include<iostream>
using namespace std;
class GiaoDich
{
protected:
	char* maGD;
	date ngayGD;
	float dongia;
	int soluong;
public:
	GiaoDich();
	GiaoDich(char* ma, date ngay, float dgia, int sl);
	virtual float thanhtien() = 0;
	date getNgay()
	{
		return ngayGD;
	}
	GiaoDich& operator = (GiaoDich other);
	virtual void nhap();
	virtual void xuat() const;
};


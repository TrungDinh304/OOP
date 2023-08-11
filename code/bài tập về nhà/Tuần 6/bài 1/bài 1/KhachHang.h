#pragma once
#include<string>
#include"date.h"
#include<iostream>
using namespace std;
class KhachHang
{
protected:
	string cmt;
	string hoten;
	date ngaydk;
	float diemTL;
public:
	KhachHang();
	KhachHang(string, string, date, float);

	virtual void nhap();
	virtual void xuat();
	virtual float TienThanhToan(float);
};


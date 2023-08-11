#pragma once
#include<iostream>
#include"date.h"
#include<string>
using namespace std;
class NhanVien
{
protected:
	string maNV;
	string hoten;
	date ngaysinh;
	string diachi;
	float luong;
public:
	NhanVien();
	NhanVien(string, string, date, string);

	string getMa();
	string getHoten();
	date getNgaysinh();
	string getDiachi();


	virtual void Nhap();
	virtual void Xuat();
	virtual float tinhluong() = 0;

};


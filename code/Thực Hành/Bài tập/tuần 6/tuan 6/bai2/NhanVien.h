#pragma once
#include<iostream>
#include"date.h"
using namespace std;
class NhanVien
{
protected:
	char* maNV;
	char* hoten;
	date ngaysinh;
	char* diachi;
	float luong;
public:
	NhanVien();
	NhanVien(const NhanVien& ini);
	NhanVien(char*, char*, date, char*);

	char* getMa();
	char* getHoten();
	date getNgaysinh();
	char* getDiachi();
	float getLuong();


	virtual void Nhap();
	virtual void Xuat();
	virtual float tinhluong() = 0;
	NhanVien& operator=(const NhanVien&);
	virtual ostream& xuatfile(ostream& out);
};


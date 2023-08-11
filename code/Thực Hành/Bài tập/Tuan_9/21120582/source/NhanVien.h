#pragma once
#include<iostream>
#include"date.h"
#include"MyException.h"
using namespace std;
class NhanVien
{
private:
	bool hople();
	bool mahople();
protected:
	char* maNV;
	char* hoten;
	date ngaysinh;
	bool gioitinh;//1: nam; 0: nữ
	char* diachi;
	float luong;
public:
	NhanVien();
	NhanVien(const NhanVien& ini);
	NhanVien(char*, char*, date, bool, char*);
	~NhanVien();

	char* getMa();
	char* getHoten();
	date getNgaysinh();
	bool getGioitinh();
	char* getDiachi();
	float getLuong();


	virtual void Nhap();
	virtual void Xuat();
	virtual float tinhluong() = 0;
	NhanVien& operator=(const NhanVien&);
	virtual ostream& xuatfile(ostream& out);
};


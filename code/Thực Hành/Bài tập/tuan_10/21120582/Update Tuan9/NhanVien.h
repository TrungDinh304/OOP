#pragma once
#include<iostream>
#include"date.h"
#include"MyException.h"
#define daima 6
#define daiten 30
#define daidiachi 50

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
	virtual ostream& write_binary_file(ostream& out);
	virtual istream& read_binary_file(istream& in);
};


#pragma once
#include<iostream>
#include<string.h>
#include"date.h"
using namespace std;
class SinhVien
{
private:
	char* hoten;
	char* maso;
	date ngaysinh;
	float bt, gk, ck, tb;
public:
	SinhVien();
	SinhVien(char*, char*, date, float, float, float);
	SinhVien(const SinhVien&);
	~SinhVien();
	char* getHoten();
	char* getMaso();
	date getNgaysinh();
	float getBt();
	float getGk();
	float getCk();
	float getTb();
	void setHoten(char*);
	void setMaso(char*);
	void setNgaySinh(date ngay);
	void setBt(float);
	void setGk(float);
	void setCk(float);
	void setTb(float);
	char* xeploai();
	SinhVien& operator=(const SinhVien&);

	//biến bool cho biết có in xep loai hay không
	void xuatSinhVien(bool);

	bool operator>(const SinhVien&)const;//so sánh điểm trung bình
	bool operator<(const SinhVien&)const;//so sánh điểm trung bình
};


#pragma once
#include<iostream>
#include<string>
#include"CMyDate.h"


using namespace std;

class CEbook
{
private:
	string ISBN;
	string tensach;
	string tacgia;
	CMyDate ngsx;
	string theloai;
	string nhasx;
	double gia;
public:
	CEbook();
	CEbook(string, string, string, CMyDate, string, string, double);
	CEbook(const CEbook&);
	CMyDate getNgaySX();
	string getMa();
	double getGia();

	bool operator >(const CEbook&)const;
	bool operator >=(const CEbook&)const;
	bool operator <(const CEbook&)const;
	bool operator <=(const CEbook&)const;
	void nhap();
	void xuat()const;
	bool tontai();
	friend ostream& operator<<(ostream&, const CEbook&);
	void hoanvi(CEbook&);

};


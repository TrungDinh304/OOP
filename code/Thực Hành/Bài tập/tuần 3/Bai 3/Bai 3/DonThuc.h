#pragma once
#include<math.h>
#include<iostream>
#include<string.h>
#include<sstream>

using namespace std;
class DonThuc
{
private:
	float heso;
	int mu;
public:
	DonThuc();
	DonThuc(float, int);
	float getHeSo();
	int getMu();
	void setHeSo(float);
	void setMu(int);
	float TinhGiaTri(float);
	DonThuc operator+(const DonThuc&)const;
	DonThuc operator-(const DonThuc&)const;
	DonThuc operator*(const DonThuc&)const;
	DonThuc operator/(const DonThuc&)const;

	friend ostream& operator << (ostream&, const DonThuc&);
	//nhập đơn thức dưới dạng <hệ số>x^<mũ>
	friend istream& operator>>(istream&, DonThuc&);
};


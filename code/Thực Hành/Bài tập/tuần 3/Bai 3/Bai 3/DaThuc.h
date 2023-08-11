#pragma once
#include<iostream>
#include"DonThuc.h"
#include<string.h>
#include<sstream>
#include<fstream>
using namespace std;



class DaThuc
{
private:
	int size;
	DonThuc* pArr;
public:
	DaThuc();
	DaThuc(int);
	~DaThuc();
	int getSize();
	DonThuc* getPArr();

	double Value(float);

	DaThuc operator+(const DaThuc&)const;
	DaThuc operator-(const DaThuc&)const;
	DaThuc operator*(const DaThuc&)const;
	DaThuc operator/(const DaThuc&)const;
	DaThuc& operator=(const DaThuc&);
	void sapxep();
	friend istream& operator>>(istream&, DaThuc&);
	friend ostream& operator<<(ostream&, const DaThuc&);
};


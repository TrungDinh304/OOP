#pragma once
#include<string>
#include<iostream>
using namespace std;

class Ghe
{
protected:
	string ma;
	bool trong;
	int gia;
public:
	Ghe(string m,bool t,int gi)
	{
		ma = m;
		trong = t;
		gia = gi;
	}
	virtual void nhap()
	{
		cout << "Ma: "; cin >> ma;
		cout << "trong: "; cin >> trong;
	}

	virtual void xuat()
	{
		if (!trong)
		{
			cout << "X";
			return;
		}
		cout << ma;
	}
	string getMa()
	{
		return ma;
	}
	int getGia()
	{
		return gia;
	}
	bool getTrong()
	{
		return trong;
	}
	void setTrong(bool t)
	{
		trong = t;
	}
};


//class T:public Ghe
//{
//private:
//	int gia;
//public:
//	void nhap()
//	{
//		Ghe::nhap();
//	}
//	void setGia(int g)
//	{
//		gia = g;
//	}
//	int getGia()
//	{
//		return gia;
//	}
//
//};
//
//class V:public Ghe
//{
//private:
//	int gia;
//public:
//	void nhap()
//	{
//		Ghe::nhap();
//	}
//	void setGia(int g)
//	{
//		gia = g;
//	}
//	int getGia()
//	{
//		return gia;
//	}
//};

#pragma once
#include<iostream>
#include"date.h"

using namespace std;
class DocGia
{
protected:
	string ma;
	string hoten;
	string gioitinh;
	date ngaysinh;
	int sosachmuon;
	string cmnd;
public:
	DocGia(string m, string ht, string gt, date ns, int sm, string cm)
	{
		ma = m;
		hoten = ht;
		gioitinh = gt;
		ngaysinh = ns;
		sosachmuon = sm;
		cmnd = cm;
	}
	virtual float tinhtien() {
		return 0;
	}

	int getNamSinh()
	{
		return ngaysinh.getnam();
	}

	string getGT()
	{
		return gioitinh;
	}

	string getma()
	{
		return ma;
	}
	string gethote()
	{
		return hoten;
	}
	date getNgayS()
	{
		return ngaysinh;
	}
	string getCM()
	{
		return cmnd;
	}

};


class treem : public DocGia
{
private:
	string cmnd;
public:
	treem(string m, string ht, string gt, date ns, int s, string cm) : DocGia(m, ht, gt, ns, s, cm)
	{

	}
	float tinhtien()
	{
		return 2000 * sosachmuon;
	}

};

class nguoilon :public DocGia
{
private:

public:
	nguoilon(string m, string ht, string gt, date ns, int s, string cm) : DocGia(m, ht, gt, ns, s, cm)
	{

	}
	float tinhtien()
	{
		return 5000 * sosachmuon;
	}
};

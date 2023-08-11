#define _CRT_SECURE_NO_WARNINGS
#include "SinhVien.h"


SinhVien::SinhVien()
{
	hoten = new char[30] {};
	maso = new char[30] {};
	strcpy(hoten, "");
	strcpy(maso, "");
	date ngay;
	ngaysinh = ngay;
	bt = gk = ck = 0;
	tb = bt * 0.25 + gk * 0.25 + ck * 0.5;
}

SinhVien::SinhVien(char* hoten_init, char* maso_init, date ngaysinh_init, float bt_init, float gk_init, float ck_init)
{
	hoten = new char[30] {};
	maso = new char[30] {};
	strcpy(hoten, hoten_init);
	strcpy(maso, maso_init);
	ngaysinh = ngaysinh_init;
	bt = bt_init;
	gk = gk_init;
	ck = ck_init;
	tb = bt * 0.25 + gk * 0.25 + ck * 0.5;
}

SinhVien::SinhVien(const SinhVien& init)
{
	hoten = new char[30];
	maso = new char[30];
	strcpy(hoten, init.hoten);
	strcpy(maso, init.maso);
	ngaysinh = init.ngaysinh;
	bt = init.bt;
	gk = init.gk;
	ck = init.ck;
	tb = bt * 0.25 + gk * 0.25 + ck * 0.5;
}

SinhVien::~SinhVien() {
	delete [] hoten;
	delete [] maso;
}

char* SinhVien::getHoten()
{
	return hoten;
}

char* SinhVien::getMaso()
{
	return maso;
}

date SinhVien::getNgaysinh()
{
	return ngaysinh;
}

float SinhVien::getBt()
{
	return bt;
}

float SinhVien::getGk()
{
	return gk;
}

float SinhVien::getCk()
{
	return ck;
}

float SinhVien::getTb()
{
	return tb;
}

void SinhVien::setHoten(char* alter)
{
	strcpy(hoten, alter);
}

void SinhVien::setMaso(char* alter)
{
	strcpy(maso, alter);
}

void SinhVien::setNgaySinh(date alter)
{
	ngaysinh = alter;
}

void SinhVien::setBt(float alter)
{
	bt = alter;
}
void SinhVien::setGk(float alter)
{
	gk = alter;
}

void SinhVien::setCk(float alter)
{
	ck = alter;
}

void SinhVien::setTb(float alter)
{
	tb = alter;
}

char* SinhVien::xeploai()
{
	char* loai = new char[15];
	if (tb < 5)
		strcpy(loai, "Yeu");
	if (tb < 6.5)
		strcpy(loai, "Trung Binh");
	if (tb < 8)
		strcpy(loai, "Kha");
	if (tb < 9)
		strcpy(loai, "Gioi");
	else
		strcpy(loai, "Xuat Sac");
	return loai;
}

SinhVien& SinhVien::operator=(const SinhVien& other)
{
	strcpy(hoten, other.hoten);
	strcpy(maso, other.maso);
	ngaysinh = other.ngaysinh;
	bt = other.bt;
	gk = other.gk;
	ck = other.ck;
	tb = other.tb;
	return *this;
}

void SinhVien::xuatSinhVien(bool inxeploai)
{
	char* ngaysinh_cstring = ngaysinh.toString();
	cout << hoten << '|' << maso << '|' << ngaysinh_cstring << '|'
		<< bt << '|' << gk << '|' << ck << '|' << tb;
	if (inxeploai)
		cout << xeploai();
	
	cout << endl;

	delete[]ngaysinh_cstring;
}


bool SinhVien::operator>(const SinhVien& other)const
{
	return tb > other.tb;
}

bool SinhVien::operator<(const SinhVien& other)const
{
	return tb < other.tb;
}

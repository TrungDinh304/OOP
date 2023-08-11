#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define Maxma 10
#define MaxTen 40
#define Maxtheloai 40
#define MaxnhaSX 40


using namespace std;
class Phim
{
private:
	char* maso = NULL;
	char* tenPhim = NULL;
	char* theloai = NULL;
	char* NhaSanXuat = NULL;
	int namSX;
	float xepHang;
	bool checkMa();
public:
	Phim();
	Phim(char* ms, char* ten, char* tl, char* nhasx, int namsx, int xl);
	Phim(Phim& source);

	Phim& operator=(Phim& source);

	bool operator>(Phim& other);
	bool operator<(Phim& other);

	char* getMaso();
	char* getTen();
	char* getTheLoai();
	char* getNhaSanXuat();
	int getNamSX();
	float getXepHang();
	friend ostream& operator<<(ostream& out, Phim src);
	friend istream& operator>>(istream& in, Phim& dst);
	

	ostream& write_bin_file(ostream& out);
	istream& read_bin_file(istream& in);

};


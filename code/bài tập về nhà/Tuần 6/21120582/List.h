#pragma once
#include"CEbook.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;
class List
{
private:
	vector<CEbook> l;

public:
	void nhap();
	void xuat()const;
	void docfile();
	void writefile(string);
	void sapxep_nsx_tang();
	void sapxep_giagiam();
	void GhiFileGia(string);
};


#pragma once

#include"SinhVien.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include"Node.h"
using namespace std;


class DanhSach
{
private:
	SinhVien* List;
	int n;
public:
	DanhSach();
	DanhSach(int);
	~DanhSach();
	int getN()const;
	SinhVien* getList()const;

	void read_File(char*);


	//biến bool cho biết có in xep loai hay không
	void write_File(char* filename, bool)const;

	float ave_tb();
	void SV_lower_tblop(char*);
	void insert_N_updateF(const SinhVien&, char*);
	
	void W_file_cur_bod_sv(char*, bool);
	

};


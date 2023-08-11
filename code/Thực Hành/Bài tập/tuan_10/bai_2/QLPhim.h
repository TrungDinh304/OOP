#pragma once
#include<vector>
#include"Phim.h"
#include<fstream>
#include<iostream>

using namespace std;
class QLPhim
{
private:
	vector<Phim*> DS;
public:
	QLPhim();
	QLPhim(QLPhim& source);
	~QLPhim();
	void print();
	void input();
	void write_bin_file(char* filename);
	void read_bin_file(char* filename);
	void remove_phim_NSX(char* NhaSX);
	void insert_Phim(Phim& add);

};


#pragma once
#include <iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include"PhanSo.h"
using namespace std;


class Array
{
private: 
	PhanSo* pArr;
	int size;
public:
	Array();
	Array(int);
	~Array();
	PhanSo SumOfArray();
	void sort_tang();
	void Write_File(char*);
	void Read_File(char*);


	friend istream& operator>>(istream&, Array&);
	friend ostream& operator<<(ostream&, const Array&);

};


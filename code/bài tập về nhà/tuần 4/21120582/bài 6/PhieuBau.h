#pragma once
#include<iostream>
#include<string>
#include"Time.h"
using namespace std;
class PhieuBau
{
private:
	string MaCaSi;
	string TenCaSi;
	bool hople;
public:
	PhieuBau();

	string getMa();
	string getTen();
	bool getHople();

	void setMa(string);
	void setTen(string);


	bool Hople(Time,Time,Time);

};


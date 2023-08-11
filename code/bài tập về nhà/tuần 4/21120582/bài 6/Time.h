#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Time
{
private: 
	int gio, phut, giay;
public:
	Time();
	Time(int, int, int);

	int getGio();
	int getPhut();
	int getGiay();
	void setGio(int);
	void setPhut(int);
	void setGiay(int);

	Time str_to_time(string);

	bool operator>(const Time&) const;
	bool operator<(const Time&) const;
};


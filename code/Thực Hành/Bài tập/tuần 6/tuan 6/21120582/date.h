#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<sstream>
#include<string>

class date
{
private:
	int ngay, thang, nam;
public:
	date();
	date(int, int, int);
	date(const date&);

	void str_todate(std::string);
	void charptr_todate(char*);

	std::string toString();

	date Cur_date();
	int getNgay();
	int getThang();
	int getNam();

	bool operator==(const date&)const;
	bool operator>(const date&)const;
	bool operator<(const date&)const;

	friend std::ostream& operator <<(std::ostream& out, date);
	friend std::istream& operator >>(std::istream& in, date&);
};


#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<sstream>
#include<string>

class CMyDate
{
private:
	int ngay, thang, nam;
public:
	CMyDate();
	CMyDate(int, int, int);
	CMyDate(const CMyDate&);

	void str_todate(std::string);
	std::string toString();

	CMyDate Cur_date();
	int getnam()
	{
		return nam;
	}

	bool operator==(const CMyDate&)const;
	bool operator>(const CMyDate&)const;
	bool operator<(const CMyDate&)const;

	friend std::ostream& operator <<(std::ostream& out, CMyDate);
	friend std::istream& operator >>(std::istream& in, CMyDate&);
};


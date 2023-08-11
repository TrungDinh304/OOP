#pragma once

#include<iostream>
#include<string>
#include<sstream>

class date
{
private:
	int ngay, thang, nam;
public:
	date();
	date(int, int, int);
	date(const date&);

	void str_todate(char*);
	std::string toString();

	date Cur_date();

	bool operator==(const date&)const;
	friend std::ostream& operator <<(std::ostream& out, date);
	friend std::istream& operator >>(std::istream& in, date&);
};


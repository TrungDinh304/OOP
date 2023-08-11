#define _CRT_SECURE_NO_WARNINGS
#include "date.h"

date::date() {
	ngay = thang = nam = 0;
}
date::date(int n, int t, int na)
{
	ngay = n;
	thang = t;
	nam = na;
}

date::date(const date& ngay_init)
{
	ngay = ngay_init.ngay;
	thang = ngay_init.thang;
	nam = ngay_init.nam;
}

void date::str_todate(char* line)
{
	std::stringstream date_line(line);
	char buffer[5] = "";
	date_line.getline(buffer, 3, '/');
	ngay = atoi(buffer);
	date_line.getline(buffer, 3, '/');
	thang = atoi(buffer);
	date_line.getline(buffer, 5, '\n');
	nam = atoi(buffer);
}

std::string date::toString()
{
	std::string result;
	result = ngay + '/' + thang + '/' + nam;
	return result;
}

date date::Cur_date()
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	nam = (now->tm_year + 1900);
	thang = (now->tm_mon + 1);
	ngay = now->tm_mday;
	return *this;
}

bool date::operator==(const date& other)const
{
	if (ngay != other.ngay)
		return 0;
	if (thang != other.thang)
		return 0;
	return 1;
}

std::ostream& operator<<(std::ostream& out, date xuat)
{
	out << xuat.ngay << '/' << xuat.thang << '/' << xuat.nam;
	return out;
}

std::istream& operator>>(std::istream& in, date& nhap)
{
	std::cout << "\tNhap Ngay: "; in >> nhap.ngay;
	std::cout << "\tNhap Thang: "; in >> nhap.thang;
	std::cout << "\tNhap Nam: "; in >> nhap.nam;
	return in;
}




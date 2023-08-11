#include "CMyDate.h"


CMyDate::CMyDate() {
	ngay = thang = nam = 0;
}
CMyDate::CMyDate(int n, int t, int na)
{
	ngay = n;
	thang = t;
	nam = na;
}

CMyDate::CMyDate(const CMyDate& ngay_init)
{
	ngay = ngay_init.ngay;
	thang = ngay_init.thang;
	nam = ngay_init.nam;
}

void CMyDate::str_todate(std::string line)
{
	std::stringstream date_line(line);

	std::string buffer;
	getline(date_line, buffer, '/');
	ngay = stoi(buffer);
	getline(date_line, buffer, '/');
	thang = stoi(buffer);
	getline(date_line, buffer, '\n');
	nam = stoi(buffer);
}

std::string CMyDate::toString()
{
	std::string result;
	result = std::to_string(ngay) + '/' + std::to_string(thang) + '/' + std::to_string(nam);
	return result;
}

CMyDate CMyDate::Cur_date()
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	nam = (now->tm_year + 1900);
	thang = (now->tm_mon + 1);
	ngay = now->tm_mday;
	return *this;
}

bool CMyDate::operator==(const CMyDate& other)const
{
	if (ngay != other.ngay)
		return 0;
	if (thang != other.thang)
		return 0;
	return 1;
}

bool CMyDate::operator>(const CMyDate& other)const
{
	if (nam > other.nam)
		return 1;
	if (thang > other.thang && nam == other.nam)
		return 1;
	if (ngay > other.ngay && thang == other.thang && nam == other.nam)
		return 1;
	return 0;
}

bool CMyDate::operator<(const CMyDate& other)const
{
	if (nam < other.nam)
		return 1;
	if (thang < other.thang && nam == other.nam)
		return 1;
	if (ngay < other.ngay && thang == other.thang && nam == other.nam)
		return 1;
	return 0;
}

std::ostream& operator<<(std::ostream& out, CMyDate xuat)
{
	out << xuat.ngay << '/' << xuat.thang << '/' << xuat.nam;
	return out;
}

std::istream& operator>>(std::istream& in, CMyDate& nhap)
{
	std::cout << "\tNhap Ngay: "; in >> nhap.ngay;
	std::cout << "\tNhap Thang: "; in >> nhap.thang;
	std::cout << "\tNhap Nam: "; in >> nhap.nam;
	return in;
}




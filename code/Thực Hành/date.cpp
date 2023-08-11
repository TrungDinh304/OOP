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

int date::getNgay()
{
	return ngay;
}

int date::getThang()
{
	return thang;
}

int date::getNam()
{
	return nam;
}

void date::str_todate(std::string line)
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

void date::charptr_todate(char* source)
{
	std::stringstream date_line(source);
	char buffer[20] = "";
	
	date_line.getline(buffer, 20, '/');
	ngay = atoi(buffer);
	date_line.getline(buffer, 20, '/');
	thang = atoi(buffer);
	date_line.getline(buffer, 20, '\n');
	nam = atoi(buffer);

}


std::string date::toString()
{
	std::string result;
	result = std::to_string(ngay) + '/' + std::to_string(thang) + '/' + std::to_string(nam);
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

bool date::operator>(const date& other)const
{
	if (nam > other.nam)
		return 1;
	if (thang > other.thang && nam == other.nam)
		return 1;
	if (ngay > other.ngay && thang == other.thang && nam == other.nam)
		return 1;
	return 0;
}

bool date::operator<(const date& other)const
{
	if (nam < other.nam)
		return 1;
	if (thang < other.thang && nam == other.nam)
		return 1;
	if (ngay < other.ngay && thang == other.thang && nam == other.nam)
		return 1;
	return 0;
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


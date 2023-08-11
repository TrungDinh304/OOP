#include "Time.h"
Time::Time()
{
	gio = phut = giay = 0;
}

Time::Time(int h, int m, int s)
{
	gio = h;
	phut = m;
	giay = s;
}

int Time::getGio()
{
	return gio;
}
int Time::getPhut()
{
	return phut;
}

int Time::getGiay()
{
	return giay;
}

void Time::setGio(int alter)
{
	gio = alter;
}

void Time::setPhut(int alter)
{
	phut = alter;
}
void Time::setGiay(int alter)
{
	giay = alter;
}

//chuyển chuỗi kí tự có format <giờ>:<phút>:<giây> thành kiểu dữ liệu Time
Time Time::str_to_time(string line)
{
	int daduyet = 0;
	stringstream infor(line);
	string buffer;

	getline(infor, buffer, ':');
	gio = stoi(buffer);
	daduyet += buffer.size() + 1;

	getline(infor, buffer, ':');
	phut = stoi(buffer);
	daduyet += buffer.size();

	if (daduyet < line.size())
	{
		getline(infor, buffer);
		giay = stoi(buffer);
	}
	
	return *this;
}

bool Time::operator>(const Time& other)const
{
	if (gio != other.gio)
		return gio > other.gio;
	if (phut != other.phut)
		return phut > other.phut;
	return giay > other.giay;
}
bool Time::operator<(const Time& other)const
{
	if (gio != other.gio)
		return gio < other.gio;
	if (phut != other.phut)
		return phut < other.phut;
	return giay < other.giay;
}

#include "DonThuc.h"
DonThuc::DonThuc()
{
	heso = 0;
	mu = 0;
}


DonThuc::DonThuc(float hs, int m)
{
	heso = hs;
	mu = m;
}

float DonThuc::TinhGiaTri(float x)
{
	return heso * pow(x, mu);
}

float DonThuc::getHeSo()
{
	return heso;
}
int DonThuc::getMu()
{
	return mu;
}

void DonThuc::setHeSo(float alter)
{
	heso = alter;
}

void DonThuc::setMu(int alter)
{
	mu = alter;
}



DonThuc DonThuc::operator*(const DonThuc& other)const
{
	DonThuc result;
	result.heso = heso * other.heso;
	result.mu = mu + other.mu;
	return result;
}

DonThuc DonThuc::operator/(const DonThuc& other)const
{
	DonThuc result;
	result.heso = heso / other.heso;
	result.mu = mu - other.mu;
	return result;
}

DonThuc DonThuc::operator+(const DonThuc& other)const
{
	DonThuc result(0, 0);
	if (mu != other.mu)
	{
		cout << "Tham so khong hop le." << endl;
		return result;
	}
	result.heso = heso + other.heso;
	result.mu = mu;
	return result;
}

DonThuc DonThuc::operator-(const DonThuc& other)const
{
	DonThuc result(0, 0);
	if (mu != other.mu)
	{
		cout << "Tham so khong hop le." << endl;
		return result;
	}
	result.heso = heso - other.heso;
	result.mu = mu;
	return result;
}

ostream& operator << (ostream& out, const DonThuc& xuat)
{
	if (xuat.heso == 0)
		return out;
	if (xuat.mu == 0)
	{
		out << xuat.heso;
		return out;
	}
	if (xuat.heso == 1 && xuat.mu == 1)
	{
		out << "x";
		return out;
	}
	if (xuat.heso == 1)
	{
		out << "x^" << xuat.mu;
		return out;
	}

	if (xuat.mu == 1)
	{
		out << xuat.heso << "x";
		return out;
	}

	out << xuat.heso << "x^" << xuat.mu;
	return out;
}
istream& operator>>(istream& in, DonThuc& Nhap)
{
	/*char buffer[30] = "";
	in >> buffer;
	stringstream inf(buffer);
	inf.getline(buffer, 100, 'x');
	if (buffer[0] == '\0')
		Nhap.heso = 1;
	else
		Nhap.heso = atof(buffer);
	inf.getline(buffer, 100, '^');
	inf.getline(buffer, 100, '\n');
	Nhap.mu = atoi(buffer);*/
	cout << "\tHe So: ";
	in >> Nhap.heso;
	cout << "\tx^: ";
	in >> Nhap.mu;
	return in;
}
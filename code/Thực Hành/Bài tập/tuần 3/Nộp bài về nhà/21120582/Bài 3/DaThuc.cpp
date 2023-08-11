#include "DaThuc.h"



DaThuc::DaThuc()
{
	size = 0;
	pArr = NULL;
}


DaThuc::DaThuc(int n)
{
	size = n;
	pArr = new DonThuc[size];
	for (int i = 0; i < size; i++)
	{
		pArr[i].setMu(i);
	}
}

DaThuc:: ~DaThuc()
{
	delete[]pArr;
}

int DaThuc::getSize()
{
	return size;
}

DonThuc* DaThuc::getPArr()
{
	return pArr;
}

double DaThuc::Value(float x)
{
	double result = 0;
	for (int i = 0; i < size; i++)
	{
		result = result + pArr[i].TinhGiaTri(x);
	}
	return result;
}


DaThuc DaThuc::operator+(const DaThuc& other)const
{
	DaThuc a = *this;
	a.sapxep();
	DaThuc b = other;
	b.sapxep();

	int res_size = max(a.size, b.size);
	DaThuc result(res_size);
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < a.size && j < b.size)
	{
		result.pArr[k++] = a.pArr[i++] + b.pArr[j++];
	}
	while (i < a.size)
	{
		result.pArr[k++] = a.pArr[i++];
	}
	while (j < b.size)
	{
		result.pArr[k++] = b.pArr[j++];
	}
	
	return result;
}
DaThuc DaThuc::operator-(const DaThuc& other)const
{
	DaThuc a = *this;
	a.sapxep();
	DaThuc b = other;
	b.sapxep();

	int res_size = max(a.size, b.size);
	DaThuc result(res_size);
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < a.size && j < b.size)
	{
		result.pArr[k++] = a.pArr[i++] - b.pArr[j++];
	}
	while (i < a.size)
	{
		result.pArr[k++] = a.pArr[i++];
	}
	while (j < b.size)
	{
		result.pArr[k++] = b.pArr[j++];
	}
	return result;
}
DaThuc DaThuc::operator*(const DaThuc& other)const
{
	DaThuc result(size + other.size -1);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			int pos = pArr[i].getMu() + other.pArr[j].getMu();
			result.pArr[pos] = result.pArr[pos] + (pArr[i] * other.pArr[j]);
		}
	}
	return result;
}
DaThuc DaThuc::operator/(const DaThuc& other)const
{
	DaThuc bichia = *this;
	bichia.sapxep();
	DaThuc sochia = other;
	sochia.sapxep();
	
	if (bichia.getSize() < sochia.getSize())
	{
		DaThuc result;
		return result;
	}

	int res_size = bichia.size - sochia.size + 1;
	DaThuc result(res_size);
	DaThuc Du;
	while (bichia.getSize() >= sochia.getSize())
	{
		DonThuc thuong = bichia.pArr[bichia.size - 1] / sochia.pArr[sochia.size - 1];

		result.pArr[thuong.getMu()] = result.pArr[thuong.getMu()] + thuong;

		DaThuc hangtu(thuong.getMu() + 1);
		hangtu.pArr[thuong.getMu()] = thuong;

		Du = hangtu * sochia;
		bichia = bichia - Du;
		bichia.sapxep();
		DaThuc temp(bichia.getSize() - 1);
		for (int i = 0; i < temp.getSize(); i++)
		{
			temp.pArr[i] = bichia.pArr[i];
		}
		bichia = temp;
	}
	return result;
}


DaThuc& DaThuc::operator=(const DaThuc& other)
{
	
	size = other.size;
	
	pArr = new DonThuc[this->size];
	for (int i = 0; i < size; i++)
	{
		pArr[i] = other.pArr[i];
	}
	return *this;
}

istream& operator>>(istream& in, DaThuc& nhap)
{
	cout << "Nhap so don nhu cua da thuc can nhap: ";
	in >> nhap.size;
	nhap.pArr = new DonThuc[nhap.size];
	
	for (int i = 0; i < nhap.size; i++)
	{
		cout << i << ". ";
		in >> nhap.pArr[i];
	}
	nhap.sapxep();
	return in;
}

void DaThuc::sapxep()
{
	int MuMax = 0;
	for (int i = 0; i < size; i++)
	{
		if (pArr[i].getMu() > MuMax)
			MuMax = pArr[i].getMu();
	}

	DaThuc temp(MuMax + 1);
	for (int i = 0; i < MuMax +1; i++)
	{
		temp.pArr[i].setMu(i);
	}
	for (int i = 0; i < size; i++)
	{
		int cur_mu = pArr[i].getMu();
		temp.pArr[cur_mu] = temp.pArr[cur_mu] + pArr[i];
	}
	
	*this = temp;
}

ostream& operator<<(ostream& out, const DaThuc& xuat)
{
	out << xuat.pArr[0];
	for (int i = 1; i < xuat.size; i++)
	{
		if (xuat.pArr[i].getHeSo() > 0)
			out << " +";
		out << xuat.pArr[i];
	}
	
	return out;
}
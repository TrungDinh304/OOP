#include "Array.h"

Array::Array()
{
	size = 0;
	pArr = new PhanSo[size];
}

Array::Array(int n)
{
	size = n;
	pArr = new PhanSo[size];
}

Array::~Array()
{
	delete[]pArr;
}

PhanSo Array::SumOfArray()
{
	PhanSo tong;
	for (int i = 0; i < size; i++)
	{
		tong = tong + pArr[i];
	}
	return tong;
}

void Array::sort_tang()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (pArr[i] > pArr[j])
			{
				pArr[i].Hoanvi(pArr[j]);
			}
		}
	}
}

ostream& operator<<(ostream& out, const Array& xuat)
{
	out << xuat.size << endl;
	for (int i = 0; i < xuat.size; i++)
	{
		out << xuat.pArr[i] << endl;
	}
	return out;
}

istream& operator>>(istream& in, Array& nhap)
{
	cout << "Nhap so phan tu: ";
	cin >> nhap.size;
	if (nhap.pArr != NULL)
	{
		delete[]nhap.pArr;
	}
	nhap.pArr = new PhanSo[nhap.size];
	for (int i = 0; i < nhap.size; i++)
	{
		cin >> nhap.pArr[i];
	}
	return in;
}

void Array::Write_File(char* filename)
{
	ofstream fout;
	fout.open(filename);

	fout << *this;
	fout.close();
}
void Array::Read_File(char* filename)
{
	ifstream fin;
	fin.open(filename);
	if (!fin)
	{
		cout << "*****Loi mo File." << endl;
		return;
	}
	if (pArr != NULL)
	{
		delete[]pArr;
	}
	char line[30] = "";
	fin.getline(line, 100, '\n');
	size = atoi(line);
	pArr = new PhanSo[size];
	for (int i = 0; i < size; i++)
	{
		int tu = 0;
		int mau = 0;
		char buffer[30] = "";
		fin.getline(line, 100, '\n');
		stringstream ps(line);
		ps.getline(buffer, 100, '/');
		tu = atoi(buffer);
		
		ps.getline(buffer, 100, '\n');
		mau = atoi(buffer);

		pArr[i].setTu(tu);
		pArr[i].setMau(mau);
	}
	cout << "Mang Phan So vua doc: " << endl;
	cout << *this;
	fin.close();
}


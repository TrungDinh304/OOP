#include "QLGiaoDich.h"

QLGiaoDich::QLGiaoDich()
{
	capa = 100;
	l = new GiaoDich * [capa];
	n = 0;
}

QLGiaoDich::QLGiaoDich(int cap)
{
	capa = cap;
	l = new GiaoDich * [capa];
	n = 0;
}

void QLGiaoDich::nhap()
{
	cout << "Nhap so Giao dich muon nhap: ";
	cin >> n;
	while (n > capa)
	{
		capa *= 2;
		delete[]l;
		l = new GiaoDich * [capa];
	}
	for (int i = 0; i < n; i++)
	{
		l[i]->nhap();
	}
}

void QLGiaoDich::xuat()
{
	cout << "Danh sach Giao Dich: " << endl;
	for (int i = 0; i < n; i++)
	{
		l[i]->xuat();
	}
}

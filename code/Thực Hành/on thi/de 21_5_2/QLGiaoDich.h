#pragma once
#include"GiaoDich.h"
#include"GDTienTe.h"
#include"GDVang.h"
class QLGiaoDich
{
private:
	GiaoDich** l;
	int n;
	int capa;
public:
	QLGiaoDich();
	QLGiaoDich(int cap);
	void nhap();
	void xuat();
	int* TongSoGiaoDich_tungloai()
	{
		int* result = new int[2] {0, 0};
		for (int i = 0; i < n; i++)
		{
			GDVang* ptr = dynamic_cast<GDVang*>(l[i]);
			if (ptr == NULL)
				result[1]++;
			else
				result[0]++;
		}
		return result;

	}

	int* SoTienLonNhat_TungLoai()
	{
		int* result = new int[3] {};
		for (int i = 0; i < n; i++)
		{
			GDTienTe* ptr = dynamic_cast<GDTienTe*>(l[i]);
			if (ptr != NULL)
			{
				if (strcmp(ptr->getLoaitt(), "vnd") == 0)
				{
					if (ptr->thanhtien() > result[0])
						result[0] = ptr->thanhtien();
				}
				else if (strcmp(ptr->getLoaitt(), "usd") == 0)
				{
					if (ptr->thanhtien() > result[1])
						result[0] = ptr->thanhtien();
				}
				else if (strcmp(ptr->getLoaitt(), "euro") == 0)
				{
					if (ptr->thanhtien() > result[2])
						result[0] = ptr->thanhtien();
				}
			}
		}
		return result;
	}


	void xuatGD_Ngay(date tim)
	{
		for (int i = 0; i < n; i++)
		{
			if (l[i]->getNgay() == tim)
				l[i]->xuat();
		}
	}

};

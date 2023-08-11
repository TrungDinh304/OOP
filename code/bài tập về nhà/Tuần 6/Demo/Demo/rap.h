#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<sstream>
#include"ghe.h"
using namespace std;


class rap
{
private:
	bool vip;
	vector<vector<Ghe*>> list;
public:
	void nhap()
	{
		cout << "Rap co phai la rap VIP:???(1=co\; 0=khong): "; cin >> vip;
		int m = 0;
		int n = 0;
		
		
		if (!vip)
		{
			cout << "Nhap kich thuoc rap: " << endl;
			cout << "\tHang (> 4): ";
			cin >> m;
			while (m <= 4)
			{
				cout << "\tHang (> 4): ";
				cin >> m;
			}
			cout << "\tGhe moi hang : ";
			cin >> n;
			

			for (int i = 0; i < 4; i++)
			{
				vector<Ghe*> h;
				list.push_back(h);
				for (int j = 0; j < n; j++)
				{
					
					Ghe* temp = new Ghe("T", 1, 60000);
					list[i].push_back(temp);

				}
			}
			
			
			for (int i = 4; i < m; i++)
			{
				vector<Ghe*> h;
				list.push_back(h);
				for (int j = 0; j < n; j++)
				{
					
					Ghe* temp2 = new Ghe("V", 1, 80000);
					list[i].push_back(temp2);
				}
			}
		}
		else
		{
			cout << "Nhap kich thuoc rap: " << endl;
			cout << "\tHang (> 5): ";
			cin >> m;
			while (m <= 5)
			{
				cout << "\tHang (> 5): ";
				cin >> m;
			}
			cout << "\tGhe moi hang : ";
			cin >> n;
			
			for (int i = 0; i < 4; i++)
			{
				vector<Ghe*> h;
				list.push_back(h);
				for (int j = 0; j < n; j++)
				{
					
					Ghe* temp = new Ghe("T", 1, 90000);
					list[i].push_back(temp);
				}
			}
			
		
			for (int i = 4; i < m-1; i++)
			{
				vector<Ghe*> h;
				list.push_back(h);
				for (int j = 0; j < n; j++)
				{
					

					Ghe* temp = new Ghe("V", 1, 120000);
					list[i].push_back(temp);
				}
			}

			
			
			vector<Ghe*> h;
			list.push_back(h);
			for (int j = 0; j < n; j++)
			{
				

				Ghe* temp = new Ghe("D", 1, 200000);
				list[m - 1].push_back(temp);
			}
				
		}
			
	}


	void xuat()
	{
		for (auto x : list)
		{
			for (auto y : x)
			{
				y->xuat();
				cout << "\t|";
			}
			cout << endl;
		}
	}


	void datve()
	{
		cout << "Nhap so ve can dat: ";
		int sove;
		cin >> sove;
		for (int k = 0; k < sove; k++)
		{
			cout << "Nhap ma ghe muon dat (hang cot loai): ";
			int m = 0; int n = 0;
			cin >> m; cin >> n;

			
			for (int i=0;i<list.size();i++)
			{
				for (int j=0;j<list[i].size();j++)
				{
					if (!list[i][j]->getTrong() || (m > i && n > j))
						cout << "Ghe khong hop le" << endl;
					if (i == m && j == n)
						list[i][j]->setTrong(0);
				}
			}
		}
		
	}
	int GetGhetrong()
	{
		int result = 0;
		for (auto x : list)
		{
			for (auto y : x)
			{
				if (y->getTrong())
					result++;
			}
		}
		return result;
	}

	int tongTien()
	{
		int result = 0;
		for (auto x : list)
		{
			for (auto y : x)
			{
				if (!y->getTrong())
					result += y->getGia();
			}
		}
		return result;
	}
	
};


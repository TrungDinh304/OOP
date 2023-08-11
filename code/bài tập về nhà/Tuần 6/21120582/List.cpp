#include "List.h"

void List::nhap()
{
	cout << "Nhap so sach ban muon nhap: ";
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << i << ". ";
		CEbook temp;
		temp.nhap();
		if (temp.tontai())
			cout << "ton tai:" << endl;
		else
			cout << "Ko ton tai." << endl;
		if (temp.tontai())
			l.push_back(temp);
		else
		{
			cout << "Sach vua nhap khong hop le (do ngay san xuat khong hop le)." << endl;
		}
	}
}
void List::xuat()const
{
	cout << "List: " << endl;
	int i = 0;
	for (auto x : l)
	{
		cout << i << ". ";
		x.xuat();
		i++;
	}
}

void List::docfile()
{
	ifstream fin;
	fin.open("INPUT.txt");
	if (!fin.is_open())
	{
		cout << "Loi mo file: " << endl;
		return;
	}
	string buffer;
	while (!fin.eof())
	{
		string ma;
		string hoten;
		string tacgia;
		//ngay sx đọc vào buffer
		CMyDate ngaysx;
		string theloai;
		string nhasanxuat;
		//gia đọc vào buffer
		double gia = 0;

		getline(fin, ma);
		getline(fin, hoten);
		getline(fin, tacgia);
		getline(fin, buffer);
		ngaysx.str_todate(buffer);
		getline(fin, theloai);
		getline(fin, nhasanxuat);
		getline(fin, buffer);
		gia = stof(buffer);
		CEbook temp(ma, hoten, tacgia, ngaysx, theloai, nhasanxuat, gia);
		if (temp.tontai())
			l.push_back(temp);
		else
		{
			cout << "***Sach:" << endl;
			cout << temp << endl;
			cout << "Co ngay xuat ban khong  hop le." << endl;
		}
	}
	fin.close();
}


void List::writefile(string filename)
{
	ofstream fout;
	fout.open(filename);
	for (auto x : l)
	{
		fout << x;
	}
	fout.close();
}


void List::sapxep_nsx_tang()
{
	int n = l.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (l[i].getNgaySX() > l[j].getNgaySX())
			{
				l[i].hoanvi(l[j]);
			}
		}
	}
}

void List::sapxep_giagiam()
{
	int n = l.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (l[i] < l[j])
			{
				l[i].hoanvi(l[j]);
			}
		}
	}
}

void List::GhiFileGia(string filename)
{
	ofstream fout;
	fout.open(filename);
	for (auto x : l)
	{
		fout << x.getMa() << ' ' << x.getGia() << endl;
	}
	fout.close();
}

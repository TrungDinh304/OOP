#include "QLPhim.h"

QLPhim::QLPhim()
{

}

QLPhim::QLPhim(QLPhim& source)
{
	int n = DS.size();
	for (int i = 0; i < n; i++)
	{
		Phim* temp = new Phim;
		*temp = *DS[i];
		DS.push_back(temp);
	}
}

QLPhim::~QLPhim()
{
	int n = DS.size();
	for (int i = 0; i < n; i++)
	{
		if (DS[i] != NULL)
			delete DS[i];
	}
}

void QLPhim::print()
{
	cout << "Danh Sach Phim: " << endl;
	int count = 0;
	int n = DS.size();
	for (int i = 0; i < n; i++)
	{
		cout << "[" << count << "]" << endl;
		cout << *DS[i] << endl; 
		count++;
	}
}

void QLPhim::input()
{
	cout << "Nhap So Phim Can Nhap Vao Danh Sach: ";
	int n = 0;
	cin >> n;
	while (n <= 0)
	{
		cout << "## So luong phai la so nguyen duong xin vui long nhap lai: ##" << endl;
		cout << "Nhap So Phim Can Nhap Vao Danh Sach: ";
		cin >> n;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i << "]: " << endl;
		Phim* temp = new Phim;
		cin >> *temp;
		/*DS.push_back(temp);*/
		insert_Phim(*temp);
	}
}

void QLPhim::write_bin_file(char* filename)
{
	ofstream fout;
	fout.open(filename,ios::binary);
	int n = DS.size();
	fout.write((char*)(&n), sizeof(n));
	for (int i=0;i<n;i++)
	{
		DS[i]->write_bin_file(fout);
	}
	fout.close();
}

void QLPhim::read_bin_file(char* filename)
{
	ifstream fin;
	fin.open(filename, ios::binary);
	int n = 0;
	fin.read((char*)(&n), sizeof(n));
	for (int i = 0; i < n; i++)
	{
		Phim* temp = new Phim;
		temp->read_bin_file(fin);
		DS.push_back(temp);
	}
	fin.close();
}

void QLPhim::remove_phim_NSX(char* NhaSX)
{
	int n = DS.size();
	for (int i = 0; i < n; i++)
	{
		if (strcmp(DS[i]->getNhaSanXuat(), NhaSX) == 0)
		{
			DS.erase(DS.begin() + i);
			i--;
			n--;
		}
	}
}

void QLPhim::insert_Phim(Phim& add)
{
	Phim* temp = &add;
	DS.push_back(temp);

	if (DS.size() == 1)
		return;

	int pos = 0;
	int n = DS.size() - 1;
	for (; pos < n; pos++)
	{
		if (*DS[pos] > add)
		{
			break;
		}
	}

	for (int i = n; i > pos; i--)
	{
		DS[i] = DS[i - 1];
	}
	DS[pos] = temp;
}







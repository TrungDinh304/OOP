#define _CRT_SECURE_NO_WARNINGS
#include "DanhSach.h"


DanhSach::DanhSach()
{
	n = 0;
	List = NULL;
}
DanhSach::DanhSach(int n_init)
{
	n = n_init;
	List = new SinhVien[n];
}

DanhSach::~DanhSach()
{
	delete[] List;
}

int DanhSach::getN()const
{
	return n;
}

SinhVien* DanhSach::getList()const
{
	return List;
}


void DanhSach::read_File(char* filename)
{
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Read File Error." << endl;
		return;
	}
	char buffer[100] = "";
	cout << buffer;
	fin.getline(buffer, 100, '\n');

	n = atoi(buffer);
	List = new SinhVien[n];

	char tendem[30] = "";
	char masodem[30] = "";
	date ngaydem;
	float diemdem[3] = { 0, 0, 0 };


	for (int i = 0; i < n; i++)
	{
		fin.getline(buffer, 100);
		stringstream line_inf(buffer);

		line_inf.getline(tendem, 100, '|');
		line_inf.getline(masodem, 100, '|');
		line_inf.getline(buffer, 100, '|');
		ngaydem.str_todate(buffer);

		line_inf.getline(buffer, 3, '|');
		diemdem[0] = atoi(buffer);
		line_inf.getline(buffer, 3, '|');

		diemdem[1] = atoi(buffer);
		line_inf.getline(buffer, 3, '|');
		diemdem[2] = atoi(buffer);

		SinhVien temp(tendem, masodem, ngaydem, diemdem[0], diemdem[1], diemdem[2]);
		List[i] = temp;
	}
}



void DanhSach::write_File(char* filename, bool in_xeploai)const
{
	freopen(filename, "wt", stdout);
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		List[i].xuatSinhVien(in_xeploai);
	}

}

float DanhSach::ave_tb()
{
	float result = 0;
	for (int i = 0; i < n; i++)
	{
		result += List[i].getTb();
	}

	result /= n;
	return result;
}


void DanhSach::SV_lower_tblop(char* filename)
{
	float ave = ave_tb();


	freopen(filename, "wt", stdout);

	
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (List[i].getTb() < ave)
			count++;
	}

	cout << count << endl;
	for (int i = 0; i < n; i++)
	{
		if (List[i].getTb() < ave)
			List[i].xuatSinhVien(0);
	}
}

void DanhSach::insert_N_updateF(const SinhVien& add, char* filename)
{
	DanhSach update(n + 1);
	for (int i = 0; i < n; i++)
	{
		update.List[i] = List[i];
	}

	update.List[n] = add;
	delete[]List;
	List = new SinhVien[n + 1];
	for (int i = 0; i < n+1; i++)
	{
		List[i] = update.List[i];
	}
	n++;
	
	

	update.write_File(filename, 0);
}

void DanhSach::W_file_cur_bod_sv(char* filename, bool in_xeploai)
{
	freopen(filename, "wt", stdout);
	int count = 0;
	date current;
	current.Cur_date();
	for (int i = 0; i < n; i++)
	{
		if (List[i].getNgaysinh() == current)
		{
			count++;
		}
	}

	cout << count << endl;

	for (int i = 0; i < n; i++)
	{
		if (List[i].getNgaysinh() == current)
		{
			List[i].xuatSinhVien(in_xeploai);
		}
	}

}




#include "CongTy.h"

CongTy::CongTy()
{
	n = 0;
	list = NULL;
}

CongTy::CongTy(const CongTy& ini)
{

	if (list != NULL)
	{
		for (int i = 0; i < n; i++)
			delete list[i];
		delete[] list;
		list = NULL;
	}
	n = ini.n;
	list = new NhanVien * [n];
	for (int i = 0; i < n; i++)
	{
		if (dynamic_cast<NVCongNhat*> (ini.list[i]) != NULL)
		{
			NVCongNhat* temp = dynamic_cast<NVCongNhat*> (ini.list[i]);
			list[i] = new NVCongNhat(*temp);
		}
		else
		{
			NVSanXuat* temp = dynamic_cast<NVSanXuat*> (ini.list[i]);
			list[i] = new NVSanXuat(*temp);
		}
	}
}

CongTy& CongTy::operator=(const CongTy& s)
{
	if (list != NULL)
	{
		for (int i = 0; i < n; i++)
			delete list[i];
		delete[] list;
		list = NULL;
	}
	n = s.n;
	list = new NhanVien* [n];
	for (int i = 0; i < n; i++)
	{
		if (dynamic_cast<NVCongNhat*> (s.list[i]) != NULL)
		{
			NVCongNhat* temp = dynamic_cast<NVCongNhat*> (s.list[i]);
			list[i] = new NVCongNhat(*temp);
		}
		else
		{
			NVSanXuat* temp = dynamic_cast<NVSanXuat*> (s.list[i]);
			list[i] = new NVSanXuat(*temp);
		}
	}

	return *this;
}

void CongTy::readfile(char* filename)
{
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Loi mo file." << endl;
		return;
	}
	char buffer[20] = "";
	fin.getline(buffer, 20, '\n');
	n = atoi(buffer);
	list = new NhanVien * [n];
	for (int i = 0; i < n; i++)
	{
		char manv[5] = "";
		char hoten[30] = "";
		date ngsinh(0, 0, 0);
		char diachi[30] = "";

		fin.getline(manv, 5, '\n');
		fin.getline(hoten, 30, '\n');
		fin.getline(buffer, 20, '\n');
		ngsinh.charptr_todate(buffer);
		fin.getline(diachi, 50, '\n');
		
		int so = 0;
		fin.getline(buffer, 20, '\n');
		so = atoi(buffer);
		if (so <= 15 && so >= 10)
		{
			list[i] = new NVSanXuat(manv, hoten, ngsinh, diachi, so);
			list[i]->tinhluong();
		}

		else if (so <= 26 && so >= 22)
		{
			list[i] = new NVCongNhat(manv, hoten, ngsinh, diachi, so);
			list[i]->tinhluong();
		}
	}
	fin.close();
}

void CongTy::write_file(char* filename)
{
	ofstream fout;
	fout.open(filename);
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		list[i]->xuatfile(fout);
	}

	fout.close();
}

void CongTy::nhap()
{
	if (list != NULL)
		delete[]list;
	cout << "Nhap so nhan vien can nhap: ";
	cin >> n;
	list = new NhanVien * [n];
	for (int i = 0; i < n; i++)
	{
		char opt = 0;
		cout << "================================" << endl;
		cout << "|Nhap loai nhan vien can nhap: |" << endl;
		cout << "|     1. Nhan vien cong nhat.  |" << endl;
		cout << "|     2. Nhan vien san xuat.   |" << endl;
		cout << "================================" << endl;
		cout << "\t-Xin vui long nhap: ";
		cin >> opt;
		while (opt != '1' && opt != '2')
		{
			cout << "Khong hop le vui long nhap lai: " << endl;
			cin >> opt;
		}
		if (opt == '1')
		{
			list[i] = new NVCongNhat;
			list[i]->Nhap();
		}
		else if (opt == '2')
		{
			list[i] = new NVSanXuat;
			list[i]->Nhap();
		}
	}
}

void CongTy::xuat()
{
	cout << "Danh sach nhan vien coong ty: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << '[' << i << ']' << endl;
		list[i]->Xuat();
	}
}

float CongTy::tongLuong()
{
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += list[i]->tinhluong();
	}
	return sum;
}

NhanVien* CongTy::NV_LuongCaoNhat()
{
	NhanVien* Max = list[0];
	for (int i = 0; i < n; i++)
	{
		if (list[i]->tinhluong() > Max->tinhluong())
			Max = list[i];
	}
	return Max;
}

float CongTy::Luong_tr_binh()
{
	float sum = tongLuong();
	return sum / n;
}

NhanVien* CongTy::tim_NV_ma(char* maso)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(maso, list[i]->getMa()) == 0)
			return list[i];
	}
	return NULL;
}

NhanVien* CongTy::tim_NV_ten(char* ten)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(ten, list[i]->getHoten()) == 0)
			return list[i];
	}
	return NULL;
}

int CongTy::So_NV_sinh_thang(int thang)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (list[i]->getNgaysinh().getThang() == thang)
			count++;
	}
	return count;
}

void CongTy::them_N_capnhat(NhanVien* add)
{
	NhanVien** temp = new NhanVien * [n + 1];
	for (int i = 0; i < n; i++)
	{
		temp[i] = list[i];
	}
	temp[n] = add;
	delete[]list;
	n++;
	list = temp;
	char filename[] = "ds_NhanVien.dat";
	this->write_file(filename);
}

void CongTy::Xoa_N_capnhat(char* maso)
{
	NhanVien** temp = new NhanVien*[n - 1];
	int i = 0;
	int flag = 0;
	for (; i < n; i++)
	{
		if (strcmp(maso, list[i]->getMa()))
			temp[i + flag] = list[i];
		else
			flag -= 1;
	}
	delete[]list;
	n += flag;
	list = temp;
}

void CongTy::xuat_file_luongthap()
{
	float trungbinh = Luong_tr_binh();
	ofstream fout;
	fout.open("emp_LowerAvgSalary.dat");
	for (int i = 0; i < n; i++)
	{
		if (list[i]->getLuong() < trungbinh)
		{
			list[i]->xuatfile(fout);
		}
	}
}

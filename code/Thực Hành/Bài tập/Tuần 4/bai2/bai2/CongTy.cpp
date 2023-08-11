#include "CongTy.h"


CongTy::CongTy()
{
	n_congnhat = n_sanxuat = 0;
	congnhat = NULL;
	sanxuat = NULL;
}


CongTy::CongTy(int cn, int sx)
{
	congnhat = new NVCongNhat[cn];
	n_congnhat = cn;
	n_sanxuat = sx;
	sanxuat = new NVSanXuat[n_sanxuat];
}

CongTy& CongTy::operator=(const CongTy& source)
{
	n_congnhat = source.n_congnhat;
	n_sanxuat = source.n_sanxuat;
	congnhat = new NVCongNhat[n_congnhat];
	sanxuat = new NVSanXuat[n_sanxuat];
	for (int i = 0; i < n_congnhat; i++)
	{
		congnhat[i] = source.congnhat[i];
	}

	for (int i = 0; i < n_sanxuat; i++)
	{
		sanxuat[i] = source.sanxuat[i];
	}
	return *this;
}

void CongTy::Nhap()
{
	cout << "===NHAN VIEN CONG NHAT===" << endl;
	cout << "Nhap so nhan vien cong nhat can nhap: ";
	cin >> n_congnhat;
	if (congnhat != NULL)
		delete[]congnhat;
	congnhat = new NVCongNhat[n_congnhat];
	for (int i = 0; i < n_congnhat; i++)
	{
		cout << "[" << i << "]: " << "-----------------------------------------------" << endl;
		congnhat[i].Nhap();
	}

	cout << "===NHAN VIEN SAN XUAT===" << endl;
	cout << "Nhap so nhan vien san xuat can nhap: ";
	cin >> n_sanxuat;
	if (sanxuat != NULL)
		delete[]sanxuat;
	sanxuat = new NVSanXuat[n_sanxuat];
	for (int i = 0; i < n_sanxuat; i++)
	{
		cout << "[" << i << "]: " << "----------------------------------------------------------" << endl;
		sanxuat[i].Nhap();
	}
}

void CongTy::Xuat()
{
	cout << "===NHAN VIEN CONG NHAT===" << endl;
	for (int i = 0; i < n_congnhat; i++)
	{
		cout << "[" << i << "]: " << "-----------------------------------------------------------------" << endl;
		congnhat[i].Xuat();
	}
	cout << "===NHAN VIEN SAN XUAT===" << endl;
	for (int i = 0; i < n_sanxuat; i++)
	{
		cout << "[" << i << "]: " << "-------------------------------------------------------------------" << endl;
		sanxuat[i].Xuat();
	}
}

float CongTy::tongLuong()
{
	float result = 0;
	for (int i = 0; i < n_congnhat; i++)
	{
		result += congnhat[i].tinhluong();
	}
	for (int i = 0; i < n_sanxuat; i++)
	{
		result += sanxuat[i].tinhluong();
	}
	return result;
}


NhanVien* CongTy::NV_luongCaoNhat()
{
	int max_cn = 0;
	for (int i = 0; i < n_congnhat; i++)
	{
		if (congnhat[i].tinhluong() > congnhat[max_cn].tinhluong())
			max_cn = i;
	}


	int max_sx = 0;
	for (int i = 0; i < n_sanxuat; i++)
	{
		if (sanxuat[i].tinhluong() > sanxuat[max_sx].tinhluong())
			max_sx = i;
	}


	if (n_congnhat > 0 && n_sanxuat > 0)
		if (congnhat[max_cn].tinhluong() > sanxuat[max_sx].tinhluong())
			return &congnhat[max_cn];
		else
			return &sanxuat[max_sx];
	else if (n_congnhat > 0)
		return &congnhat[max_cn];
	else if (n_sanxuat > 0)
		return &sanxuat[max_sx];


	return NULL;
}



float CongTy::ave_luong()
{
	float result = 0;
	for (int i = 0; i < n_congnhat; i++)
	{
		result += congnhat[i].tinhluong();
	}
	for (int i = 0; i < n_sanxuat; i++)
	{
		result += sanxuat[i].tinhluong();
	}
	result = result / (n_congnhat + n_sanxuat);
	return result;
}

NhanVien* CongTy::Tim_NV_ma(string ma)
{
	for (int i = 0; i < n_congnhat; i++)
	{
		if (congnhat[i].getMa() == ma)
			return &congnhat[i];
	}

	for (int i = 0; i < n_sanxuat; i++)
	{
		if (sanxuat[i].getMa() == ma)
			return &sanxuat[i];
	}
	return NULL;
}


NhanVien* CongTy::Tim_NV_hoten(string ten)
{
	for (int i = 0; i < n_congnhat; i++)
	{
		if (congnhat[i].getHoten() == ten)
			return &congnhat[i];
	}

	for (int i = 0; i < n_sanxuat; i++)
	{
		if (sanxuat[i].getHoten() == ten)
			return &sanxuat[i];
	}
	return NULL;
}

int CongTy::count_NgSinh_thang(int thang)
{
	int result = 0;
	for (int i = 0; i < n_congnhat; i++)
	{
		if (congnhat[i].getNgaysinh().getThang() == thang)
			result++;
	}

	for (int i = 0; i < n_sanxuat; i++)
	{
		if (sanxuat[i].getNgaysinh().getThang() == thang)
			result++;
	}

	return result;
}

void CongTy::insert_NV()
{
	cout << "Nhap nhan vien muon them vao:" << endl;
	cout << "1. Nhan vien cong nhat; 2. Nhan vien san xuat." << endl;
	char option = '\0';
	cin >> option;
	while (option != '1' && option != '2')
	{
		cout << "Khong hop le vui long nhap lai:";
		cin >> option;
	}
	if (option == '1')
	{
		NVCongNhat temp;
		temp.Nhap();
		NVCongNhat* result = new NVCongNhat[n_congnhat + 1];
		for (int i = 0; i < n_congnhat; i++)
		{
			result[i] = congnhat[i];
		}
		result[n_congnhat] = temp;
		n_congnhat++;
		delete[]congnhat;
		congnhat = result;
	}
	else if (option == '2')
	{
		NVSanXuat a;
		a.Nhap();
		NVSanXuat* result = new NVSanXuat[n_sanxuat + 1];
		for (int i = 0; i < n_sanxuat; i++)
		{
			result[i] = sanxuat[i];
		}
		result[n_sanxuat] = a;
		n_sanxuat++;
		delete[]sanxuat;
		sanxuat = result;
	}

}

void CongTy::remove_NV(string maNV)
{
	for (int i = 0; i < n_congnhat; i++)
	{
		if (congnhat[i].getMa() == maNV)
		{
			n_congnhat--;
			for (int j = i; j < n_congnhat; j++)
				congnhat[j] = congnhat[j + 1];

			NVCongNhat* result = new NVCongNhat[n_congnhat];
			for (int j = 0; j < n_congnhat; j++)
				result[j] = congnhat[j];

			delete[]congnhat;
			congnhat = result;
			i--;
		}
	}

	for (int i = 0; i < n_sanxuat; i++)
	{
		if (sanxuat[i].getMa() == maNV)
		{
			n_sanxuat--;
			for (int j = i; j < n_sanxuat; j++)
				sanxuat[j] = sanxuat[j + 1];

			NVSanXuat* result = new NVSanXuat[n_sanxuat];
			for (int j = 0; j < n_sanxuat; j++)
				result[j] = sanxuat[j];

			delete[]sanxuat;
			sanxuat = result;
			i--;
		}
	}
}

void CongTy::write_file_lower()
{
	ofstream fout;
	fout.open("emp_LowerAvgSalary.dat");
	fout << "NVCN: " << endl;
	for (int i = 0; i < n_congnhat; i++)
	{
		if (congnhat[i].tinhluong() < ave_luong())
			fout << congnhat[i];
	}
	fout << "NVSX: " << endl;
	for (int i = 0; i < n_sanxuat; i++)
		if (sanxuat[i].tinhluong() < ave_luong())
			fout << sanxuat[i];	
	fout.close();
}

CongTy::~CongTy()
{

}


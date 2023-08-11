#define _CRT_SECURE_NO_WARNINGS
#include "NhanVien.h"

bool NhanVien::hople()
{
	date ngayhientai;
	ngayhientai.Cur_date();
	int tuoi = ngayhientai.getNam() - ngaysinh.getNam();
	if (gioitinh == true)//nếu là nam
	{
		return tuoi >= 18 && tuoi <= 60;
	}
	return tuoi >= 18 && tuoi <= 55;
}

bool NhanVien::mahople()
{
	int len = strlen(maNV);
	if (len != 5)
		return false;
	for (int i = 0; i < len; i++)
	{
		if (maNV[i] > '9' || maNV[i] < '0')
			return false;
	}
	return true;
}

NhanVien::NhanVien()
{
	maNV = new char[6] {};
	hoten = new char[30] {};
	ngaysinh = { 0,0,0 };
	gioitinh = 0;
	diachi = new char[50] {};
	luong = 0;
}

NhanVien::NhanVien(const NhanVien& s)
{
	maNV = new char[6];
	hoten = new char[30];
	diachi = new char[50];
	strcpy(maNV, s.maNV);
	strcpy(hoten, s.hoten);
	strcpy(diachi, s.diachi);
	ngaysinh = s.ngaysinh;
	gioitinh = s.gioitinh;
	luong = s.luong;
}

NhanVien::NhanVien(char* ma, char* _hoten, date ngs, bool gtinh, char* dchi)
{
	maNV = new char[6] {};
	strcpy(maNV, ma);
	hoten = new char[30] {};
	strcpy(hoten, _hoten);
	ngaysinh = ngs;
	gioitinh = gtinh;
	diachi = new char[50] {};
	strcpy(diachi, dchi);
	luong = 0;
}

NhanVien::~NhanVien()
{
	delete[]maNV;
	delete[]hoten;
	delete[]diachi;
}

char* NhanVien::getMa()
{
	return maNV;
}

char* NhanVien::getHoten()
{
	return hoten;
}

date NhanVien::getNgaysinh()
{
	return ngaysinh;
}

bool NhanVien::getGioitinh()
{
	return gioitinh;
}

char* NhanVien::getDiachi()
{
	return diachi;
}

float NhanVien::getLuong()
{
	return luong;
}

void NhanVien::Nhap()
{
	while (true)
	{
		try
		{
			cout << "Nhap Ma Nhan Vien: ";
			cin >> maNV;
			if (!mahople())
				throw MyException("## Ma Nhan vien phai là chuoi 5 chu so: ##");
			break;
		}
		catch (MyException err)
		{
			cout << err.getMessage() << endl;
			cout << "## Xin vui long nhap lai. ##" << endl;
		}
	}

	cout << "Nhap ho ten nhan vien: ";
	cin.ignore();
	cin.getline(hoten, 30, '\n');
	while (true)
	{
		try
		{
			cout << "Nhap ngay sinh: \n";
			cin >> ngaysinh;
			string temp;
			cout << "Nhap gioi tinh (1: Nam; 0: Nu; neu nhap khac 2 gia tri tren mac dinh la nam): ";//nêu nhập khác 0 thì mặc định là nam
			cin >> temp;
			if (temp[0] == '0')
				gioitinh = 0;
			else
				gioitinh = 1;

			if (hople() == 0)
			{
				throw MyException("So tuoi so voi gioi tinh khong hop le.");
			}
			break;
		}
		catch (MyException error)
		{
			cout << error.getMessage() << endl;
			cout << "Vui long nhap lai ngay sinh va gioi tinh." << endl;
		}
		catch (...)
		{
			cout << "Loi khong xac dinh." << endl;
			break;
		}
	}
	cout << "Nhap dia chi: ";
	cin.ignore();
	cin.getline(diachi, 50, '\n');
}

void NhanVien::Xuat()
{
	cout << "\tMa Nhan Vien: " << maNV << endl;
	cout << "\tHo ten: " << hoten << endl;
	cout << "\tNgay sinh: " << ngaysinh << endl;
	if (gioitinh)
		cout << "\tGioi tinh: Nam." << endl;
	else
		cout << "\tGioi tinh: Nu." << endl;
	cout << "\tDia chi: " << diachi << endl;
}

NhanVien& NhanVien::operator=(const NhanVien& s)
{
	if (maNV != NULL)
		delete[]maNV;
	if (hoten != NULL)
		delete[] hoten;
	if (diachi != NULL)
		delete[] diachi;

	maNV = new char[6];
	hoten = new char[30];
	diachi = new char[50];
	strcpy(maNV, s.maNV);
	strcpy(hoten, s.hoten);
	strcpy(diachi, s.diachi);
	ngaysinh = s.ngaysinh;
	gioitinh = s.gioitinh;
	luong = s.luong;
	return *this;
}

ostream& NhanVien::xuatfile(ostream& out)
{
	out << maNV << endl;
	out << hoten << endl;
	out << ngaysinh << endl;
	out << gioitinh << endl;
	out << diachi << endl;
	return out;
}

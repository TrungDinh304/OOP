#define _CRT_SECURE_NO_WARNINGS
#include "NVSanXuat.h"

bool NVSanXuat::hople()
{
	return sosanpham <= 15 && sosanpham >= 10;
}

NVSanXuat::NVSanXuat() :NhanVien()
{
	sosanpham = 0;
	luong = sosanpham * 50000.0 * 26;
}

NVSanXuat::NVSanXuat(const NVSanXuat& s) : NhanVien(s)
{
	sosanpham = s.sosanpham;
	luong = sosanpham * 50000.0 * 26;
}

NVSanXuat::NVSanXuat(char* ma, char* ht, date ns, bool gt, char* dc, int ssp) :NhanVien(ma, ht, ns, gt, dc)
{
	sosanpham = ssp;
	luong = sosanpham * 50000.0 * 26;
}

int NVSanXuat::getSoSP()
{
	return sosanpham;
}

void NVSanXuat::Nhap()
{
	NhanVien::Nhap();
	/*cout << "Nhap so san pham: ";
	cin >> sosanpham;
	while (sosanpham > 15 || sosanpham < 10)
	{
		cout << "Xin vui long nhap lai (Du lieu nhap khong hop le): ";
		cin >> sosanpham;
	}*/
	while (true)
	{
		try {
			cout << "Nhap so san pham: ";
			cin >> sosanpham;
			if (!hople())
			{
				throw MyException("So san pham khong hop le.");
			}
			break;
		}

		catch (MyException error)
		{
			cout << error.getMessage() << endl;
			cout << "Vui long nhap lai so sanpham." << endl;
		}
		catch (...)
		{
			cout << "Loi khong xac dinh." << endl;
			break;
		}
	}
}

void NVSanXuat::Xuat()
{
	NhanVien::Xuat();
	cout << "\tSo san pham: " << sosanpham << endl;
	cout << "\tLuong: " << (long)luong << " VND" << endl;
}

float NVSanXuat::tinhluong()
{
	luong = sosanpham * 50000.0 * 26;
	return luong;
}

NVSanXuat& NVSanXuat::operator=(const NVSanXuat& s)
{
	NhanVien::operator=(s);
	sosanpham = s.sosanpham;
	return *this;
}

ostream& NVSanXuat::xuatfile(ostream& out)
{
	NhanVien::xuatfile(out);
	out << sosanpham << endl;
	return out;
}

ostream& NVSanXuat::write_binary_file(ostream& out)
{
	NhanVien::write_binary_file(out);
	out.write((char*)(&sosanpham), sizeof(sosanpham));
	return out;
}

istream& NVSanXuat::read_binary_file(istream& in)
{
	NhanVien::read_binary_file(in);
	in.read((char*)(&sosanpham), sizeof(sosanpham));
	return in;
}


#define _CRT_SECURE_NO_WARNINGS
#include "NVCongNhat.h"

bool NVCongNhat::hople()
{
	return songay <= 26 && songay >= 22;
}

NVCongNhat::NVCongNhat() :NhanVien()
{
	songay = 0;
}

NVCongNhat::NVCongNhat(const NVCongNhat& s) :NhanVien(s)
{
	songay = s.songay;
}

NVCongNhat::NVCongNhat(char* ma, char* _hoten, date ns, bool gt, char* dc, int sng) : NhanVien(ma, _hoten, ns, gt, dc)
{
	songay = sng;
}

int NVCongNhat::getSongay()
{
	return songay;
}

void NVCongNhat::Nhap()
{
	NhanVien::Nhap();
	/*while (songay > 26 || songay < 22)
	{
		cout << "Xin vui long nhap lai (Du lieu nhap khong hop le): ";
		cin >> songay;
	}*/
	while (true)
	{
		try {
			cout << "Nhap so ngay: ";
			cin >> songay;
			if (!hople())
			{
				throw MyException("So ngay cong khong hop le.");
			}
			break;
		}

		catch (MyException error)
		{
			cout << error.getMessage() << endl;
			cout << "Vui long nhap lai so ngay." << endl;
		}
		catch (...)
		{
			cout << "Loi khong xac dinh." << endl;
			break;
		}
	}
}

void NVCongNhat::Xuat()
{
	NhanVien::Xuat();
	cout << "\tSo ngay cong: " << songay << endl;
}

float NVCongNhat::tinhluong()
{
	luong = songay * 500000.0;
	return luong;
}

NVCongNhat& NVCongNhat::operator=(const NVCongNhat& s)
{
	NhanVien::operator = (s);
	songay = s.songay;
	return *this;
}

ostream& NVCongNhat::xuatfile(ostream& out)
{
	NhanVien::xuatfile(out);
	out << songay << endl;
	return out;
}



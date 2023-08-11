#include<sstream>
#include<string>
#include<fstream>
#include <vector>
#include <iostream>

using namespace std;
class NhanVien {
protected:
	string hoten;
	string ngaySinh;
	string diachi;

public:
	virtual void nhap()
	{
		cout << "Ho va Ten: ";
		cin.ignore();
		getline(cin, hoten);
		cout << "Ngay Sinh: ";
		cin >> ngaySinh;
		cout << "Dia Chi: ";
		cin.ignore();
		getline(cin, diachi);


	}
	virtual void Xuat()
	{
		cout << "HoTen: " << hoten << endl;
		cout << "NgaySinh: " << ngaySinh << endl;
		cout << "Dia Chi: " << diachi << endl;
	}

	virtual float tinhluong() = 0;
};

class NVsx :public NhanVien
{
private:
	int sosanpham;
public:
	void nhap()
	{
		NhanVien::nhap();
		cout << "So san Pham: ";
		cin >> sosanpham;
	}

	void Xuat()
	{
		NhanVien::Xuat();
		cout << "So San Pham: " << sosanpham << endl;
	}
	float tinhluong()
	{
		return sosanpham * 100000;
	}

};
class  NVcongnhat : public NhanVien
{
private:
	int songaycong;
public:
	void nhap()
	{
		NhanVien::nhap();
		cout << "songaycong: ";
		cin >> songaycong;
	}
	void Xuat()
	{
		NhanVien::Xuat();
		cout << "SoNgaycong: " << songaycong << endl;
	}
	float tinhluong()
	{
		return songaycong * 200000;
	}
};

class NVQL :public NhanVien
{
private:
	int luongcoban;
	float heso;
public:
	void nhap()
	{
		NhanVien::nhap();
		cout << "Luongcb: ";
		cin >> luongcoban;
		cout << "HS: ";
		cin >> heso;
	}
	void Xuat()
	{
		NhanVien::Xuat();
		cout << "Luongcb: " << luongcoban << endl;
		cout << "Heso: " << heso << endl;
	}

	float tinhluong()
	{
		return luongcoban * heso;
	}
};

class CTy
{
private:
	int n;
	vector<NhanVien*> ds;
public:
	void nhap() {
		cout << "Nhap so luong nhan vien:";
		cin >> n;

		int loai = 0;
		NhanVien* a;
		for (int i = 0; i < n; i++) {
			cout << "Nhap loai nhan vien (0.NVQL, 1.NVCN, 2.NVSX): ";
			cin >> loai;

			if (loai == 0) {
				a = new NVQL;
				a->nhap();
				ds.push_back(a);
			}
			if (loai == 1) {
				a = new NVcongnhat;
				a->nhap();
				ds.push_back(a);
			}
			if (loai == 2) {
				a = new NVsx;
				a->nhap();
				ds.push_back(a);
			}
		}
	}

	void xuat() {
		for (auto i : ds) {
			i->Xuat();
			cout << endl;
		}
	}

	float tinhluong() {
		float sum = 0;
		for (int i = 0; i < n; i++) {
			sum += ds[i]->tinhluong();
		}
		return sum;
	}
};

int main()
{
	CTy abc;
	abc.nhap();
	abc.xuat();
	cout << abc.tinhluong();

	return 0;
}



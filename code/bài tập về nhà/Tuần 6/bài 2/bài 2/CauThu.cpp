#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <sstream>


class date
{
private:
	int ngay, thang, nam;
public:
	date();
	date(int, int, int);
	date(const date&);

	void str_todate(char*);
	std::string toString();

	date Cur_date();

	bool operator==(const date&)const;
	friend std::ostream& operator <<(std::ostream& out, date);
	friend std::istream& operator >>(std::istream& in, date&);
};


date::date() {
	ngay = thang = nam = 0;
}
date::date(int n, int t, int na)
{
	ngay = n;
	thang = t;
	nam = na;
}

date::date(const date& ngay_init)
{
	ngay = ngay_init.ngay;
	thang = ngay_init.thang;
	nam = ngay_init.nam;
}

void date::str_todate(char* line)
{
	std::stringstream date_line(line);
	char buffer[5] = "";
	date_line.getline(buffer, 3, '/');
	ngay = atoi(buffer);
	date_line.getline(buffer, 3, '/');
	thang = atoi(buffer);
	date_line.getline(buffer, 5, '\n');
	nam = atoi(buffer);
}

std::string date::toString()
{
	std::string result;
	result = ngay + '/' + thang + '/' + nam;
	return result;
}

date date::Cur_date()
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	nam = (now->tm_year + 1900);
	thang = (now->tm_mon + 1);
	ngay = now->tm_mday;
	return *this;
}

bool date::operator==(const date& other)const
{
	if (ngay != other.ngay)
		return 0;
	if (thang != other.thang)
		return 0;
	return 1;
}

std::ostream& operator<<(std::ostream& out, date xuat)
{
	out << xuat.ngay << '/' << xuat.thang << '/' << xuat.nam;
	return out;
}

std::istream& operator>>(std::istream& in, date& nhap)
{
	std::cout << "\tNhap Ngay: "; in >> nhap.ngay;
	std::cout << "\tNhap Thang: "; in >> nhap.thang;
	std::cout << "\tNhap Nam: "; in >> nhap.nam;
	return in;
}


class CauThu {
protected:
	string maso;
	string hoten;
	date ngsinh;
	string soao;
	string vitri;
	date hopdong;
	float luong;
public:
	virtual void nhap() {
		cout << "Nhap maso:";
		getline(cin, maso);
		cout << "Nhap ho ten:";
		getline(cin, hoten);
		cout << "Nhap ngay sinh";
		cin >> ngsinh;
		cout << "Nhap so ao:";
		getline(cin, soao);
		cout << "Nhap vi tri:";
		getline(cin, vitri);
		cout << "Nhap ngay den han hop dong:";
		cin >> hopdong;
		cout << "Nhap luong hang tuan:";
		cin >> luong;
	}
	virtual void xuat() {
		cout << maso << " " << hoten << " " << ngsinh << " "
			<< soao << " " << vitri << " " << hopdong 
			<< " " << luong << endl;
	}

	string getMaso() {
		return maso;
	}
	string getHoten() {
		return hoten;
	}
	date getNgsinh() {
		return ngsinh;
	}
	string getSoao() {
		return soao;
	}
	string getVitr() {
		return vitri;
	}
	date getHopdong() {
		return hopdong;
	}
	float getLuong() {
		return luong;
	}
};


class CauThuTre : public CauThu {
private:
	int diem;
	bool trangthai;
public:
	void nhap() {
		CauThu::nhap();
		cout << "Nhap diem trien vong:";
		cin >> diem;
		cout << "Nhap trang thai: (true, false)";
		cin >> trangthai;
	}

	void xuat() {
		CauThu::xuat();
		cout << diem << " " << trangthai << endl;
	}
	
	int getDiem() {
		return diem;
	}
	bool getTrangthai() {
		return trangthai;
	}
};

class DoiBong {
	vector <CauThu*> list;
public:
	void nhap() {
		while (true) {
			int loai;
			cout << "Nhap loai:";
			cout << "1. A, 2. B, 0.exit";
			cin >> loai;

			CauThu* temp = NULL;
			if (loai == 1) {
				temp = new CauThu;
			}
			if (loai == 2) {
				temp = new CauThuTre;
			}
			if (loai == 0) {
				break;
			}

			temp->nhap();
			list.push_back(temp);

		}
	}

	void xuat() {
		for (auto i : list) {
			i->xuat();
		}
	}

	/*void them(CauThuThiDau A) {
		ChinhThuc.push_back(A);
	}
	void them(CauThuDuBi A) {
		ChinhThuc.push_back(A);
	}
	int tongSM() {
		int tong = 0;
		for (int i = 0; i < ChinhThuc.size(); i++)
			tong += ChinhThuc[i].getSuc();
		return tong;
	}*/

	/*void thay() {

		freopen("OUTPUT.txt", "wt", stdout);

		int dem = 0;
		for (int i = 0; i < ChinhThuc.size() - 2; i++)
			for (int j = i + 1; j < ChinhThuc.size() - 1; j++)
				for (int k = j + 1; k < ChinhThuc.size(); k++) {
					string str1, str2, str3;
					str1 = ChinhThuc[i].getVT();
					str2 = ChinhThuc[j].getVT();
					str3 = ChinhThuc[k].getVT();
					if (str1 != str2 && str2 != str3 && str3 != str1)
					{
						DoiBong temp;
						temp.them(ChinhThuc[i]);
						temp.them(ChinhThuc[j]);
						temp.them(ChinhThuc[k]);
						if (temp.tongSM() > 150)
						{
							dem++;
							if (dem == 4)
								return;
							cout << dem << endl;

							temp.xuat();
						}
					}
				}
	}*/


};

//class DoiBong
//{
//private:
//	vector<CauThu> A;
//	vector<CauThuTre> B;
//	vector<CauThu> thidauchinhthuc;
//};


int main() {





	/*freopen("INPUT.txt", "rt", stdin);*/

	//while (!cin.eof()) {
	//	string s;
	//	getline(cin, s);

	//	stringstream ss(s);
	//	vector<string>v;
	//	string w;
	//	while (ss >> w)
	//		v.push_back(w);

	//	if (v.size() == 4)
	//	{
	//		string vt;
	//		for (int i = 1; i < 3; i++)
	//			vt += v[i] + " ";
	//		vt.erase(vt.size() - 1);
	//		CauThuDuBi B(v[0], vt, v[3]);
	//		DS.them(B);
	//	}
	//	else {
	//		string vt;
	//		for (int i = 1; i < 3; i++)
	//			vt += v[i] + " ";
	//		vt.erase(vt.size() - 1);
	//		DS.them(CauThuThiDau(v[0], vt, v[3], v[4], v[5]));
	//	}

	//}
	//cout << endl;
	//DS.thay();
	

}
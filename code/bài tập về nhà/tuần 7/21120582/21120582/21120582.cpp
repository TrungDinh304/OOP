#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include<string>
#include<random>
#include<ctime>
#include<sstream>
using namespace std;

//========================KHAI BÁO VÀ ĐỊNH NGHĨA CLASS DATE=====================
class date
{
private:
	int ngay, thang, nam;
public:
	date();
	date(int, int, int);
	date(const date&);

	void str_todate(std::string);
	std::string toString();

	date Cur_date();
	int getNgay();
	int getThang();
	int getNam();

	long to_hours()
	{
		int songay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		return ngay * 24 + thang * songay[thang] * 24 + nam * 365 * 24;
	}

	bool operator==(const date&)const;
	bool operator>(const date&)const;
	bool operator<(const date&)const;
	date random()
	{
		int songay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		int n = rand() % (2023 - 1980 + 1) + 1980;
		int t = rand() % 12 + 1;
		int ng = rand() % songay[t] + 1;
		date result(ng, t, n);
		*this = result;
		return result;
	}

	friend ostream& operator <<(std::ostream& out, date);
	friend istream& operator >>(std::istream& in, date&);
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

int date::getNgay()
{
	return ngay;
}

int date::getThang()
{
	return thang;
}

int date::getNam()
{
	return nam;
}

void date::str_todate(string line)
{
	std::stringstream date_line(line);

	string buffer;
	getline(date_line, buffer, '/');
	ngay = stoi(buffer);
	getline(date_line, buffer, '/');
	thang = stoi(buffer);
	getline(date_line, buffer, '\n');
	nam = stoi(buffer);
}

string date::toString()
{
	string result;
	result = to_string(ngay) + '/' + to_string(thang) + '/' + to_string(nam);
	return result;
}

date date::Cur_date()
{
	time_t t = std::time(0);
	tm* now = std::localtime(&t);
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

bool date::operator>(const date& other)const
{
	if (nam > other.nam)
		return 1;
	if (thang > other.thang && nam == other.nam)
		return 1;
	if (ngay > other.ngay && thang == other.thang && nam == other.nam)
		return 1;
	return 0;
}

bool date::operator<(const date& other)const
{
	if (nam < other.nam)
		return 1;
	if (thang < other.thang && nam == other.nam)
		return 1;
	if (ngay < other.ngay && thang == other.thang && nam == other.nam)
		return 1;
	return 0;
}

std::ostream& operator<<(std::ostream& out, date xuat)
{
	out << xuat.ngay << '/' << xuat.thang << '/' << xuat.nam;
	return out;
}

istream& operator>>(std::istream& in, date& nhap)
{
	cout << "\tNhap Ngay: "; in >> nhap.ngay;
	cout << "\tNhap Thang: "; in >> nhap.thang;
	cout << "\tNhap Nam: "; in >> nhap.nam;
	return in;
}

//====================================================================================================
//===================================KHAI BÁO VÀ ĐỊNH NGHĨA CLASS CaSi================================
class CaSi
{
protected:
    string HoTen;
    string MaSo;
	date NgaySinh;
	int sl_album;
	int SoBuoiTD_thang;
	long luottheodoi;
	virtual ostream& Xuat(ostream& out)
	{
		out << "Ho ten: " << HoTen << endl;
		out << "Ma so: " << MaSo << endl;
		out << "Ngay sinh: " << NgaySinh << endl;
		out << "So album da phat hanh: " << sl_album << endl;
		out << "So buoi dien trong 1 thang: " << SoBuoiTD_thang << endl;
		out << "So luot theo doi: " << luottheodoi << endl;
		return out;
	}
	virtual istream& Nhap(istream& in)
	{
		cout << "Nhap Ho ten: ";
		getline(in, HoTen);
		cout << "Nhap ma so: ";
		in >> MaSo;
		cout << "Nhap ngay sinh: " << endl;
		in >> NgaySinh;
		cout << "Nhap so luong album da phat hang: ";
		in >> sl_album;
		cout << "Nhap so buoi trinh dien trong thang: ";
		in >> SoBuoiTD_thang;
		cout << "Nhap so luot theo doi: ";
		in >> luottheodoi;
		return in;
	}
public:
	CaSi();
	CaSi(string, string, date, int, int, long);
	CaSi(const CaSi&);
	string getMa()
	{
		return MaSo;
	}

	long getFollow()
	{
		return luottheodoi;
	}

	date getNgaysinh()
	{
		return NgaySinh;
	}

	virtual float luong();
	friend ostream& operator <<(ostream&, CaSi);
	friend istream& operator>>(istream&, CaSi&);

};


CaSi::CaSi()
{
	HoTen = "";
	MaSo = "";
	date a(0, 0, 0);
	NgaySinh = a;
	sl_album = 0;
	SoBuoiTD_thang = 0;
	luottheodoi = 0;
}


CaSi::CaSi(string _ten, string _ma, date _ngsinh, int _slab, int _sobuoitd_thang, long _luottd)
{
	HoTen = _ten;
	MaSo = _ma;
	NgaySinh = _ngsinh;
	sl_album = _slab;
	SoBuoiTD_thang = _sobuoitd_thang;
	luottheodoi = _luottd;
}


CaSi::CaSi(const CaSi& init)
{
	HoTen = init.HoTen;
	MaSo = init.MaSo;
	NgaySinh = init.NgaySinh;
	sl_album = init.sl_album;
	SoBuoiTD_thang = init.SoBuoiTD_thang;
	luottheodoi = init.luottheodoi;
}



float CaSi::luong()
{
	return 3000000 + 250000 * SoBuoiTD_thang;
}

ostream& operator <<(ostream& out, CaSi xuat)
{
	xuat.Xuat(out);
	/*out << "Ho ten: " << xuat->HoTen << endl;
	out << "Ma so: " << xuat->MaSo << endl;
	out << "Ngay sinh: " << xuat->NgaySinh << endl;
	out << "So album da phat hanh: " << xuat->sl_album << endl;
	out << "So buoi dien trong 1 thang: " << xuat->SoBuoiTD_thang << endl;
	out << "So luot theo doi: " << xuat->luottheodoi << endl;*/
	return out;
}

istream& operator >>(istream& in, CaSi& nhap)
{
	/*cout << "Nhap Ho ten: ";
	getline(in, nhap->HoTen);
	cout << "Nhap ma so: ";
	in >> nhap->MaSo;
	cout << "Nhap ngay sinh: " << endl;
	in >> nhap->NgaySinh;
	cout << "Nhap so luong album da phat hang: ";
	in >> nhap->sl_album;
	cout << "Nhap so buoi trinh dien trong thang: ";
	in >> nhap->SoBuoiTD_thang;
	cout << "Nhap so luot theo doi: ";
	in >> nhap->luottheodoi;*/
	/*cout << "Nhap Ho ten: ";
	getline(in, nhap.HoTen);
	cout << "Nhap ma so: ";
	in >> nhap.MaSo;
	cout << "Nhap ngay sinh: " << endl;
	in >> nhap.NgaySinh;
	cout << "Nhap so luong album da phat hang: ";
	in >> nhap.sl_album;
	cout << "Nhap so buoi trinh dien trong thang: ";
	in >> nhap.SoBuoiTD_thang;
	cout << "Nhap so luot theo doi: ";
	in >> nhap.luottheodoi;*/



	nhap.Nhap(in);
	return in;
}

//===========================KHAI BÁO VÀ ĐỊNH NGHĨA CSnoitieng=====================================
class CSnoitieng :public CaSi
{
private:
	int sogameshow;
public:
	CSnoitieng();
	CSnoitieng(string, string, date, int, int, int, int);
	CSnoitieng(const CSnoitieng&);

	ostream& Xuat(ostream& out)
	{
		CaSi::Xuat(out);
		out << "So Game show da tham gia: " << sogameshow;
		return out;
	}
	istream& Nhap(istream& in)
	{
		CaSi::Nhap(in);
		cout << "Nhap so game show da tham gia: ";
		in >> sogameshow;
		return in;
	}

	float luong();
	int getSogameShows()
	{
		return sogameshow;
	}
};

CSnoitieng::CSnoitieng() :CaSi() {
	sogameshow = 0;
}


CSnoitieng::CSnoitieng(string _ten, string _ma, date _ngsinh, int _slab, int _sobuoitd_thang, int _luottd, int _gameshows)
	:CaSi(_ten, _ma, _ngsinh, _slab, _sobuoitd_thang, _luottd)
{
	sogameshow = _gameshows;
}


CSnoitieng::CSnoitieng(const CSnoitieng& init)
{
	HoTen = init.HoTen;
	MaSo = init.MaSo;
	NgaySinh = init.NgaySinh;
	sl_album = init.sl_album;
	SoBuoiTD_thang = init.SoBuoiTD_thang;
	luottheodoi = init.luottheodoi;
	sogameshow = init.sogameshow;
}


float CSnoitieng::luong()
{
	return 20000000 + 500000 * SoBuoiTD_thang + 5000000 * sogameshow;
}


//===============================================================================================
//hàm random chuỗi
string random_ten()
{
	vector<string> a = {
		"Elizabeth", "Emily", "Emma", "Jessica", "Jennifer", "Laura", "Linda", "Maria",  "Rebecca", "Sarah","Brian", "Christopher",  "David", "Daniel", "Brian", "John", "James", "Kevin", "Mark", "Matthew",  "Michael", "Robert", "William"
	};


	string result = a[rand() % (a.size() - 1)];
	int t = rand() % 3 + 1;
	for (int i = 0; i < t; i++)
	{
		result += " " + a[rand() % (a.size() - 1)];
	}

    return result;   
}

//random mã
string random_ma()
{
	vector<string> a = { "0","1","2","3","4","5","6","7","8","9"};


	int t = 8;
	string result;
	for (int i = 0; i < t; i++)
	{
		result += a[rand() % (a.size() - 1)];
	}

	return result;
}
//============================class danhsach=====================================
class danhsach {
private:
	vector<CaSi*> list;
public:
	danhsach();
	danhsach(int);
	void remove_maso(string);

	pair<int, int> thognke();
	void tongluong_sothang(int sothang)
	{
		int count = 0;
		for (auto x : list)
		{
			cout << count++ << '.';
			cout << x->getMa() << endl;
			cout << "\tTien luong: " << long long (sothang * x->luong()) << endl;
		}
	}

	void cs_ngaysinh_nearest()
	{
		date temp;
		cout << "Nhap ngay can tim: ";
		cin >> temp;
		long temp_hours = temp.to_hours();

		long* distance = new long[list.size()] {0};

		int count = 0;
		for (auto x : list)
		{
			distance[count++] = abs(x->getNgaysinh().to_hours() - temp_hours);
		}

		cout << "3 ca si co ngay sinh gan nhat: " << endl;
		for (int j = 0; j < 3; j++)
		{
			int min = 0;
			for (int i = 0; i < list.size(); i++)
			{
				if (distance[i] < distance[min])
					min = i;
			}
			cout << *list[min] << endl;
			distance[min] = INT16_MAX;
		}
		

	}

	void xuat()
	{
		int count = 0;
		for (auto x : list)
		{
			cout << count++ << ". " << endl;
			cout << *x << endl;
		}
	}



	~danhsach();

	void nhap() {
		int size;
		cout << "Nhap so luong ca si: ";
		cin >> size;
		int i = 0;
		list.resize(size);
		for (int i = 0; i < size; i++) {
			list[i] = nullptr;
		}

		while (i < size) {
			int opt;
			do {

				cout << "\n==================\n";
				cout << "||1.ca si chua noi||\n";
				cout << "||2.ca si da noi  ||\n";
				cout << "====================\n";
				cout << "Vui long chon: ";
				cin >> opt;
				if (opt != 1 && opt != 2) {
					cout << "Chi duoc nhap 1 hoac 2! Vui long nhap lai!\n";
				}
			} while (opt != 1 && opt != 2);


			CaSi* cs = nullptr;
			if (opt == 1) {
				cs = new CaSi;
			}

			else if (opt == 2) {
				cs = new CSnoitieng;
			}
			cin >> *cs;
			list.push_back(cs);
			i++;
		}
	}
};


danhsach::danhsach()
{

}

danhsach::danhsach(int init)
{
	for (int i = 0; i < init; i++)
	{
		string ten = random_ten();
		string ma = random_ma();
		date sinh;
		sinh.random();
		int album = rand() % 10 + 1;
		int buoi= rand() % 10 + 1;
		long follows = rand() % (1100000+900000-1)+999000;
		if (follows < 1000000)
		{
			CaSi* temp = new CaSi(ten, ma, sinh, album, buoi, follows);
			list.push_back(temp);
		}
		else
		{
			int gameshows = rand() % 20 + 1;
			CaSi* temp = new CSnoitieng(ten, ma, sinh, album, buoi, follows, gameshows);
			list.push_back(temp);
		}
	}

}

//phần tử first là cs chưa nổi, phần tử second là số ca sỉ nổi tiếng
pair<int, int> danhsach::thognke()
{
	pair<int, int> result = { 0,0 };
	for (auto x : list)
	{
		if (x->getFollow() > 1000000)
		{
			result.second++;
		}
		else
			result.first++;
	}
	cout << "So ca si chua noi: " << result.first << endl;
	cout << "So ca si da noi: " << result.second << endl;
	return result;
}

void danhsach::remove_maso(string xoa)
{
	int n = list.size();
	for (int i = 0; i < n; i++)
	{
		if (list[i]->getMa() == xoa)
		{
			list.erase(list.begin() + i);
		}
	}
}



danhsach::~danhsach()
{
	for (auto x : list)
	{
		delete x;
	}
}


void menuDS(danhsach& l)
{
	char option = '\0';
	do
	{
		system("cls");

		cout << "\t\t\t==============================================================" << endl;
		cout << "\t\t\t|   1. Xuat danh sach hien tai                               |" << endl;
		cout << "\t\t\t|   2. Thong ke cac ca si.                                   |" << endl;
		cout << "\t\t\t|   3. Nhap 1 ma so va xoa ca si co ma so do khoi danh sach  |" << endl;
		cout << "\t\t\t|                                                            |" << endl;
		cout << "\t\t\t|   4. Nhap 1 nay/thang/nam.                                 |" << endl;
		cout << "\t\t\t|       tim 3 ca si co ngay thang nam sinh gan nhat.         |" << endl;
		cout << "\t\t\t|   5. Nhap so thang, in ra so luong cong ty phai tra cho moi|" << endl;
		cout << "\t\t\t|       ca si.                                               |" << endl;
		cout << "\t\t\t|    Nhan phim 0 de tao lai danh sach moi.                   |" << endl;
		cout << "\t\t\t==============================================================" << endl;

		cout << "Nhap chuc nang muon test: ";
		cin >> option;

		if (option == '1')
		{
			l.xuat();
		}
		else if (option == '2')
		{
			cout << "Thong ke ca si: " << endl;
			l.thognke();
		}
		else if (option == '3')
		{
			cout << "Nhap ma so ca si muon xoa khoi danh sach: ";
			string n;
			cin >> n;
			l.remove_maso(n);
			l.xuat();
		}

		else if (option == '4')
		{
			l.cs_ngaysinh_nearest();
		}
		else if (option == '5')
		{
			cout << "Nhap so thang: ";
			int n = 0;
			cin >> n;
			while (n <= 0)
			{
				cout << "Khong hop le: " << endl;
				cout << "Nhap so thang: ";
				cin >> n;
			}
			l.tongluong_sothang(n);
		}
		if (option != '0')

			system("pause");
	} while (option != '0');
}

void menu()
{

	char opt = '\0';
	while (true)
	{
		system("cls");

		cout << "\t\t\t==============================================================" << endl;
		cout << "\t\t\t|   1. Nhap danh sach cac ca si.                             |" << endl;
		cout << "\t\t\t|                                                            |" << endl;
		cout << "\t\t\t|   2. Nhap vao mot so nguyen duong ngau nhien, de thu duoc  |" << endl;
		cout << "\t\t\t|      danh sach ca si ngau nhien.                           |" << endl;
		cout << "\t\t\t==============================================================" << endl;

		cout << "Nhap chuc nang muon test: ";
		cin >> opt;

		if (opt == '1')
		{
			danhsach a;
			a.nhap();
			system("pause");
			menuDS(a);
		}
		else if (opt == '2')
		{
			cout << "Nhap so ca si can tao ngau nhien: ";
			int n = 0;
			cin >> n;
			while (n <= 0)
			{
				cout << "Khong hop le: " << endl;
				cout << "Nhap so ca si can tao ngau nhien: ";
				cin >> n;
			}
			danhsach ngaunhien(n);
			cout << "Danh sach ngau nhien vua duoc tao: " << endl;
			ngaunhien.xuat();
			system("pause");
			menuDS(ngaunhien);
		}
		else if (opt == '0')
			break;
	} 
	cout << "****Ket Thuc Chuong Trinh.****" << endl;
}



int main()
{
	/*cout << RAND_MAX << endl;
	cout << "Nhap so ca si muon khoi tao: ";
	int n;
	cin >> n;
	danhsach a(n);
	a.xuat();
	a.thognke();*/
	/*a.cs_ngaysinh_nearest();
	cout << "============tong luong===========" << endl;
	a.tongluong_sothang(2);*/
	
	menu();
	/*danhsach a;
	a.nhap();
	a.xuat();*/
	

    return 1;
}


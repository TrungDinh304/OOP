#include "Phim.h"

bool Phim::checkMa()
{
	if (strlen(maso) != 5)
		return 0;
	int n = strlen(maso);
	for (int i = 0; i < n; i++)
	{
		if (maso[i] > '9' || maso[i] < '0')
			return 0;
	}
	return 1;
}

Phim::Phim()
{
	maso = new char[Maxma] {""};
	tenPhim = new char[MaxTen] {""};
	theloai = new char[Maxtheloai] {""};
	NhaSanXuat = new char[MaxnhaSX] {""};
	namSX = 0;
	xepHang = 0;
}

Phim::Phim(char* ms, char* ten, char* tl, char* nhasx, int namsx, int xl)
{
	maso = new char[Maxma] {""};
	tenPhim = new char[MaxTen] {""};
	theloai = new char[Maxtheloai] {""};
	NhaSanXuat = new char[MaxnhaSX] {""};
	strcpy(maso, ms);
	strcpy(tenPhim, ten);
	strcpy(theloai, tl);
	strcpy(NhaSanXuat, nhasx);
	namSX = namsx;
	xepHang = xl;
}

Phim::Phim(Phim& source)
{
	maso = new char[Maxma] {""};
	tenPhim = new char[MaxTen] {""};
	theloai = new char[Maxtheloai] {""};
	NhaSanXuat = new char[MaxnhaSX] {""};
	strcpy(maso, source.maso);
	strcpy(tenPhim, source.tenPhim);
	strcpy(theloai, source.theloai);
	strcpy(NhaSanXuat, source.NhaSanXuat);
	namSX = source.namSX;
	xepHang = source.xepHang;
}

Phim& Phim::operator=(Phim& source)
{
	/*if (maso != NULL)
		delete[]maso;
	if (tenPhim != NULL)
		delete[]tenPhim;
	if (theloai != NULL)
		delete[]theloai;
	if (NhaSanXuat != NULL)
		delete[]NhaSanXuat;

	maso = new char[Maxma] {""};
	tenPhim = new char[MaxTen] {""};
	theloai = new char[Maxtheloai] {""};
	NhaSanXuat = new char[MaxnhaSX] {""};*/
	strcpy(maso, source.maso);
	strcpy(tenPhim, source.tenPhim);
	strcpy(theloai, source.theloai);
	strcpy(NhaSanXuat, source.NhaSanXuat);
	namSX = source.namSX;
	xepHang = source.xepHang;
	return *this;
}

bool Phim::operator>(Phim& other)
{
	return namSX > other.namSX;
}

bool Phim::operator<(Phim& other)
{
	return namSX < other.namSX;
}

char* Phim::getMaso()
{
	return maso;
}

char* Phim::getTen()
{
	return tenPhim;
}

char* Phim::getTheLoai()
{
	return theloai;
}

char* Phim::getNhaSanXuat()
{
	return NhaSanXuat;
}

int Phim::getNamSX()
{
	return namSX;
}

float Phim::getXepHang()
{
	return xepHang;
}

ostream& Phim::write_bin_file(ostream& out)
{
	out.write(maso, Maxma);
	out.write(tenPhim, MaxTen);
	out.write(theloai, Maxtheloai);
	out.write(NhaSanXuat, MaxnhaSX);
	out.write((char*)(&namSX), sizeof(namSX));
	out.write((char*)(&xepHang), sizeof(xepHang));
	return out;
}

istream& Phim::read_bin_file(istream& in)
{
	in.read(maso,Maxma);
	in.read(tenPhim,MaxTen);
	in.read(theloai,Maxtheloai);
	in.read(NhaSanXuat,MaxnhaSX);
	in.read((char*)(&namSX),sizeof(namSX));
	in.read((char*)(&xepHang),sizeof(xepHang));
	return in;
}

ostream& operator<<(ostream& out, Phim src)
{
	out << "\tMa Phim: " << src.maso << endl;
	out << "\tTen Phim: " << src.tenPhim << endl;
	out << "\tThe loai: " << src.theloai << endl;
	out << "\tNha San Xuat: " << src.NhaSanXuat << endl;
	out << "\tNam SAn Xuat: " << src.namSX << endl;
	out << "\tXep Hang: " << src.xepHang << endl;
	return out;
}

istream& operator>>(istream& in, Phim& dst)
{
	cout << "\tNhap Ma Phim: "; 
	in >> dst.maso;
	while (dst.checkMa() == 0)
	{
		cout << "Ma phim khong hop le xin vui long nhap lai ma phim gom 5 ki tu so: " << endl;
		in >> dst.maso;
	}

	cout << "\tNhap Ten Phim: ";
	in.ignore();
	in.getline(dst.tenPhim, MaxTen, '\n');

	cout << "\tNhap The Loai: ";
	in.getline(dst.theloai, Maxtheloai, '\n');

	cout << "\tNhap Nha San Xuat: ";
	in.getline(dst.NhaSanXuat, MaxnhaSX, '\n');

	cout << "\tNhap Nam San Xuat: ";
	in >> dst.namSX;

	cout << "\tNhap Xep Hang: ";
	in >> dst.xepHang;
	return in;
}

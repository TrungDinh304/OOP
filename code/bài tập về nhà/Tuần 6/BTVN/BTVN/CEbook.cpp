#include "CEbook.h"


CEbook::CEbook()
{
	ISBN = "";
	tensach = "";
	tacgia = "";
	CMyDate a;
	ngsx = a;
	theloai = "";
	nhasx = "";
	gia = 0;
}

CEbook::CEbook(string id, string ten, string tg, CMyDate nsx, string theloai_init, string nhasx_init, double gia_init)
{
	ISBN = id;
	tensach = ten;
	tacgia = tg;
	ngsx = nsx;
	theloai = theloai_init;
	nhasx = nhasx_init;
	gia = gia_init;
}

CEbook::CEbook(const CEbook& init)
{
	ISBN = init.ISBN;
	tensach = init.tensach;
	tacgia = init.tacgia;
	ngsx = init.ngsx;
	theloai = init.theloai;
	nhasx = init.nhasx;
	gia = init.gia;
}


CMyDate CEbook::getNgaySX()
{
	return ngsx;
}

bool CEbook::operator >(const CEbook& other)const
{
	return gia > other.gia;
}

bool CEbook::operator <(const CEbook& other)const
{
	return gia < other.gia;
}


bool CEbook::operator >=(const CEbook& other)const
{
	return gia >= other.gia;
}

bool CEbook::operator <= (const CEbook& other)const
{
	return gia <= other.gia;
}

string CEbook::getMa()
{
	return ISBN;
}

double CEbook::getGia()
{
	return gia;
}


void CEbook::nhap()
{
	cout << "\tNhap ma sach: ";
	cin >> ISBN;
	cin.ignore();
	cout << "\tNhap ten sach: ";
	getline(cin, tensach);
	cout << "\tNhap ten tac gia: ";
	cin.ignore();
	getline(cin, tacgia);
	cout << "\tNhap ngay san xuat: ";
	cin >> ngsx;
	cout << "\tNhap the loai: ";
	cin.ignore();
	getline(cin, theloai);
	cout << "\tNhap nha san xuat: ";
	cin.ignore();
	getline(cin, nhasx);
	cout << "\tNhap Gia: ";
	cin >> gia;	
}



void CEbook::xuat()const
{
	cout << "\tMa sach: " << ISBN << endl;
	cout << "\tTen sach: " << tensach << endl;
	cout << "\tTac gia: " << tacgia << endl;
	cout << "\tNgay san xuat: " << ngsx << endl;
	cout << "\tThe loai: " << theloai << endl;
	cout << "\tNha san xuat: " << nhasx << endl;
	cout << "\tGia tien: " << gia << endl;

}

bool CEbook::tontai()
{
	CMyDate cur;
	cur.Cur_date();
	return ngsx < cur;
}

ostream& operator<<(ostream& out, const CEbook& xuat)
{
	out << xuat.ISBN << endl;
	out << xuat.tensach << endl;
	out << xuat.tacgia << endl;
	out << xuat.ngsx << endl;
	out << xuat.theloai << endl;
	out << xuat.nhasx << endl;
	out << xuat.gia << endl;
	return out;
}

void CEbook::hoanvi(CEbook& other)
{
	CEbook temp = *this;
	*this = other;
	other = temp;
}

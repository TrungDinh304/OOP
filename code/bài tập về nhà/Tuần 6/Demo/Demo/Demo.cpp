#include<iostream>
#include"rap.h"
using namespace std;


int main()
{
	rap a;
	a.nhap();
	a.xuat();
	a.datve();
	a.xuat();
	cout << "\t+ So Ghe Con Lai: " << a.GetGhetrong() << endl;
	cout << "\t+ So tien phai tra: " << a.tongTien() << endl;
	return 0;
}
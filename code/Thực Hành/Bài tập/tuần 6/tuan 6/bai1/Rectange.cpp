#include "Rectange.h"



Rectange::Rectange()
{
	X = { 0,0 };
	W = H = 0;
}


Rectange::Rectange(Point ini, double w_ini, double h_ini)
{
	X = ini;
	W = w_ini;
	H = h_ini;
}


double Rectange::area()
{
	return H * W;
}

bool Rectange::IsSelected(Point p)
{
	bool resultx = 0;
	if (p.X<X.X + W && p.X>X.X)
		resultx = 1;
	bool resulty = 0;
	if (p.Y<X.Y && p.Y>X.Y - H)
		resulty = 1;

	return resultx && resulty;
}



Shape* Rectange::Clone()
{
	Shape* result = new Rectange(X, W, H);

	return result;
}

void Rectange::input()
{
	cout << "Nhap toa do cua diem goc trai ben tren cua hcn:" << endl;
	cout << "\tNhap x: "; cin >> X.X;
	cout << "\tNhap y: "; cin >> X.Y;
	cout << "Nhap chieu cao: "; cin >> H;
	cout << "Nhap chieu rong: "; cin >> W;
}

void Rectange::print()
{
	cout << "Toa do goc trai ben phai: " << X << endl;
	cout << "Chieu dai: " << H << "; Chieu dai: " << W << endl;
}



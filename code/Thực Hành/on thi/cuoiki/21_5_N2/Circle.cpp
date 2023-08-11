#include "Circle.h"


Circle::Circle()
{
	C = { 0,0 };
	R = 0;
}
Circle::Circle(Point c, double r)
{
	C = c;
	R = r;
}

Circle::Circle(Circle& s)
{
	C = s.C;
	R = s.R;

}

Point Circle::getC()
{
	return C;
}

double Circle::getR()
{
	return R;
}

double Circle::area()
{
	return 3.14 * R * R;
}

Shape* Circle::Clone()
{
	Shape* result = new Circle(C, R);
	return result;
}

void Circle::input()
{
	cout << "Nhap Lan luot tam va ban khinh: " << endl;
	cout << "Tam C: " << endl;
	C.input();
	cout << "Ban kinh R: ";
	cin >> R;
}

void Circle::output()
{
	cout << "Hinh Tron: " << endl;
	cout << "\tTam C: "; C.ouput(); cout << endl;
	cout << "\tBan kinh R: " << R << endl;
}

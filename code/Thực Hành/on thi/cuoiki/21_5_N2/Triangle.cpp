#include "Triangle.h"

bool Triangle::check_point()
{
	double a = B.distance(C);
	
	double b = A.distance(C);
	double c = A.distance(B);
	cout << a << '+' << b << '+' << c << endl;
	cout << a - b - c << endl;
	cout << b - a - c << endl;
	cout << c - a - b << endl;

	if (abs(a - b - c) <= 1e-10 || abs(b - a - c) <= 1e-10 || abs(c - a - b) <= 1e-10)
		return 0;
	return 1;
}

Triangle::Triangle()
{
	A = B = C = { 0,0 };
}

Triangle::Triangle(Triangle& s)
{
	A = s.A;
	B = s.B;
	C = s.C;
}

Triangle::Triangle(Point a, Point b, Point c)
{
	A = a;
	B = b;
	C = c;
}

Point Triangle::getA()
{
	return A;
}

Point Triangle::getB()
{
	return B;
}

Point Triangle::getC()
{
	return C;
}

double Triangle::area()
{
	double a = B.distance(C);
	double b = A.distance(C);
	double c = A.distance(B);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

Shape* Triangle::Clone()
{
	Shape* result = new Triangle(A, B, C);
	return result;
}

void Triangle::input()
{
	cout << "Nhap lan luot 3 dinh A, B, C: " << endl;
	cout << "\tA: " << endl;
	A.input();
	cout << "\tB: " << endl;
	B.input();
	cout << "\tC: " << endl;
	C.input();
	while (!check_point())
	{
		cout << "3 diem khong du dieu kien tao thanh tam giac (3 diem thang hang):" << endl;
		cout << "Xin vui long nhap lai." << endl;
		cout << "\tA: " << endl;
		A.input();
		cout << "\tB: " << endl;
		B.input();
		cout << "\tC: " << endl;
		C.input();
	}
}

void Triangle::output()
{
	cout << "Hinh Tam Giac : " << endl;
	cout << "\tA: ";
	A.ouput();
	cout << "\n\tB: "; B.ouput();
	cout << "\n\tC: "; C.ouput();
	cout << endl;
}

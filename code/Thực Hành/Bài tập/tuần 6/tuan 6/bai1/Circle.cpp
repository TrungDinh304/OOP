#include "Circle.h"



Circle::Circle()
{
	C = { 0,0 };
	R = 0;
}

Circle::Circle(Point ini, double R_ini)
{
	C = ini;
	R = R_ini;
}


double Circle::area()
{
	return R * R * 3.14;
}

/*----- Implement methods: IsSelected(), Clone() -----*/
// method IsSelected
bool Circle::IsSelected(Point p) {
	// pC <= R : Diem p nam tren hinh tron => IsSelected() = true
	return ((p.X - C.X) * (p.X - C.X) + (p.Y - C.Y) * (p.Y - C.Y)) <= R * R;
}
// Deep copy
Shape* Circle::Clone() {
	Circle* p = new Circle;
	if (p == NULL) return NULL;
	p->C = C;
	p->R = R;
	return p;
}
void Circle::input()
{
	cout << "Nhap toa do cua tam duong tron: " << endl;
	cout << "\tNhap x: "; cin >> C.X;
	cout << "\tNhap y: "; cin >> C.Y;
	cout << "Nhap ban kinh hinh tron: "; cin >> R;
}
void Circle::print()
{
	cout << "Toa do tam hinh tron: " << C << endl;
	cout << "Ban kinh: " << R << endl;
}



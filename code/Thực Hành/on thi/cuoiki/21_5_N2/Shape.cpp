#include "Shape.h"

Point::Point(Point& P)
{
	x = P.x;
	y = P.y;
}

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int X, int Y)
{
	x = X;
	y = Y;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

//Point Point::operator=(Point a)
//{
//	x = a.x;
//	y = a.y;
//	return *this;
//}

void Point::input()
{
	cout << "\tx: ";
	cin >> x;
	cout << "\ty: ";
	cin >> y;
}

void Point::ouput()
{
	cout << "(" << x << ", " << y << ")";
}

double Point::distance(Point P)
{
	return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
}

ostream& operator<<(ostream& out, Point s)
{
	// TODO: insert return statement here
	out << s.x << ';' << s.y;

	return out;
}


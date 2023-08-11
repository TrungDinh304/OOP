#pragma once
#include "Shape.h"
class Circle: public Shape
{
private:
	Point C;
	double R;
public:
	Circle();
	Circle(Point c, double r);
	Circle(Circle& s);
	Point getC();
	double getR();
	double area();
	Shape* Clone();
	void input();
	void output();
};


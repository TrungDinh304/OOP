#pragma once
#include"Shape.h"
class Triangle:public Shape
{
private:
	Point A, B, C;
	//kiểm tra thẳng hàng nếu thẳng hành thì không thể tạo thành hình tam giác
	bool check_point();
public:
	Triangle();
	Triangle(Triangle& s);
	Triangle(Point a, Point b, Point c);
	Point getA();
	Point getB();
	Point getC();

	double area();
	Shape* Clone();
	void input();
	void output();
};


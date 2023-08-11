/*****************************************************
* Define Circle class, File giao dien cho lop Circle
*****************************************************/
#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
// Dinh nghia lop Circle
class Circle : public Shape {
protected:
	Point C; // toa do tam
	double R; // do dai ban kinh
public:
	// Constructors
	Circle();
	Circle(Point, double);
	/* override area() method */
	double area();
	bool IsSelected(Point p);
	Shape* Clone();
	void input();
	void print();
};


#endif
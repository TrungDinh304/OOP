/*********************************************************
* Define Rectange class, File giao dien cho lop Rectange
*********************************************************/
#ifndef RECTANGE_H
#define RECTANGE_H
#include "shape.h"
// Dinh nghia lop Rectange
class Rectange : public Shape {
protected:
	Point X; // Toa do goc trai tren
	double W, H; // Chieu rong va chieu cao
public:
	// Constructors
	Rectange();
	Rectange(Point, double, double);
	/* area of rectange */
	double area();
	bool IsSelected(Point p);
	Shape* Clone();
	void input();
	void print();
};
#endif
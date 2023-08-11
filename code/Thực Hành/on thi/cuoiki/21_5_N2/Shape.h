#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <math.h>
using namespace std;
class Point {
public:
	int x;
	int y;
	// constructors
	Point(Point& P);
	Point();
	Point(int X, int Y);
	int getX();
	int getY();
	void input();
	void ouput();
	// Tính khoảng cách giữa 2 điểm
	double distance(Point P);
};
// Dinh nghia lop Shape 
class Shape {
public:
	// Clone() method
	virtual Shape* Clone() = 0;
	// Area of Shape 

	virtual double area() = 0;
	// Input(), Output() methods
	virtual void input() { };
	virtual void output() { };
};
#endif

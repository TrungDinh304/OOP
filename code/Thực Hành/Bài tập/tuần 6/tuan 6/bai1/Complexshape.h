/***********************************************************
* Define ComplexShape, File giao dien cho lop ComplexShape
***********************************************************/
#include "shape.h"
#include"Circle.h"
#include"Rectange.h"
// Dinh nghia lop ComplexShape
class ComplexShape : public Shape {
protected:
	// (1) vector<Shape*> Children;
	// Các hình vẽ thành phần: Circle, rectangle, ...
	int sz; // Number of shapes
	Shape** Children; // Danh sách các hình
public:
	// Constructors
	/* area of ComplexShape */
	ComplexShape();
	ComplexShape(const ComplexShape&);
	~ComplexShape();
	double area();
	bool IsSelected(Point p);
	Shape* Clone();
	void input();
	void print();
	int circle_Num();
};
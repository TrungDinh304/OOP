#include "Complexshape.h"


ComplexShape::ComplexShape()
{
	sz = 0;
	Children = NULL;
}
ComplexShape::ComplexShape(const ComplexShape& a)
{
	sz = a.sz;
	Children = new Shape * [sz];
	for (int i = 0;i < sz;i++)
	{
		Children[i] = a.Children[i]->Clone();
	}
}


ComplexShape::~ComplexShape()
{
	for (int i = 0;i < sz;i++)
		delete Children[i];
	delete[] Children;
}

double ComplexShape::area()
{
	double result = 0;
	for (int i = 0;i < sz;i++)
	{
		result += Children[i]->area();
	}
	return result;
}

bool ComplexShape::IsSelected(Point p)
{
	for (int i = 0;i < sz;i++)
		if (Children[i]->IsSelected(p))
			return 1;
	return 0;
}

Shape* ComplexShape::Clone()
{
	Shape* result = new ComplexShape(*this);
	
	return result;
}

void ComplexShape::input()
{
	cout << "Nhap so hinh muon tao: ";
	cin >> sz;
	Children = new Shape * [sz];
	for (int i = 0;i < sz;i++)
	{
		char otp = '\0';
		cout << "1. tron; 2. chu nhat." << endl;
		cin >> otp;
		while (otp != '1' && otp != '2')
		{
			cout << "Khong hop le vui long nhap lai: " << endl;
			cout << "1. tron; 2. chu nhat." << endl;
			cin >> otp;
		}
		if (otp == '1')
		{
			Children[i] = new Circle;
			Children[i]->input();
		}
		if (otp == '2')
		{
			Children[i] = new Rectange;
			Children[i]->input();
		}
	}
	
	
}

void ComplexShape::print()
{
	for (int i = 0;i < sz;i++)
	{
		cout << i << endl;
		Children[i]->print();
	}
}

int ComplexShape::circle_Num()
{
	int count = 0;
	for (int i = 0;i < sz;i++)
	{
		if (dynamic_cast<Circle*>(Children[i]) != nullptr) {
			count++;
		}
	}
	
	return count;
}

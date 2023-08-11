#pragma once
#include<fstream>
#include<sstream>
#include"Shape.h"
#include"Circle.h"
#include"Triangle.h"
class Cppl_Shape: public Shape
{
private:
	Shape** Children;
	int n;
public:
	Cppl_Shape();
	double area();
	Shape* Clone();
	void input();
	void output();
	void writefile(char* filename);
	void readfile(char*filename);
	void Max_area_eachType();
	void Insert(Shape* add);
};


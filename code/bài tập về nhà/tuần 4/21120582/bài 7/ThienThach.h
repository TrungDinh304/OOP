#pragma once
#include<iostream>
#include<string>
#include"Point.h"
using namespace std;


class ThienThach
{
private:
	string Ma;
	Point toado;
	double banKinh;
	double vantoc;
public:
	ThienThach();
	ThienThach(string, Point, double, double);
	string getMa();
	Point getToaDo();
	double getbanKinh();
	double getvantoc();
	double tg_chamDat();


};


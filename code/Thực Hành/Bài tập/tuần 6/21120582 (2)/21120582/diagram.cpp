// diagram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Complexshape.h"
using namespace std;

int main()
{
	ComplexShape a;
	a.input();
	a.print();
	cout << a.circle_Num() << endl;
	cout << a.area() << endl;
	return 0;
}

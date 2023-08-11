// 21_5_N2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include"Cppl_Shape.h"
using namespace std;

int main()
{
    /*Cppl_Shape a;
    a.input();
    a.output();*/
    char filename[] = "a.dat";
   // a.writefile(filename);
    Cppl_Shape b;

    cout << "---------------------------------" << endl;
    b.readfile(filename);

    b.output();

    b.Max_area_eachType();
    Point rewsa(0, 1);
    Circle temp(rewsa, 3.5);
    b.Insert(&temp);
    b.output();
    
    return 0;
}

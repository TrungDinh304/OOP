#include<iostream>
#include"DocGia.h"
#include"list.h"
using namespace std;


int main()
{
	list a;
	a.readfile();
	a.write();
	a.write_tt();
	return 0;
}
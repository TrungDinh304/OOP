#include <iostream>
#include"Student.h"


using namespace std;

int main()
{
    Student a(999999998, 5);
    Student b(a);
    cout << b.getId() << "," << b.getGpa() << endl;
    Student c;

    c += a;
    cout << c.getId() << "," << c.getGpa() << endl;

    c -= a;
    cout << c.getId() << "," << c.getGpa() << endl;

    c *= a;
    cout << c.getId() << "," << c.getGpa() << endl;


    c /= a;
    cout << c.getId() << "," << c.getGpa() << endl;


    c %= a;
    cout << c.getId() << "," << c.getGpa() << endl;

    c = a;
    cout << c.getId() << "," << c.getGpa() << endl;

    
    return 0;
}

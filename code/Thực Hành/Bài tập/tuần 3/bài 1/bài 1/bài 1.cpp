#include <iostream>
#include"MyIntArray.h"
using namespace std;



int main()
{
    MyIntArray test0;
    test0.print();

    MyIntArray test1(9);
    test1.print();
    /*cin >> test1;
    cout << "test1: ";
    test1.print();*/

    cout << "Phan tu thu 1: " << test1[1] << endl;

    test0 = test1;
    cout << "test0: " << endl;
    test0.print();


    cout << "MyIntArray t2(test1): ";
    MyIntArray t2(test1);


    cout << "MyIntArray t = test1: ";
    MyIntArray t = test1;


    cout << "t = test1: ";
    t = test1;
    return 1;
}

//copy constructor được gọi khi khai 1 biến khởi tạo giá trị cho biến đó
// bất kế toán tử gán gía trị là () hay là dấu bằng '='
//Assignment Operator Overloading:
// được gọi khi gán giá trị vào một biến đã được khai báo sẵn trước đó bằng toán tử bằng
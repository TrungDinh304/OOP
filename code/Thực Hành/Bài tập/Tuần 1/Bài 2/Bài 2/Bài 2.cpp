#include <iostream>
#include"List.h"
#include"Stack.h"
using namespace std;




int main()
{
    ////============================test bài 1==============================
    //list test1;
    ////insert các chuỗi vào list
    //test1.insert(0, "1. you are the greatest one i've ever seen <3.");
    //test1.insert(0, "2. you are the greatest one i've ever seen <3.");
    //test1.insert(0, "3. you are the greatest one i've ever seen <3.");
    //test1.insert(0, "4. you are the greatest one i've ever seen <3.");
    //test1.insert(0, "5. you are the greatest one i've ever seen <3.");
    ////lấy độ dài của list
    //cout << test1.size() << endl;
    //test1.print();
    ////xóa 1 phần tử với vị trí ko tồn tại trong list
    //test1.erase(5);
    ////in ra phần tử đầu tiên trong list
    //cout << test1.get(0) << endl;
    ////xóa phần tử thứ 3 trong list.
    //test1.erase(3);
    //test1.print();

    ////xóa phần tử trong danh sách với số lượng xóa > size hiện tại 
    //test1.erase(0);
    //test1.erase(0);
    //test1.erase(0);
    //test1.erase(0);
    //test1.erase(0);

    //==========================TEST BÀI 2======================================

   Stack test2;
    test2.push("1. you are the greatest one I've ever seen <3.");
    test2.push("2. you are the greatest one I've ever seen <3.");
    test2.push("3. you are the greatest one I've ever seen <3.");
    test2.push("4. you are the greatest one I've ever seen <3.");
    test2.push("5. you are the greatest one I've ever seen <3.");

    cout << test2.size() << endl;
    test2.print();
    test2.pop();
    test2.pop();
    cout << "Top: " << test2.top() << endl;
    test2.pop();
    test2.pop();
    test2.pop();
    test2.pop();
    test2.pop();
    test2.pop();
    test2.pop();



    return 0;
}


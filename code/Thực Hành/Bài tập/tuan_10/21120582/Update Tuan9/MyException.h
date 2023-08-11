#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
#include <string>
using namespace std;
class MyException {
private:
	string message;
public:
	MyException() {
		message = "";
	}
	MyException(string msg) {
		message = msg;
	}
	string getMessage() {
		return message;
	}
};
#endif
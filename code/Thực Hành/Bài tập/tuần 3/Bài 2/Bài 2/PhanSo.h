#pragma once 
#include <iostream>
#include <string>
#include <sstream>
using namespace std;



class PhanSo {
private:
    int _tu, _mau;
    int UCLN(int, int);
public:
    PhanSo();
    PhanSo(int, int);
    PhanSo(const PhanSo&);
    ~PhanSo();
    int getTu();
    void setTu(int);
    int getMau();
    void setMau(int);
    string toString();

    PhanSo& operator=(const PhanSo&);
    const PhanSo operator+(const PhanSo&) const;
    const PhanSo operator-(const PhanSo&) const;
    const PhanSo operator*(const PhanSo&) const;
    const PhanSo operator/(const PhanSo&) const;
    PhanSo operator++();
    PhanSo operator++(int);
    PhanSo operator--();
    PhanSo operator--(int);
    bool operator>(const PhanSo&)const;
    bool operator<(const PhanSo&)const;
    bool operator==(const PhanSo&)const;

    void toigian();
    void Hoanvi(PhanSo&);

    friend istream& operator>>(istream& in, PhanSo& src);
    friend ostream& operator<<(ostream& out, const PhanSo& src);
   
    


};
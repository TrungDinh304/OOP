#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int UCLN(int a, int b)
{
    if(a==0||b==0)
        return a+b;
    return UCLN(b, a%b);
}

class PhanSo{
private:
    int _tu,_mau;
public:
    PhanSo();
    PhanSo(int, int);
    PhanSo(const PhanSo&);
    ~PhanSo();
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

    void toigian();

friend istream& operator>>(istream &in,PhanSo& src);
friend ostream& operator<<(ostream &out, const PhanSo& src);

};

PhanSo::PhanSo(){
    _tu = 0;
    _mau = 1;
}

PhanSo::PhanSo(int tu, int mau){
    _tu = tu;
    _mau = mau;
}

PhanSo::PhanSo(const PhanSo& other){
    this->_tu = other._tu;
    this->_mau = other._mau;
}

PhanSo::~PhanSo(){
    cout << "Da huy phan so.\n";
}

string PhanSo::toString(){
    stringstream builder;
    builder << "(" << _tu << "/" << _mau << ")";
    return builder.str();
}

PhanSo&PhanSo::operator=(const PhanSo& other){
    this->_tu = other._tu;
    this->_mau = other._mau;
    return *this;
}

const PhanSo PhanSo::operator+(const PhanSo& other) const{
    int tuMoi =_tu*other._mau+other._tu*_mau;
    int mauMoi = _mau * other._mau;
    PhanSo result(tuMoi, mauMoi);
    result.toigian();
    return result;
}

const PhanSo PhanSo::operator-(const PhanSo& other) const{
    int tuMoi =_tu*other._mau-other._tu*_mau;
    int mauMoi = _mau * other._mau;
    PhanSo result(tuMoi, mauMoi);
    result.toigian();
    return result;
}

const PhanSo PhanSo::operator*(const PhanSo& other) const{
    int tuMoi =_tu*other._tu;
    int mauMoi = _mau * other._mau;
    PhanSo result(tuMoi, mauMoi);
    result.toigian();
    return result;
}

const PhanSo PhanSo::operator/(const PhanSo& other) const{
    int tuMoi =_tu*other._mau;
    int mauMoi = _mau * other._tu;
    PhanSo result(tuMoi, mauMoi);
    result.toigian();
    return result;
}

PhanSo PhanSo::operator++()
{
    PhanSo mot(1,1);
    *this = *this + mot;
    return *this;
}

PhanSo PhanSo::operator++(int a )
{
    PhanSo temp=*this;
    PhanSo mot(1,1);
    *this = *this + mot;
    return temp;
}

PhanSo PhanSo::operator--()
{
    PhanSo mot(1,1);
    *this = *this - mot;
    return *this;
}

PhanSo PhanSo::operator--(int a )
{
    PhanSo temp=*this;
    PhanSo mot(1,1);
    *this = *this - mot;
    return temp;
}


istream&operator>>(istream &in, PhanSo& src){
    cout << "Tu: ";
    in >> src._tu;
    cout << "Mau: ";
    in >> src._mau;
    return in;
}

ostream&operator<<(ostream &out,const PhanSo& src){
    out << "("<< src._tu << "/" << src._mau << ")\n";
    return out;
}

void PhanSo::toigian()
{
    int uocChung=UCLN(_mau,_tu);
    _mau/=uocChung;
    _tu/=uocChung;
}

int main(){
    PhanSo s1(1,6), s2(1,6);
    PhanSo s3 = s1 + s2;

    cout << s1.toString() << "*" << s2.toString() << "=" << s3 << endl;
    s3.toigian();
    cout<< s3;
    cin>>s3;
    s3.toigian();
    cout<<s3;
    return 0; 
}
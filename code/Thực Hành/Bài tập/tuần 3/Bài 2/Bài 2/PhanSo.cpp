#include "PhanSo.h"

int PhanSo::getTu()
{
    return _tu;
}

void PhanSo::setTu(int tu)
{
    _tu = tu;
}

int PhanSo::getMau()
{
    return _mau;
}

void PhanSo::setMau(int mau)
{
    _mau = mau;
}


PhanSo::PhanSo() {
    _tu = 0;
    _mau = 1;
}

PhanSo::PhanSo(int tu, int mau) {
    _tu = tu;
    _mau = mau;
}

PhanSo::PhanSo(const PhanSo& other) {
    this->_tu = other._tu;
    this->_mau = other._mau;
}

PhanSo::~PhanSo() {

}

string PhanSo::toString() {
    stringstream builder;
    builder << "(" << _tu << "/" << _mau << ")";
    return builder.str();
}

PhanSo& PhanSo::operator=(const PhanSo& other) {
    this->_tu = other._tu;
    this->_mau = other._mau;
    return *this;
}

const PhanSo PhanSo::operator+(const PhanSo& other) const {

    int tuMoi = _tu * other._mau + other._tu * _mau;
    int mauMoi = _mau * other._mau;
    PhanSo result(tuMoi, mauMoi);
    result.toigian();
    return result;
}

const PhanSo PhanSo::operator-(const PhanSo& other) const {

    int tuMoi = _tu * other._mau - other._tu * _mau;
    int mauMoi = _mau * other._mau;
    PhanSo result(tuMoi, mauMoi);
    result.toigian();
    return result;
}

const PhanSo PhanSo::operator*(const PhanSo& other) const {
    int tuMoi = _tu * other._tu;
    int mauMoi = _mau * other._mau;
    PhanSo result(tuMoi, mauMoi);
    //result.toigian();
    return result;
}

const PhanSo PhanSo::operator/(const PhanSo& other) const {

    int tuMoi = _tu * other._mau;
    int mauMoi = _mau * other._tu;
    PhanSo result(tuMoi, mauMoi);
    //result.toigian();
    return result;
}

PhanSo PhanSo::operator++()
{
    PhanSo mot(1, 1);
    *this = *this + mot;
    return *this;
}

PhanSo PhanSo::operator++(int a)
{
    PhanSo temp = *this;
    PhanSo mot(1, 1);
    *this = *this + mot;
    return temp;
}

PhanSo PhanSo::operator--()
{
    PhanSo mot(1, 1);
    *this = *this - mot;
    return *this;
}

PhanSo PhanSo::operator--(int a)
{
    PhanSo temp = *this;
    PhanSo mot(1, 1);
    *this = *this - mot;
    return temp;
}

bool PhanSo::operator<(const PhanSo& other)const
{
    return _tu * other._mau < other._tu * _mau;
}
bool PhanSo::operator>(const PhanSo& other)const
{
    return _tu * other._mau > other._tu * _mau;
}
bool PhanSo::operator==(const PhanSo& other)const
{
    return _tu * other._mau == other._tu * _mau;
}


void PhanSo::Hoanvi(PhanSo& other)
{
    PhanSo temp = *this;
    *this = other;
    other = temp;
}


istream& operator>>(istream& in, PhanSo& src) {
    cout << "Tu: ";
    in >> src._tu;
    cout << "Mau: ";
    in >> src._mau;
    return in;
}

ostream& operator<<(ostream& out, const PhanSo& src) {
    out << src._tu << "/" << src._mau;
    return out;
}

void PhanSo::toigian()
{
    int uocChung = UCLN(_mau, _tu);
    _mau /= uocChung;
    _tu /= uocChung;
}

int PhanSo::UCLN(int a,int b)
{
    if (a == 0 || b == 0)
        return a + b;
    return UCLN(b, a % b);
}
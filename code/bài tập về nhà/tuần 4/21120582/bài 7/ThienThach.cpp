#include "ThienThach.h"

ThienThach::ThienThach()
{
	Ma = "";
	toado.setX(0);
	toado.setY(0);
	banKinh = 0;
	vantoc = 0;
}

ThienThach::ThienThach(string Ma_, Point toado_, double bankinh_, double vantoc_)
{
	Ma = Ma_;
	toado = toado_;
	banKinh = bankinh_;
	vantoc=vantoc_;
}

string ThienThach::getMa()
{
	return Ma;
}

Point ThienThach::getToaDo()
{
	return toado;
}

double ThienThach::getbanKinh()
{
	return banKinh;
}
double ThienThach::getvantoc()
{
	return vantoc;
}

double ThienThach::tg_chamDat()
{
	Point tam(0, 0);
	double quangDuong = toado.distance(tam) - banKinh;
	return quangDuong / vantoc;
}

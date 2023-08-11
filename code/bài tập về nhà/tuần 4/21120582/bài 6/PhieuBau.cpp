#include "PhieuBau.h"

PhieuBau::PhieuBau()
{
	MaCaSi = "";
	TenCaSi = "";
	hople = false;
}

string PhieuBau::getMa()
{
	return MaCaSi;
}

string PhieuBau::getTen()
{
	return TenCaSi;
}

bool PhieuBau::getHople()
{
	return hople;
}

void PhieuBau::setMa(string Ma)
{
	MaCaSi = Ma;
}

void PhieuBau::setTen(string Ten)
{
	TenCaSi = Ten;
}




bool PhieuBau::Hople(Time start, Time finish,Time TgBau)
{
	hople = (TgBau > start && TgBau < finish);
	return hople;
}


#include "Person.h"



Person::Person()
{
	identity = 0;
}

Person::Person(long id) : identity(id)
{
	assert(identity >= 100000000 && identity <= 999999999);
}

Person::~Person()
{

}

Person::Person(const Person& person)
{
	this->identity = person.identity;
}

long Person::getId()const
{
	return identity;
}

void Person::setId(long identity)
{
	assert(identity >= 100000000 && identity <= 999999999);
	this->identity = identity;
}

void Person::print()
{
	cout << "ID: " << identity<<endl;
}


Person& Person::operator =(const Person& source)
{
	identity = source.identity;
	return *this;
}
Person& Person::operator +=(const Person& other)
{
	identity += other.identity;
	return *this;
}
Person& Person::operator -=(const Person& other)
{
	identity -= other.identity;
	return *this;
}
Person& Person::operator *=(const Person& other)
{
	identity *= other.identity;
	return *this;
}
Person& Person::operator /=(const Person& other)
{
	identity /= other.identity;
	return *this;
}
Person& Person::operator %=(const Person& other)
{
	identity %= other.identity;
	return *this;
}

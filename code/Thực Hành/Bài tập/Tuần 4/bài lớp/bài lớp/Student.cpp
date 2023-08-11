#include "Student.h"

Student::Student():Person()
{
	gpa = 0;
}

Student::Student(long id, double gp): Person(id), gpa(gp)
{
	assert(gpa >= 0.0 && gpa <= 10.0);
}
Student::~Student()
{

}

Student::Student(const Student& student):Person(student)
{
	gpa = student.gpa;
}

double Student::getGpa()const
{
	return gpa;
}

void Student::setGpa(double gpa)
{
	assert(gpa >= 0.0 && gpa <= 10.0);
	this->gpa = gpa;
}

void Student::print()
{
	Person::print();
	cout << "GPA: " << gpa << endl;
}


Student& Student::operator =(const Student& source)
{
	//this->setId(source.getId());
	Person::operator=(source);
	gpa = source.gpa;
	return *this;
}
Student& Student::operator +=(const Student& other)
{
	/*this->setId(other.getId() + this->getId());*/
	Person::operator+=(other);
	gpa += other.gpa;
	return *this;
}
Student& Student::operator -=(const Student& other)
{
	/*this->setId( this->getId() - other.getId() );*/
	Person::operator-=(other);
	gpa -= other.gpa;
	return *this;
}
Student& Student::operator *=(const Student& other)
{
	//this->setId(other.getId() * this->getId());
	Person::operator*=(other);
	gpa *= other.gpa;
	return *this;
}
Student& Student::operator /=(const Student& other)
{
	//this->setId(this->getId() / other.getId());
	Person::operator/=(other);
	gpa /= other.gpa;
	return *this;
}
Student& Student::operator %=(const Student& other)
{
	//this->setId(this->getId() % other.getId());
	Person::operator%=(other);
	double a = gpa / other.gpa;
	gpa = gpa - a * other.gpa;
	return *this;
}
#include "Point.h"
Point::Point()
{
	x = y = 0;
}

Point::Point(float x_, float y_)
{
	x = x_;
	y = y_;
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}

void Point::setX(float alter)
{
	x = alter;
}

void Point::setY(float alter)
{
	y = alter;
}

double Point::distance(const Point& other)
{
	return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}



#pragma once
#include<math.h>
class Point
{
private:
	float x, y;
public:
	Point();
	Point(float, float);
	float getX();
	float getY();
	void setX(float);
	void setY(float);
	double distance(const Point& other);
};


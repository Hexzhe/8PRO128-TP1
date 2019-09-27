#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Segment.h"

class Circle
{
public:
	Circle(Segment radius = Segment(0, 0));
	~Circle() {};

	Circle MoveRelative(double countX, double countY);
	std::string Info();
	double Area();
	double Circumference();
	double Diameter();
private:
	Segment Radius;
};


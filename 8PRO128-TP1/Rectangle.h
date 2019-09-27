#pragma once
#include "Segment.h"

class Rectangle
{
public:
	Rectangle(Point h2 = Point(0, 0), Point hb = Point(0, 0), Point b2 = Point(0, 0));
	~Rectangle() {};

	Rectangle MoveRelative(double countX, double countY);
	std::string Info();
	double Area();
	double Perimeter();
	double Diag();
private:
	Segment Base;
	Segment Height;
};


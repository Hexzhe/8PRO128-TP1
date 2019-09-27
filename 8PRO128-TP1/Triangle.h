#pragma once
#include "Segment.h"
#include <stdexcept>

class Triangle
{
public:
	Triangle(Point a = Point(0, 0), Point b = Point(0, 0), Point c = Point(0, 0));
	~Triangle() {};

	Triangle MoveRelative(double countX, double countY);
	std::string Info();
	double Area();
	double Perimeter();
	double Height(std::string base = "B");
private:
	Segment SegA;
	Segment SegB;
	Segment SegC;
};


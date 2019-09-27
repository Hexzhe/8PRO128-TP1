#pragma once
#include <cmath>
#include "Point.h"

class Segment
{
public:
	Segment(Point a = Point(0, 0), Point b = Point(0, 0));
	~Segment() {};

	Segment MoveAbsolute(Point newA, Point newB);
	Segment MoveRelative(double countX, double countY);
	std::string Info();
	double Length();
private:
	Point PointA;
	Point PointB;
};


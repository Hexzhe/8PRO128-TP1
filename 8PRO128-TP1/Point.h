#pragma once
#include <string>

class Point
{
private:
	double X;
	double Y;
public:
	Point(double x = 0, double y = 0);
	~Point() {};

	Point MoveAbsolute(double x, double y);
	Point MoveRelative(double countX, double countY);
	std::string Info();
};
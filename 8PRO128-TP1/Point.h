#pragma once
#include <string>

class Point
{
public:
	Point(double x = 0, double y = 0);
	~Point() {};

	double GetX();
	double GetY();

	Point MoveAbsolute(double x, double y);
	Point MoveRelative(double countX, double countY);
	std::string Info();
private:
	double X;
	double Y;
};
#include "Point.h"

Point::Point(double x, double y)
{
	this->X = x;
	this->Y = y;
}

Point Point::MoveAbsolute(double x, double y)
{
	this->X = x;
	this->Y = y;

	return *this;
}

Point Point::MoveRelative(double countX, double countY)
{
	this->MoveAbsolute(this->X + countX, this->Y + countY);

	return *this;
}

std::string Point::Info()
{
	return std::string("Type: Point, X: " + std::to_string(this->X) + ", Y: " + std::to_string(this->Y));
}

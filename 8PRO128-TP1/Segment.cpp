#include "Segment.h"

Segment::Segment(Point a, Point b)
{
	this->PointA = a;
	this->PointB = b;
}

Segment Segment::MoveAbsolute(Point newA, Point newB)
{
	this->PointA.MoveAbsolute(newA.GetX(), newA.GetY());
	this->PointB.MoveAbsolute(newB.GetX(), newB.GetY());

	return *this;
}

Segment Segment::MoveRelative(double countX, double countY)
{
	this->PointA.MoveRelative(countX, countY);
	this->PointB.MoveRelative(countX, countY);

	return *this;
}

std::string Segment::Info()
{
	return std::string("P1: " + this->PointA.Info() + ", P2: " + this->PointB.Info() + ", Length: " + std::to_string(this->Length()));
}

double Segment::Length()
{
	double diffX = this->PointA.GetX() - this->PointB.GetX();
	double diffY = this->PointA.GetY() - this->PointB.GetY();
	return std::sqrt((diffX * diffX) + (diffY * diffY));
}

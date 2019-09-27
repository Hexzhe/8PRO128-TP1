#include "Circle.h"

Circle::Circle(Segment radius)
{
	this->Radius = radius;
}

Circle Circle::MoveRelative(double countX, double countY)
{
	this->Radius.MoveRelative(countX, countY);

	return *this;
}

std::string Circle::Info()
{
	return std::string("Area: " + std::to_string(this->Area()) + ", Circumference: " + std::to_string(this->Circumference()) + ", Diameter: " + std::to_string(this->Diameter()) + "\n  Radius:\n    " + this->Radius.Info());
}

double Circle::Area()
{
	return M_PI*(this->Radius.Length() * this->Radius.Length());
}

double Circle::Circumference()
{
	return 2*M_PI*this->Radius.Length();
}

double Circle::Diameter()
{
	return 2*this->Radius.Length();
}

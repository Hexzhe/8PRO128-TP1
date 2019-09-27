#include "Triangle.h"

Triangle::Triangle(Point a, Point b, Point c)
{
	this->SegA = Segment(a, b);
	this->SegB = Segment(b, c);
	this->SegC = Segment(c, a);
}

Triangle Triangle::MoveRelative(double countX, double countY)
{
	this->SegA.MoveRelative(countX, countY);
	this->SegB.MoveRelative(countX, countY);
	this->SegC.MoveRelative(countX, countY);

	return *this;
}

std::string Triangle::Info()
{
	return std::string("Area: " + std::to_string(this->Area()) + ", Perimeter: " + std::to_string(this->Perimeter()) + ", Height: " + std::to_string(this->Height()) + "\n  SegA:\n    " + this->SegA.Info() + ",\n  SegB:\n    " + this->SegB.Info() + ",\n  SegC:\n    " + this->SegC.Info());
}

double Triangle::Area()
{
	return std::sqrt(this->Perimeter() * (this->Perimeter() - this->SegA.Length()) * (this->Perimeter() - this->SegB.Length()) * (this->Perimeter() - this->SegC.Length()));
}

double Triangle::Perimeter()
{
	return this->SegA.Length() + this->SegB.Length() + this->SegC.Length();
}

double Triangle::Height(std::string base)
{
	Segment b;

	if (base == "A")
		b = this->SegA;
	else if (base == "B")
		b = this->SegB;
	else if (base == "C")
		b = this->SegC;
	else
		throw std::invalid_argument("double Triangle::Height(std::string base)'s base must be either 'A', 'B' or 'C'");

	return 2*(this->Area()/b.Length());
}

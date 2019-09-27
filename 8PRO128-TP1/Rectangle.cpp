#include "Rectangle.h"

Rectangle::Rectangle(Point h2, Point hb, Point b2)
{
	this->Height = Segment(hb, h2);
	this->Base = Segment(hb, b2);
}

Rectangle Rectangle::MoveRelative(double countX, double countY)
{
	this->Base.MoveRelative(countX, countY);
	this->Height.MoveRelative(countX, countY);

	return *this;
}

std::string Rectangle::Info()
{
	return std::string("Area: " + std::to_string(this->Area()) + ", Perimeter: " + std::to_string(this->Perimeter()) + ", Diag: " + std::to_string(this->Diag()) + "\n  Base:\n    " + this->Base.Info() + ",\n  Height:\n    " + this->Height.Info());
}

double Rectangle::Area()
{
	return this->Base.Length()*this->Height.Length();
}

double Rectangle::Perimeter()
{
	return (2*this->Base.Length())+(2*this->Height.Length());
}

double Rectangle::Diag()
{
	return std::sqrt((this->Base.Length()* this->Base.Length()) + (this->Height.Length() * this->Height.Length()));
}

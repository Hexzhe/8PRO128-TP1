#pragma once
#include <string>
#include "Point.h"
#include "Segment.h"
#include "Triangle.h"
#include "Rectangle.h"

template<class T>
class NamedItem
{
public:
	NamedItem(std::string name = "", T item = NULL)
	{
		this->Name = name;
		this->Item = item;
	};
	~NamedItem() {};

	std::string Name;
	T Item;

	std::string Info()
	{
		return "Name: " + this->Name;
	};
};

template<>
std::string NamedItem<Point>::Info()
{
	return "Name: " + this->Name + ", Type: Point, " + this->Item.Info();
};

template<>
std::string NamedItem<Segment>::Info()
{
	return "Name: " + this->Name + ", Type: Segment, " + this->Item.Info();
};

template<>
std::string NamedItem<Triangle>::Info()
{
	return "Name: " + this->Name + ", Type: Triangle, " + this->Item.Info();
};

template<>
std::string NamedItem<Rectangle>::Info()
{
	return "Name: " + this->Name + ", Type: Rectangle, " + this->Item.Info();
};
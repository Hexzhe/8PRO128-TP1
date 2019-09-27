#pragma once
#include <string>
#include "Point.h"
#include "Segment.h"

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
	return "Name: " + this->Name + ", " + this->Item.Info();
};

template<>
std::string NamedItem<Segment>::Info()
{
	return "Name: " + this->Name + ", " + this->Item.Info();
};
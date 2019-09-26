#pragma once
#include <string>

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
};
#pragma once
#include <string>

template<class T>
class NamedItem
{
public:
	NamedItem();
	std::string Name;
	T Item;
};
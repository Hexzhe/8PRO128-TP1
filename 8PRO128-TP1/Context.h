#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "NamedItem.h"
#include "Point.h"
#include <algorithm>

class Context
{
public:
	Context() {};
	~Context() {};

	void CommandCreate(std::string* command);
	void CommandDelete(std::string* command);
	void CommandMove(std::string* command);
	void CommandSlide(std::string* command);
	void CommandShow(std::string* command);
	void CommandShowAll(std::string* command);
private:
	std::vector<NamedItem<Point>> Points;
	std::vector<NamedItem<Point>>::iterator GetPoint(std::string name);
	void CreatePoint(std::string* command);

	std::string FindTypeByName(std::string name);
	bool IsNameAvailable(std::string name);
	Point GetPointFromString(std::string str);
};
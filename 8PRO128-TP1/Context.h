#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "NamedItem.h"

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

	std::vector<NamedItem<Segment>> Segments;
	std::vector<NamedItem<Segment>>::iterator GetSegment(std::string name);
	void CreateSegment(std::string* command);

	std::vector<NamedItem<Triangle>> Triangles;
	std::vector<NamedItem<Triangle>>::iterator GetTriangle(std::string name);
	void CreateTriangle(std::string* command);

	std::vector<NamedItem<Rectangle>> Rectangles;
	std::vector<NamedItem<Rectangle>>::iterator GetRectangle(std::string name);
	void CreateRectangle(std::string* command);

	std::string FindTypeByName(std::string name);
	bool IsNameAvailable(std::string name);
	Point GetPointFromString(std::string str);
};
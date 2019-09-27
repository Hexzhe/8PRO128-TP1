#include "Context.h"

void Context::CommandCreate(std::string* command)
{
	std::string type = command[1], name = command[2];

	if (!this->IsNameAvailable(name))
	{
		std::cout << "Name \"" + name + "\" is already used" << std::endl;
		return;
	}

	if (type == "point")
		this->CreatePoint(command);
	else if (type == "segment")
		this->CreateSegment(command);
	else
		std::cout << "Error: \"" + type + "\" is not a recognized item (case-sensitive, type \"help\" for command list)" << std::endl;
}

void Context::CommandDelete(std::string* command)
{
	std::string name = command[1];
	std::string findResult = FindTypeByName(name);

	if (findResult == "point")
		this->Points.erase(GetPoint(name));
	else if (findResult == "segment")
		this->Segments.erase(GetSegment(name));
	else
		std::cout << "Error: Name \"" + name + "\" doesn't exist (type \"showall\" to see created item's names)" << std::endl;
}

void Context::CommandMove(std::string* command)
{
	std::string name = command[1], strP1 = command[2], strP2 = command[3];
	std::string findResult = FindTypeByName(name);

	if (strP1 == "")
	{
		std::cout << "Error: Invalid arguments (type \"help\" for command list)" << std::endl;
		return;
	}

	Point p1 = GetPointFromString(strP1);

	if (findResult == "point")
		(*GetPoint(name)).Item.MoveAbsolute(p1.GetX(), p1.GetY());
	else if (findResult == "segment")
	{
		if (strP2 == "")
		{
			std::cout << "Error: Invalid arguments (type \"help\" for command list)" << std::endl;
			return;
		}

		Point p2 = GetPointFromString(strP2);

		(*GetSegment(name)).Item.MoveAbsolute(p1, p2);
	}
	else if (findResult == "?")
		std::cout << "Error: Name \"" + name + "\" doesn't exist (type \"showall\" to see created item's names)" << std::endl;
	else
		std::cout << "Error: Item type \"" + findResult + "\" doesn't support the command MOVE (type \"help\" for command list)" << std::endl;
}

void Context::CommandSlide(std::string* command)
{
	std::string name = command[1], xCount = command[2], yCount = command[3];
	std::string findResult = FindTypeByName(name);

	if (xCount == "" || yCount == "")
	{
		std::cout << "Error: Invalid arguments (type \"help\" for command list)" << std::endl;
		return;
	}

	if (findResult == "point")
		(*GetPoint(name)).Item.MoveRelative(std::stod(xCount), std::stod(yCount));
	else if (findResult == "segment")
		(*GetSegment(name)).Item.MoveRelative(std::stod(xCount), std::stod(yCount));
	else
		std::cout << "Error: Name \"" + name + "\" doesn't exist (type \"showall\" to see created item's names)" << std::endl;
}

void Context::CommandShow(std::string* command)
{
	std::string name = command[1];
	std::string findResult = FindTypeByName(name);

	if (findResult == "point")
		std::cout << (*GetPoint(name)).Item.Info() << std::endl;
	else if (findResult == "segment")
		std::cout << (*GetSegment(name)).Item.Info() << std::endl;
	else
		std::cout << "Error: Name \"" + name + "\" doesn't exist (type \"showall\" to see created item's names)" << std::endl;
}

void Context::CommandShowAll(std::string* command)
{
	if (this->Points.size() < 1 && this->Segments.size() < 1)
	{
		std::cout << "Empty" << std::endl;
		return;
	}

	if (this->Points.size() > 0)
	{
		std::cout << "Points:" << std::endl;
		int i = 1;
		std::for_each(this->Points.begin(), this->Points.end(), [&i](NamedItem<Point>& obj) { std::cout << "  " << i << ". " << obj.Info() << std::endl; i++; });
	}

	if (this->Segments.size() > 0)
	{
		std::cout << "Segments:" << std::endl;
		int i = 1;
		std::for_each(this->Segments.begin(), this->Segments.end(), [&i](NamedItem<Segment>& obj) { std::cout << "  " << i << ". " << obj.Info() << std::endl; i++; });
	}
}

std::vector<NamedItem<Point>>::iterator Context::GetPoint(std::string name)
{
	return std::find_if(this->Points.begin(), this->Points.end(), [name](const NamedItem<Point>& obj) { return obj.Name == name; });
}

void Context::CreatePoint(std::string* command)
{
	std::string name = command[2], strP1 = command[3];

	if (strP1 == "")
	{
		std::cout << "Error: Invalid arguments (type \"help\" for command list)" << std::endl;
		return;
	}

	Point p1 = GetPointFromString(strP1);
	this->Points.push_back(NamedItem<Point>(name, p1));
}

std::vector<NamedItem<Segment>>::iterator Context::GetSegment(std::string name)
{
	return std::find_if(this->Segments.begin(), this->Segments.end(), [name](const NamedItem<Segment>& obj) { return obj.Name == name; });
}

void Context::CreateSegment(std::string* command)
{
	std::string name = command[2], strP1 = command[3], strP2 = command[4];

	if (strP1 == "" || strP2 == "")
	{
		std::cout << "Error: Invalid arguments (type \"help\" for command list)" << std::endl;
		return;
	}

	Point p1 = GetPointFromString(strP1);
	Point p2 = GetPointFromString(strP2);
	this->Segments.push_back(NamedItem<Segment>(name, Segment(p1, p2)));
}

std::string Context::FindTypeByName(std::string name)
{
	if (GetPoint(name) != this->Points.end())
		return "point";
	else if (GetSegment(name) != this->Segments.end())
		return "segment";
	else
		return "?";
}

bool Context::IsNameAvailable(std::string name)
{
	return this->FindTypeByName(name) == "?";
}

Point Context::GetPointFromString(std::string str)
{
	std::vector<std::string> result;

	std::stringstream  data(str);
	std::string line;
	while (std::getline(data, line, ','))
		result.push_back(line);

	if (result.size() != 2)
	{
		std::cout << "Error: Couldn't parse coordinate from \"" << str << "\", used 0,0 instead" << std::endl;
		return Point();
	}

	return Point(std::stod(result[0]), std::stod(result[1]));
}

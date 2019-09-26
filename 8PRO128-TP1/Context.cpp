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
	else
		std::cout << "Error: \"" + type + "\" is not a recognized item (case-sensitive, type \"help\" for command list)" << std::endl;
}

void Context::CommandDelete(std::string* command)
{
	std::string name = command[1];
	std::string findResult = FindTypeByName(name);

	if (findResult == "point")
		this->Points.erase(GetPoint(name));
	else
		std::cout << "Error: Name \"" + name + "\" doesn't exist (use the command \"showall\" to see created item's names)" << std::endl;
}

void Context::CommandMove(std::string* command)
{
	std::string name = command[1], strP1 = command[2];
	std::string findResult = FindTypeByName(name);

	if (strP1 == "")
	{
		std::cout << "Error: Invalid arguments (type \"help\" for command list)" << std::endl;
		return;
	}

	Point p1 = GetPointFromString(strP1);

	if (findResult == "point")
		(*GetPoint(name)).Item.MoveAbsolute(p1.GetX(), p1.GetY());
	else
		std::cout << "Error: Name \"" + name + "\" doesn't exist (use the command \"showall\" to see created item's names)" << std::endl;
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
	else
		std::cout << "Error: Name \"" + name + "\" doesn't exist (use the command \"showall\" to see created item's names)" << std::endl;
}

void Context::CommandShow(std::string* command)
{
	std::string name = command[1];
	std::string findResult = FindTypeByName(name);

	if (findResult == "point")
		std::cout << (*GetPoint(name)).Item.Info() << std::endl;
	else
		std::cout << "Error: Name \"" + name + "\" doesn't exist (use the command \"showall\" to see created item's names)" << std::endl;
}

void Context::CommandShowAll(std::string* command)
{
	if (this->Points.size() < 1)
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

std::string Context::FindTypeByName(std::string name)
{
	if (GetPoint(name) != this->Points.end())
		return "point";
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
		std::cout << "Error: Couldn't parse a coordinate from \"" << str << "\", used 0,0 instead" << std::endl;
		return Point();
	}

	return Point(std::stod(result[0]), std::stod(result[1]));
}

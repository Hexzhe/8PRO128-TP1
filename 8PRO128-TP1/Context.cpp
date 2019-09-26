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
	std::string findResult = FindByName(name);

	if (findResult == "point")
		this->Points.erase(std::find_if(this->Points.begin(), this->Points.end(), [name](const NamedItem<Point>& obj) { return obj.Name == name; }));
	else
		std::cout << "Error: Name \"" + name + "\" doesn't exist (use the command \"showall\" to see created item's names)" << std::endl;
}

void Context::CommandMove(std::string* command)
{
	std::string name = command[1], x = command[2], y = command[3];
	std::string findResult = FindByName(name);

	if (x == "" || y == "")
	{
		std::cout << "Error: Invalid arguments (type \"help\" for command list)" << std::endl;
		return;
	}

	if (findResult == "point")
		(*(std::find_if(this->Points.begin(), this->Points.end(), [name](const NamedItem<Point>& obj) { return obj.Name == name; }))).Item.MoveAbsolute(std::stod(x), std::stod(y)); //Such an elegant language
	else
		std::cout << "Error: Name \"" + name + "\" doesn't exist (use the command \"showall\" to see created item's names)" << std::endl;
}

void Context::CommandSlide(std::string* command)
{
	//TODO
}

void Context::CommandShow(std::string* command)
{
	//TODO
}

void Context::CommandShowAll(std::string* command)
{
	//TODO
	std::cout << "Points: " << this->Points.size() << std::endl;
}

void Context::CreatePoint(std::string* command)
{
	std::string name = command[2], x = command[3], y = command[4];

	if (x == "" || y == "")
	{
		std::cout << "Error: Invalid arguments (type \"help\" for command list)" << std::endl;
		return;
	}

	this->Points.push_back(NamedItem<Point>(name, Point(std::stod(x), std::stod(y))));
}

std::string Context::FindByName(std::string name)
{
	if (std::find_if(this->Points.begin(), this->Points.end(), [&name](const NamedItem<Point>& obj) { return obj.Name == name; }) != this->Points.end())
		return "point";
	else
		return "?";
}

bool Context::IsNameAvailable(std::string name)
{
	return this->FindByName(name) == "?";
}

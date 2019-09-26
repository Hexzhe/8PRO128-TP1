#include <iostream>
#include <sstream>
#include "Context.h"

bool ProcessInput(std::string line, Context* ctx);
void ShowHelp();

int main()
{
	std::cout << "8PRO128-TP1 - Jason Gilbert & Dominique Boivin" << std::endl
		<< "Type \"help\" for command list" << std::endl;

	Context* ctx = new Context();

	while (true)
	{
		std::cout << "> " << std::flush;

		std::string input;
		std::getline(std::cin, input);

		if (!ProcessInput(input, ctx))
			break;
	}

	delete ctx;
	return 0;
}

bool ProcessInput(std::string line, Context* ctx)
{
	if (line.length() == 0)
		return true;

	std::string command[10]; //max one command + 3 args, no spaces exept between args
	std::istringstream iss(line);
	for (size_t i = 0; iss.good() && i < 5; i++)
		iss >> command[i];

	if (command[0] == "help")
	{
		ShowHelp();
	}
	else if (command[0] == "exit")
	{
		std::cout << "Bye" << std::endl;
		return false;
	}
	else if (command[0] == "create")
	{
		ctx->CommandCreate(command);
	}
	else if (command[0] == "delete")
	{
		ctx->CommandDelete(command);
	}
	else if (command[0] == "move")
	{
		ctx->CommandMove(command);
	}
	else if (command[0] == "slide")
	{
		ctx->CommandSlide(command);
	}
	else if (command[0] == "show")
	{
		ctx->CommandShow(command);
	}
	else if (command[0] == "showall")
	{
		ctx->CommandShowAll(command);
	}
	else
		std::cout << "\"" + command[0] + "\" is not a command (case-sensitive, type \"help\" for command list)" << std::endl;

	return true;
}

void ShowHelp()
{
	std::cout << "Help" << std::endl;
}
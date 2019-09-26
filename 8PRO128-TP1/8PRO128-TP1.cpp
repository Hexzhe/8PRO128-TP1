#include <iostream>
#include <sstream>

void ShowHelp()
{
	std::cout << "Help" << std::endl;
}

bool ProcessInput(std::string line)
{
	if (line.length() == 0)
		return true;

	std::string command[10]; //max one command + 9 args, no spaces exept between args
	std::istringstream iss(line);
	for (size_t i = 0; iss.good() && i < 4; i++)
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
	else
		std::cout << "\"" + command[0] + "\" is not a command (case-sensitive, type \"help\" for command list)" << std::endl;

	return true;
}

int main()
{
	std::cout << "8PRO128-TP1 - Jason Gilbert & Dominique Boivin" << std::endl
		<< "Type \"help\" for command list" << std::endl;

	while (true)
	{
		std::cout << "> " << std::flush;

		std::string input;
		std::getline(std::cin, input);

		if (!ProcessInput(input))
			break;
	}

	return 0;
}
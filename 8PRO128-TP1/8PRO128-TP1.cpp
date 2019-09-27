/******************************************************************
* Titre:       Travail pratique #1 (8PRO128\TP1)
* Auteur(e)s:  Dominique Boivin (BOID31609701)
*              Jason Gilbert (GILJ05069703)
* Date:        2019-09-26
* Description: Le programme se présente sous forme d'un terminal
*              classique opérant avec des lignes de commandes.
*              Les commandes disponibles sont documentés grace à
*              la commande HELP comme indiqué au lancement.
*              On peut créer des entités (point, segment, triangle,
*              rectangle et circle) grace à la commande CREATE.
*              On peut par la suite Les déplacer grace aux commandes
*              MOVE (point et segment seulement) et SLIDE (tous).
*              On peut également afficher leurs caracteristiques
*              avec la commande SHOW et SHOWALL et les supprimer
*              avec DELETE. EXIT permet d'arrêter le programme.
*******************************************************************/

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

	std::string command[6]; //max one command + 5 args, no spaces exept between args
	std::istringstream iss(line);
	for (size_t i = 0; iss.good() && i < 7; i++)
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
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

	std::cout << "CREATE: Create a new instance of an item using the given coordinates under a unique name" << std::endl;
	std::cout << "  create [type] [name] [x,y] ?[x,y] ?[x,y]" << std::endl;
	std::cout << "    e.g. \"create point pp 6,9\"" << std::endl;
	std::cout << "    e.g. \"create segment ss 6,9 4,20\"" << std::endl;
	std::cout << "    e.g. \"create triangle tt 6,9 4,20 0,0\"" << std::endl;
	std::cout << "    e.g. \"create rectangle rr 6,9 4,20 0,0\"" << std::endl;
	std::cout << "      The first point represents the second point of the height, the second point represents the first point of the height and the base, and the third point represents the second point of the base" << std::endl;
	std::cout << "    e.g. \"create circle cc 6,9 4,20\"" << std::endl;
	std::cout << "      The first point represents the center of the circle" << std::endl;

	std::cout << "DELETE: Delete an item from your collection using it's unique name" << std::endl;
	std::cout << "  delete [name]" << std::endl;
	std::cout << "    e.g. \"delete pp\"" << std::endl;

	std::cout << "MOVE: Move a point or a segment to a new absolute location using it's unique name" << std::endl;
	std::cout << "  move [name] [x,y] ?[x,y]" << std::endl;
	std::cout << "    e.g. \"move pp 4,20\"" << std::endl;
	std::cout << "    e.g. \"move ss 4,20 6,9\"" << std::endl;

	std::cout << "SLIDE: Translate an item relatively to it's current location using it's unique name" << std::endl;
	std::cout << "  slide [name] [x increment] [y increment]" << std::endl;
	std::cout << "    e.g. \"slide pp 6 -9\"" << std::endl;

	std::cout << "SHOW: Show an item's informations using it's unique name" << std::endl;
	std::cout << "  show [name]" << std::endl;
	std::cout << "    e.g. \"show pp\"" << std::endl;

	std::cout << "SHOWALL: Show all of your item's informations" << std::endl;
	std::cout << "  showall" << std::endl;

	std::cout << "HELP: Show command list" << std::endl;
	std::cout << "  help" << std::endl;

	std::cout << "EXIT: Exit this program" << std::endl;
	std::cout << "  exit" << std::endl;

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}
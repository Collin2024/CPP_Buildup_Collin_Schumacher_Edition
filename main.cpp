/**************************************************************
 * Name:  Collin Schumacher                                   *
 * Project : Buildup Project C++                              *
 * Class : CMPS 366 Organization of Programming Languages	  *
 * Date : 2/7/2023                                            *
 **************************************************************/

#include "headers.h"
#include "Game.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Game buildup;
	int choice = buildup.menu();
	if (choice == 1)
	{
		system("cls");
		buildup.load_game();
	}
	else if (choice == 2)
	{
		system("cls");
		buildup.new_game();
	}
	else
	{
		system("cls");
		cout << "closing Build Up until next time!" << endl;
	}
	return EXIT_SUCCESS;
}

#include "headers.h"
#include "Game.h"
#include "Computer.h"
#include "Human.h"
#include "Round.h"
/* *********************************************************************
Function Name: Game
Purpose: To create a Game object
Parameters:
			none
Return Value:
			none
Algorithm:
			NOT AVAIABLE
Assistance Received: none
********************************************************************* */
Game::Game()
{
	this->player_list = player_list;
}
/* *********************************************************************
Function Name: menu
Purpose: To display the intro menu and validate the input
Parameters:
			none
Return Value:
			returns the selction made
Algorithm:

			1. Display welcome message and options.
			2. Enter the input and repeat steps 1-2. If steps 1-2 result in an invalid option (num<1 or num >3),
			display options and ask for input.

Assistance Received: none
********************************************************************* */
int Game::menu()
{
	int selection = 0;
	cout << "Welcome to Buildup " << endl;
	do
	{
		cout << "Choose from any of these options by entering the number" << endl;
		cout << "1. Load existing game" << endl;
		cout << "2. Play a new game" << endl;
		cout << "3. EXIT Buildup" << endl;
		cout << "Please enter the approiate number: ";
		cin >> selection;
	} while (selection < 1 || selection > 3);
	return selection;
}
/* *********************************************************************
Function Name: load_game
Purpose: To load in a game from a serialization file
Parameters:
			none
Return Value:
			none
Algorithm:

			1. Prompt for filename with the proper input validation.
			If it can't be found, show all .TXT files that the project
			can see and try again.
			2. Inside the entire file, read each line and, WHERE APPROIATE,
			ultilizing pre formatted serialization files (load_memory), then load
			all information in the approiate spots based on the PREDEFINED provided file layout.
			3. Determine first player and display the round.
			4. Play the round.

Assistance Received: thanks to https://superuser.com/questions/382685/list-only-files-of-a-particular-extension-with-the-dir-command
for the help with ONLY showing .TXT files in the directory ultilizing a system call
********************************************************************* */
void Game::load_game()
{
	// Computer's default color
	const char COMPUTER_COLOR_DEFAULT = 'W';
	// Human's default color
	const char HUMAN_COLOR_DEFAULT = 'B';
	// Default system colors will be used if the boneyards are empty 
	// verify that the Default system colors are NOT equal to eachother if they are display error and return
	if (COMPUTER_COLOR_DEFAULT == HUMAN_COLOR_DEFAULT)
	{
		system("cls");
		cerr << "ERROR: auxiliary variable COMPUTER_COLOR_DEFAULT and HUMAN_COLOR_DEFAULT can't equal eachother"<<endl;
		cerr << "SYSTEM ABORT!!" << endl;
		return;
	}
	const string FILE_EXTENSION = ".txt";
	const int MAX = 5000;
	char statement[MAX + 1];
	char line[MAX + 1];
	string names = "";
	string stack;
	ifstream current_game;
	string file;
	string current_turn;
	bool empty_bone_yard = false;
	do
	{
		cout << "Enter a file name of the saved game" << endl;
		cin.ignore();
		cin.getline(statement, MAX + 1);
		file = string(statement);
	} while (file.size() == 0);
	size_t pos = file.find(FILE_EXTENSION);
	if (pos == string::npos)
	{
		file += FILE_EXTENSION;
	}
	current_game.open(file);
	/* if it can't be opened show directory .txt files and prompt again repeat until it
	opens successfully */
	int turn = 0;

	while (current_game.is_open() == false)
	{
		system("cls");
		string command = "dir *";
		
		command += FILE_EXTENSION;
		// shows only the allowed FILE EXTENSION for this project serialization was restricted to .txt files
		system(command.c_str());
		cout << "Enter a file name of the saved game (choose from the list above)" << endl;

		cin.getline(statement, MAX + 1);
		file = string(statement);
		size_t pos = file.find(FILE_EXTENSION);
		if (pos == string::npos)
		{
			file += FILE_EXTENSION;
		}
		current_game.open(file);
	}
	while (current_game.eof() == false)
	{
		current_game.getline(line, MAX + 1, '\n');

		string current_line = string(line) + '\n';
		if (current_line.find("Turn: ") != string::npos)
		{
			memory.clear();
			load_memory(current_line, "Turn: ");
			if (memory.size() > 0)
			{
				current_turn = memory.at(0);
				
			}
			break;
		}
		else if (current_line.find("Computer") != string::npos)
		{
			names = "Computer";
		}
		else if (current_line.find("Human") != string::npos)
		{
			names = "Human";
		}
		else if (current_line.find("Stacks: ") != string::npos)
		{
			stack = current_line;

		}
		else if (current_line.find("Boneyard: ") != string::npos && names.size() != 0)
		{
			
			load_memory(current_line, "Boneyard: ");
			if (memory.size() == 0)
			{
				empty_bone_yard = true;
			}
			if (names == "Computer")
			{
				//if their is no dominoes in the boneyard load the default system color
				if (empty_bone_yard == true)
				{
					player_list.push_back(new Computer(names, COMPUTER_COLOR_DEFAULT));
				}
				else
				{
					player_list.push_back(new Computer(names, color(memory.at(0))));
				}
			}
			else if (names == "Human")
			{
				//if their is no dominoes in the boneyard load the default system color

				if (empty_bone_yard == true)
				{
					player_list.push_back(new Human(names, HUMAN_COLOR_DEFAULT));
					//player_list.push_back(new Computer(names, HUMAN_COLOR_DEFAULT));

				}
				else
				{
					player_list.push_back(new Human(names, color(memory.at(0))));
					//player_list.push_back(new Computer(names, color(memory.at(0))));

				}
			}
			for (int i = 0; i < memory.size(); i++)
			{
				player_list[player_list.size() - 1]->add_to_bone_yard(memory.at(i));
			}
			memory.clear();
			load_memory(stack, "Stacks: ");
			for (int i = 0; i < memory.size(); i++)
			{
				player_list[player_list.size() - 1]->add_to_stack(memory.at(i));
			}
			memory.clear();
		}
		else if (current_line.find("Hand: ") != string::npos && names.size() != 0)
		{
			load_memory(current_line, "Hand: ");
			for (int i = 0; i < memory.size(); i++)
			{
				player_list[player_list.size() - 1]->add_to_hand(memory.at(i));
			}
			memory.clear();
		}
		else if (current_line.find("Score: ") != string::npos && names.size() != 0)
		{
			load_memory(current_line, "Score: ");
			for (int i = 0; i < memory.size(); i++)
			{
				player_list[player_list.size() - 1]->set_score(re_convert(memory.at(i)));
			}
			memory.clear();
		}
		else if (current_line.find("Rounds Won: ") != string::npos && names.size() != 0)
		{
			load_memory(current_line, "Rounds Won: ");
			for (int i = 0; i < memory.size(); i++)
			{
				player_list[player_list.size() - 1]->set_wins(re_convert(memory.at(i)));
			}
			memory.clear();
		}	

	}
	current_game.close();
	const int DRAW = 6;
	
	Round tournament(player_list);	
	tournament.set_loaded(true);
	if (player_list[0]->bone_yard_size() >0 &&current_turn.size() == 0 && player_list[0]->domino_value(player_list[0]->get_at_boneyard_position(0)) == player_list[1]->domino_value(player_list[1]->get_at_boneyard_position(0)))
	{	system("cls");
		tournament.display_round();
		cout << "Sorry both players will have the same size starting domino. Boneyards, Stacks, and Hands will now reset" << endl;
		system("pause");
		while (true)
		{
			
			for (int i = 0; i < player_list.size(); i++)
			{
				player_list[i]->reset_bone_yard();
				for (int j = 0; j < 6; j++)
				{
					player_list[i]->add_to_stack(player_list[i]->draw_domino_from_boneyard());
				}
			}
			if (player_list[0]->domino_value(player_list[0]->get_at_boneyard_position(0)) < player_list[1]->domino_value(player_list[1]->get_at_boneyard_position(0)))
			{
				turn = 1;
				break;
			}
			else if (player_list[0]->domino_value(player_list[0]->get_at_boneyard_position(0)) > player_list[1]->domino_value(player_list[1]->get_at_boneyard_position(0)))
			{
				turn = 0;
				break;
			}
		}
		for (int i = 0; i < player_list.size(); i++)
		{

			if (player_list[i]->hand_size() == 0 && tournament.get_load() == true)
			{
				for (int j = 0; j < DRAW; j++)
				{
					player_list[i]->set_domino(player_list[i]->draw_domino_from_boneyard());

					player_list[i]->add_to_hand(player_list[i]->get_domino());
				}
			}
		}
		tournament.Set_first(turn);

		tournament.play_round();
	}
	for (int i = 0; i < player_list.size(); i++)
	{

		if (player_list[i]->hand_size() == 0 && tournament.get_load() == true)
		{
			for (int j = 0; j < DRAW; j++)
			{
				player_list[i]->set_domino(player_list[i]->draw_domino_from_boneyard());
				
				player_list[i]->add_to_hand(player_list[i]->get_domino());
			}
		}
	}
	for (int i = 0; i < player_list.size(); i++)
	{
		string getter = player_list[i]->get_name();
		if (memory.size() == 0)
		{
			break;
		}
		string mem = memory.at(0);

		mem.pop_back();
		if (getter == mem)
		{
			turn = i;
		}
	}
	tournament.Set_first(turn);
	
	tournament.play_round();
}
/* *********************************************************************
Function Name: new_game
Purpose: To play a new game
Parameters:
			none
Return Value:
			none
Algorithm:
			1. create the players, construct the round, and call play_round from the round class

Assistance Received: none
********************************************************************* */
void Game::new_game()
{
	player_list.push_back(new Computer("Computer", 'W'));
	player_list.push_back(new Human("Human", 'B'));
	//player_list.push_back(new Computer("Human", 'B'));
	Round tourment(player_list);
	tourment.play_round();
}
/* *********************************************************************
Function Name: color
Purpose: To get the color of the domino
Parameters:
			tile- the specified tile passed by value
Return Value:
			return the first character in the tile string
Algorithm:
			1. return the first character in the tile string

Assistance Received: none
********************************************************************* */
char Game::color(string tile)
{
	return tile[0];
}
/* *********************************************************************
Function Name: load_memory
Purpose: To load the parsed line into the game's memory for object initialization (WHEN LOADING IN A SERIALIZATION FILE)
Parameters:
			line- the specified parsed line for loading passed by value
			KEY- the word to look for in the PREFORMATTED SERIALIZATION file passed by value
Return Value:
			none
Algorithm:

			1. Erase the KEY in the line.
			2. Push back the line value and return based on the KEY value.

Assistance Received: none
********************************************************************* */
void Game::load_memory(string line, const string KEY)
{
	const int BONE = 3;
	line.erase(line.begin(), line.begin() + KEY.size());
	if (KEY == "Score: " || KEY == "Rounds Won: ")
	{
		memory.push_back(line);
		return;
	}
	if (KEY == "Turn: ")
	{
		
		memory.clear();
		memory.push_back(line);
		return;
	}
	
	line.erase(remove(line.begin(), line.end(), ' '), line.end());
	if (line.size() <= 1)
	{
		return;
	}
	while (line.size() > 0)
	{
		
		string temp;
		for (int i = 0; i < BONE; i++)
		{
			temp += line[i];
		}
		memory.push_back(temp);
		if (line.size() <= 4)
		{
			return;
		}
		line.erase(line.begin(), line.begin() + BONE);
	}
}
/* *********************************************************************
Function Name: re_convert
Purpose: To convert a string into a number
Parameters:
			line- the string to convert into a number passed by value
Return Value:
			returns the converted number
Algorithm:
			converts the string to a number using stringstream
Assistance Received: none
********************************************************************* */
int Game::re_convert(string line)
{
	int bone;
	stringstream con;
	con << line;
	con >> bone;
	return bone;
}

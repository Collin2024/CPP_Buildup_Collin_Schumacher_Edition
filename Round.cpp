#include "headers.h"
#include "Round.h"
#include "Player.h"

/* *********************************************************************
Function Name: Round
Purpose: To create  Round object
Parameters: none
Return Value:
			none
Algorithm:
			NOT AVAIABLE
Assistance Received: none
********************************************************************* */
Round::Round()
{
	// Nothing to see here
}

/* *********************************************************************
Function Name: Round
Purpose:
			To create a Round object with the 2 players
Parameters:
			loaded_player_list- a list of the players passed by reference
			
Return Value:
			none
Algorithm:
			NOT AVAIABLE
Assistance Received: none
********************************************************************* */
Round::Round(vector<Player*>& loaded_player_list)
{
	this -> player_list = loaded_player_list;
	this->hand_counter = hand_counter;
	this->loaded = loaded;
}
/* *********************************************************************
Function Name: hand_method
Purpose:
			To determine how the hand sets up each round for the players
Parameters:
			none

Return Value:
			none
Algorithm:
			1. If it is a serialized game, return (to exit function).
			2. Reset hands and set next to false. 
			3. If it's the first hand, reset the boneyards and 
			call the first_hand.
			4. If hand is either second or third hand, draw 6 dominoes 
			from their boneyard and add to hand.
			5. ELSE draw 4 dominoes from their boneyard and add to hand.
Assistance Received: none
********************************************************************* */
void Round::hand_method()
{
	const int FINAL_DRAW = 4;
	
	
	if (player_list[0]->bone_yard_size() <= 4 && player_list[0]->bone_yard_size() >= 0 && hand_counter != 4 && get_load() == true)
	{
		hand_counter = 4;
		
	}
	if (player_list[0]->bone_yard_size() == 0 && hand_counter == 2 && get_load() == true)
	{
		hand_counter = 5;
		return;
	}
	if (player_list[0]->bone_yard_size() == 4 && player_list[0]->hand_size() == 1 && get_load() == true)
	{
		hand_counter = 3;
	}
	else if (player_list[0]->bone_yard_size() <= 10 && player_list[0]->bone_yard_size() > 4 && hand_counter != 3 && get_load() == true)
	{
		hand_counter = 3;
	}
	cout << hand_counter << endl;
	if (hand_counter == 1)
	{
		for (int i = 0; i < player_list.size(); i++)
		{
			if (get_load() == false)
			{
				player_list[i]->reset_hand();
				player_list[i]->set_next(false);
			}
		}
		for (int i = 0; i < player_list.size(); i++)
		{
			if (get_load() == false )
			{
				player_list[i]->reset_bone_yard();
			}
		}
		if (get_load() == false || (get_load() == true && is_first > 1))
		{
			
			first_hand();
		}
	}
	else if (hand_counter >= 2 && hand_counter < FINAL_DRAW)
	{
		int times = player_list[0]->bone_yard_size();
		if (times >= 6)
		{
			times = 6;
		}
		if (player_list[0]->hand_size() == 0)
		{
			for (int i = 0; i < player_list.size(); i++)
			{

				for (int j = 0; j < times; j++)
				{
					player_list[i]->add_to_hand(player_list[i]->draw_domino_from_boneyard());
				}

			}
		}
	}
	else
	{
		if (player_list[0] -> hand_size() != 0)
		{
			return;
		}
		for (int i = 0; i < player_list.size(); i++)
		{
			for (int j = 0; j < FINAL_DRAW; j++)
			{
				player_list[i]->add_to_hand(player_list[i]->draw_domino_from_boneyard());
			}
		}
	}
}
/* *********************************************************************
Function Name: play_round
Purpose:
			Play a whole round
Parameters:
			none

Return Value:
			none
Algorithm:
			Please note player_list[0] is computer and player_list[1] is human
			1. If there are NOT 2 players (since its a 2 player game), display error 
			message and terminate.
			2. If it is a serialized game, return set the player at the specified position as first player
			based on the turn: section.
			3. If computer is first, set human to next and computer to false.
			4. Display the round and computer makes its move at this time, then human 
			determines what they want to do. Players both alternate turns until either 
			there are no legal moves or their hand is empty.
			5. Determine the score and announce the winner, move and increment hand counter.
			6. Prompt for another round, and if they want another one, rinse and repeat ELSE 
			announce winner of tourment based on number of rounds won and terminate.

Assistance Received: none
********************************************************************* */
void Round::play_round()
{
	const int MAX_HAND = 4;
	char reply = '\0';
	// if their is less then 2 players error output and return
	if (player_list.size() != 2 )
	{
		system("cls");
		cerr << "Must have 2 players system ABORT!" << endl;
		return;
	}		
	
	do
	{
		if (reply == 'y')
		{
			hand_counter = 1;
			set_loaded(false);
			for (int i = 0; i < player_list.size(); i++)
			{
				player_list[i] -> reset_bone_yard();
				
				player_list[i]->reset_score();
			}
		}
		do
		{

			hand_method();
			if (hand_counter > MAX_HAND)
			{
				break;
			}
			if (get_load() == true && hand_counter == 1)
			{
				player_list[is_first]-> set_first(true);	
			}
			display_round();
			// computer goes first
			if (player_list[0]->is_first() == true || is_first == 0)
			{
				
				cout << player_list[0]->get_name() << " Goes first because";
				if (get_load() == true)
				{
					cout << " it was the first player loaded in from the serialization file" << endl;
				}
				else if(hand_counter == 1)
				{
					cout << " it drew the bigger domino, it drew ";
					cout << player_list[0]->get_at_hand_position(0) << " while " << player_list[1]->get_name() << " drew " << player_list[1]->get_at_hand_position(0) << endl;
				}
				else
				{
					cout << " it was the first player in the round." << endl;
				}
				player_list[1]->set_next(true);
				system("pause");
				display_round();
				do
				{
					for (int a = 0; a < 2; a++)
					{
						for (int b = 1 - a; b >= 0; b--)
						{
							int choice = player_list[a]->selection();
							if (choice == 1)
							{
								save_game();
								return;
							}
							else if (choice == 2)
							{
								player_list[a]->make_move(player_list[b]);
							}
							else if (choice == 3)
							{
								player_list[b]->help_mode(player_list[a]);
								player_list[a]->make_move(player_list[b]);
							}
							else
							{
								return;
							}
							display_round();
							break;
						}
					}
				} while (((player_list[0]->can_move(player_list[1], 1) == true && player_list[1]->can_move(player_list[0], 1) == true) || (player_list[0]->can_move(player_list[1], 1) == true || player_list[1]->can_move(player_list[0], 1) == true)) || (((player_list[0]->can_move(player_list[1], 2) == true && player_list[1]->can_move(player_list[0], 2) == true)) || (player_list[0]->can_move(player_list[1], 2) == true || player_list[1]->can_move(player_list[0], 2) == true)));
				
				player_list[0]->tally_score(player_list[1]);
				player_list[1]->tally_score(player_list[0]);
				
				hand_counter++;				
				player_list[0]->reset_hand();
				player_list[1]->reset_hand();
				set_loaded(false);
				display_round();
			}
			// Human goes first
			else if (player_list[1]->is_first() == true || is_first == 1)
			{
				cout << player_list[1]->get_name() << " Goes first because";
				if (get_load() == true)
				{
					cout << " it was the first player loaded in from the serialization file" << endl;
				}
				else if (hand_counter == 1)
				{
					cout << " it drew the bigger domino, it drew ";
					cout << player_list[1]->get_at_hand_position(0) << " while " << player_list[0]->get_name() << " drew " << player_list[0]->get_at_hand_position(0) << endl;
				}
				else
				{
					cout << " it was the first player in the round." << endl;
				}
				player_list[0]->set_next(true);
				system("pause");
				display_round();
				do
				{
					for (int a = 0; a < 2; a++)
					{
						for (int b = 1-a; b >= 0; b--)
						{
							int choice = player_list[b]->selection();
							if (choice == 1)
							{
								save_game();
								return;
							}
							else if (choice == 2)
							{
								player_list[b]->make_move(player_list[a]);
							}
							else if (choice == 3)
							{
								player_list[a]->help_mode(player_list[b]);								
								player_list[b]->make_move(player_list[a]);
							}
							else
							{
							return;
							}
							display_round();
							break;
						}
					}
				} while (((player_list[0]->can_move(player_list[1], 1) == true && player_list[1]->can_move(player_list[0], 1) == true) || (player_list[0]->can_move(player_list[1], 1) == true || player_list[1]->can_move(player_list[0], 1) == true)) || (((player_list[0]->can_move(player_list[1], 2) == true && player_list[1]->can_move(player_list[0], 2) == true)) || (player_list[0]->can_move(player_list[1], 2) == true || player_list[1]->can_move(player_list[0], 2) == true)));
				player_list[1]->tally_score(player_list[0]);
				player_list[0]->tally_score(player_list[1]);
				hand_counter++;
				player_list[0]->reset_hand();
				player_list[1]->reset_hand();
				display_round();
			}
		} while (hand_counter <= MAX_HAND);
		who_won();
		set_loaded(false);
		player_list[0]->set_first(false);
		player_list[1]->set_first(false);
		display_round();
		do
		{
			cout << "Would you like to play another round? (Enter y for yes or n for no)" << endl;
			cin >> reply;
			reply = tolower(reply);
		} while (reply != 'y' && reply != 'n');
	} while (reply == 'y');
	if (reply == 'n')
	{
		tournament_winner();
	}
}
/* *********************************************************************
Function Name: tournament_winner
Purpose:
			Determine winner of the tournament
Parameters:
			none

Return Value:
			none
Algorithm:
			Please note player_list[0] is computer and player_list[1] is human
			1. If computer has more round wins than human,
			display that the computer won.
			2. ELSE, if the human has more round wins, the computer will
			display that the human won.
			3. Otherwise, display that it's a draw.

Assistance Received: none
********************************************************************* */
void Round::tournament_winner()
{
	if (player_list[0]->get_wins() > player_list[1]->get_wins())
	{
		cout << player_list[0]->get_name() << " has won the tournament with a score of " << player_list[0]->get_wins() << endl;
	}
	else if (player_list[1]->get_wins() > player_list[0]->get_wins())
	{
		cout << player_list[1]->get_name() << " has won the tournament with a score of " << player_list[1]->get_wins() << endl;
	}
	else
	{
		cout << "The tournament is a draw with a score of " << player_list[1]->get_wins() << endl;
	}
}
/* *********************************************************************
Function Name: first_hand
Purpose:
			Set up first hand
Parameters:
			none

Return Value:
			none
Algorithm:
			Please note player_list[0] is computer and player_list[1] is human
			1. Both players will draw 6 tiles from their respective boneyards
			and add them to their stacks.
			2. Both players draw a domino from their boneyard and add to their hand. Player with higher
			domino is the player that goes first. The drawn domino of each player is added to their respective hand.
			3. Draw 5 remaining dominoes from the boneyard and add them to the hand.

Assistance Received: none
********************************************************************* */
void Round::first_hand()
{
	int bone_one = 0;
	int bone_two = 0;
	
	if (hand_counter == 1)
	{
		
		for (int i = 0; i < player_list.size(); i++)
		{
			for (int j = 0; j < 6; j++)
			{
				player_list[i] -> add_to_stack(player_list[i] -> draw_domino_from_boneyard());
			}
		}
		do
		{
			player_list[0] -> set_domino(player_list[0] -> draw_domino_from_boneyard());
			player_list[0] -> add_to_hand(player_list[0] -> get_domino());
			bone_one = player_list[0] -> domino_value(player_list[0] -> get_domino());
			player_list[1] -> set_domino(player_list[1] -> draw_domino_from_boneyard());
			player_list[1] -> add_to_hand(player_list[1] -> get_domino());
			bone_two = player_list[1] -> domino_value(player_list[1] -> get_domino());

			if (bone_one == bone_two)
			{
				player_list[0] -> reset_bone_yard();
				player_list[1] -> reset_bone_yard();
				for (int i = 0; i < player_list.size(); i++)
				{
					for (int j = 0; j < 6; j++)
					{
						player_list[i] -> add_to_stack(player_list[i] -> draw_domino_from_boneyard());
					}
				}
				player_list[0] -> set_domino(player_list[0] -> draw_domino_from_boneyard());
				player_list[0] -> add_to_hand(player_list[0] -> get_domino());
				bone_one = player_list[0] -> domino_value(player_list[0] -> get_domino());
				player_list[1] -> set_domino(player_list[1] -> draw_domino_from_boneyard());
				player_list[1] -> add_to_hand(player_list[1] -> get_domino());
				bone_two = player_list[1] -> domino_value(player_list[1] -> get_domino());
			}
		} while(bone_one == bone_two);
		
		if (bone_one > bone_two)
		{
			player_list[0] -> set_first(true);
		}
		else
		{
			player_list[1] -> set_first(true);
		}
	
		for (int i = 0; i < player_list.size(); i++)
		{
			for (int j = 0; j < 5; j++)
			{
				player_list[i] -> add_to_hand(player_list[i] -> draw_domino_from_boneyard());
			}
		}

	}
}
/* *********************************************************************
Function Name: display_round
Purpose:
			Display the round
Parameters:
			none

Return Value:
			none
Algorithm:
			Please note player_list[0] is computer and player_list[1] is human
			1. Clear terminal window 
			and add them to their stacks.
			2. For each player display their name, stack, boneyard, hand, score, wins IN THAT ORDER.
			3. Display who goes next.

Assistance Received: none
********************************************************************* */
void Round::display_round()
{
	system("cls");
	const int MAX_HAND = 4;
	for (int i = 0; i < player_list.size(); i++)
	{
		cout << player_list[i] -> get_name()<<':' << endl;
		player_list[i] -> display_stack();
		player_list[i] -> display_bone_yard();
		player_list[i] -> display_hand();
		player_list[i] -> display_score();
		player_list[i] -> display_wins();
		
		cout << endl;
	}
	for (int i = 0; i < player_list.size(); i++)
	{
		if (player_list[i]->is_next() == true)
		{
			cout << "Turn: " << player_list[i]->get_name() << endl;
			break;
		}
	}
	if (hand_counter > MAX_HAND)
	{
		cout << "Hand complete" << endl;
	}
	else
	{
		cout << "Hand #" << hand_counter << endl;
	}
	cout << endl;
	system("pause");
}
/* *********************************************************************
Function Name: who_won
Purpose:
			To determine who won the round
Parameters:
			none

Return Value:
			none
Algorithm:
			Please note player_list[0] is computer and player_list[1] is human
			1. If computer has higher score than human,  
			display the computer won with its score.
			2. ELSE, if human has higher score than computer, 
			display the human won with its score.
			3. Otherwise, display that it's a draw.

Assistance Received: none
********************************************************************* */
void Round::who_won()
{
	if (player_list[0] -> get_score() > player_list[1] -> get_score())
	{
		cout << player_list[0] -> get_name() << " has won this round with a score of " << player_list[0] -> get_score() << endl;
		player_list[0] -> winner();
		system("pause");
	}
	else if (player_list[1] -> get_score() > player_list[0] -> get_score())
	{
		cout << player_list[1] -> get_name() << " has won this round with a score of " << player_list[1] -> get_score() << endl;
		player_list[1] -> winner();
		system("pause");

	}
	else
	{
		cout << " The round is a draw better luck next time" << endl;
		system("pause");
	}

}
/* *********************************************************************
Function Name: save_game
Purpose:
			Save the game to a file
Parameters:
			none

Return Value:
			none
Algorithm:
			Please note player_list[0] is computer and player_list[1] is human
			1. Prompt for the serialization file, add the extension(.txt),
			display the computer won with its score.
			2. Open the file and write in the information for the players
			in the following order: Computer, Stacks, Boneyard, Hand, Score, Rounds Won,
			and Turn. Repeat this order for the human player.
			3. Terminate game.

Assistance Received: none
********************************************************************* */
void Round::save_game()
{
	system("pause");
	const string FILE_EXTENSION = ".txt";
	const int MAX = 5000;
	char statement[MAX + 1];
	cout << "Now saving CURRENT GAME . . ." << endl;
	ofstream current_game;
	cout << "Enter a name for THIS GAME" << endl;
	cin.ignore();
	cin.getline(statement, MAX + 1);
	string file = string(statement);
	size_t pos = file.find(FILE_EXTENSION);
	if (pos == string::npos)
	{
		file += FILE_EXTENSION;
	}
	current_game.open(file);
	for (int i = 0; i < player_list.size(); i++)
	{
		current_game << player_list[i]->get_name()<<':' << endl;
		current_game << "	Stacks: ";
		for (int j = 0; j < player_list[i]->stack_size(); j++)
		{
			current_game << player_list[i]->get_at_stack_position(j) << ' ';
		}
		current_game << endl;
		current_game << "	Boneyard: ";
		for (int j = 0; j < player_list[i]->bone_yard_size(); j++)
		{
			current_game << player_list[i]->get_at_boneyard_position(j) << ' ';
		}
		current_game << endl;
		current_game << "	Hand: ";
		for (int j = 0; j < player_list[i]->hand_size(); j++)
		{
			current_game << player_list[i]->get_at_hand_position(j) << ' ';
		}
		current_game << endl;
		current_game << "	Score: " << player_list[i]->get_score() << endl;
		current_game << "	Rounds Won: " << player_list[i]->get_wins() << endl;
		current_game << endl;
	}
	for (int i = 0; i < player_list.size(); i++)
	{
		if (player_list[i]->is_next() == true)
		{
			current_game << "Turn: " << player_list[i]->get_name() << endl;
			current_game << endl;
			return;
		}
	}
}
/* *********************************************************************
Function Name: set_loaded
Purpose: To set the loaded status (for serialization purposes)
Parameters:
			STATE- the specified state (true or false) passed by value
Return Value:
			none
Algorithm:
			1. loaded = LOAD_WINS
Assistance Received: none
********************************************************************* */
void Round::set_loaded(const bool STATE)
{
	loaded = STATE;
}
/* *********************************************************************
Function Name: get_load
Purpose: Determine if  the game was loaded from a file (for serialization purposes)
Parameters:
			none
Return Value:
			returns loaded
Algorithm:
			1. return loaded
Assistance Received: none
********************************************************************* */
bool Round::get_load()
{
	return loaded;
}
/* *********************************************************************
Function Name: set_first
Purpose: To set the first player when game was loaded in from a file (for serialization purposes)
Parameters:
			player- the specified player position passed by value
Return Value:
			none
Algorithm:
			1. is_first = player
Assistance Received: none
********************************************************************* */
void Round::Set_first(int player)
{
	is_first = player;
}
/* *********************************************************************
Function Name: get_first
Purpose: Determine which player got to go first (position wise) when the game was loaded from a file (for serialization purposes)
Parameters:
			none
Return Value:
			returns loaded
Algorithm:
			1. return loaded
Assistance Received: none
********************************************************************* */
int Round::get_first()
{
	return is_first;
}

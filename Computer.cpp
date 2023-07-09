#include "Player.h"
#include "headers.h"

#include "Computer.h"
#include "Domino.h"

/* *********************************************************************
Function Name: Computer
Purpose: To create a Computer object
Parameters:
			none
Return Value:
			none
Algorithm:
			NOT AVAIABLE
Assistance Received: none
********************************************************************* */
Computer::Computer()
{
	// Nothing to see here
}
/* *********************************************************************
Function Name: Computer
Purpose:
			To create a Computer object and setup the board
Parameters:
			name- Name of the Computer passed by value
			player_color- the color of the player passed by value
Return Value:
			none
Algorithm:
			sets the name of the Computer and creates the board for that player and other private variable initalizations
Assistance Received: none
********************************************************************* */
Computer::Computer(string name, char player_color) :Player(name, player_color)
{
	// Nothing to see here
}
/* *********************************************************************
Function Name: make_move
Purpose: To make a move (POLYMORPHIC FUNCTION)
Parameters:
			opponent- the opposing player passed by reference
Return Value:
			none
Algorithm:
			1. Set opponent as next player.
			2. Determine if it's possible to stack a domino on opponent's stacks and that it's not fully seized.
			If so, proceed to step 3. Otherwise, proceed to step 5.
			3. Choose an approiate domino from the hand based on optimal placement.
			4. Determine if the selected domino can be legally placed. If it's possible,
			choose the best stack on opponent's side, stack it on their side, and remove the tile from hand.
			Otherwise, repeat steps 3-4.
			5. Determine if it's possible to stack a domino on your stacks. If so, proceed to step 6. Otherwise,
			computer skips turn.
			6. Choose an approiate domino from the hand based on optimal placement.
			7. Determine if the selected domino can be legally placed. If it's possible,
			choose the best stack on opponent's side, stack it on their side, and remove the tile from hand.
			Otherwise, repeat steps 6-7.
			ELSE, if steps 2-7 are not possible, computer skips turn.
			8. Display approiate computer's strategy.
Assistance Received: none
********************************************************************* */
void Computer::make_move(Player*& opponent)
{	
	opponent->set_next(true);
	set_next(false);
	if (can_move(opponent, 1) == false && can_move(opponent, 2) == false)
	{
		cout << get_name() << " cannot make any moves this means its the " << opponent->get_name() << "'s turn" << endl;
		system("pause");
		return;
	}
	string domino;
	string select;

	if (can_move(opponent, 2) == true)
	{
		int i = 0;
		int j = 0;
		int d = 0;
		int c = 0;
		do
		{
			select = get_at_hand_position(ai_decision(hand_size()));
			//set it to opponents hand for comparison purposes only  
			opponent->set_domino(select);
			domino = opponent->get_at_stack_position(ai_decision(stack_size()));
			while (is_double_domino(select) == true && domino_value(select) < domino_value(domino) && select[0] == domino[0]&& d < 12)
			{
				domino = opponent->get_at_stack_position(ai_decision(stack_size()));
				if (select[0] != domino[0])
				{
					break;
				}
				if (d >= 5)
				{
					domino = get_at_stack_position(ai_decision(stack_size()));
				}
				d++;
			}
			while (select[0] == domino[0] && c < 12 && is_double_domino(select) == true && domino_value(select) <= domino_value(domino))
			{
				if (no_singles() == false)
				{
					select = get_at_hand_position(ai_decision(hand_size()));
					opponent->set_domino(select);
				}
				domino = opponent->get_at_stack_position(ai_decision(stack_size()));
				c++;
			}
			if (is_double_domino(select) == true && no_singles() == false)
			{
				while (is_double_domino(select) == true && j < 6)
				{
					select = get_at_hand_position(ai_decision(hand_size()));
					opponent->set_domino(select);
					j++;
				}
			}
			while (select[0] == domino[0] && i < 12)
			{
				if (no_singles() == true)
				{
					select = get_at_hand_position(ai_decision(hand_size()));
					opponent->set_domino(select);
				}
				domino = opponent->get_at_stack_position(ai_decision(stack_size()));
				i++;
			}
		} while (opponent->determine_legal_placement(domino) == false);
		string strat = computer_strategy(select, domino);
		cout << "The " << get_name() << " chose to pick " << select << " to";
		cout << strat << '.' << endl;
		int stack_location = opponent->domino_location(domino, 'S');

		cout << "It placed " << select << " on stack " << opponent->get_color() << stack_location + 1 << " because";
		cout << " it wanted to maximize tile coverage for a higher score it had " << domino << " on the top" << endl;
		system("pause");

		opponent->cover(domino);
		draw_domino_from_hand(select);
	}
	else if (can_move(opponent, 1) == true)
	{
		do
		{
			select = get_at_hand_position(ai_decision(hand_size()));
			//set it to opponents hand for comparison purposes only  
			set_domino(select);
			domino = get_at_stack_position(ai_decision(stack_size()));
		} while (determine_legal_placement(domino) == false);
		string strat = computer_strategy(select, domino);
		cout << "The " << get_name() << " chose to pick " << select << " to";
		cout << strat << '.' << endl;
		int stack_location = domino_location(domino, 'S');
		if (domino_location(domino, 'S') == -1)
		{
			stack_location = opponent->domino_location(domino, 'S');
			//stack_color = opponent->get_color();
		}
		cout << "It placed " << select << " on stack " << get_color() << stack_location + 1 << " because";
		cout << " it wanted to reclaim tile coverage for a higher score by reclaiming the stack it had " << domino << " on the top" << endl;
		system("pause");
		cover(domino);
		draw_domino_from_hand(select);
	}
}
/* *********************************************************************
Function Name: ai_decision
Purpose: Computer's position used in choosing a position in a specified pile e.g hand or stack
Parameters:
			num- the specified number range passed by value
Return Value:
			returns a random number
Algorithm:
			return rand() % num
Assistance Received: none
********************************************************************* */
int Computer::ai_decision(int num)
{
	return rand() % num;
}
/* *********************************************************************
Function Name: selection
Purpose: POLYMORPHIC FUNCTION to determine what the player wants to do
Parameters:
			none
Return Value:
			returns the selection AKA computer plays to win by ALWAYS choosing to make a move
Algorithm:
			1. return 2 (AKA the option to make a move)
Assistance Received: none
********************************************************************* */
int Computer::selection()
{
	return 2;
}
/* *********************************************************************
Function Name: no_singles
Purpose: To determine if their are ANY singles left
Parameters:
			none
Return Value:
			returns false if it finds a single (or non double domino) ELSE
			return true
Algorithm:
			1. Look at the dominoes of the hand. If it finds one that is NOT a double domino,
			then it returns false.
			2. ELSE, return true.
Assistance Received: none
********************************************************************* */
bool Computer::no_singles()
{
	for (int i = 0; i < hand_size(); i++)
	{
		if (is_double_domino(get_at_hand_position(i)) == false)
		{
			return false;
		}
	}
	return true;
}
/* *********************************************************************
Function Name: help_mode
Purpose: To help the player (POLYMORPHIC FUNCTION since this project ultilizes polymorphic behavior)
Parameters:
			opponent- the opposing player passed by value
Return Value:
			none
Algorithm:

			1. Determine if it's possible for opponent to stack a domino on its opponent's stacks and that it's not fully seized.
			If so, proceed to step 2. Otherwise, proceed to step 4.
			2. Opponent chooses an approiate domino from the hand based on optimal placement.
			3. Determine if the opponent's selected domino can be legally placed. If it's possible, 
			choose the best stack on its opponent's side, stack it on their side, and remove the tile from hand.
			Otherwise, repeat steps 2-3.
			Display its reccommendation.
			4. Determine if it's possible for opponent to stack a domino on its stacks. If so, proceed to step 5. Otherwise, 
			computer skips turn.
			5. Opponent chooses an approiate domino from the hand based on optimal placement.
			6. Determine if the opponent's selected domino can be legally placed. If it's possible, 
			choose the best stack on its opponent's side, stack it on their side, and remove the tile from hand.
			Otherwise, repeat steps 5-6.
			Display its reccommendation

Assistance Received: none
********************************************************************* */
void Computer::help_mode(Player* opponent)
{	
	string select;
	string domino;
	
	if ((opponent->can_move(opponent, 2) == true && opponent->is_fully_seized() == false && is_fully_seized() == false) ||(opponent->can_move(opponent, 2) == true && opponent->can_move(opponent, 1) == false) || opponent->can_move(opponent, 2) == true)
	{
		int i = 0;
		int j = 0;
		int c = 0;
		int a = 0;
		bool switch_stack = false;
		do
		{
			select = opponent->get_at_hand_position(ai_decision(opponent->hand_size()));
			//set it to opponents hand for comparison purposes only  
			opponent->set_domino(select);
			
			domino = get_at_stack_position(ai_decision(stack_size()));

			while (c < 12 && is_double_domino(select) == true && select[0] == domino[0])
			{
				domino = opponent->get_at_stack_position(ai_decision(stack_size()));
				switch_stack = true;
				c++;
			}
			if (is_double_domino(select) == true && no_singles() == false)
			{
				while (is_double_domino(select) == true && j < 6)
				{
					select = opponent->get_at_hand_position(ai_decision(opponent->hand_size()));
					opponent->set_domino(select);
					j++;
				}
			}
			while (select[0] == domino[0] && i < 12)
			{
				if (no_singles() == true)
				{
					select = opponent->get_at_hand_position(ai_decision(opponent->hand_size()));
					opponent->set_domino(select);
				}
				domino = opponent->get_at_stack_position(ai_decision(stack_size()));
				i++;
			}
			a++;
		} while (opponent->determine_legal_placement(domino) == false && a < 5);
		// error checking at its finest for 
			if (a >= 5)
			{
				int i = 0;
				int j = 0;
				do
				{
					select = opponent->get_at_hand_position(ai_decision(opponent->hand_size()));
					//set it to opponents hand for comparison purposes only  
					opponent->set_domino(select);

					domino = opponent->get_at_stack_position(ai_decision(opponent->stack_size()));
					if (is_double_domino(select) == true && no_singles() == false)
					{
						while (is_double_domino(select) == true && j < 6)
						{
							select = opponent->get_at_hand_position(ai_decision(hand_size()));
							opponent->set_domino(select);
							j++;
						}
					}
					while (select[0] == domino[0] && i < 12)
					{
						if (no_singles() == true)
						{
							select = opponent->get_at_hand_position(ai_decision(opponent->hand_size()));
							opponent->set_domino(select);
						}
						domino = opponent->get_at_stack_position(ai_decision(opponent->stack_size()));
						i++;
					}

				} while (opponent->determine_legal_placement(domino) == false);
				int stack_location = opponent->domino_location(domino, 'S');
				string strat = computer_strategy(select, domino);
				cout << "I recommend you draw " << select << " and stack on " << opponent->get_color() << stack_location + 1 << endl;
				cout << "where " << domino << " is on top of the stack and to" << strat << " and allow for maximum tile coverage" << endl;
				cout << "You got this I believe in you! :)" << endl;
				system("pause");
				return;
			}
		
		int stack_location = domino_location(domino, 'S');
		char stack_color = get_color();
		if (switch_stack == true && opponent->domino_location(domino, 'S') == -1)
		{
			stack_location = opponent->domino_location(domino, 'S');
			stack_color = opponent->get_color();
		}
		else if (domino_location(domino, 'S') == -1)
		{
			stack_location = opponent->domino_location(domino, 'S');
			stack_color = opponent->get_color();
		}
		cout << "I recommend draw "<< select << " and stack on "<< stack_color << stack_location + 1<<endl;
		string strat = computer_strategy(select, domino);
		cout << "where " << domino << " is on top of the stack and to" << strat << " and allow for maximum tile coverage" << endl;
		cout << "You got this I believe in you! :)" << endl;
		system("pause");
	}
	else if (opponent->can_move(opponent, 1) == true)
	{
		int i = 0;
		int j = 0;
		do
		{
			select = opponent->get_at_hand_position(ai_decision(opponent->hand_size()));
			//set it to opponents hand for comparison purposes only  
			opponent->set_domino(select);

			domino = opponent->get_at_stack_position(ai_decision(opponent->stack_size()));
			if (is_double_domino(select) == true && no_singles() == false)
			{
				while (is_double_domino(select) == true && j < 6)
				{
					select = opponent->get_at_hand_position(ai_decision(hand_size()));
					opponent->set_domino(select);
					j++;
				}
			}
			while (select[0] == domino[0] && i < 12)
			{
				if (no_singles() == true)
				{
					select = opponent->get_at_hand_position(ai_decision(opponent->hand_size()));
					opponent->set_domino(select);
				}
				domino = opponent->get_at_stack_position(ai_decision(opponent->stack_size()));
				i++;
			}

		} while (opponent->determine_legal_placement(domino) == false);
		int stack_location = opponent->domino_location(domino, 'S');
		string strat = computer_strategy(select, domino);
		cout << "I recommend you draw " << select << " and stack on " << opponent->get_color() << stack_location + 1 << endl;
		cout << "where " << domino << " is on top of the stack and to" << strat <<" and allow for maximum tile coverage" << endl;
		cout << "You got this I believe in you! :)" << endl;
		system("pause");
	}
	
}
/* *********************************************************************
Function Name: computer_strategy
Purpose: to determine its method
Parameters:
			select- the selected domino from the hand passed by value
			domino- the selected domino from the stack passed by value
Return Value:
			returns the approiate method
Algorithm:
			1. If select is more than domino, and select is a double domino,
			return " increase a stack".
			Then, it returns false.
			2. ELSE, if select is equal to domino, and select is NOT a double domino,
			return " seize a stack".
			3. ELSE, if select is less than domino, and select and domino are both doubles,
			return " reset a stack".
Assistance Received: none
********************************************************************* */
string Computer::computer_strategy(string select, string domino)
{
	string strat;
	if (domino_value(select) > domino_value(domino) && is_double_domino(select) == false)
	{
		strat = " increase a stack";
	}
	else if (domino_value(select) == domino_value(domino) && is_double_domino(select) == false)
	{
		strat = " seize a stack";
	}
	else if (domino_value(select) < domino_value(domino) && is_double_domino(select) == true && is_double_domino(domino) == false)
	{
		strat = " reset a stack";
	}
	else
	{
		strat = " claim a stack";
	}
	return strat;
}
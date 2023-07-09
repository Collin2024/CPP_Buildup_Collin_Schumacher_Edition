#include "headers.h"
#include "Player.h"
#include "Domino.h"

/* *********************************************************************
Function Name: Player
Purpose: To create a player object
Parameters:
			none
Return Value:
			none
Algorithm:
			NOT AVAIABLE
Assistance Received: none
********************************************************************* */
Player::Player()
{
	this->color = color;
}

/* *********************************************************************
Function Name: Player
Purpose:
			To create a player object
Parameters:
			name- name of the player passed by value
			player_color- character to represent the player's domino color 
Return Value:
			none
Algorithm:
			initalizes the name of the player and color and sets up the bone yard
Assistance Received: none
********************************************************************* */
Player::Player(string name, char player_color)
{
	this -> Player_name = name;
	this -> color = player_color;
	this -> table = table;
	this -> first = first;
	this -> score = score;
	this -> win_count = win_count;
	this -> next = next;
	this->load_first = load_first;	
}
void Player::reset_bone_yard()
{
	table.setup_bone_yard(color);
}
/* *********************************************************************
Function Name: get_name
Purpose: To get the name of the player
Parameters:
			none
Return Value:
			the player's name
Algorithm:
			NOT AVAIABLE
Assistance Received: none
********************************************************************* */
string Player::get_name()
{
	return Player_name;
}
/* *********************************************************************
Function Name: display_bone_yard
Purpose: To display the bone yard
Parameters:
			none
Return Value:
			none
Algorithm:
			calls the display_bone_yard function from the domino class
Assistance Received: none
********************************************************************* */
void Player::display_bone_yard()
{
	table.display_bone_yard();
}
/* *********************************************************************
Function Name: draw_domino_from_boneyard
Purpose: To draw a random domino from the bone yard
Parameters:
			none
Return Value:
			returns the drawn domino
Algorithm:
			calls the draw_domino_from_boneyard function from the domino class
Assistance Received: none
********************************************************************* */
string Player::draw_domino_from_boneyard()
{
	return table.draw_domino_from_boneyard();
}
/* *********************************************************************
Function Name: add_to_hand
Purpose: To add a specified domino to the hand
Parameters:
			tile- the specified domino passed by value
Return Value:
			none
Algorithm:
			calls the add_to_hand function from the domino class
Assistance Received: none
********************************************************************* */
void Player::add_to_hand(string tile)
{
	table.add_to_hand(tile);
}
/* *********************************************************************
Function Name: add_to_stack
Purpose: To add a specified domino to the stack
Parameters:
			tile- the specified domino passed by value
Return Value:
			none
Algorithm:
			calls the add_to_stack function from the domino class
Assistance Received: none
********************************************************************* */
void Player::add_to_stack(string tile)
{
	table.add_to_stack(tile);
}
/* *********************************************************************
Function Name: display_stack
Purpose: To display the stack
Parameters:
			none
Return Value:
			none
Algorithm:
			calls the display_stack function from the domino class
Assistance Received: none
********************************************************************* */
void Player::display_stack()
{
	table.display_stack();
}
/* *********************************************************************
Function Name: display_hand
Purpose: To display the hand
Parameters:
			none
Return Value:
			none
Algorithm:
			calls the display_hand function from the domino class
Assistance Received: none
********************************************************************* */
void Player::display_hand()
{
	table.display_hand();
}
/* *********************************************************************
Function Name: domino_value
Purpose: To determine the numerical value of the specified domino
Parameters:
			tile- the specified domino passed by value
Return Value:
			returns the specified domino's total pips (DOTS)
Algorithm:
			calls the domino_value function from the domino class
Assistance Received: none
********************************************************************* */
int Player::domino_value(string tile)
{
	return table.domino_value(tile);
}

/* *********************************************************************
Function Name: add_to_bone_yard
Purpose: To add a specified domino to the bone yard
Parameters:
			tile- the specified domino passed by value
Return Value:
			none
Algorithm:
			calls the add_to_bone_yard function from the domino class
Assistance Received: none
********************************************************************* */
void Player::add_to_bone_yard(string tile)
{
	table.add_to_bone_yard(tile);
}
/* *********************************************************************
Function Name: set_first
Purpose: To set the first player
Parameters:
			STATE- true or false passed by value
Return Value:
			none
Algorithm:
			1. first = STATE
Assistance Received: none
********************************************************************* */
void Player::set_first(const bool STATE)
{
	first = STATE;
}
/* *********************************************************************
Function Name: is_first
Purpose: To get the first player variable
Parameters:
			none
Return Value:
			returns first
Algorithm:
			1. first = STATE
Assistance Received: none
********************************************************************* */
bool Player::is_first()
{
	return first;
}
/* *********************************************************************
Function Name: set_domino
Purpose: To set the selected domino 
Parameters:
			tile- the specified domino passed by value
Return Value:
			none
Algorithm:
			calls the set_domino function from the domino class
Assistance Received: none
********************************************************************* */
void Player::set_domino(string tile)
{
	table.set_domino(tile);
}
/* *********************************************************************
Function Name: get_domino
Purpose: To set the selected domino
Parameters:
			tile- the specified domino passed by value
Return Value:
			none
Algorithm:
			calls the set_domino function from the domino class
Assistance Received: none
********************************************************************* */
string Player::get_domino()
{
	return table.get_domino();
}
/* *********************************************************************
Function Name: make_move
Purpose: To make a move (POLYMORPHIC FUNCTION)
Parameters:
			opponent- the opposing player passed by reference
Return Value:
			none
Algorithm:
			see human and computer classes for the algorithm
Assistance Received: none
********************************************************************* */
void Player::make_move(Player*& opponent)
{
	// polymorphic function implemented in human and computer
	return;
}
/* *********************************************************************
Function Name: determine_legal_placement
Purpose: To determine if the domino can be placed
Parameters:
			tile- the specified stack domino passed by value
Return Value:
			returns true if it can be placed otherwise return false
Algorithm:
			calls the determine_legal_placement function in the domino class
Assistance Received: none
********************************************************************* */
bool Player::determine_legal_placement(string tile)
{
	return table.determine_legal_placement(tile);
}
/* *********************************************************************
Function Name: is_double_domino
Purpose: To determine if it is a double domino
Parameters:
			tile- the specified domino passed by value
Return Value:
			returns true if it's double domino otherwise return false

Algorithm:
			calls the is_double_domino function from the domino class
Assistance Received: none
********************************************************************* */
bool Player::is_double_domino(string tile)
{
	return table.is_double_domino(tile);
}
/* *********************************************************************
Function Name: domino_location
Purpose: To get the specified domino's location
Parameters:
			tile- the specified domino passed by value
			pile- the type of pile that we are looking at e.g: S for stack or H for hand passed by value
Return Value:
			returns the domino location if it exists if it does not exist return -1
Algorithm:
			calls the domino_location from the domino class
Assistance Received: none
********************************************************************* */
int Player::domino_location(string tile, char pile)
{
	return table.domino_location(tile, pile);
}
/* *********************************************************************
Function Name: cover
Purpose: To cover the specified domino's location in the stack
Parameters:
			tile- the specified domino passed by value
			
Return Value:
			none
Algorithm:
			calls the cover from the domino class
Assistance Received: none
********************************************************************* */
void Player::cover(string tile)
{
	table.cover(tile);
}
/* *********************************************************************
Function Name: get_at_stack_position
Purpose: To get the domino at the specified stack location
Parameters:
			pos- the specified location passed by value
Return Value:
			returns the stack domino at the specified location
Algorithm:
			1. return the get_at_stack_position from the domino class
Assistance Received: none
********************************************************************* */
string Player::get_at_stack_position(int pos)
{
	return table.get_at_stack_position(pos);
}
/* *********************************************************************
Function Name: get_at_hand_position
Purpose: To get the domino at the specified hand location
Parameters:
			pos- the specified location passed by value
Return Value:
			returns the hand domino at the specified location
Algorithm:
			1. return the hand domino at the specified location
Assistance Received: none
********************************************************************* */
string Player::get_at_hand_position(int pos)
{
	return table.get_at_hand_position(pos);
}
/* *********************************************************************
Function Name: can_move
Purpose: To determine if it is possible to play a move or if you have to skip
Parameters:
			opponent- the opposing player which is passed by reference
			selection- the specifed option of either stacking your own (1) or opponents side (2)
Return Value:
			returns true if it is possible to play a turn 
			ELSE return false
Algorithm:
			1. Determine if you and opponent have any dominoes left in the hand and, if not, return false.
			2. If the selection is 1 (stacking on your own side) iterate through your hand and through your stack and determine
			if there are any legal placements. If so, return true.
			3. ELSE we will repeat step 2 BUT ONLY this time. We will use the opponent pointer eg opponent->2.
			4. Otherwise, return false

Assistance Received: none
********************************************************************* */
bool Player::can_move(Player*& opponent, int selection)
{
	if (hand_size() == 0 && opponent->hand_size() == 0)
	{
		return false;
	}
	if (selection == 1)
	{
		for (int i = 0; i < hand_size(); i++)
		{
			set_domino(get_at_hand_position(i));
			for (int j = 0; j < stack_size(); j++)
			{
				if (determine_legal_placement(get_at_stack_position(j)) == true)
				{
					return true;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < hand_size(); i++)
		{
			opponent->set_domino(get_at_hand_position(i));
			for (int j = 0; j < opponent -> stack_size(); j++)
			{
				if (opponent -> determine_legal_placement(opponent->get_at_stack_position(j)) == true)
				{
					return true;
				}
			}
		}
	}
	return false;
}
/* *********************************************************************
Function Name: hand_size
Purpose: To get the hand size
Parameters:
			none
Return Value:
			returns the hand size
Algorithm:
			1. return the hand size from the domino class
Assistance Received: none
********************************************************************* */
int Player::hand_size()
{
	return table.hand_size();
}
/* *********************************************************************
Function Name: stack_size
Purpose: To get the hand size
Parameters:
			none
Return Value:
			returns the stack size
Algorithm:
			1. return the stack size from the domino class
Assistance Received: none
********************************************************************* */
int Player::stack_size()
{
	return table.stack_size();
}
/* *********************************************************************
Function Name: draw_domino_from_hand
Purpose: To remove a specified domino from the hand
Parameters:
			tile- the specified domino passed by value
Return Value:
			none
Algorithm:
			1. calls the draw_domino_from_hand from the domino class
Assistance Received: none
********************************************************************* */
void Player::draw_domino_from_hand(string tile)
{
	table.draw_domino_from_hand(tile);
}
/* *********************************************************************
Function Name: tally_score
Purpose: To determine the final score 
Parameters:
			opponent- the opposing player which is passed by value
Return Value:
			none
Algorithm:
			1. Loop through the player's stack and if the color equals the player's color, add up the domino 
			value eg W66 would be +12 for computer.
			2. Loop through the opponent's stack and if the color equals the player's color, add up the domino 
			value eg W66 would be +12 for computer.
			3. If hand size > 0 add up the hand dice and subtract the difference from the score. 
			4. Return score.


Assistance Received: none
********************************************************************* */
int Player::tally_score(Player* opponent)
{
	//loop through the stack
	for (int a = 0; a < stack_size(); a++)
	{
		// if its color is the players and NOT the opponents then add the bone's value to the score
		if (is_color(get_at_stack_position(a)) == true && opponent->is_color(get_at_stack_position(a)) == false)
		{
			score += domino_value(get_at_stack_position(a));
		}
	}
	// loop through the opponents stack
	for (int b = 0; b < stack_size(); b++)
	{
		// if its color is the players and NOT the opponents then add the opponents bone's value to the score
		if (is_color(opponent->get_at_stack_position(b)) == true && opponent->is_color(opponent->get_at_stack_position(b)) == false)
		{
			score += domino_value(opponent->get_at_stack_position(b));
		}
	}
	// if their are unplayed hand tiles left over then subtract the difference
	if (hand_size() > 0)
	{
		int differ = 0;
		for (int c = 0; c < hand_size(); c++)
		{
			differ += domino_value(get_at_hand_position(c));
		}
		score -= differ;

	}
	return score;
}
/* *********************************************************************
Function Name: get_score
Purpose: To get the score
Parameters:
			none
Return Value:
			returns the score
Algorithm:
			1. return score
Assistance Received: none
********************************************************************* */
int Player::get_score()
{
	return score;
}
/* *********************************************************************
Function Name: get_color
Purpose: To get the color
Parameters:
			none
Return Value:
			returns the color
Algorithm:
			1. return color
Assistance Received: none
********************************************************************* */
char Player::get_color()
{
	return color;
}
/* *********************************************************************
Function Name: display_score
Purpose: To display the score
Parameters:
			none
Return Value:
			none
Algorithm:
			1. display the score
Assistance Received: none
********************************************************************* */
void Player::display_score()
{
	cout << "Score: " << score << endl;
}
/* *********************************************************************
Function Name: is_color
Purpose: To remove a specified domino from the hand
Parameters:
			tile- the specified domino passed by value
Return Value:
			returns true if its the same color otherwise return false
Algorithm:
			1. If the first character = the color character, return true.
			2. Otherwise, return false.
Assistance Received: none
********************************************************************* */
bool Player::is_color(string tile)
{
	if (tile[0] == get_color())
	{
		return true;
	}
	return false;
}
/* *********************************************************************
Function Name: reset_hand
Purpose: To reset a hand at the end of a round
Parameters:
			none
Return Value:
			none
Algorithm:
			1. calls the reset_hand from the domino class
Assistance Received: none
********************************************************************* */
void Player::reset_hand()
{
	table.reset_hand();
}
/* *********************************************************************
Function Name: winner
Purpose: To increment win count
Parameters:
			none
Return Value:
			none
Algorithm:
			1. increment win count
Assistance Received: none
********************************************************************* */
void Player::winner()
{
	win_count++;
}
/* *********************************************************************
Function Name: get_wins
Purpose: To get the number of rounds won
Parameters:
			none
Return Value:
			returns the win_count (aka number of won rounds)
Algorithm:
			1. return win_count
Assistance Received: none
********************************************************************* */
int Player::get_wins()
{
	return win_count;
}
/* *********************************************************************
Function Name: display_wins
Purpose: To display the rounds won
Parameters:
			none
Return Value:
			none
Algorithm:
			1. display the rounds won
Assistance Received: none
********************************************************************* */
void Player::display_wins()
{
	cout << "Rounds Won: " << win_count << endl;
}
/* *********************************************************************
Function Name: reset_score
Purpose: To reset the score
Parameters:
			none
Return Value:
			none
Algorithm:
			1. score = 0
Assistance Received: none
********************************************************************* */
void Player::reset_score()
{
	score = 0;
}
/* *********************************************************************
Function Name: selection
Purpose: POLYMORPHIC FUNCTION to determine what the player wants to do
Parameters:
			none
Return Value:
			returns the selection
Algorithm:
			1. return 0 
Assistance Received: none
********************************************************************* */
int Player::selection()
{
	return 0;
}
/* *********************************************************************
Function Name: bone_yard_size
Purpose: To get the bone yard size
Parameters:
			none
Return Value:
			returns the bone yard size
Algorithm:
			1.  returns the bone_yard_size from the domino class
Assistance Received: none
********************************************************************* */
int Player::bone_yard_size()
{
	return table.bone_yard_size();
}
/* *********************************************************************
Function Name: get_at_boneyard_position
Purpose: To get domino in the bone yard at the specified position
Parameters:
			pos- the specified position passed by value
Return Value:
			returns the bone yard domino at the specified position
Algorithm:
			1.  returns the get_at_boneyard_position from the domino class
Assistance Received: none
********************************************************************* */
string Player::get_at_boneyard_position(int pos)
{
	return table.get_at_boneyard_position(pos);
}
/* *********************************************************************
Function Name: set_next
Purpose: To set the status of the next player (true or false)
Parameters:
			STATE- the specified state (true or false) passed by value
Return Value:
			none
Algorithm:
			1.  next = STATE
Assistance Received: none
********************************************************************* */
void Player::set_next(const bool STATE)
{
	next = STATE;
}
/* *********************************************************************
Function Name: is_next
Purpose: To determine if the player next
Parameters:
			none
Return Value:
			return next
Algorithm:
			1.  return next
Assistance Received: none
********************************************************************* */
bool Player::is_next()
{
	return next;
}
/* *********************************************************************
Function Name: set_score
Purpose: To set the score of the player (for serialization purposes)
Parameters:
			LOAD_SCORE- the specified score passed by value
Return Value:
			none
Algorithm:
			1. score = LOAD_SCORE
Assistance Received: none
********************************************************************* */
void Player::set_score(const int LOAD_SCORE)
{
	score = LOAD_SCORE;
}
/* *********************************************************************
Function Name: set_wins
Purpose: To set the round wins of the player (for serialization purposes)
Parameters:
			LOAD_SCORE- the specified score passed by value
Return Value:
			none
Algorithm:
			1. win_count = LOAD_WINS
Assistance Received: none
********************************************************************* */
void Player::set_wins(const int LOAD_WINS)
{
	win_count = LOAD_WINS;
}
/* *********************************************************************
Function Name: is_fully_seized
Purpose: To determine if the board is fully stacked by the opponent
Parameters:
			none
Return Value:
			returns false if its not all seized by opponent OTHERWISE return true
Algorithm:
			1. Loop through the stack to determine if there are any tiles that are 
			the same color assigned to the player, if so, it is not fully seized (return false).
			2. ELSE return true
Assistance Received: none
********************************************************************* */
bool Player::is_fully_seized()
{
	for (int i = 0; i < stack_size(); i++)
	{
		if (is_color(get_at_stack_position(i)) == true)
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
			see computer class for the algorithm
Assistance Received: none
********************************************************************* */
void Player::help_mode(Player* opponent)
{
	return;
}

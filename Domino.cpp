#include "headers.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
/* *********************************************************************
Function Name: Domino
Purpose: To create a Domino object
Parameters:
			none
Return Value:
			none
Algorithm:
			initalize the boneyard and hand
Assistance Received: none
********************************************************************* */
Domino::Domino()
{
	this->bone_yard = bone_yard;
	this->hand = hand;
	this->selected_bone = selected_bone;
}

/* *********************************************************************
Function Name: setup_bone_yard
Purpose: To set the bone_yard pile for the player
Parameters:
			player_color- the color of the player's dominos passed by value
Return Value:
			none
Algorithm:
			1.Set the domino color for the player.
			2. Use a triple for loop to generate the TOTAL 28 dominoes 0|0 to 6|6.
			3. Use a built in function within C++ called "random_shuffle" to assist in shuffling the dominoes while also
			ultilizing the srand to keep shifts random.

Assistance Received: I used this site for assistance for vector shuffling
https://www.techiedelight.com/shuffle-vector-cpp/
********************************************************************* */
void Domino::setup_bone_yard(char player_color)
{
	bone_yard.clear();
	hand.clear();
	stack.clear();
	string bone;
	int counter = 1;
	const int TOTAL = 28;
	const int MAX_PIPS = 6;
	for (int i = 0; i <= MAX_PIPS; i++)
	{
		for (int j = i; j <= MAX_PIPS; j++)
		{
			// after the TOTAL dominoes are created shuffle the pile and return
			if (counter > TOTAL)
			{
				random_shuffle(bone_yard.begin(), bone_yard.end(), [&](int x) {return rand() % x; });
				return;
			}
			for (int k = j; k <= MAX_PIPS; k++)
			{
				bone += player_color;
				bone += convert(j);
				bone += convert(k);
				add_to_bone_yard(bone);
				bone.clear();
				counter++;
			}
		}
	}


}
/* *********************************************************************
Function Name: display_bone_yard
Purpose: To display the bone yard
Parameters:
			none
Return Value:
			none
Algorithm:
			display the boneyard
Assistance Received: none
********************************************************************* */
void Domino::display_bone_yard()
{
	cout << "Boneyard: ";
	for (int i = 0; i < bone_yard.size(); i++)
	{
		cout << bone_yard.at(i) << ' ';
	}
	cout << endl;
}
/* *********************************************************************
Function Name: convert
Purpose: To convert a number into a string
Parameters:
			num- the number to convert into a string passed by value
Return Value:
			returns the converted string
Algorithm:
			converts the number to a string using stringstream
Assistance Received: none
********************************************************************* */
string Domino::convert(int num)
{
	string line;
	stringstream con;
	con << num;
	con >> line;
	return line;
}
/* *********************************************************************
Function Name: re_convert
Purpose: To convert a string into a number
Parameters:
			tile- the domino string to convert into a number passed by value
Return Value:
			returns the converted number
Algorithm:
			converts the domino string to a number using stringstream
Assistance Received: none
********************************************************************* */
int Domino::re_convert(string tile)
{
	int bone;
	stringstream con;
	con << tile;
	con >> bone;
	return bone;
}
/* *********************************************************************
Function Name: draw_domino_from_boneyard
Purpose: To draw a random domino from the bone yard
Parameters:
			none
Return Value:
			returns the drawn domino
Algorithm:
			1. Determine a random number position between 0 and the size of the bone yard.
			2. Determine the specified domino at the position.
			3. Remove the domino from the bone yard.
Assistance Received: none
********************************************************************* */
string Domino::draw_domino_from_boneyard()
{
	string tile = bone_yard.at(0);
	bone_yard.erase(bone_yard.begin() + 0);
	return tile;
}
/* *********************************************************************
Function Name: add_to_hand
Purpose: To add a specified domino to the hand
Parameters:
			tile- the specified domino passed by value
Return Value:
			none
Algorithm:
			adds the tile to the hand
Assistance Received: none
********************************************************************* */
void Domino::add_to_hand(string tile)
{
	hand.push_back(tile);
}
/* *********************************************************************
Function Name: add_to_stack
Purpose: To add a specified domino to the stack
Parameters:
			tile- the specified domino passed by value
Return Value:
			none
Algorithm:
			adds the tile to the stack
Assistance Received: none
********************************************************************* */
void Domino::add_to_stack(string tile)
{
	stack.push_back(tile);
}
/* *********************************************************************
Function Name: display_stack
Purpose: To display the stack
Parameters:
			none
Return Value:
			none
Algorithm:
			display the stack
Assistance Received: none
********************************************************************* */
void Domino::display_stack()
{
	cout << "Stacks: ";
	for (int i = 0; i < stack.size(); i++)
	{
		cout << stack.at(i) << ' ';
	}
	cout << endl;
}
/* *********************************************************************
Function Name: display_hand
Purpose: To display the hand
Parameters:
			none
Return Value:
			none
Algorithm:
			display the hand
Assistance Received: none
********************************************************************* */
void Domino::display_hand()
{
	cout << "Hand: ";
	for (int i = 0; i < hand.size(); i++)
	{
		cout << hand.at(i) << ' ';
	}
	cout << endl;
}
/* *********************************************************************
Function Name: domino_value
Purpose: To determine the numerical value of the specified domino
Parameters:
			tile- the specified domino passed by value
Return Value:
			returns the specified domino's total pips (DOTS)
Algorithm:
			1. Erase the first character.
			2. Use re_convert to convert it to an integer e.g: W66 = 66.
			3. Determine 2's result / 10 + determine 2's result % 10
			e.g W66 = 66 = 12.

Assistance Received: none
********************************************************************* */
int Domino::domino_value(string tile)
{
	tile.erase(0, 1);
	return (((re_convert(tile) / 10)) + (re_convert(tile) % 10));
}
/* *********************************************************************
Function Name: add_to_bone_yard
Purpose: To add a specified domino to the stack
Parameters:
			tile- the specified domino passed by value
Return Value:
			none
Algorithm:
			adds the tile to the bone yard
Assistance Received: none
********************************************************************* */
void Domino::add_to_bone_yard(string tile)
{
	bone_yard.push_back(tile);
}
/* *********************************************************************
Function Name: draw_domino_from_hand
Purpose: To remove a specified domino from the hand
Parameters:
			tile- the specified domino passed by value
Return Value:
			none
Algorithm:
			1. Search through the bone yard to determine if tile matches
			the current iteration of the boneyard.
			2. Erase tile at that found position.
Assistance Received: none
********************************************************************* */
void Domino::draw_domino_from_hand(string tile)
{
	hand.erase(hand.begin() + domino_location(tile, 'H'));
}
/* *********************************************************************
Function Name: set_domino
Purpose: To set the selected domino
Parameters:
			tile- the specified domino passed by value
Return Value:
			none
Algorithm:
			1. selected_bone = tile
Assistance Received: none
********************************************************************* */
void Domino::set_domino(string tile)
{
	selected_bone = tile;
}
/* *********************************************************************
Function Name: get_domino
Purpose: To get the selected domino
Parameters:
			none
Return Value:
			returns the selected bone
Algorithm:
			1. selected_bone = tile
Assistance Received: none
********************************************************************* */
string Domino::get_domino()
{
	return selected_bone;
}
/* *********************************************************************
Function Name: determine_legal_placement
Purpose: To determine if the domino can be placed
Parameters:
			tile- the specified stack domino passed by value
Return Value:
			returns true if it can be placed, otherwise, return false
Algorithm:
			1. Determine if the selected bone is NOT a double tile and that it is greater than or equal to the
			desired stack domino. If so, return true.
			2. Determine if the selected bone is a double tile and if the stack domino is NOT a double tile. If so, return true.
			3. Determine if the selected bone and stack tile are both double tile and that the selected bone is greater than the
			stack tile. If so, return true.
			4. Otherwise return false
Assistance Received: none
********************************************************************* */
bool Domino::determine_legal_placement(string tile)
{

	if (is_double_domino(selected_bone) == false && (domino_value(selected_bone) >= domino_value(tile)))
	{
		//cout << domino_value(selected_bone) << " >= " << domino_value(tile)<<endl;
		return true;
	}
	else if (is_double_domino(selected_bone) == true && is_double_domino(tile) == false)
	{
		return true;
	}
	else if ((is_double_domino(selected_bone) == true && is_double_domino(tile) == true) && (domino_value(selected_bone) > domino_value(tile)))
	{
		return true;
	}
	return false;
}
/* *********************************************************************
Function Name: is_double_domino
Purpose: To determine if it is a double domino
Parameters:
			tile- the specified domino passed by value
Return Value:
			returns true if it's double domino, otherwise return false
Algorithm:
			1. Erase first character (color).
			2. Creates 2 strings for the other 2 characters (0-6).
			3. Ultilize re_convert function to convert them to numbers and, if they are equal,
			return true.
			4. Otherwise, return false.
Assistance Received: none
********************************************************************* */
bool Domino::is_double_domino(string tile)
{
	tile.erase(0, 1);
	string first_face;
	string second_face;
	first_face += tile[0];
	second_face += tile[1];
	if (re_convert(first_face) == re_convert(second_face))
	{
		return true;
	}
	return false;

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
			1. Determine if the domino string size is equal to 3 and, if its not, return -1.
			2. Determine if the first character accurately represents the color of the bone e.g B for black or W for white.
			If it doesn't, return -1.
			3. Determine if the rest of the characters are a number from 0 to 6. If not, return -1.
			4. If the pile is H (for looking into hand), look for the specifed bone in the hand pile. If
			it is found, return the location.
			5. If the pile is S (for looking into stack), look for the specifed bone in the stack pile. If
			it is found, return the location.
			6. Otherwise, return -1.
Assistance Received: none
********************************************************************* */
int Domino::domino_location(string tile, char pile)
{
	int place = 0;
	// tiles have color and 2 numbers ONLY
	if (tile.size() != 3)
	{
		return -1;
	}
	else if (tile[0] != 'W' && tile[0] != 'B')
	{
		return -1;
	}
	for (int i = 1; i < tile.size(); i++)
	{
		if (tile[i] > '6' || tile[i] < '0')
		{
			return -1;
		}
	}
	// if we are looking into the hand
	if (pile == 'H')
	{
		for (int i = 0; i < hand.size(); i++)
		{
			if (hand.at(i) == tile)
			{
				return i;
			}
		}
	}
	// if we are looking into the stack
	else if (pile == 'S')
	{
		for (int i = 0; i < stack.size(); i++)
		{
			if (stack.at(i) == tile)
			{
				return i;
			}
		}
	}
	return -1;
}
/* *********************************************************************
Function Name: cover
Purpose: To cover the specified domino
Parameters:
			tile- the specified domino passed by value
Return Value:
			none
Algorithm:
			1. Determine the location of the domino in the stack.
			2. Set the stack at the specified location equal to the selected_bone
			which is "covering".
Assistance Received: none
********************************************************************* */
void Domino::cover(string tile)
{
	int pos = 0;
	for (int i = 0; i < stack.size(); i++)
	{
		if (stack.at(i) == tile)
		{
			pos = i;
			break;
		}
	}
	stack.at(pos) = selected_bone;
}
/* *********************************************************************
Function Name: get_at_stack_position
Purpose: To get the domino at the specified stack location
Parameters:
			pos- the specified location passed by value
Return Value:
			returns the stack domino at the specified location
Algorithm:
			1. return the stack domino at the specified location
Assistance Received: none
********************************************************************* */
string Domino::get_at_stack_position(int pos)
{
	return stack.at(pos);
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
string Domino::get_at_hand_position(int pos)
{
	return hand.at(pos);
}
/* *********************************************************************
Function Name: hand_size
Purpose: To get the hand size
Parameters:
			none
Return Value:
			returns the hand size
Algorithm:
			1. return the hand size
Assistance Received: none
********************************************************************* */
int Domino::hand_size()
{
	return hand.size();
}
/* *********************************************************************
Function Name: stack_size
Purpose: To get the hand size
Parameters:
			none
Return Value:
			returns the stack size
Algorithm:
			1. return the stack size
Assistance Received: none
********************************************************************* */
int Domino::stack_size()
{
	return stack.size();
}
/* *********************************************************************
Function Name: reset_hand
Purpose: To get the hand size
Parameters:
			none
Return Value:
			returns the stack size
Algorithm:
			1. return the stack size
Assistance Received: none
********************************************************************* */
void Domino::reset_hand()
{
	if (hand.size() != 0)
	{
		hand.clear();
	}
}
/* *********************************************************************
Function Name: bone_yard_size
Purpose: To get the bone yard size
Parameters:
			none
Return Value:
			returns the bone yard size
Algorithm:
			1. return the bone yard size
Assistance Received: none
********************************************************************* */
int Domino::bone_yard_size()
{
	return bone_yard.size();
}
/* *********************************************************************
Function Name: get_at_boneyard_position
Purpose: To get the bone yard size
Parameters:
			none
Return Value:
			pos- the position passed by value
Algorithm:
			1. return the bone_yard.at(pos)
Assistance Received: none
********************************************************************* */
string Domino::get_at_boneyard_position(int pos)
{
	return bone_yard.at(pos);
}


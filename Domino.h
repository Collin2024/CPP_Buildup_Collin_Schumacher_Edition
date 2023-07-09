#pragma once
#ifndef _DOMINO_H
#define _DOMINO_H
#include "headers.h"
#include "Player.h"

class Domino
{

public:
	Domino();
	void setup_bone_yard(char player_color);
	void display_bone_yard();
	string draw_domino_from_boneyard();
	void add_to_hand(string tile);
	void add_to_stack(string tile);
	void display_stack();
	void display_hand();
	int domino_value(string tile);
	void draw_domino_from_hand(string tile);	
	void add_to_bone_yard(string tile);
	void set_domino(string tile);
	bool determine_legal_placement(string tile);
	string get_domino();
	bool is_double_domino(string tile);
	int domino_location(string tile, char pile);
	void cover(string tile);
	string get_at_stack_position(int pos);
	string get_at_hand_position(int pos);
	string get_at_boneyard_position(int pos);
	int hand_size();
	int stack_size();
	void reset_hand();
	int bone_yard_size();
private:
	vector <string> bone_yard;
	vector <string> hand;
	vector <string> stack;
	string convert(int num);
	int re_convert(string tile);
	string selected_bone;

	
};
#endif
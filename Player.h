#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H
#include "headers.h"
#include "Domino.h"
class Player {

public:
	Player();
	Player(string name, char player_color);
	string get_name();
	void display_bone_yard();
	string draw_domino_from_boneyard();
	void add_to_hand(string tile);
	void add_to_stack(string tile);
	void display_stack();
	void display_hand();
	int domino_value(string tile);
	void add_to_bone_yard(string tile);
	void draw_domino_from_hand(string tile);
	void set_first(const bool STATE);
	bool is_first();
	void set_domino(string tile);
	string get_domino();
	void reset_bone_yard();
	virtual void make_move(Player *&opponent);
	bool determine_legal_placement(string tile);
	bool is_double_domino(string tile);
	int domino_location(string tile, char pile);
	void cover(string domino);
	bool can_move(Player*& opponent, int selection);
	string get_at_stack_position(int pos);
	string get_at_hand_position(int pos);
	int hand_size();
	int stack_size();
	int tally_score(Player* opponent);
	int get_score();
	char get_color();
	void display_score();
	void reset_hand();
	void winner();
	int get_wins();
	void display_wins();
	void reset_score();
	virtual int selection();
	int bone_yard_size();
	string get_at_boneyard_position(int pos);
	void set_next(const bool STATE);
	bool is_next();
	void set_score(const int LOAD_SCORE);
	void set_wins(const int LOAD_WINS);
	bool is_color(string tile);
	bool is_fully_seized();
	virtual void help_mode(Player* opponent);
private:
	string Player_name;
	char color;
	Domino table;
	bool first = false;
	bool next = false;
	int win_count = 0;
	int score = 0;
	int load_first = 0;
	int hand_counter = 1;

};
#endif

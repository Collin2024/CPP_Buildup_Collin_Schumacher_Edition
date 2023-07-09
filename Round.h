#pragma once
#ifndef _ROUND_H
#define _ROUND_H

#include "headers.h"
#include "Player.h"
class Round
{

public:
	Round();
	Round(vector<Player*>&players);
	void play_round();
	void first_hand();
	void hand_method();
	void save_game();
	void display_round();
	void set_loaded(const bool STATE);
	bool get_load();
	void Set_first(int player);
	int get_first();

private:
	vector<Player *> player_list;
	int hand_counter = 1;
	bool loaded = false;
	void who_won();
	void tournament_winner();
	int is_first = 3;
};
#endif

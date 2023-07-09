#pragma once
#ifndef _GAME_H
#define _GAME_H
#include "headers.h"
#include "Round.h"
#include "Computer.h"
#include "Human.h"
class Game
{

public:
	Game();
	int menu();
	void new_game();
	void load_game();
private:
	vector<Player*> player_list;

	vector<string> memory;
	char color(string bone);
	void load_memory(string line, const string KEY);
	int re_convert(string tile);
	
};
#endif
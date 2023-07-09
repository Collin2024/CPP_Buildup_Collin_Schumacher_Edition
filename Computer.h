#pragma once
#ifndef _COMPUTER_H
#define _COMPUTER_H
#include "Player.h"
#include "headers.h"
#include "Domino.h"

class Computer :public Player
{
public:
	Computer();
	Computer(string name, char player_color);
	virtual void make_move(Player*& opponent);
	virtual int selection();
	virtual void help_mode(Player* opponent);

private:
	int ai_decision(int num);
	bool no_singles();
	string computer_strategy(string select, string domino);

};
#endif
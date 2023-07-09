#pragma once
#ifndef _HUMAN_H
#define _HUMAN_H
#include "Player.h"
#include "headers.h"
class Human :public Player
{

public:
	Human();
	Human(string name, char color);
	virtual void make_move(Player*& opponent);
	virtual int selection();
	virtual void help_mode(Player* opponent);

private:

};
#endif
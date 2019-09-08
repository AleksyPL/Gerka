#pragma once
#include "biblioteki.h"
#include "player.h"

class Przeciwnik
{
public:
	int hp;
	int max_hp;
	int damage;
	int defence;
	int gold;
	int xp;
	string skill;
	string name;
};
player fight(player gracz,int nr);


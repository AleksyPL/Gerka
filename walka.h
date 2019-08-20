#pragma once
#include "biblioteki.h"
#include "mobki1.h"
#include "player.h"
#include "tabelka.h"
#include "zakres.h"

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


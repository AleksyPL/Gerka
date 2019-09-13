#pragma once
#include "biblioteki.h"

class Mob
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

class Mieszkaniec_small:public Mob
{
public:
	Mieszkaniec_small();
};

class Mieszkaniec_medium :public Mob
{
public:
	Mieszkaniec_medium();
};

class Mieszkaniec_big :public Mob
{
public:
	Mieszkaniec_big();
};
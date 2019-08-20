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
	Mieszkaniec_small()
	{
		hp = 20;
		max_hp = hp;
		xp = 10000;
		damage = 3;
		gold = (rand() % 10)+1;
		name = "MIESZKANIEC";
	}
};

class Mieszkaniec_medium :public Mob
{
public:
	Mieszkaniec_medium()
	{
		hp = 25;
		max_hp = hp;
		xp = 15;
		damage = 4;
		gold = (rand() % 10) + 5;
		name = "MIESZKANIEC";
	}
};

class Mieszkaniec_big :public Mob
{
public:
	Mieszkaniec_big()
	{
		hp = 30;
		max_hp = hp;
		xp = 20;
		damage = 5;
		gold = (rand() % 10) + 10;
		name = "MIESZKANIEC";
	}
};
#include "biblioteki.h"
#include "player.h"
#include "koniec_tury.h"

void end_of_turn(player &gracz)
{
	gracz.licznik_dnia = gracz.licznik_dnia + 1;
	gracz.hunger = gracz.hunger - 1;
	gracz.alko = 0;
	if(gracz.hunger<0)
	{
		gracz.hunger = 0;
	}
	if (gracz.hunger == 0)
	{
		gracz.hp = gracz.hp - 10;
		sound_damage();
	}
	if (gracz.counter_nerf_str != 0)
	{
		gracz.counter_nerf_str = gracz.counter_nerf_str - 1;
		if (gracz.counter_nerf_str <= 0)
		{
			gracz.counter_nerf_str = 0;
			gracz.str = gracz.before_nerf_str;
		}
	}
	if (gracz.counter_boost_str != 0)
	{
		gracz.counter_boost_str = gracz.counter_boost_str - 1;
		if (gracz.counter_boost_str <= 0)
		{
			gracz.counter_boost_str = 0;
			gracz.str = gracz.before_boost_str;
		}
	}
	if (gracz.counter_nerf_agility != 0)
	{
		gracz.counter_nerf_agility = gracz.counter_nerf_agility - 1;
		if (gracz.counter_nerf_agility <= 0)
		{
			gracz.counter_nerf_agility = 0;
			gracz.agility = gracz.before_nerf_agility;
		}
	}
	if (gracz.counter_boost_agility != 0)
	{
		gracz.counter_boost_agility = gracz.counter_boost_agility - 1;
		if (gracz.counter_boost_agility <= 0)
		{
			gracz.counter_boost_agility = 0;
			gracz.agility = gracz.before_boost_agility;
		}
	}
	if (gracz.counter_nerf_intel != 0)
	{
		gracz.counter_nerf_intel = gracz.counter_nerf_intel - 1;
		if (gracz.counter_nerf_intel <= 0)
		{
			gracz.counter_nerf_intel = 0;
			gracz.intel = gracz.before_nerf_intel;
		}
	}
	if (gracz.counter_boost_intel != 0)
	{
		gracz.counter_boost_intel = gracz.counter_boost_intel - 1;
		if (gracz.counter_boost_intel <= 0)
		{
			gracz.counter_boost_intel = 0;
			gracz.intel = gracz.before_boost_intel;
		}
	}
	if (gracz.counter_nerf_charisma != 0)
	{
		gracz.counter_nerf_charisma = gracz.counter_nerf_charisma - 1;
		if (gracz.counter_nerf_charisma <= 0)
		{
			gracz.counter_nerf_charisma = 0;
			gracz.charisma = gracz.before_nerf_charisma;
		}
	}
	if (gracz.counter_boost_charisma != 0)
	{
		gracz.counter_boost_charisma = gracz.counter_boost_charisma - 1;
		if (gracz.counter_boost_charisma <= 0)
		{
			gracz.counter_boost_charisma = 0;
			gracz.charisma = gracz.before_boost_charisma;
		}
	}
	if (gracz.counter_nerf_luck != 0)
	{
		gracz.counter_nerf_luck = gracz.counter_nerf_luck - 1;
		if (gracz.counter_nerf_luck <= 0)
		{
			gracz.counter_nerf_luck = 0;
			gracz.luck = gracz.before_nerf_luck;
		}
	}
	if (gracz.counter_boost_luck != 0)
	{
		gracz.counter_boost_luck = gracz.counter_boost_luck - 1;
		if (gracz.counter_boost_luck <= 0)
		{
			gracz.counter_boost_luck = 0;
			gracz.luck = gracz.before_boost_luck;
		}
	}
}
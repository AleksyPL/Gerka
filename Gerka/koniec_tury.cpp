#include "biblioteki.h"
#include "player.h"

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
}
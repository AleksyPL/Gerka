#include "czas.h"
#include "boost_syf.h"

void boost_nerf(player &gracz)
{
	if (gracz.counter_nerf_str != 0)
	{
		gracz.counter_nerf_str--;
		if (gracz.counter_nerf_str == 0)
		{
			remove_nerf_str(gracz);
		}
	}
	if (gracz.counter_boost_str != 0)
	{
		gracz.counter_boost_str--;
		if (gracz.counter_boost_str == 0)
		{
			remove_boost_str(gracz);
		}
	}
	if (gracz.counter_nerf_agility != 0)
	{
		gracz.counter_nerf_agility--;
		if (gracz.counter_nerf_agility == 0)
		{
			remove_nerf_agility(gracz);
		}
	}
	if (gracz.counter_boost_agility != 0)
	{
		gracz.counter_boost_agility--;
		if (gracz.counter_boost_agility == 0)
		{
			remove_boost_agility(gracz);
		}
	}
	if (gracz.counter_nerf_intel != 0)
	{
		gracz.counter_nerf_intel--;
		if (gracz.counter_nerf_intel == 0)
		{
			remove_nerf_intel(gracz);
		}
	}
	if (gracz.counter_boost_intel != 0)
	{
		gracz.counter_boost_intel--;
		if (gracz.counter_boost_intel == 0)
		{
			remove_boost_intel(gracz);
		}
	}
	if (gracz.counter_nerf_charisma != 0)
	{
		gracz.counter_nerf_charisma--;
		if (gracz.counter_nerf_charisma == 0)
		{
			remove_nerf_charisma(gracz);
		}
	}
	if (gracz.counter_boost_charisma != 0)
	{
		gracz.counter_boost_charisma--;
		if (gracz.counter_boost_charisma == 0)
		{
			remove_boost_charisma(gracz);
		}
	}
	if (gracz.counter_nerf_luck != 0)
	{
		gracz.counter_nerf_luck--;
		if (gracz.counter_nerf_luck == 0)
		{
			remove_nerf_luck(gracz);
		}
	}
	if (gracz.counter_boost_luck != 0)
	{
		gracz.counter_boost_luck--;
		if (gracz.counter_boost_luck == 0)
		{
			remove_boost_luck(gracz);
		}
	}
}
void hungry_and_sober(player &gracz, int off_hunger, int off_sobering)
{
	if (gracz.hour % 2 == 0)
	{
		if (off_sobering == 0)
		{
			gracz.a_bit_sober();
		}
		if (off_hunger == 0)
		{
			gracz.a_bit_hungry(1);
		}
	}
	else
	{
		if (off_sobering == 0)
		{
			gracz.a_bit_sober();
		}
	}
}
void change_time(player &gracz, int hours, int minutes, int off_hunger, int off_sobering)
{
	gracz.minute = gracz.minute + minutes;
	while (gracz.minute >= 60)
	{
		hours++;
		gracz.minute = gracz.minute - 60;
	}
	for (int i = 0; i < hours; i++)
	{
		gracz.hour++;
		if (gracz.hour == 24)
		{
			gracz.licznik_dnia = gracz.licznik_dnia + 1;
			gracz.hour = 0;
		}
		hungry_and_sober(gracz, off_hunger, off_sobering);
		boost_nerf(gracz);
	}
}

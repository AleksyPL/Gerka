#include "zakres.h"

void range(player &gracz)
{
	if (gracz.level > 9999)
	{
		gracz.level = 9999;
	}
	if (gracz.exp > 999999999)
	{
		gracz.exp = 999999999;
	}
	if (gracz.exp_to_next_level > 999999999)
	{
		gracz.exp_to_next_level = 999999999;
	}
	if (gracz.hp > 999999999)
	{
		gracz.hp = 999999999;
	}
	if (gracz.max_hp > 999999999)
	{
		gracz.max_hp = 999999999;
	}
	if (gracz.hp > gracz.max_hp)
	{
		gracz.hp = gracz.max_hp;
	}
	if (gracz.gold > MAXLONGLONG)
	{                 
		gracz.gold = MAXLONGLONG;
	}
	if (gracz.licznik_dnia >= 10000 || gracz.licznik_dnia == 10000)
	{
		gracz.licznik_dnia = 9999;
	}
	if (gracz.helmet >= 10000 || gracz.helmet == 10000)
	{
		gracz.helmet = 9999;
	}
	if (gracz.chestplate >= 10000 || gracz.chestplate == 10000)
	{
		gracz.chestplate = 9999;
	}
	if (gracz.gloves >= 10000 || gracz.gloves == 10000)
	{
		gracz.gloves = 9999;
	}
	if (gracz.pants >= 10000 || gracz.pants == 10000)
	{
		gracz.pants = 9999;
	}
	if (gracz.shoes >= 10000 || gracz.shoes == 10000)
	{
		gracz.shoes = 9999;
	}
	if (gracz.weapon >= 10000 || gracz.weapon == 10000)
	{
		gracz.weapon = 9999;
	}
	if (gracz.str >= 10000 || gracz.str == 10000)
	{
		gracz.str = 9999;
	}
	if (gracz.intel >= 10000 || gracz.intel == 10000)
	{
		gracz.intel = 9999;
	}
	if (gracz.agility >= 10000 || gracz.agility == 10000)
	{
		gracz.agility = 9999;
	}
}
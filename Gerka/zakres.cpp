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
	if (gracz.licznik_dnia > 9999)
	{
		gracz.licznik_dnia = 9999;
	}
	if (gracz.helmet > 9999)
	{
		gracz.helmet = 9999;
	}
	if (gracz.chestplate > 9999)
	{
		gracz.chestplate = 9999;
	}
	if (gracz.gloves > 9999)
	{
		gracz.gloves = 9999;
	}
	if (gracz.pants > 9999)
	{
		gracz.pants = 9999;
	}
	if (gracz.shoes > 9999)
	{
		gracz.shoes = 9999;
	}
	if (gracz.weaponDamage > 9999)
	{
		gracz.weaponDamage = 9999;
	}
	if (gracz.str > 9999)
	{
		gracz.str = 9999;
	}
	if (gracz.intel > 9999)
	{
		gracz.intel = 9999;
	}
	if (gracz.agility > 9999)
	{
		gracz.agility = 9999;
	}
}
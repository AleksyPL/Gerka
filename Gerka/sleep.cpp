#include "sleep.h"
#include "zakres.h"
#include "czas.h"

void sleep(player &gracz, int cena,int hours, int minutes, int height, int startPoint, vector <string> &message)
{
	//string tab[2];
	if (gracz.gold < cena)
	{
		message.push_back(no_money());
	}
	else
	{
		if (gracz.hunger < 5)
		{
			message.push_back("You are too hungry to fall asleep");
		}
		else
		{
			if (minutes == 0)
			{
				message.push_back("You sleep safely for " + to_string(hours) + " hours");
			}
			else
			{
				message.push_back("You sleep safely for " + to_string(hours) + " hours" + to_string(minutes) + " minutes");
			}
			if (gracz.hp < gracz.max_hp)
			{
				
				message.push_back("You regenerate some health points");
				gracz.hp = gracz.hp + (0.05*gracz.hp);
			}
			gracz.gold = gracz.gold - cena;
			if (gracz.hp > gracz.max_hp)
			{
				gracz.hp = gracz.max_hp;
			}
			change_time(height, startPoint, gracz, hours, minutes);
			range(gracz);
		}
	}
}
#include "level_up.h"
#include "tytul.h"
#include "boost_syf.h"
#include "tabelka.h"

void removeNegativeEffects(player& gracz)
{
	if (gracz.counter_nerf_str != 0)
	{
		remove_nerf_str(gracz);
	}
	if (gracz.counter_nerf_agility != 0)
	{
		remove_nerf_agility(gracz);
	}
	if (gracz.counter_nerf_intel != 0)
	{
		remove_nerf_intel(gracz);
	}
	if (gracz.counter_nerf_luck != 0)
	{
		remove_nerf_luck(gracz);
	}
	if (gracz.counter_nerf_charisma != 0)
	{
		remove_nerf_charisma(gracz);
	}
}

void levelUp(int height, int startPoint, player& gracz, int skipCheckingXP)
{
	if (skipCheckingXP == 1)
	{
		vector <string> message;
		vector <string> options;
		removeNegativeEffects(gracz);
		message.push_back("You are promoted to level " + to_string(gracz.level + 1));
		gracz.exp_to_next_level = gracz.level * 1000;
		gracz.level = gracz.level + 1;
		gracz.hp = gracz.max_hp + 10;
		gracz.max_hp = gracz.hp;
		give_the_title(gracz);
		message.push_back("You get a skill point, which statistic you want to add it to?");
		options.push_back("Strength");
		options.push_back("Agility");
		options.push_back("Inteligence");
		options.push_back("Charisma");
		options.push_back("Luck");
		int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
		switch (highlight)
		{
		case 0:
		{
			gracz.str++;
			break;
		}
		case 1:
		{
			gracz.agility++;
			break;
		}
		case 2:
		{
			gracz.intel++;
			break;
		}
		case 3:
		{
			gracz.charisma++;
			break;
		}
		case 4:
		{
			gracz.luck++;
			break;
		}
		}
	}
	else
	{
		while (gracz.exp >= gracz.exp_to_next_level)
		{
			vector <string> message;
			vector <string> options;
			removeNegativeEffects(gracz);
			message.push_back("You are promoted to level " + to_string(gracz.level + 1));
			gracz.exp = gracz.exp - gracz.exp_to_next_level;
			gracz.exp_to_next_level = gracz.level * 1000;
			gracz.level = gracz.level + 1;
			gracz.hp = gracz.max_hp + 10;
			gracz.max_hp = gracz.hp;
			give_the_title(gracz);
			message.push_back("You get a skill point, which statistic you want to add it to?");
			options.push_back("Strength");
			options.push_back("Agility");
			options.push_back("Inteligence");
			options.push_back("Charisma");
			options.push_back("Luck");
			int highlight = tabSubmenuOneColumnChoice(height, startPoint, message, options);
			switch (highlight)
			{
			case 0:
			{
				gracz.str++;
				break;
			}
			case 1:
			{
				gracz.agility++;
				break;
			}
			case 2:
			{
				gracz.intel++;
				break;
			}
			case 3:
			{
				gracz.charisma++;
				break;
			}
			case 4:
			{
				gracz.luck++;
				break;
			}
			}
		}
	}
}
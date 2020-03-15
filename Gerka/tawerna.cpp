#include "tawerna.h"
#include "tabelka.h"
#include "zakres.h"
#include "czas.h"
#include "karty.h"
#include "level_up.h"
#include "chest.h"
#include "sleep.h"
#include "wait.h"

void drunked(int height, int startPoint, player &gracz)
{
	vector <string> message;
	message.push_back("You're too drunk, you fall asleep in a tavern");
	change_time(height, startPoint, gracz, 8, 0);
	robbery(height, startPoint, gracz, message);
}

void robbery(int height, int startPoint, player &gracz, vector <string> message)
{
	srand((unsigned int)time(NULL));
	int rand1 = rand() % 100;
	int rand2 = rand() % 100+gracz.luck;
	if (rand2 < rand1 && gracz.gold>0)
	{
		message.push_back("Someone stole some money from you");
		if (gracz.gold > 10000)
		{
			gracz.gold=gracz.gold - (0.2*gracz.gold);
		}
		else if (gracz.gold > 1000)
		{
			gracz.gold = gracz.gold - (0.1*gracz.gold);
		}
		else
		{
			gracz.gold = gracz.gold - (0.05*gracz.gold);
		}
	}
	else
	{
		message.push_back("You sleep safely for 8 hours");
	}
	tabSubmenuTextOnly(height, startPoint, message);
}

void flirting(int height, int startPoint, player &gracz)
{
	vector <string> message;
	srand((unsigned int)time(NULL));
	int sukces = rand() % 100;
	int sukces2 = rand() % 100+gracz.luck;
	if (sukces2 > sukces)
	{
		message.push_back("You've managed to successfully hit on a girl");
		vector <string> names;
		string linia;
		fstream plik;
		plik.open("./txt/tawerna/imiona.txt", ios::in);
		while (!plik.eof())
		{
			getline(plik, linia);
			names.push_back(linia);
		}
		plik.close();
		int rand1 = rand() % names.size();
		message.push_back("Her name is " + names[rand1]);
		if (gracz.alko != 0)
		{
			message.push_back("The date goes well, both of you get a little tipsy");
		}
		sukces = rand() % 100;
		sukces2 = rand() % 20 + gracz.luck;
		if (sukces2 < sukces)
		{
			message.push_back("It turns out she came with some guy, the two of you begin to brawl");
			message.push_back("The function is not ready yet \"TODO\"");
			tabSubmenuTextOnly(height, startPoint, message);
			//int rand1 = rand() % 3;
			//gracz = fight(gracz, rand1);
			//gracz.reset_fight_status();
		}
		else
		{
			message.push_back("She left. Probably got spooked out, that's a shame...");
		}
	}
	else
	{
		message.push_back("You've not managed to successfully hit on a girl, better luck next time");
	}
	tabSubmenuTextOnly(height,startPoint,message);
}

player enter_tavern(player gracz,barman bobby, chest &krzynka)
{
	change_time(23,32,gracz, 0, 5);
	int tryb = 0;
	int highlight = 0;
	while (1)
	{
		levelUp(23,32,gracz);
		if (gracz.hp <= 0)
		{
			return gracz;
		}
		string info[20];
		string local = "Tavern";

		string menu[20];
		long ceny[20]; 

		if (tryb == 1)
		{
			for (int i = 0; i < 20; i++)
			{
				menu[i] = bobby.menu[i];
				ceny[i] = bobby.ceny[i];
				info[i] = bobby.info[i];
			}
		}
		else
		{
			/* 1*/menu[0] = "Talk to Barkeep";
			/* 2*/menu[1] = "Play cards";
			/* 3*/menu[2] = "Start a fight [unavailable]";
			/* 4*/menu[3] = "Look for a team [unavailable]";
			/* 5*/menu[4] = "Hit up on girls";
			/* 6*/menu[5] = "Stash items in a chest";
			/* 7*/menu[6] = "";
			/* 8*/menu[7] = "";
			/* 9*/menu[8] = "";
			/*10*/menu[9] = "";
			/*11*/menu[10] = "";
			/*12*/menu[11] = "";
			/*13*/menu[12] = "";
			/*14*/menu[13] = "";
			/*15*/menu[14] = "";
			/*16*/menu[15] = "";
			/*17*/menu[16] = "";
			/*18*/menu[17] = "";
			/*19*/menu[18] = "";
			/*20*/menu[19] = "";
			ceny[0] = 0;
			ceny[1] = 0;
			ceny[2] = 0;
			ceny[3] = 0;
			ceny[4] = 0;
			ceny[5] = 0;
			ceny[6] = 0;
			ceny[7] = 0;
			ceny[8] = 0;
			ceny[9] = 0;
			ceny[10] = 0;
			ceny[11] = 0;
			ceny[12] = 0;
			ceny[13] = 0;
			ceny[14] = 0;
			ceny[15] = 0;
			ceny[16] = 0;
			ceny[17] = 0;
			ceny[18] = 0;
			ceny[19] = 0;
			info[0] = "Leave tavern";
			info[1] = "Wait";
			info[2] = "";
			info[3] = "";
			info[4] = "";
			info[5] = "";
			info[6] = "";
			info[7] = "";
			info[8] = "";
			info[9] = "";
			info[10] = "";
			info[11] = "";
			info[12] = "";
			info[13] = "";
			info[14] = "";
			info[15] = "";
			info[16] = "";
			info[17] = "";
			info[18] = "";
			info[19] = "";
		}


		for (int i = 0; i < 20; i++)
		{
			if (ceny[i] > 10000)
			{
				ceny[i] = 10000;
			}
			else if (ceny[i] < 0)
			{
				ceny[i] = 0;
			}
		}
		tab(gracz, highlight, local, info, menu, ceny);
		switch (highlight)
		{
		case 0:
		{
			if (gracz.alko == 10 && tryb == 0)
			{
				drunked(23, 32, gracz);
				break;
			}
			else if (tryb == 0)
			{
				change_time(23,32,gracz, 0, 5);
				return gracz;
			}
			else if (tryb == 1)
			{
				tryb = 0;
				change_time(23,32,gracz, 0, 1);
				break;
			}
		}
		case 1:
		{
			wait_n_hours(23, 32, gracz);
			break;
		}
		case 20:
		{
			if (tryb == 0)
			{
				change_time(23,32,gracz, 0, 1);
				tryb = 1;
			}
			else
			{
				bobby.gossip(23, 32, gracz);
			}
			break;
		}
		case 21:
		{
			if (tryb == 0)
			{
				gambling(23, 32, gracz);
				range(gracz);
			}
			else
			{
				bobby.give_room(23, 32, gracz);
				tryb = 0;
			}
			break;
		}
		case 22:
		{
			if (tryb == 0)
			{
				/*int rand1 = rand() % 3;
				gracz = fight(gracz, rand1);*/
				vector <string> message;
				message.push_back("The function is not ready yet \"TODO\"");
				tabSubmenuTextOnly(23, 32, message);
				break;
			}
			else
			{
				bobby.sell_food(23, 32, gracz, 2);
			}
			break;
		}
		case 23:
		{
			if (tryb == 0)
			{
				vector <string> message;
				message.push_back("The function is not ready yet \"TODO\"");
				tabSubmenuTextOnly(23, 32, message);
				break;
			}
			else
			{
				bobby.sell_beer(23, 32, gracz);
				if (gracz.alko == 10)
				{
					drunked(23, 32, gracz);
				}
			}
			break;
		}
		case 24:
		{
			if (tryb == 0)
			{
				flirting(23, 32, gracz);
			}
			else
			{
				;
			}
			break;
		}
		case 25:
		{
			if (tryb == 0)
			{
				enter_chest_mode(gracz, krzynka);
			}
			else
			{
				;
			}
			break;
		}
		}
	}
}
#include "town square.h"
#include "tawerna.h"
#include "kowal.h"
#include "burdel.h"
#include "alchemik.h"
#include "general_store.h"
#include "game_over.h"
#include "cheat_menu.h"
#include "save.h"
#include "shamans_house.h"
#include "szpital.h"
#include "inventory.h"
#include "level_up.h"
#include "tabelka.h"
#include "quest.h"
#include "dungeon.h"
#include "czas.h"
#include "bladesmithShop.h"

int enterTownSquare(player gracz,barman bobby, generalStoreSeller handlarz, blacksmith kowal, bladesmith miecznik, alchemist alchemik,shaman szaman, doctor lekarz, chest krzynka)
{
	srand((unsigned int)time(NULL));
	int highlight = 0;
	while (1)
	{
		check_quest_status(gracz);
		levelUp(23,32,gracz);
		if (gracz.hp <= 0)
		{
			game_over(55,0);
			return 0;
		}
		string local = "Town square";

		string info[20];
		info[0] = "Close game";
		info[1] = "Save game";
		info[2] = "Equipment & Stats";
		info[3] = "Skills";
		info[4] = "Quests";
		info[5] = "Crafting";
		info[6] = "Wait";
		info[7] = "Test";
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

		string menu[20];
		/* 1*/menu[0] = "Go to the tavern";
		/* 2*/menu[1] = "Go to the forge"; 
		/* 3*/menu[2] = "Go to the bladesmith shop";
		/* 4*/menu[3] = "Go to the alchemist's lab";
		/* 5*/menu[4] = "Go to the brothel";
		/* 6*/menu[5] = "Go to the general store";
		/* 7*/menu[6] = "Go to the shaman's house";
		/* 8*/menu[7] = "Go to the hospital";
		/* 9*/menu[8] = "Enter the dungeon";
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

		__int64 ceny[20];
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
		case 20:
		{
			gracz = enter_tavern(gracz,bobby,krzynka);
			break;
		}
		case 21:
		{
			gracz = enter_forge(gracz,kowal);
			break;
		}
		case 22:
		{
			gracz = enterBladesmithShop(gracz, miecznik);
			break;
		}
		case 23:
		{
			gracz = enter_laboratory(gracz,alchemik);
			break;
		}
		case 24:
		{
			gracz = enter_brothel(gracz);
			break;
		}
		case 25:
		{
			gracz = enter_shop(gracz,handlarz);
			break;
		}
		case 26:
		{
			gracz = enter_shaman_house(gracz,szaman);
			break;
		}
		case 27:
		{
			gracz = enter_hospital(gracz, lekarz);
			break;
		}
		case 28:
		{
			gracz = enterDungeon(gracz);
			break;
		}
		case 0:
		{
			vector <string> message;
			vector <string> options;
			message.push_back("Are you sure you want to close the game?");
			message.push_back("The progress will not be saved.");
			options.push_back("Yes");
			options.push_back("No");
			int highlight = tabSubmenuOneColumnChoice(23,32,message,options);
			if (highlight == 0)
			{
				return 0;
			}
			break;
		}
		case 1:
		{
			save(23,32,gracz, bobby, handlarz, kowal, alchemik, krzynka);
			break;
		}
		case 2:
		{
			gracz = enter_inventory(gracz);
			break;
		}
		case 6:
		{
			wait_n_hours(23, 32, gracz);
			break;
		}
		case 5:
		{
			break;
		}
		case 7:
		{
			gracz = enter_cheat_menu(gracz);
			break;
		}
		default:
		{
			break;
		}
		}
	}
	return 0;
}
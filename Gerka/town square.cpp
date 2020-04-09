#include "town square.h"
//#include "tawerna.h"
#include "kowal.h"
//#include "burdel.h"
//#include "alchemik.h"
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
//#include "dungeon.h"
#include "czas.h"
//#include "bladesmithShop.h"
#include "playerTransport.h"
#include "NPCTransport.h"

int enterTownSquare(player gracz,barman bobby, generalStoreSeller handlarz, blacksmith kowal, bladesmith miecznik, alchemist alchemik,shaman szaman, doctor lekarz, chest krzynka)
{
	srand((unsigned int)time(NULL));
	int highlight = 0;
	while (1)
	{
		checkQuestStatus(gracz);
		levelUp(23,32,gracz);
		if (gracz.hp <= 0)
		{
			gameOver(55,0);
			return 0;
		}
		string local = "Town square";

		string info[20];
		info[0] = "Back to main menu";
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
			//gracz = enterTavern(gracz,bobby,krzynka);
			typedef void(*Shit_fun)();
			Shit_fun shit;
			//HINSTANCE cos = LoadLibrary("../Debug/Tavern.dll");
			HINSTANCE cos = LoadLibrary("./dll/Tavern.dll");
			if (cos)
			{
				shit = (Shit_fun)GetProcAddress(cos, "enterTavern");
				if (shit)
				{
					savePlayerTemp(gracz);
					saveBarmanTemp(bobby);
					saveChestTemp(krzynka);
					shit();
					loadPlayerTemp(gracz);
					loadBarmanTemp(bobby);
					loadChestTemp(krzynka);
				}
				else
				{
					vector <string> message = { "This location is unavailable, you have to buy a expansion." };
					tabSubmenuTextOnly(23, 32, message);
				}
				FreeLibrary(cos);
			}
			else
			{
				vector <string> message = { "This location is unavailable, you have to buy a expansion." };
				tabSubmenuTextOnly(23, 32, message);
			}
			break;
		}
		case 21:
		{
			gracz = enterForge(gracz,kowal);
			break;
		}
		case 22:
		{
			//gracz = enterBladesmithShop(gracz, miecznik);
			typedef void(*Shit_fun)();
			Shit_fun shit;
			//HINSTANCE cos = LoadLibrary("../Debug/BladesmithShop.dll");
			HINSTANCE cos = LoadLibrary("./dll/BladesmithShop.dll");
			if (cos)
			{
				shit = (Shit_fun)GetProcAddress(cos, "enterBladesmithShop");
				if (shit)
				{
					savePlayerTemp(gracz);
					saveBladesmithTemp(miecznik);
					shit();
					loadPlayerTemp(gracz);
					loadBladesmithTemp(miecznik);
				}
				else
				{
					vector <string> message = { "This location is unavailable, you have to buy a expansion." };
					tabSubmenuTextOnly(23, 32, message);
				}
				FreeLibrary(cos);
			}
			else
			{
				vector <string> message = { "This location is unavailable, you have to buy a expansion." };
				tabSubmenuTextOnly(23, 32, message);
			}
			break;
		}
		case 23:
		{
			//gracz = enterLaboratory(gracz,alchemik);
			typedef void(*Shit_fun)();
			Shit_fun shit;
			//HINSTANCE cos = LoadLibrary("../Debug/AlchemistLab.dll");
			HINSTANCE cos = LoadLibrary("./dll/AlchemistLab.dll");
			if (cos)
			{
				shit = (Shit_fun)GetProcAddress(cos, "enterAlchemistLab");
				if (shit)
				{
					savePlayerTemp(gracz);
					saveAlchemistTemp(alchemik);
					shit();
					loadPlayerTemp(gracz);
					loadAlchemistTemp(alchemik);
				}
				else
				{
					vector <string> message = { "This location is unavailable, you have to buy a expansion." };
					tabSubmenuTextOnly(23, 32, message);
				}
				FreeLibrary(cos);
			}
			else
			{
				vector <string> message = { "This location is unavailable, you have to buy a expansion." };
				tabSubmenuTextOnly(23, 32, message);
			}
			break;
		}
		case 24:
		{
			typedef void(*Shit_fun)();
			Shit_fun shit;
			HINSTANCE cos = LoadLibrary("./dll/Brothel.dll");
			if (cos)
			{
				shit = (Shit_fun)GetProcAddress(cos, "enterBrothel");
				if (shit)
				{
					savePlayerTemp(gracz);
					shit();
					loadPlayerTemp(gracz);
				}
				else
				{
					vector <string> message = { "This location is unavailable, you have to buy a expansion." };
					tabSubmenuTextOnly(23, 32, message);
				}
				FreeLibrary(cos);
			}
			else
			{
				vector <string> message = { "This location is unavailable, you have to buy a expansion." };
				tabSubmenuTextOnly(23, 32, message);
			}
			break;
		}
		case 25:
		{
			gracz = enterShop(gracz,handlarz);
			break;
		}
		case 26:
		{
			gracz = enterShamanHouse(gracz,szaman);
			break;
		}
		case 27:
		{
			gracz = enterHospital(gracz, lekarz);
			break;
		}
		case 28:
		{
			//gracz = enterDungeon(gracz);
			typedef void(*Shit_fun)();
			Shit_fun shit;
			//HINSTANCE cos = LoadLibrary("../Debug/Dungeon.dll");
			HINSTANCE cos = LoadLibrary("./dll/Dungeon.dll");
			if (cos)
			{
				shit = (Shit_fun)GetProcAddress(cos, "enterDungeon");
				if (shit)
				{
					savePlayerTemp(gracz);
					shit();
					loadPlayerTemp(gracz);
				}
				else
				{
					vector <string> message = { "This location is unavailable, you have to buy a expansion." };
					tabSubmenuTextOnly(23, 32, message);
				}
				FreeLibrary(cos);
			}
			else
			{
				vector <string> message = { "This location is unavailable, you have to buy a expansion." };
				tabSubmenuTextOnly(23, 32, message);
			}
			break;
		}
		case 0:
		{
			vector <string> message;
			vector <string> options;
			message.push_back("Are you sure you want to back to the main menu?");
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
			gracz = enterInventory(gracz);
			break;
		}
		case 6:
		{
			waitNHours(23, 32, gracz);
			break;
		}
		case 5:
		{
			break;
		}
		case 7:
		{
			gracz = enterCheatMenu(gracz);
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
#include "bladesmithShop.h"
#include "tabelka.h"
#include "czas.h"
#include "level_up.h"
#include "zakres.h"
#include "trade_mode.h"
#include "playerTransport.h"
#include "NPCTransport.h"
#include "dwellers.h"

extern "C" DLLFUNCEX void enterBladesmithShop()
{
	player gracz;
	loadPlayerTemp(gracz);
	bladesmith miecznik;
	loadBladesmithTemp(miecznik);
	bool exit = false;
	int highlight = 0;
	string menu[20];
	string info[20];
	__int64 ceny[20];
	string local;
	changeTime(23, 32, gracz, 0, 5);
	if (gracz.hour >= 20 || gracz.hour < 6)
	{
		vector<string> message;
		message.push_back("Forge closed");
		tabSubmenuFancyTextOnly(23, 32, message, 50);
		exit = true;
		savePlayerTemp(gracz);
		saveBladesmithTemp(miecznik);
	}
	int tryb = 0;
	while (exit == false)
	{
		if (gracz.hour >= 20 || gracz.hour < 6)
		{
			miecznik.weAreClosing(gracz);
			vector<string> message;
			message.push_back("You have to go. We're closing.");
			tabSubmenuFancyTextOnly(23, 32, message, 50);
			changeTime(23, 32, gracz, 0, 5);
			exit = true;
			savePlayerTemp(gracz);
			saveBladesmithTemp(miecznik);
		}
		if (gracz.hp <= 0)
		{
			exit = true;
			savePlayerTemp(gracz);
			saveBladesmithTemp(miecznik);
		}
		levelUp(23, 32, gracz);
		local = "Bladesmith Shop";
		if (tryb == 1)
		{
			miecznik.generateMerch(gracz);
			for (int i = 0; i < 20; i++)
			{
				menu[i] = miecznik.menu[i];
				ceny[i] = miecznik.ceny[i];
				info[i] = miecznik.info[i];
			}
		}
		else
		{
			/* 1*/menu[0] = "Talk to bladesmith";
			/* 2*/menu[1] = "";
			/* 3*/menu[2] = "";
			/* 4*/menu[3] = "";
			/* 5*/menu[4] = "";
			/* 6*/menu[5] = "";
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
			info[0] = "Leave Bladesmith shop";
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
		range(gracz);
		tab(gracz, highlight, local, info, menu, ceny);
		switch (highlight)
		{
		case 20:
		{
			if (tryb == 0)
			{
				tryb = 1;
				changeTime(23, 32, gracz, 0, 1);
			}
			else
			{
				gracz = tradeModeBladesmithShop(gracz, miecznik);
			}
			break;
		}
		case 1:
		{
			waitNHours(23, 32, gracz);
			break;
		}
		case 0:
		{
			if (tryb == 0)
			{
				changeTime(23, 32, gracz, 0, 5);
				exit = true;
				savePlayerTemp(gracz);
				saveBladesmithTemp(miecznik);
			}
			else if (tryb == 1)
			{
				tryb = 0;
				changeTime(23, 32, gracz, 0, 1);
				break;
			}
		}
		}
	}
}

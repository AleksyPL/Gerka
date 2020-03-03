#include "general_store.h"
#include "tabelka.h"
#include "trade_mode.h"
#include "trade_tab.h"
#include "level_up.h"
#include "czas.h"
#include "wait.h"


player enter_shop(player gracz, seller handlarz)
{
	int highlight = 0;
	change_time(23,32,gracz, 0, 5);
	if (gracz.hour >= 20 || gracz.hour <6)
	{
		vector<string> message;
		message.push_back("Store closed");
		tabSubmenuFancyTextOnly(23, 32, message, 50);
		return gracz;
	}
	int tryb = 0;
	while (1)
	{
		if (gracz.hour >= 20 || gracz.hour < 6)
		{
			handlarz.weAreClosing(gracz);
			vector<string> message;
			message.push_back("You have to go. We're closing.");
			tabSubmenuFancyTextOnly(23, 32, message, 50);
			change_time(23,32,gracz, 0, 5);
			return gracz;
		}
		if (gracz.hp <= 0)
		{
			return gracz;
		}
		levelUp(23,32,gracz);
		string menu[20];
		string info[20];
		long ceny[20];
		string local = "General store";
		if (tryb == 1)
		{
			//Opcje w lokacji 35 znakow
			/* 1*/menu[0] = handlarz.menu[0];
			/* 2*/menu[1] = handlarz.menu[1];
			/* 3*/menu[2] = handlarz.menu[2];
			/* 4*/menu[3] = handlarz.menu[3];
			/* 5*/menu[4] = handlarz.menu[4];
			/* 6*/menu[5] = handlarz.menu[5];
			/* 7*/menu[6] = handlarz.menu[6];
			/* 8*/menu[7] = handlarz.menu[7];
			/* 9*/menu[8] = handlarz.menu[8];
			/*10*/menu[9] = handlarz.menu[9];
			/*11*/menu[10] = handlarz.menu[10];
			/*12*/menu[11] = handlarz.menu[11];
			/*13*/menu[12] = handlarz.menu[12];
			/*14*/menu[13] = handlarz.menu[13];
			/*15*/menu[14] = handlarz.menu[14];
			/*16*/menu[15] = handlarz.menu[15];
			/*17*/menu[16] = handlarz.menu[16];
			/*18*/menu[17] = handlarz.menu[17];
			/*19*/menu[18] = handlarz.menu[18];
			/*20*/menu[19] = handlarz.menu[19];
			ceny[0] = handlarz.ceny[0];
			ceny[1] = handlarz.ceny[1];
			ceny[2] = handlarz.ceny[2];
			ceny[3] = handlarz.ceny[3];
			ceny[4] = handlarz.ceny[4];
			ceny[5] = handlarz.ceny[5];
			ceny[6] = handlarz.ceny[6];
			ceny[7] = handlarz.ceny[7];
			ceny[8] = handlarz.ceny[8];
			ceny[9] = handlarz.ceny[9];
			ceny[10] = handlarz.ceny[10];
			ceny[11] = handlarz.ceny[11];
			ceny[12] = handlarz.ceny[12];
			ceny[13] = handlarz.ceny[13];
			ceny[14] = handlarz.ceny[14];
			ceny[15] = handlarz.ceny[15];
			ceny[16] = handlarz.ceny[16];
			ceny[17] = handlarz.ceny[17];
			ceny[18] = handlarz.ceny[18];
			ceny[19] = handlarz.ceny[19];
			info[0] = handlarz.info[0];
			info[1] = handlarz.info[1];
			info[2] = handlarz.info[2];
			info[3] = handlarz.info[3];
			info[4] = handlarz.info[4];
			info[5] = handlarz.info[5];
			info[6] = handlarz.info[6];
			info[7] = handlarz.info[7];
			info[8] = handlarz.info[8];
			info[9] = handlarz.info[9];
			info[10] = handlarz.info[10];
			info[11] = handlarz.info[11];
			info[12] = handlarz.info[12];
			info[13] = handlarz.info[13];
			info[14] = handlarz.info[14];
			info[15] = handlarz.info[15];
			info[16] = handlarz.info[16];
			info[17] = handlarz.info[17];
			info[18] = handlarz.info[18];
			info[19] = handlarz.info[19];
		}
		else
		{
			/* 1*/menu[0] = "Talk with trader";
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
			info[0] = "Leave general store";
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
		case 20:
		{
			if (tryb == 0)
			{
				change_time(23,32,gracz, 0, 1);
				tryb = 1;
			}
			else
			{
				//table menuu;
				gracz = trade_mode(gracz, handlarz);
			}
			break;
		}
		case 1:
		{
			wait_n_hours(23, 32, gracz);
			break;
		}
		case 0:
		{
			if (tryb == 0)
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
		}
	}
}
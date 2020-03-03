#include "tabelka.h"
#include "zakres.h"
#include "kowal.h"
#include "level_up.h"
#include "czas.h"
#include "wait.h"

player enter_forge(player gracz,blacksmith kowal)
{
	int highlight = 0;
	change_time(23,32,gracz, 0, 5);
	if (gracz.hour >= 20 || gracz.hour <6)
	{
		vector<string> message;
		message.push_back("Forge closed");
		tabSubmenuFancyTextOnly(23, 32, message, 50);
		return gracz;
	}
	int tryb = 0;
	while (1)
	{
		if (gracz.hour >= 20 || gracz.hour < 6)
		{
			kowal.weAreClosing(gracz);
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
		levelUp(23,32, gracz);
		string menu[20];
		string info[20];
		long ceny[20];
		string local = "Forge";
		if (tryb == 1)
		{
			kowal.load_player_points(gracz);
			//Opcje w lokacji 35 znakow
			/* 1*/menu[0] = kowal.menu[0];
			/* 2*/menu[1] = kowal.menu[1];
			/* 3*/menu[2] = kowal.menu[2];
			/* 4*/menu[3] = kowal.menu[3];
			/* 5*/menu[4] = kowal.menu[4];
			/* 6*/menu[5] = kowal.menu[5];
			/* 7*/menu[6] = kowal.menu[6];
			/* 8*/menu[7] = kowal.menu[7];
			/* 9*/menu[8] = kowal.menu[8];
			/*10*/menu[9] = kowal.menu[9];
			/*11*/menu[10] = kowal.menu[10];
			/*12*/menu[11] = kowal.menu[11];
			/*13*/menu[12] = kowal.menu[12];
			/*14*/menu[13] = kowal.menu[13];
			/*15*/menu[14] = kowal.menu[14];
			/*16*/menu[15] = kowal.menu[15];
			/*17*/menu[16] = kowal.menu[16];
			/*18*/menu[17] = kowal.menu[17];
			/*19*/menu[18] = kowal.menu[18];
			/*20*/menu[19] = kowal.menu[19];
			ceny[0] = kowal.ceny[0];
			ceny[1] = kowal.ceny[1];
			ceny[2] = kowal.ceny[2];
			ceny[3] = kowal.ceny[3];
			ceny[4] = kowal.ceny[4];
			ceny[5] = kowal.ceny[5];
			ceny[6] = kowal.ceny[6];
			ceny[7] = kowal.ceny[7];
			ceny[8] = kowal.ceny[8];
			ceny[9] = kowal.ceny[9];
			ceny[10] = kowal.ceny[10];
			ceny[11] = kowal.ceny[11];
			ceny[12] = kowal.ceny[12];
			ceny[13] = kowal.ceny[13];
			ceny[14] = kowal.ceny[14];
			ceny[15] = kowal.ceny[15];
			ceny[16] = kowal.ceny[16];
			ceny[17] = kowal.ceny[17];
			ceny[18] = kowal.ceny[18];
			ceny[19] = kowal.ceny[19];
			info[0] = kowal.info[0];
			info[1] = kowal.info[1];
			info[2] = kowal.info[2];
			info[3] = kowal.info[3];
			info[4] = kowal.info[4];
			info[5] = kowal.info[5];
			info[6] = kowal.info[6];
			info[7] = kowal.info[7];
			info[8] = kowal.info[8];
			info[9] = kowal.info[9];
			info[10] = kowal.info[10];
			info[11] = kowal.info[11];
			info[12] = kowal.info[12];
			info[13] = kowal.info[13];
			info[14] = kowal.info[14];
			info[15] = kowal.info[15];
			info[16] = kowal.info[16];
			info[17] = kowal.info[17];
			info[18] = kowal.info[18];
			info[19] = kowal.info[19];
		}
		else
		{
			/* 1*/menu[0] = "Talk to blacksmith";
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
			info[0] = "Leave forge";
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
		if (highlight >= 20 && highlight <= 25 && tryb == 1)
		{
			kowal.power_up(23, 32, gracz, highlight - 20);
		}
		else
		{
			switch (highlight)
			{
			case 20:
			{
				if (tryb == 0)
				{
					tryb = 1;
					change_time(23,32,gracz, 0, 1);
					kowal.load_weapons();
					kowal.generate_merch(gracz);
				}
				else
				{
					;
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
}

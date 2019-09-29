#include "shamans_house.h"
#include "tabelka.h"
#include "zakres.h"
#include "level_up.h"
#include "czas.h"
#include "wait.h"

player enter_shaman_house(player gracz, shaman szaman)
{
	change_time(gracz, 0, 5);
	if (gracz.hour >= 20 || gracz.hour <6)
	{
		system("cls");
		print_info_box_from_file("shaman_closed");
		change_time(gracz, 0, 5);
		return gracz;
	}
	int tryb = 0;
	//int info_box = 0;
	while (1)
	{
		if (gracz.hour >= 20 || gracz.hour < 6)
		{
			print_info_box_from_string("Musisz ju¿ iœæ, zamykam");
			change_time(gracz, 0, 5);
			return gracz;
		}
		if (gracz.hp <= 0)
		{
			return gracz;
		}
		level_up(gracz);
		system("cls");
		string menu[60];
		string info[8];
		long ceny[20];

		//glowne staty 23 znaki
		/* 1*/menu[0] = "PUNKTY SI£Y:";
		/* 2*/menu[1] = "PUNKTY ZRÊCZNOŒCI:";
		/* 3*/menu[2] = "PUNKTY INTELIGENCJI:";
		/* 4*/menu[3] = "PUNKTY CHARYZMY:";
		/* 5*/menu[4] = "PUNKTY SZCZÊŒCIA:";
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

		//wartosci glownych statow
		/* 1*/menu[20] = to_string(gracz.str);
		/* 2*/menu[21] = to_string(gracz.agility);
		/* 3*/menu[22] = to_string(gracz.intel);
		/* 4*/menu[23] = to_string(gracz.charisma);
		/* 5*/menu[24] = to_string(gracz.luck);
		/* 6*/menu[25] = "";
		/* 7*/menu[26] = "";
		/* 8*/menu[27] = "";
		/* 9*/menu[28] = "";
		/*10*/menu[29] = "";
		/*11*/menu[30] = "";
		/*12*/menu[31] = "";
		/*13*/menu[32] = "";
		/*14*/menu[33] = "";
		/*15*/menu[34] = "";
		/*16*/menu[35] = "";
		/*17*/menu[36] = "";
		/*18*/menu[37] = "";
		/*19*/menu[38] = "";
		/*20*/menu[39] = "";

		if (tryb == 1)
		{
			//Opcje w lokacji 35 znakow
			/* 1*/menu[40] = szaman.menu[0];
			/* 2*/menu[41] = szaman.menu[1];
			/* 3*/menu[42] = szaman.menu[2];
			/* 4*/menu[43] = szaman.menu[3];
			/* 5*/menu[44] = szaman.menu[4];
			/* 6*/menu[45] = szaman.menu[5];
			/* 7*/menu[46] = szaman.menu[6];
			/* 8*/menu[47] = szaman.menu[7];
			/* 9*/menu[48] = szaman.menu[8];
			/*10*/menu[49] = szaman.menu[9];
			/*11*/menu[50] = szaman.menu[10];
			/*12*/menu[51] = szaman.menu[11];
			/*13*/menu[52] = szaman.menu[12];
			/*14*/menu[53] = szaman.menu[13];
			/*15*/menu[54] = szaman.menu[14];
			/*16*/menu[55] = szaman.menu[15];
			/*17*/menu[56] = szaman.menu[16];
			/*18*/menu[57] = szaman.menu[17];
			/*19*/menu[58] = szaman.menu[18];
			/*20*/menu[59] = szaman.menu[19];
			ceny[0] = szaman.ceny[0];
			ceny[1] = szaman.ceny[1];
			ceny[2] = szaman.ceny[2];
			ceny[3] = szaman.ceny[3];
			ceny[4] = szaman.ceny[4];
			ceny[5] = szaman.ceny[5];
			ceny[6] = szaman.ceny[6];
			ceny[7] = szaman.ceny[7];
			ceny[8] = szaman.ceny[8];
			ceny[9] = szaman.ceny[9];
			ceny[10] = szaman.ceny[10];
			ceny[11] = szaman.ceny[11];
			ceny[12] = szaman.ceny[12];
			ceny[13] = szaman.ceny[13];
			ceny[14] = szaman.ceny[14];
			ceny[15] = szaman.ceny[15];
			ceny[16] = szaman.ceny[16];
			ceny[17] = szaman.ceny[17];
			ceny[18] = szaman.ceny[18];
			ceny[19] = szaman.ceny[19];
			info[0] = szaman.info[0];
			info[1] = szaman.info[1];
			info[2] = szaman.info[2];
			info[3] = szaman.info[3];
			info[4] = szaman.info[4];
			info[5] = szaman.info[5];
			info[6] = szaman.info[6];
			info[7] = szaman.info[7];
		}
		else
		{
			/* 1*/menu[40] = "ROZMAWIAJ Z SZAMANEM";
			/* 2*/menu[41] = "";
			/* 3*/menu[42] = "";
			/* 4*/menu[43] = "";
			/* 5*/menu[44] = "";
			/* 6*/menu[45] = "";
			/* 7*/menu[46] = "";
			/* 8*/menu[47] = "";
			/* 9*/menu[48] = "";
			/*10*/menu[49] = "";
			/*11*/menu[50] = "";
			/*12*/menu[51] = "";
			/*13*/menu[52] = "";
			/*14*/menu[53] = "";
			/*15*/menu[54] = "";
			/*16*/menu[55] = "";
			/*17*/menu[56] = "";
			/*18*/menu[57] = "";
			/*19*/menu[58] = "";
			/*20*/menu[59] = "";
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
			info[0] = "DOM SZAMANA";
			info[1] = "W: WRÓÆ NA RYNEK";
			info[2] = "C: CZEKAJ";
			info[3] = "";
			info[4] = "";
			info[5] = "";
			info[6] = "";
			info[7] = "";
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
		tab(gracz, info, menu, ceny);
		cout << "Twój wybór to: ";
		string wyb;
		cin >> wyb;
		wyb = string_tolower(wyb);
		switch (wyb[0])
		{
		case '1':
		{
			if (tryb == 0)
			{
				change_time(gracz, 0, 1);
				tryb = 1;
			}
			else
			{
				szaman.add_boost(gracz, 1);
			}
			break;
		}
		case '2':
		{
			if (tryb == 0)
			{
				;
			}
			else
			{
				szaman.add_boost(gracz, 2);
			}
			break;
		}
		case '3':
		{
			if (tryb == 0)
			{
				;
			}
			else
			{
				szaman.add_boost(gracz, 3);
			}
			break;
		}
		case '4':
		{
			if (tryb == 0)
			{
				;
			}
			else
			{
				szaman.add_boost(gracz, 4);
			}
			break;
		}
		case '5':
		{
			if (tryb == 0)
			{
				;
			}
			else
			{
				szaman.add_boost(gracz, 5);
			}
			break;
		}
		case '6':
		{
			if (tryb == 0)
			{
				;
			}
			else
			{
				szaman.add_return_quest(gracz);
			}
			break;
		}
		case 'c':
		{
			gracz = wait_n_hours(gracz,20);
			break;
		}
		case 'w':
		{
			if (tryb == 0)
			{
				change_time(gracz, 0, 5);
				return gracz;
			}
			else if (tryb == 1)
			{
				tryb = 0;
				change_time(gracz, 0, 1);
				break;
			}
		}
		default:
		{
			system("cls");
			break;
		}
		}
	}
}

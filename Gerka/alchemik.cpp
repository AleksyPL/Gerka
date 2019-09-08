#include "zakres.h"
#include "tabelka.h"
#include "level_up.h"
#include "alchemik.h"

player enter_laboratory(player gracz,alchemist alchemik)
{
	int tryb = 0;
	while (1)
	{
		level_up(gracz);
		system("cls");
		string menu[100];
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
			/* 1*/menu[40] = alchemik.menu[0];
			/* 2*/menu[41] = alchemik.menu[1];
			/* 3*/menu[42] = alchemik.menu[2];
			/* 4*/menu[43] = alchemik.menu[3];
			/* 5*/menu[44] = alchemik.menu[4];
			/* 6*/menu[45] = alchemik.menu[5];
			/* 7*/menu[46] = alchemik.menu[6];
			/* 8*/menu[47] = alchemik.menu[7];
			/* 9*/menu[48] = alchemik.menu[8];
			/*10*/menu[49] = alchemik.menu[9];
			/*11*/menu[50] = alchemik.menu[10];
			/*12*/menu[51] = alchemik.menu[11];
			/*13*/menu[52] = alchemik.menu[12];
			/*14*/menu[53] = alchemik.menu[13];
			/*15*/menu[54] = alchemik.menu[14];
			/*16*/menu[55] = alchemik.menu[15];
			/*17*/menu[56] = alchemik.menu[16];
			/*18*/menu[57] = alchemik.menu[17];
			/*19*/menu[58] = alchemik.menu[18];
			/*20*/menu[59] = alchemik.menu[19];
			ceny[0] = gracz.level * 100;
			ceny[1] = alchemik.ceny[1];
			ceny[2] = alchemik.ceny[2];
			ceny[3] = alchemik.ceny[3];
			ceny[4] = alchemik.ceny[4];
			ceny[5] = alchemik.ceny[5];
			ceny[6] = alchemik.ceny[6];
			ceny[7] = alchemik.ceny[7];
			ceny[8] = alchemik.ceny[8];
			ceny[9] = alchemik.ceny[9];
			ceny[10] = alchemik.ceny[10];
			ceny[11] = alchemik.ceny[11];
			ceny[12] = alchemik.ceny[12];
			ceny[13] = alchemik.ceny[13];
			ceny[14] = alchemik.ceny[14];
			ceny[15] = alchemik.ceny[15];
			ceny[16] = alchemik.ceny[16];
			ceny[17] = alchemik.ceny[17];
			ceny[18] = alchemik.ceny[18];
			ceny[19] = alchemik.ceny[19];
			info[0] = alchemik.info[0];
			info[1] = alchemik.info[1];
			info[2] = alchemik.info[2];
			info[3] = alchemik.info[3];
			info[4] = alchemik.info[4];
			info[5] = alchemik.info[5];
			info[6] = alchemik.info[6];
			info[7] = alchemik.info[7];
		}
		else
		{
			/* 1*/menu[40] = "ROZMAWIAJ Z ALCHEMIKIEM";
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
			info[0] = "LABORATORIUM";
			info[1] = "W: WRÓÆ NA RYNEK";
			info[2] = "M: MIKSTURA ¯YCIA";
			info[3] = "";
			info[4] = "";
			info[5] = "";
			info[6] = "";
			info[7] = "";
		}
		
		/* 1*/menu[60] = "MIKSTURY ¯YCIA:";
		/* 2*/menu[61] = "MIKSTURY SI£Y:";
		/* 3*/menu[62] = "MIKSTURY ZRÊCZNOŒCI:";
		/* 4*/menu[63] = "MIKSTURY INTELIGENCJI:";
		/* 5*/menu[64] = "MIKSTURY CHARYZMY:";
		/* 6*/menu[65] = "MIKSTURY SZCZÊŒCIA:";
		/* 7*/menu[66] = "";
		/* 8*/menu[67] = "";
		/* 9*/menu[68] = "";
		/*10*/menu[69] = "";
		/*11*/menu[70] = "";
		/*12*/menu[71] = "";
		/*13*/menu[72] = "";
		/*14*/menu[73] = "";
		/*15*/menu[74] = "";
		/*16*/menu[75] = "";
		/*17*/menu[76] = "";
		/*18*/menu[77] = "";
		/*19*/menu[78] = "";
		/*20*/menu[79] = "";

		/* 1*/menu[80] = to_string(gracz.hp_potion);
		/* 2*/menu[81] = to_string(gracz.str_potion);
		/* 3*/menu[82] = to_string(gracz.agility_potion);
		/* 4*/menu[83] = to_string(gracz.intel_potion);
		/* 5*/menu[84] = to_string(gracz.charisma_potion);
		/* 6*/menu[85] = to_string(gracz.luck_potion);
		/* 7*/menu[86] = "";
		/* 8*/menu[87] = "";
		/* 9*/menu[88] = "";
		/*10*/menu[89] = "";
		/*11*/menu[90] = "";
		/*12*/menu[91] = "";
		/*13*/menu[92] = "";
		/*14*/menu[93] = "";
		/*15*/menu[94] = "";
		/*16*/menu[95] = "";
		/*17*/menu[96] = "";
		/*18*/menu[97] = "";
		/*19*/menu[98] = "";
		/*20*/menu[99] = "";
		
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
		tab(gracz,info, menu, ceny);
		cout << "Twój wybór to: ";
		string wyb;
		cin >> wyb;
		switch (wyb[0])
		{
			//helmet
		case '1':
		{
			if (tryb == 0)
			{
				tryb = 1;
			}
			else
			{
				if (gracz.gold > ceny[0])
				{
					cout << endl << "KUPI£EŒ MIKSTURÊ NOWEGO POZIOMU" << endl;
					level_up(gracz,1);
					gracz.gold = gracz.gold - (gracz.level * 100);
					alchemik.show_image();
				}
				else
				{
					no_money();
				}
				system("PAUSE");
			}
			break;
		}
		//chestplate
		case '2':
		{
			if (tryb == 0)
			{
				;
			}
			else
			{
				alchemik.buy_hp_potion(gracz);
			}
			break;
		}
		case 'M':
		{
			gracz.use_hp_potion();
			break;
		}
		case 'm':
		{
			gracz.use_hp_potion();
			break;
		}
		case 'W':
		{
			if (tryb == 0)
			{
				return gracz;
			}
			else if (tryb == 1)
			{
				tryb = 0;
				break;
			}
		}
		case 'w':
		{
			if (tryb == 0)
			{
				return gracz;
			}
			else if (tryb == 1)
			{
				tryb = 0;
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
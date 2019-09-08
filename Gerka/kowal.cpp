#include "tabelka.h"
#include "zakres.h"
#include "kowal.h"
#include "level_up.h"

player enter_forge(player gracz,blacksmith kowal)
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
		/* 2*/menu[1] = "PUNKTY ZR CZNOåCI:";
		/* 3*/menu[2] = "PUNKTY INTELIGENCJI:";
		/* 4*/menu[3] = "PUNKTY CHARYZMY:";
		/* 5*/menu[4] = "PUNKTY SZCZ åCIA:";
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
			/* 1*/menu[40] = kowal.menu[0];
			/* 2*/menu[41] = kowal.menu[1];
			/* 3*/menu[42] = kowal.menu[2];
			/* 4*/menu[43] = kowal.menu[3];
			/* 5*/menu[44] = kowal.menu[4];
			/* 6*/menu[45] = kowal.menu[5];
			/* 7*/menu[46] = kowal.menu[6];
			/* 8*/menu[47] = kowal.menu[7];
			/* 9*/menu[48] = kowal.menu[8];
			/*10*/menu[49] = kowal.menu[9];
			/*11*/menu[50] = kowal.menu[10];
			/*12*/menu[51] = kowal.menu[11];
			/*13*/menu[52] = kowal.menu[12];
			/*14*/menu[53] = kowal.menu[13];
			/*15*/menu[54] = kowal.menu[14];
			/*16*/menu[55] = kowal.menu[15];
			/*17*/menu[56] = kowal.menu[16];
			/*18*/menu[57] = kowal.menu[17];
			/*19*/menu[58] = kowal.menu[18];
			/*20*/menu[59] = kowal.menu[19];
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
		}
		else
		{
			/* 1*/menu[40] = "POROZMAWIAJ Z KOWALEM";
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
			info[0] = "KUèNIA";
			info[1] = "W: WR”∆ NA RYNEK";
			info[2] = "M: MIKSTURA ØYCIA";
			info[3] = "";
			info[4] = "";
			info[5] = "";
			info[6] = "";
			info[7] = "";
		}

		/* 1*/menu[60] = "MIKSTURY ØYCIA:";
		/* 2*/menu[61] = "MIKSTURY SI£Y:";
		/* 3*/menu[62] = "MIKSTURY ZR CZNOåCI:";
		/* 4*/menu[63] = "MIKSTURY INTELIGENCJI:";
		/* 5*/menu[64] = "MIKSTURY CHARYZMY:";
		/* 6*/menu[65] = "MIKSTURY SZCZ åCIA:";
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
		tab(gracz,info,menu,ceny);
		cout << "TwÛj wybÛr to: ";
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
				kowal.power_up(gracz,1);
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
				kowal.power_up(gracz, 2);
			}
			break;
		}
		//gloves
		case '3':
		{
			if (tryb == 0)
			{
				;
			}
			else
			{
				kowal.power_up(gracz, 3);
			}
			break;
		}
		//pants
		case '4':
		{
			if (tryb == 0)
			{
				;
			}
			else
			{
				kowal.power_up(gracz, 4);
			}
			break;
		}
		//shoes
		case '5':
		{
			if (tryb == 0)
			{
				;
			}
			else
			{
				kowal.power_up(gracz, 5);
			}
			break;
		}
		//weapon
		case '6':
		{
			if (tryb == 0)
			{
				;
			}
			else
			{
				kowal.power_up(gracz, 6);
			}
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
		default:
		{
			system("cls");
			break;
		}
		}
	}
}

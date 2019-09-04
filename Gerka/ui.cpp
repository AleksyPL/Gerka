#include "biblioteki.h"
#include "ui.h"
#include "tawerna.h"
#include "kowal.h"
#include "burdel.h"
#include "start.h"
#include "alchemik.h"
#include "trader.h"
#include "game_over.h"
#include "cheat_menu.h"
#include "dwellers.h"
#include "save.h"
#include "shamans_house.h"
#include "szpital.h"
#include "inventory.h"


int ui(player gracz,barman bobby, seller handlarz, blacksmith kowal, alchemist alchemik,shaman szaman, doctor lekarz)
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		level_up(gracz);
		if (gracz.hp <= 0)
		{
			game_over();
			return 0;
		}
		system("cls");
		string info[8];
		info[0]= "RYNEK";
		info[1] = "W: WR�� DO MENU";
		info[2] = "Z: ZAPISZ GR�";
		info[3] = "P: PRZEDMIOTY";
		info[4] = "";
		info[5] = "";
		info[6] = "";
		info[7] = "";
		string menu[100];
		long ceny[20];
	
		//glowne staty 23 znaki
		/* 1*/menu[0] = "PUNKTY SI�Y:";
		/* 2*/menu[1] = "PUNKTY ZR�CZNO�CI:"; 
		/* 3*/menu[2] = "PUNKTY INTELIGENCJI:";
		/* 4*/menu[3] = "PUNKTY CHARYZMY:";
		/* 5*/menu[4] = "PUNKTY SZCZʌCIA:";
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

		//Opcje w lokacji 48 znakow
		/* 1*/menu[40] = "ID� DO TAWERNY";
		/* 2*/menu[41] = "ID� DO KU�NI";
		/* 3*/menu[42] = "ID� DO LABORATORIUM ALCHEMIKA";
		/* 4*/menu[43] = "ID� DO BURDELU";
		/* 5*/menu[44] = "ID� DO SKLEPU WIELOBRAN�OWEGO";
		/* 6*/menu[45] = "ID� DO DOMU SZAMANA";
		/* 7*/menu[46] = "ID� DO SZPITALA";
		/* 8*/menu[47] = "ID� DO TABLICY OG�OSZE�";
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

		/* 1*/menu[60] = "MIKSTURY �YCIA:";
		/* 2*/menu[61] = "MIKSTURY SI�Y:";
		/* 3*/menu[62] = "MIKSTURY ZR�CZNO�CI:";
		/* 4*/menu[63] = "MIKSTURY INTELIGENCJI:";
		/* 5*/menu[64] = "MIKSTURY CHARYZMY:";
		/* 6*/menu[65] = "MIKSTURY SZCZʌCIA:";
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

		//Ceny za poszczeg�lne akcje
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
		tab(gracz,info, menu,ceny);
		cout << "Twoj wybor to: ";
		string wybor;
		cin >> wybor;
		
		switch (wybor[0])
		{
		case '1':
		{
			gracz = enter_tavern(gracz,bobby);
			break;
		}
		case '2':
		{
			gracz = enter_forge(gracz,kowal);
			break;
		}
		case '3':
		{
			gracz = enter_laboratory(gracz,alchemik);
			break;
		}
		case '4':
		{
			gracz = enter_brothel(gracz);
			break;
		}
		case '5':
		{
			gracz = enter_shop(gracz,handlarz);
			break;
		}
		case '6':
		{
			gracz = enter_shaman_house(gracz,szaman);
			break;
		}
		case '7':
		{
			gracz = enter_hospital(gracz, lekarz);
			break;
		}
		case 'z':
		{
			save(gracz,bobby,handlarz,kowal,alchemik);
			break;
		}
		case 'Z':
		{
			save(gracz,bobby,handlarz,kowal,alchemik);
			break;
		}
		case 'P':
		{
			gracz = enter_inventory(gracz);
			break;
		}
		case 'p':
		{
			gracz = enter_inventory(gracz);
			break;
		}
		case 'w':
		{
			while (1)
			{
				cout << "Czy napewno chcesz wr�ci� do menu, niezapisany post�p przepadnie?" << endl;
				cout << "1.Tak" << endl;
				cout << "2.Nie" << endl;
				cout << "Tw�j wyb�r to: ";
				string wyb;
				cin >> wyb;
				switch (wyb[0])
				{
				case '1':
				{
					return 0;
				}
				case '2':
				{
					break;
				}
				default:
				{
					break;
				}
				break;
				}
				break;
			}
			break;
		}
		case 'W':
		{
			while (1)
			{
				cout << "Czy napewno chcesz wr�ci� do menu, niezapisany post�p przepadnie?" << endl;
				cout << "1.Tak" << endl;
				cout << "2.Nie" << endl;
				cout << "Tw�j wyb�r to: ";
				string wyb;
				cin >> wyb;
				switch (wyb[0])
				{
				case '1':
				{
					return 0;
				}
				case '2':
				{
					break;
				}
				default:
				{
					break;
				}
				break;
				}
				break;
			}
			break;
		}
		case 't':
		{
			if (wybor == "test")
			{
				gracz = enter_cheat_menu(gracz);
				system("PAUSE");
				break;
			}
		}
		default:
		{
			break;
		}
		}
	}
}
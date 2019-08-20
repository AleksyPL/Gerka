#include "biblioteki.h"
#include "ui.h"
#include "tabelka.h"
#include "zakres.h"
#include "level_up.h"


player enter_cheat_menu(player gracz)
{
	while (1)
	{
		range(gracz);
		level_up(gracz);
		system("cls");
		string menu[80];
		string info[8];
		info[0] = "CHEAT MENU";
		info[1] = "W: WRÓÆ NA RYNEK";
		info[2] = "M: MIKSTURA ¯YCIA";
		info[3] = "";
		info[4] = "";
		info[5] = "";
		info[6] = "";
		info[7] = "";

		//glowne staty 23 znaki
		/* 1*/menu[0] = "IMIÊ POSTACI:";
		/* 2*/menu[1] = "UMIEJÊTNOŒÆ POSTACI:";
		/* 3*/menu[2] = "PUNKTY SI£Y:";
		/* 4*/menu[3] = "PUNKTY ZRÊCZNOŒCI:";
		/* 5*/menu[4] = "PUNKTY INTELIGENCJI:";
		/* 6*/menu[5] = "PUNKTY SZCZÊŒCIA:";
		/* 7*/menu[6] = "SUMA PUNKTÓW ATAKU:";
		/* 8*/menu[7] = "SUMA PUNKTÓW OBRONY:";
		/* 9*/menu[8] = "MIKSTURY ¯YCIA:";
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
		/* 1*/menu[20] = gracz.nazwa;
		/* 2*/menu[21] = gracz.skill;
		/* 3*/menu[22] = to_string(gracz.str);
		/* 4*/menu[23] = to_string(gracz.agility);
		/* 5*/menu[24] = to_string(gracz.intel);
		/* 6*/menu[25] = to_string(gracz.luck);
		/* 7*/menu[26] = to_string(gracz.weapon);
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
		/* 1*/menu[40] = "ZMIEÑ ILOŒÆ PUNKTÓW ¯YCIA";
		/* 2*/menu[41] = "ZMIEÑ ILOŒÆ MAKS. PUNKTÓW ¯YCIA";
		/* 3*/menu[42] = "ZMIEÑ ILOŒÆ PUNKTÓW DOŒWIADCZENIA";
		/* 4*/menu[43] = "ZMIEÑ ILOŒÆ MAKS. PUNKTÓW DOŒWIADCZENIA";
		/* 5*/menu[44] = "ZMIEÑ ILOŒÆ PUNKTÓW NAJEDZENIA";
		/* 6*/menu[45] = "ZMIEÑ ILOŒÆ PUNKTÓW UPOJENIA ALKOHOLOWEGO";
		/* 7*/menu[46] = "ZMIEÑ ILOŒÆ Z£OTA";
		/* 8*/menu[47] = "ZMIEÑ POZIOM POSTACI";
		/* 9*/menu[48] = "ZMIEÑ ILOŒÆ PUNKTÓW SI£Y";
		/*10*/menu[49] = "ZMIEÑ ILOŒÆ PUNKTÓW ZRÊCZNOŒCI";
		/*11*/menu[50] = "ZMIEÑ ILOŒÆ PUNKTÓW INTELIGENCJI";
		/*12*/menu[51] = "ZMIEÑ ILOŒÆ PUNKTÓW CHARYZMY";
		/*13*/menu[52] = "ZMIEÑ ILOŒÆ PUNKTÓW SZCZÊŒCIA";
		/*14*/menu[53] = "ZMIEÑ ILOŒÆ PUNKTÓW ATAKU BRONI";
		/*15*/menu[54] = "ZMIEÑ ILOŒÆ PUNKTÓW HE£MU";
		/*16*/menu[55] = "ZMIEÑ ILOŒÆ PUNKTÓW NAPIERŒNIKA";
		/*17*/menu[56] = "ZMIEÑ ILOŒÆ PUNKTÓW RÊKAWIC";
		/*18*/menu[57] = "ZMIEÑ ILOŒÆ PUNKTÓW SPODNI";
		/*19*/menu[58] = "ZMIEÑ ILOŒÆ PUNKTÓW BUTÓW";
		/*20*/menu[59] = "ZMIEÑ ILOŒÆ MIKSTUR ¯YCIA";

		//Skroty 21 znakow
		/* 1*/menu[60] = "W: WRÓÆ NA RYNEK";
		/* 2*/menu[61] = "";
		/* 3*/menu[62] = "";
		/* 4*/menu[63] = "";
		/* 5*/menu[64] = "";
		/* 6*/menu[65] = "";
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

		range(gracz);
		tab_cheat(gracz, info, menu);
		cout << "Twój wybór to: ";
		string wyb;
		cin >> wyb;
		switch (wyb[0])
		{
		case '1':
		{
			cout << "Podaj now¹ wartoœæ punktów ¿ycia: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0 || numer>gracz.max_hp)
			{
				cout << "Podaj now¹ wartoœæ punktów ¿ycia: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> numer;
			}
			gracz.hp = numer;
			sound_cheat_activated();
			break;
		}
		case '2':
		{
			cout << "Podaj now¹ wartoœæ maks. punktów ¿ycia: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0 || numer<gracz.hp)
			{
				cout << "Podaj now¹ wartoœæ maks. punktów ¿ycia: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> numer;
			}
			gracz.max_hp = numer;
			sound_cheat_activated();
			break;
		}
		case '3':
		{
			cout << "Podaj now¹ wartoœæ punktów doœwiadczenia: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0)
			{
				cout << "Podaj now¹ wartoœæ punktów doœwiadczenia: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> numer;
			}
			gracz.exp = numer;
			sound_cheat_activated();
			break;
		}
		case '4':
		{
			cout << "Podaj now¹ wartoœæ maks. punktów doœwiadczenia: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0)
			{
				cout << "Podaj now¹ wartoœæ maks. punktów doœwiadczenia: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> numer;
			}
			gracz.exp_to_next_level = numer;
			sound_cheat_activated();
			break;
		}
		case '5':
		{
			cout << "Podaj now¹ wartoœæ punktów najedzenia: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0 || numer>10)
			{
				cout << "Podaj now¹ wartoœæ punktów najedzenia: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> numer;
			}
			gracz.hunger = numer;
			sound_cheat_activated();
			break;
		}
		case '6':
		{
			cout << "Podaj now¹ wartoœæ punktów upojenia alkoholowego: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0 || numer>10)
			{
				cout << "Podaj now¹ wartoœæ punktów upojenia alkoholowego: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> numer;
			}
			gracz.alko = numer;
			sound_cheat_activated();
			break;
		}
		case '7':
		{
			cout << "Podaj now¹ iloœæ z³ota: ";
			long long numer;
			cin >> numer;
			while (cin.fail() || numer<0)
			{
				cout << "Podaj now¹ iloœæ z³ota: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> numer;
			}
			gracz.gold = numer;
			sound_cheat_activated();
			break;
		}
		case '8':
		{
			cout << "Podaj now¹ wartoœæ poziomu postaci: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0)
			{
				cout << "Podaj now¹ wartoœæ poziomu postaci: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> numer;
			}
			gracz.level = numer;
			sound_cheat_activated();
			break;
		}
		case 'W':
		{
			sound_stop();
			return gracz;
		}
		case 'w':
		{
			sound_stop();
			return gracz;
		}
		default:
		{
			system("cls");
			break;
		}
		}
	}
}
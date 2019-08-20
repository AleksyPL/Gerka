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
		info[1] = "W: WR�� NA RYNEK";
		info[2] = "M: MIKSTURA �YCIA";
		info[3] = "";
		info[4] = "";
		info[5] = "";
		info[6] = "";
		info[7] = "";

		//glowne staty 23 znaki
		/* 1*/menu[0] = "IMI� POSTACI:";
		/* 2*/menu[1] = "UMIEJ�TNO�� POSTACI:";
		/* 3*/menu[2] = "PUNKTY SI�Y:";
		/* 4*/menu[3] = "PUNKTY ZR�CZNO�CI:";
		/* 5*/menu[4] = "PUNKTY INTELIGENCJI:";
		/* 6*/menu[5] = "PUNKTY SZCZʌCIA:";
		/* 7*/menu[6] = "SUMA PUNKT�W ATAKU:";
		/* 8*/menu[7] = "SUMA PUNKT�W OBRONY:";
		/* 9*/menu[8] = "MIKSTURY �YCIA:";
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
		/* 1*/menu[40] = "ZMIE� ILO�� PUNKT�W �YCIA";
		/* 2*/menu[41] = "ZMIE� ILO�� MAKS. PUNKT�W �YCIA";
		/* 3*/menu[42] = "ZMIE� ILO�� PUNKT�W DO�WIADCZENIA";
		/* 4*/menu[43] = "ZMIE� ILO�� MAKS. PUNKT�W DO�WIADCZENIA";
		/* 5*/menu[44] = "ZMIE� ILO�� PUNKT�W NAJEDZENIA";
		/* 6*/menu[45] = "ZMIE� ILO�� PUNKT�W UPOJENIA ALKOHOLOWEGO";
		/* 7*/menu[46] = "ZMIE� ILO�� Z�OTA";
		/* 8*/menu[47] = "ZMIE� POZIOM POSTACI";
		/* 9*/menu[48] = "ZMIE� ILO�� PUNKT�W SI�Y";
		/*10*/menu[49] = "ZMIE� ILO�� PUNKT�W ZR�CZNO�CI";
		/*11*/menu[50] = "ZMIE� ILO�� PUNKT�W INTELIGENCJI";
		/*12*/menu[51] = "ZMIE� ILO�� PUNKT�W CHARYZMY";
		/*13*/menu[52] = "ZMIE� ILO�� PUNKT�W SZCZʌCIA";
		/*14*/menu[53] = "ZMIE� ILO�� PUNKT�W ATAKU BRONI";
		/*15*/menu[54] = "ZMIE� ILO�� PUNKT�W HE�MU";
		/*16*/menu[55] = "ZMIE� ILO�� PUNKT�W NAPIER�NIKA";
		/*17*/menu[56] = "ZMIE� ILO�� PUNKT�W R�KAWIC";
		/*18*/menu[57] = "ZMIE� ILO�� PUNKT�W SPODNI";
		/*19*/menu[58] = "ZMIE� ILO�� PUNKT�W BUT�W";
		/*20*/menu[59] = "ZMIE� ILO�� MIKSTUR �YCIA";

		//Skroty 21 znakow
		/* 1*/menu[60] = "W: WR�� NA RYNEK";
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
		cout << "Tw�j wyb�r to: ";
		string wyb;
		cin >> wyb;
		switch (wyb[0])
		{
		case '1':
		{
			cout << "Podaj now� warto�� punkt�w �ycia: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0 || numer>gracz.max_hp)
			{
				cout << "Podaj now� warto�� punkt�w �ycia: ";
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
			cout << "Podaj now� warto�� maks. punkt�w �ycia: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0 || numer<gracz.hp)
			{
				cout << "Podaj now� warto�� maks. punkt�w �ycia: ";
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
			cout << "Podaj now� warto�� punkt�w do�wiadczenia: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0)
			{
				cout << "Podaj now� warto�� punkt�w do�wiadczenia: ";
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
			cout << "Podaj now� warto�� maks. punkt�w do�wiadczenia: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0)
			{
				cout << "Podaj now� warto�� maks. punkt�w do�wiadczenia: ";
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
			cout << "Podaj now� warto�� punkt�w najedzenia: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0 || numer>10)
			{
				cout << "Podaj now� warto�� punkt�w najedzenia: ";
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
			cout << "Podaj now� warto�� punkt�w upojenia alkoholowego: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0 || numer>10)
			{
				cout << "Podaj now� warto�� punkt�w upojenia alkoholowego: ";
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
			cout << "Podaj now� ilo�� z�ota: ";
			long long numer;
			cin >> numer;
			while (cin.fail() || numer<0)
			{
				cout << "Podaj now� ilo�� z�ota: ";
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
			cout << "Podaj now� warto�� poziomu postaci: ";
			int numer;
			cin >> numer;
			while (cin.fail() || numer<0)
			{
				cout << "Podaj now� warto�� poziomu postaci: ";
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
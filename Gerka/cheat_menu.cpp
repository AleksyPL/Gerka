#include "tabelka.h"
#include "zakres.h"
#include "level_up.h"
#include "cheat_menu.h"

int load_value(string comment, string type, int active0,string mark,int min, int active1, string mark1, int max)
{
	cout << comment;
	if (type == "int")
	{
		int numer;
		cin >> numer;
		if (active0 == 1 && active1 == 1)
		{
			if (mark == "<" && mark1 == ">")
			{
				while (cin.fail() || numer<min || numer>max)
				{
					cout << comment;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numer;
				}
			}
			else if (mark == ">" && mark1 == "<")
			{
				while (cin.fail() || numer>min || numer<max)
				{
					cout << comment;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numer;
				}
			}
		}
		else if (active0 == 1 && active1 == 0)
		{
			if (mark == "<")
			{
				while (cin.fail() || numer<min)
				{
					cout << comment;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numer;
				}
			}
			else if (mark == ">")
			{
				while (cin.fail() || numer>min)
				{
					cout << comment;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numer;
				}
			}
		}
		return numer;
	}
	else if (type == "long")
	{
		long numer;
		cin >> numer;
		if (active0 == 1 && active1 == 1)
		{
			if (mark == "<" && mark1 == ">")
			{
				while (cin.fail() || numer<min || numer>max)
				{
					cout << comment;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numer;
				}
			}
			else if (mark == ">" && mark1 == "<")
			{
				while (cin.fail() || numer>min || numer<max)
				{
					cout << comment;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numer;
				}
			}
		}
		else if (active0 == 1 && active1 == 0)
		{
			if (mark == "<")
			{
				while (cin.fail() || numer<min)
				{
					cout << comment;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numer;
				}
			}
			else if (mark == ">")
			{
				while (cin.fail() || numer>min)
				{
					cout << comment;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numer;
				}
			}
		}
		return numer;
	}
	else if (type == "long long")
	{
		long long numer;
		cin >> numer;
		if (active0 == 1 && active1 == 1)
		{
			if (mark == "<" && mark1 == ">")
			{
				while (cin.fail() || numer<min || numer>max)
				{
					cout << comment;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numer;
				}
			}
			else if (mark == ">" && mark1 == "<")
			{
				while (cin.fail() || numer>min || numer<max)
				{
					cout << comment;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numer;
				}
			}
		}
		else if (active0 == 1 && active1 == 0)
		{
			if (mark == "<")
			{
				while (cin.fail() || numer<min)
				{
					cout << comment;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numer;
				}
			}
			else if (mark == ">")
			{
				while (cin.fail() || numer>min)
				{
					cout << comment;
					cin.clear();
					cin.ignore(256, '\n');
					cin >> numer;
				}
			}
		}
		return numer;
	}
}
player enter_cheat_menu(player &gracz)
{
	while (1)
	{
		if (gracz.hp <= 0)
		{
			return gracz;
		}
		range(gracz);
		level_up(gracz);
		system("cls");
		string menu[80];
		string info[8];
		info[0] = "CHEAT MENU";
		info[1] = "W: WRÓÆ NA RYNEK";
		info[2] = "";
		info[3] = "";
		info[4] = "";
		info[5] = "";
		info[6] = "";
		info[7] = "";

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

		//Opcje w lokacji 48 znakow
		/* 1*/menu[40] = "ZMIEÑ ILOŒÆ PUNKTÓW ¯YCIA";
		/* 2*/menu[41] = "ZMIEÑ ILOŒÆ MAKSYMALNYCH PUNKTÓW ¯YCIA";
		/* 3*/menu[42] = "ZMIEÑ ILOŒÆ PUNKTÓW DOŒWIADCZENIA";
		/* 4*/menu[43] = "ZMIEÑ ILOŒÆ MAKSYMALNYCH PUNKTÓW DOŒWIADCZENIA";
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
		/*20*/menu[59] = "ZMIEÑ GODZINÊ";
		/* 1*/menu[60] = "";
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
		wyb = string_tolower(wyb);
		switch (wyb[0])
		{
		case '1':
		{
			if (wyb.length() == 1)
			{
				gracz.hp = load_value("Podaj now¹ wartoœæ punktów ¿ycia: ", "int", 1, "<", 0, 1, ">", gracz.max_hp);
				sound_cheat_activated();
			}
			else if(wyb[1]=='0')
			{
				gracz.agility = load_value("Podaj now¹ wartoœæ punktów zrêcznoœci: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			else if (wyb[1] == '1')
			{
				gracz.intel = load_value("Podaj now¹ wartoœæ punktów inteligencji: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			else if (wyb[1] == '2')
			{
				gracz.charisma = load_value("Podaj now¹ wartoœæ punktów charyzmy: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			else if (wyb[1] == '3')
			{
				gracz.luck = load_value("Podaj now¹ wartoœæ punktów szczêœcia: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			else if (wyb[1] == '4')
			{
				gracz.weapon = load_value("Podaj now¹ wartoœæ punktów ataku broni: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			else if (wyb[1] == '5')
			{
				gracz.helmet = load_value("Podaj now¹ wartoœæ punktów he³mu: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			else if (wyb[1] == '6')
			{
				gracz.chestplate = load_value("Podaj now¹ wartoœæ punktów napierœnika: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			else if (wyb[1] == '7')
			{
				gracz.gloves = load_value("Podaj now¹ wartoœæ punktów rêkawic: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			else if (wyb[1] == '8')
			{
				gracz.pants = load_value("Podaj now¹ wartoœæ punktów spodni: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			else if (wyb[1] == '9')
			{
				gracz.shoes = load_value("Podaj now¹ wartoœæ punktów butów: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			break;
		}
		case '2':
		{
			if (wyb.length() == 1)
			{
				gracz.max_hp = load_value("Podaj now¹ wartoœæ maks. punktów ¿ycia: ", "int", 1, "<", 0, 1, ">", gracz.hp);
				sound_cheat_activated();
			}
			else if (wyb[1] == '0')
			{
				gracz.hour = load_value("Podaj która godznina: ", "int", 1, "<", 0, 1, ">", 23);
				gracz.minute = load_value("Podaj która minuta: ", "int", 1, "<", 0, 1, ">", 59);
				sound_cheat_activated();
			}
			else if (wyb[1] == '1')
			{

			}
			else if (wyb[1] == '2')
			{

			}
			else if (wyb[1] == '3')
			{

			}
			else if (wyb[1] == '4')
			{

			}
			else if (wyb[1] == '5')
			{

			}
			else if (wyb[1] == '6')
			{

			}
			else if (wyb[1] == '7')
			{

			}
			else if (wyb[1] == '8')
			{

			}
			else if (wyb[1] == '9')
			{

			}
			break;
		}
		case '3':
		{
			if (wyb.length() == 1)
			{
				gracz.exp = load_value("Podaj now¹ wartoœæ punktów doœwiadczenia: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			else if (wyb[1] == '0')
			{

			}
			else if (wyb[1] == '1')
			{

			}
			else if (wyb[1] == '2')
			{

			}
			else if (wyb[1] == '3')
			{

			}
			else if (wyb[1] == '4')
			{

			}
			else if (wyb[1] == '5')
			{

			}
			else if (wyb[1] == '6')
			{

			}
			else if (wyb[1] == '7')
			{

			}
			else if (wyb[1] == '8')
			{

			}
			else if (wyb[1] == '9')
			{

			}
			break;
		}
		case '4':
		{
			if (wyb.length() == 1)
			{
				gracz.exp_to_next_level = load_value("Podaj now¹ wartoœæ maks. punktów doœwiadczenia: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			else if (wyb[1] == '0')
			{

			}
			else if (wyb[1] == '1')
			{

			}
			else if (wyb[1] == '2')
			{

			}
			else if (wyb[1] == '3')
			{

			}
			else if (wyb[1] == '4')
			{

			}
			else if (wyb[1] == '5')
			{

			}
			else if (wyb[1] == '6')
			{

			}
			else if (wyb[1] == '7')
			{

			}
			else if (wyb[1] == '8')
			{

			}
			else if (wyb[1] == '9')
			{

			}
			break;
		}
		case '5':
		{
			if (wyb.length() == 1)
			{
				gracz.hunger = load_value("Podaj now¹ wartoœæ punktów najedzenia: ", "int", 1, "<", 0, 1, ">", 10);
				sound_cheat_activated();
				break;
			}
		}
		case '6':
		{
			if (wyb.length() == 1)
			{
				gracz.alko = load_value("Podaj now¹ wartoœæ punktów upojenia alkoholowego: ", "int", 1, "<", 0, 1, ">", 10);
				sound_cheat_activated();
				break;
			}
		}
		case '7':
		{
			if (wyb.length() == 1)
			{
				gracz.gold = load_value("Podaj now¹ iloœæ z³ota: ", "long long", 1, "<", 0);
				sound_cheat_activated();
			}
			break;
		}
		case '8':
		{
			if (wyb.length() == 1)
			{
				gracz.level = load_value("Podaj now¹ wartoœæ poziomu postaci: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			break;
		}
		case '9':
		{
			if (wyb.length() == 1)
			{
				gracz.str = load_value("Podaj now¹ wartoœæ punktów si³y: ", "int", 1, "<", 0);
				sound_cheat_activated();
			}
			break;
		}
		case 'w':
		{
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
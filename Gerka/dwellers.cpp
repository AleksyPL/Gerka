#include "biblioteki.h"
#include "koniec_tury.h"
#include "jedzenie.h"
#include "boost-syf.h"
#include "level_up.h"
#include "dwellers.h"


dweller::dweller()
{
	rep_level = 1;
	rep_points = 0;
	rep_points_to_next_level = 500;
	gold = 5000;
}
barman::barman()
	{
		info[0] = "TAWERNA - ROZMOWA Z BARMANEM";
		info[1] = "W: ZAKO—CZ ROZMOW ";
		info[2] = "M: MIKSTURA ØYCIA";
		info[3] = "";
		info[4] = "";
		info[5] = "";
		info[6] = "";
		info[7] = "";
		menu[0] = "S£UCHAJ PLOTEK";
		menu[1] = "ZAPYTAJ O NOCLEG";
		menu[2] = "KUP POSI£EK";
		menu[3] = "KUP PIWO";
		menu[4] = "";
		menu[5] = "";
		menu[6] = "";
		menu[7] = "";
		menu[8] = "";
		menu[9] = "";
		menu[10] = "";
		menu[11] = "";
		menu[12] = "";
		menu[13] = "";
		menu[14] = "";
		menu[15] = "";
		menu[16] = "";
		menu[17] = "";
		menu[18] = "";
		menu[19] = "";
		ceny[0] = 0;
		ceny[1] = 10;
		ceny[2] = 5;
		ceny[3] = 5;
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
	}
int barman::gold_info()
	{
		return gold;
	}	
int barman::rep_level_info()
	{
		return rep_level;
	}
int barman::rep_points_info()
	{
		return rep_points;
	}
int barman::rep_points_to_next_level_info()
	{
		return rep_points_to_next_level;
	}
void barman::gold_set(int a)
	{
		gold = a;
	}
void barman::rep_level_set(int a)
	{
		rep_level = a;
	}
void barman::rep_points_set(int a)
	{
		rep_points = a;
	}	
void barman::rep_points_to_next_level_set(int a)
	{
		rep_points_to_next_level = a;
	}
void barman::gossip()
	{
		srand((unsigned int)time(NULL));
		int ran = rand() % 10;
		string linia;
		int nr_linii = 1;
		fstream plik;
		if (ran == 0)
		{
			plik.open("./txt/tawerna/plota0.txt", ios::in);
		}
		else if (ran == 1)
		{
			plik.open("./txt/tawerna/plota1.txt", ios::in);
		}
		else if (ran == 2)
		{
			plik.open("./txt/tawerna/plota2.txt", ios::in);
		}
		else if (ran == 3)
		{
			plik.open("./txt/tawerna/plota3.txt", ios::in);
		}
		else if (ran == 4)
		{
			plik.open("./txt/tawerna/plota4.txt", ios::in);
		}
		else if (ran == 5)
		{
			plik.open("./txt/tawerna/plota5.txt", ios::in);
		}
		else if (ran == 6)
		{
			plik.open("./txt/tawerna/plota6.txt", ios::in);
		}
		else if (ran == 7)
		{
			plik.open("./txt/tawerna/plota7.txt", ios::in);
		}
		else if (ran == 8)
		{
			plik.open("./txt/tawerna/plota8.txt", ios::in);
		}
		else if (ran == 9)
		{
			plik.open("./txt/tawerna/plota9.txt", ios::in);
		}
		while (!plik.eof())
		{
			getline(plik, linia);
			cout << linia << endl;
		}
		plik.close();
		system("PAUSE");
		system("cls");
	}
void barman::sleep(player &gracz)
	{
		if (gracz.gold < ceny[1])
		{
			no_money();
		}
		else
		{
			cout << "Karczmarz ma wolny pokoj" << endl;
			cout << "Pokoj jest twoj" << endl;
			if (gracz.hp < gracz.max_hp)
			{
				cout << "Regenerujesz swoje si≥y" << endl;
				gracz.hp = gracz.hp + (0.05*gracz.hp);
			}
			gracz.gold = gracz.gold - ceny[1];
			if (gracz.hp > gracz.max_hp)
			{
				gracz.hp = gracz.max_hp;
			}
			end_of_turn(gracz);
		}
		system("PAUSE");
	}
void barman::sell_food(player &gracz, int ilosc)
	{
		eat_food(gracz, ceny[2], 2);
	}
void barman::sell_beer(player &gracz)
	{
		if (gracz.alko == 10)
		{
			cout << "TOBIE JUØ WYSTARCZY!!!" << endl;
			system("PAUSE");
		}
		else if (gracz.gold >= ceny[3])
		{
			sound_beer();
			gracz.gold = gracz.gold - ceny[3];
			gracz.alko = gracz.alko + 1;
			if (gracz.alko == 2 || gracz.alko == 4 || gracz.alko == 6 || gracz.alko == 8 || gracz.alko == 10)
			{
				gracz.hunger = gracz.hunger - 1;
			}
			string linia;
			int nr_linii = 1;
			fstream plik;
			plik.open("./txt/tawerna/beer.txt", ios::in);
			while (!plik.eof())
			{
				getline(plik, linia);
				cout << linia << endl;
			}
			plik.close();
			cout << "PIJESZ PYSZNE, ZIMNE PIWKO" << endl;
			system("PAUSE");
		}
		else
		{
			no_money();
			system("PAUSE");
		}
	}
seller::seller()
{
	info[0] = "SKLEP WIELOBRANØOWY - ROZMOWA Z HANDLARZEM";
	info[1] = "W: ZAKO—CZ ROZMOW ";
	info[2] = "M: MIKSTURA ØYCIA";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	info[7] = "";
	menu[0] = "ZACZNIJ HANDEL";
	menu[1] = "";
	menu[2] = "";
	menu[3] = "";
	menu[4] = "";
	menu[5] = "";
	menu[6] = "";
	menu[7] = "";
	menu[8] = "";
	menu[9] = "";
	menu[10] = "";
	menu[11] = "";
	menu[12] = "";
	menu[13] = "";
	menu[14] = "";
	menu[15] = "";
	menu[16] = "";
	menu[17] = "";
	menu[18] = "";
	menu[19] = "";
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
	for (int i = 0; i < 80; i++)
	{
		menu_items[i] = "";
		menu_price[i] = 0;
	}
}
int seller::gold_info()
{
	return gold;
}
int seller::rep_level_info()
{
	return rep_level;
}
int seller::rep_points_info()
{
	return rep_points;
}
int seller::rep_points_to_next_level_info()
{
	return rep_points_to_next_level;
}
void seller::gold_set(int a)
{
	gold = a;
}
void seller::rep_level_set(int a)
{
	rep_level = a;
}
void seller::rep_points_set(int a)
{
	rep_points = a;
}
void seller::rep_points_to_next_level_set(int a)
{
	rep_points_to_next_level = a;
}
void seller::load_merch()
{
		string linia;
		fstream plik;
		int nr_linii = 1;
		plik.open("./txt/trader/items_trash.txt", ios::in);
		while (getline(plik, linia))
		{
			switch (nr_linii)
			{
			case 1:
			{
				menu_items[0] = linia;
				break;
			}
			case 2:
			{
				menu_price[0] = atoi(linia.c_str());
				break;
			}
			case 3:
			{
				menu_items[1] = linia;
				break;
			}
			case 4:
			{
				menu_price[1] = atoi(linia.c_str());
				break;
			}
			case 5:
			{
				menu_items[2] = linia;
				break;
			}
			case 6:
			{
				menu_price[2] = atoi(linia.c_str());
				break;
			}
			case 7:
			{
				menu_items[3] = linia;
				break;
			}
			case 8:
			{
				menu_price[3] = atoi(linia.c_str());
				break;
			}
			case 9:
			{
				menu_items[4] = linia;
				break;
			}
			case 10:
			{
				menu_price[4] = atoi(linia.c_str());
				break;
			}
			case 11:
			{
				menu_items[5] = linia;
				break;
			}
			case 12:
			{
				menu_price[5] = atoi(linia.c_str());
				break;
			}
			case 13:
			{
				menu_items[6] = linia;
				break;
			}
			case 14:
			{
				menu_price[6] = atoi(linia.c_str());
				break;
			}
			case 15:
			{
				menu_items[7] = linia;
				break;
			}
			case 16:
			{
				menu_price[7] = atoi(linia.c_str());
				break;
			}
			case 17:
			{
				menu_items[8] = linia;
				break;
			}
			case 18:
			{
				menu_price[8] = atoi(linia.c_str());
				break;
			}
			case 19:
			{
				menu_items[9] = linia;
				break;
			}
			case 20:
			{
				menu_price[9] = atoi(linia.c_str());
				break;
			}
			case 21:
			{
				menu_items[10] = linia;
				break;
			}
			case 22:
			{
				menu_price[10] = atoi(linia.c_str());
				break;
			}
			case 23:
			{
				menu_items[11] = linia;
				break;
			}
			case 24:
			{
				menu_price[11] = atoi(linia.c_str());
				break;
			}
			case 25:
			{
				menu_items[12] = linia;
				break;
			}
			case 26:
			{
				menu_price[12] = atoi(linia.c_str());
				break;
			}
			case 27:
			{
				menu_items[13] = linia;
				break;
			}
			case 28:
			{
				menu_price[13] = atoi(linia.c_str());
				break;
			}
			case 29:
			{
				menu_items[14] = linia;
				break;
			}
			case 30:
			{
				menu_price[14] = atoi(linia.c_str());
				break;
			}
			case 31:
			{
				menu_items[15] = linia;
				break;
			}
			case 32:
			{
				menu_price[15] = atoi(linia.c_str());
				break;
			}
			case 33:
			{
				menu_items[16] = linia;
				break;
			}
			case 34:
			{
				menu_price[16] = atoi(linia.c_str());
				break;
			}
			case 35:
			{
				menu_items[17] = linia;
				break;
			}
			case 36:
			{
				menu_price[17] = atoi(linia.c_str());
				break;
			}
			case 37:
			{
				menu_items[18] = linia;
				break;
			}
			case 38:
			{
				menu_price[18] = atoi(linia.c_str());
				break;

			}
			case 39:
			{
				menu_items[19] = linia;
				break;
			}
			case 40:
			{
				menu_price[19] = atoi(linia.c_str());
				break;
			}
			}
			nr_linii++;
		}
		plik.close();
		nr_linii = 1;
		plik.open("./txt/trader/items_low.txt", ios::in);
		while (getline(plik, linia))
		{
			switch (nr_linii)
			{
			case 1:
			{
				menu_items[20] = linia;
				break;
			}
			case 2:
			{
				menu_price[20] = atoi(linia.c_str());
				break;
			}
			case 3:
			{
				menu_items[21] = linia;
				break;
			}
			case 4:
			{
				menu_price[21] = atoi(linia.c_str());
				break;
			}
			case 5:
			{
				menu_items[22] = linia;
				break;
			}
			case 6:
			{
				menu_price[22] = atoi(linia.c_str());
				break;
			}
			case 7:
			{
				menu_items[23] = linia;
				break;
			}
			case 8:
			{
				menu_price[23] = atoi(linia.c_str());
				break;
			}
			case 9:
			{
				menu_items[24] = linia;
				break;
			}
			case 10:
			{
				menu_price[24] = atoi(linia.c_str());
				break;
			}
			case 11:
			{
				menu_items[25] = linia;
				break;
			}
			case 12:
			{
				menu_price[25] = atoi(linia.c_str());
				break;
			}
			case 13:
			{
				menu_items[26] = linia;
				break;
			}
			case 14:
			{
				menu_price[26] = atoi(linia.c_str());
				break;
			}
			case 15:
			{
				menu_items[27] = linia;
				break;
			}
			case 16:
			{
				menu_price[27] = atoi(linia.c_str());
				break;
			}
			case 17:
			{
				menu_items[28] = linia;
				break;
			}
			case 18:
			{
				menu_price[28] = atoi(linia.c_str());
				break;
			}
			case 19:
			{
				menu_items[29] = linia;
				break;
			}
			case 20:
			{
				menu_price[29] = atoi(linia.c_str());
				break;
			}
			case 21:
			{
				menu_items[30] = linia;
				break;
			}
			case 22:
			{
				menu_price[30] = atoi(linia.c_str());
				break;
			}
			case 23:
			{
				menu_items[31] = linia;
				break;
			}
			case 24:
			{
				menu_price[31] = atoi(linia.c_str());
				break;
			}
			case 25:
			{
				menu_items[32] = linia;
				break;
			}
			case 26:
			{
				menu_price[32] = atoi(linia.c_str());
				break;
			}
			case 27:
			{
				menu_items[33] = linia;
				break;
			}
			case 28:
			{
				menu_price[33] = atoi(linia.c_str());
				break;
			}
			case 29:
			{
				menu_items[34] = linia;
				break;
			}
			case 30:
			{
				menu_price[34] = atoi(linia.c_str());
				break;
			}
			case 31:
			{
				menu_items[35] = linia;
				break;
			}
			case 32:
			{
				menu_price[35] = atoi(linia.c_str());
				break;
			}
			case 33:
			{
				menu_items[36] = linia;
				break;
			}
			case 34:
			{
				menu_price[36] = atoi(linia.c_str());
				break;
			}
			case 35:
			{
				menu_items[37] = linia;
				break;
			}
			case 36:
			{
				menu_price[37] = atoi(linia.c_str());
				break;
			}
			case 37:
			{
				menu_items[38] = linia;
				break;
			}
			case 38:
			{
				menu_price[38] = atoi(linia.c_str());
				break;

			}
			case 39:
			{
				menu_items[39] = linia;
				break;
			}
			case 40:
			{
				menu_price[39] = atoi(linia.c_str());
				break;
			}
			}
			nr_linii++;
		}
		plik.close();
		nr_linii = 1;
		plik.open("./txt/trader/items_mid.txt", ios::in);
		while (getline(plik, linia))
		{
			switch (nr_linii)
			{
			case 1:
			{
				menu_items[40] = linia;
				break;
			}
			case 2:
			{
				menu_price[40] = atoi(linia.c_str());
				break;
			}
			case 3:
			{
				menu_items[41] = linia;
				break;
			}
			case 4:
			{
				menu_price[41] = atoi(linia.c_str());
				break;
			}
			case 5:
			{
				menu_items[42] = linia;
				break;
			}
			case 6:
			{
				menu_price[42] = atoi(linia.c_str());
				break;
			}
			case 7:
			{
				menu_items[43] = linia;
				break;
			}
			case 8:
			{
				menu_price[43] = atoi(linia.c_str());
				break;
			}
			case 9:
			{
				menu_items[44] = linia;
				break;
			}
			case 10:
			{
				menu_price[44] = atoi(linia.c_str());
				break;
			}
			case 11:
			{
				menu_items[45] = linia;
				break;
			}
			case 12:
			{
				menu_price[45] = atoi(linia.c_str());
				break;
			}
			case 13:
			{
				menu_items[46] = linia;
				break;
			}
			case 14:
			{
				menu_price[46] = atoi(linia.c_str());
				break;
			}
			case 15:
			{
				menu_items[47] = linia;
				break;
			}
			case 16:
			{
				menu_price[47] = atoi(linia.c_str());
				break;
			}
			case 17:
			{
				menu_items[48] = linia;
				break;
			}
			case 18:
			{
				menu_price[48] = atoi(linia.c_str());
				break;
			}
			case 19:
			{
				menu_items[49] = linia;
				break;
			}
			case 20:
			{
				menu_price[49] = atoi(linia.c_str());
				break;
			}
			case 21:
			{
				menu_items[50] = linia;
				break;
			}
			case 22:
			{
				menu_price[50] = atoi(linia.c_str());
				break;
			}
			case 23:
			{
				menu_items[51] = linia;
				break;
			}
			case 24:
			{
				menu_price[51] = atoi(linia.c_str());
				break;
			}
			case 25:
			{
				menu_items[52] = linia;
				break;
			}
			case 26:
			{
				menu_price[52] = atoi(linia.c_str());
				break;
			}
			case 27:
			{
				menu_items[53] = linia;
				break;
			}
			case 28:
			{
				menu_price[53] = atoi(linia.c_str());
				break;
			}
			case 29:
			{
				menu_items[54] = linia;
				break;
			}
			case 30:
			{
				menu_price[54] = atoi(linia.c_str());
				break;
			}
			case 31:
			{
				menu_items[55] = linia;
				break;
			}
			case 32:
			{
				menu_price[55] = atoi(linia.c_str());
				break;
			}
			case 33:
			{
				menu_items[56] = linia;
				break;
			}
			case 34:
			{
				menu_price[56] = atoi(linia.c_str());
				break;
			}
			case 35:
			{
				menu_items[57] = linia;
				break;
			}
			case 36:
			{
				menu_price[57] = atoi(linia.c_str());
				break;
			}
			case 37:
			{
				menu_items[58] = linia;
				break;
			}
			case 38:
			{
				menu_price[58] = atoi(linia.c_str());
				break;

			}
			case 39:
			{
				menu_items[59] = linia;
				break;
			}
			case 40:
			{
				menu_price[59] = atoi(linia.c_str());
				break;
			}
			}
			nr_linii++;
		}
		plik.close();
		nr_linii = 1;
		plik.open("./txt/trader/items_high.txt", ios::in);
		while (getline(plik, linia))
		{
			switch (nr_linii)
			{
			case 1:
			{
				menu_items[60] = linia;
				break;
			}
			case 2:
			{
				menu_price[60] = atoi(linia.c_str());
				break;
			}
			case 3:
			{
				menu_items[61] = linia;
				break;
			}
			case 4:
			{
				menu_price[61] = atoi(linia.c_str());
				break;
			}
			case 5:
			{
				menu_items[62] = linia;
				break;
			}
			case 6:
			{
				menu_price[62] = atoi(linia.c_str());
				break;
			}
			case 7:
			{
				menu_items[63] = linia;
				break;
			}
			case 8:
			{
				menu_price[63] = atoi(linia.c_str());
				break;
			}
			case 9:
			{
				menu_items[64] = linia;
				break;
			}
			case 10:
			{
				menu_price[64] = atoi(linia.c_str());
				break;
			}
			case 11:
			{
				menu_items[65] = linia;
				break;
			}
			case 12:
			{
				menu_price[65] = atoi(linia.c_str());
				break;
			}
			case 13:
			{
				menu_items[66] = linia;
				break;
			}
			case 14:
			{
				menu_price[66] = atoi(linia.c_str());
				break;
			}
			case 15:
			{
				menu_items[67] = linia;
				break;
			}
			case 16:
			{
				menu_price[67] = atoi(linia.c_str());
				break;
			}
			case 17:
			{
				menu_items[68] = linia;
				break;
			}
			case 18:
			{
				menu_price[68] = atoi(linia.c_str());
				break;
			}
			case 19:
			{
				menu_items[69] = linia;
				break;
			}
			case 20:
			{
				menu_price[69] = atoi(linia.c_str());
				break;
			}
			case 21:
			{
				menu_items[70] = linia;
				break;
			}
			case 22:
			{
				menu_price[70] = atoi(linia.c_str());
				break;
			}
			case 23:
			{
				menu_items[71] = linia;
				break;
			}
			case 24:
			{
				menu_price[71] = atoi(linia.c_str());
				break;
			}
			case 25:
			{
				menu_items[72] = linia;
				break;
			}
			case 26:
			{
				menu_price[72] = atoi(linia.c_str());
				break;
			}
			case 27:
			{
				menu_items[73] = linia;
				break;
			}
			case 28:
			{
				menu_price[73] = atoi(linia.c_str());
				break;
			}
			case 29:
			{
				menu_items[74] = linia;
				break;
			}
			case 30:
			{
				menu_price[74] = atoi(linia.c_str());
				break;
			}
			case 31:
			{
				menu_items[75] = linia;
				break;
			}
			case 32:
			{
				menu_price[75] = atoi(linia.c_str());
				break;
			}
			case 33:
			{
				menu_items[76] = linia;
				break;
			}
			case 34:
			{
				menu_price[76] = atoi(linia.c_str());
				break;
			}
			case 35:
			{
				menu_items[77] = linia;
				break;
			}
			case 36:
			{
				menu_price[77] = atoi(linia.c_str());
				break;
			}
			case 37:
			{
				menu_items[78] = linia;
				break;
			}
			case 38:
			{
				menu_price[78] = atoi(linia.c_str());
				break;

			}
			case 39:
			{
				menu_items[79] = linia;
				break;
			}
			case 40:
			{
				menu_price[79] = atoi(linia.c_str());
				break;
			}
			}
			nr_linii++;
		}
		plik.close();
		nr_linii = 1;
		plik.open("./txt/alchemik/items_crafting_alchemy.txt", ios::in);
		while (getline(plik, linia))
		{
			switch (nr_linii)
			{
			case 1:
			{
				menu_items[80] = linia;
				break;
			}
			case 2:
			{
				menu_price[80] = atoi(linia.c_str());
				break;
			}
			case 3:
			{
				menu_items[81] = linia;
				break;
			}
			case 4:
			{
				menu_price[81] = atoi(linia.c_str());
				break;
			}
			case 5:
			{
				menu_items[82] = linia;
				break;
			}
			case 6:
			{
				menu_price[82] = atoi(linia.c_str());
				break;
			}
			case 7:
			{
				menu_items[83] = linia;
				break;
			}
			case 8:
			{
				menu_price[83] = atoi(linia.c_str());
				break;
			}
			case 9:
			{
				menu_items[84] = linia;
				break;
			}
			case 10:
			{
				menu_price[84] = atoi(linia.c_str());
				break;
			}
			case 11:
			{
				menu_items[85] = linia;
				break;
			}
			case 12:
			{
				menu_price[85] = atoi(linia.c_str());
				break;
			}
			case 13:
			{
				menu_items[86] = linia;
				break;
			}
			case 14:
			{
				menu_price[86] = atoi(linia.c_str());
				break;
			}
			case 15:
			{
				menu_items[87] = linia;
				break;
			}
			case 16:
			{
				menu_price[87] = atoi(linia.c_str());
				break;
			}
			case 17:
			{
				menu_items[88] = linia;
				break;
			}
			case 18:
			{
				menu_price[88] = atoi(linia.c_str());
				break;
			}
			case 19:
			{
				menu_items[89] = linia;
				break;
			}
			case 20:
			{
				menu_price[89] = atoi(linia.c_str());
				break;
			}
			case 21:
			{
				menu_items[90] = linia;
				break;
			}
			case 22:
			{
				menu_price[90] = atoi(linia.c_str());
				break;
			}
			case 23:
			{
				menu_items[91] = linia;
				break;
			}
			case 24:
			{
				menu_price[91] = atoi(linia.c_str());
				break;
			}
			case 25:
			{
				menu_items[92] = linia;
				break;
			}
			case 26:
			{
				menu_price[92] = atoi(linia.c_str());
				break;
			}
			case 27:
			{
				menu_items[93] = linia;
				break;
			}
			case 28:
			{
				menu_price[93] = atoi(linia.c_str());
				break;
			}
			case 29:
			{
				menu_items[94] = linia;
				break;
			}
			case 30:
			{
				menu_price[94] = atoi(linia.c_str());
				break;
			}
			case 31:
			{
				menu_items[95] = linia;
				break;
			}
			case 32:
			{
				menu_price[95] = atoi(linia.c_str());
				break;
			}
			case 33:
			{
				menu_items[96] = linia;
				break;
			}
			case 34:
			{
				menu_price[96] = atoi(linia.c_str());
				break;
			}
			case 35:
			{
				menu_items[97] = linia;
				break;
			}
			case 36:
			{
				menu_price[97] = atoi(linia.c_str());
				break;
			}
			case 37:
			{
				menu_items[98] = linia;
				break;
			}
			case 38:
			{
				menu_price[98] = atoi(linia.c_str());
				break;

			}
			case 39:
			{
				menu_items[99] = linia;
				break;
			}
			case 40:
			{
				menu_price[99] = atoi(linia.c_str());
				break;
			}
			}
			nr_linii++;
		}
		plik.close();
		nr_linii = 1;
		plik.open("./txt/kowal/items_crafting_forge.txt", ios::in);
		while (getline(plik, linia))
		{
			switch (nr_linii)
			{
			case 1:
			{
				menu_items[100] = linia;
				break;
			}
			case 2:
			{
				menu_price[100] = atoi(linia.c_str());
				break;
			}
			case 3:
			{
				menu_items[101] = linia;
				break;
			}
			case 4:
			{
				menu_price[101] = atoi(linia.c_str());
				break;
			}
			case 5:
			{
				menu_items[102] = linia;
				break;
			}
			case 6:
			{
				menu_price[102] = atoi(linia.c_str());
				break;
			}
			case 7:
			{
				menu_items[103] = linia;
				break;
			}
			case 8:
			{
				menu_price[103] = atoi(linia.c_str());
				break;
			}
			case 9:
			{
				menu_items[104] = linia;
				break;
			}
			case 10:
			{
				menu_price[104] = atoi(linia.c_str());
				break;
			}
			case 11:
			{
				menu_items[105] = linia;
				break;
			}
			case 12:
			{
				menu_price[105] = atoi(linia.c_str());
				break;
			}
			case 13:
			{
				menu_items[106] = linia;
				break;
			}
			case 14:
			{
				menu_price[106] = atoi(linia.c_str());
				break;
			}
			case 15:
			{
				menu_items[107] = linia;
				break;
			}
			case 16:
			{
				menu_price[107] = atoi(linia.c_str());
				break;
			}
			case 17:
			{
				menu_items[108] = linia;
				break;
			}
			case 18:
			{
				menu_price[108] = atoi(linia.c_str());
				break;
			}
			case 19:
			{
				menu_items[109] = linia;
				break;
			}
			case 20:
			{
				menu_price[109] = atoi(linia.c_str());
				break;
			}
			case 21:
			{
				menu_items[110] = linia;
				break;
			}
			case 22:
			{
				menu_price[110] = atoi(linia.c_str());
				break;
			}
			case 23:
			{
				menu_items[111] = linia;
				break;
			}
			case 24:
			{
				menu_price[111] = atoi(linia.c_str());
				break;
			}
			case 25:
			{
				menu_items[112] = linia;
				break;
			}
			case 26:
			{
				menu_price[112] = atoi(linia.c_str());
				break;
			}
			case 27:
			{
				menu_items[113] = linia;
				break;
			}
			case 28:
			{
				menu_price[113] = atoi(linia.c_str());
				break;
			}
			case 29:
			{
				menu_items[114] = linia;
				break;
			}
			case 30:
			{
				menu_price[114] = atoi(linia.c_str());
				break;
			}
			case 31:
			{
				menu_items[115] = linia;
				break;
			}
			case 32:
			{
				menu_price[115] = atoi(linia.c_str());
				break;
			}
			case 33:
			{
				menu_items[116] = linia;
				break;
			}
			case 34:
			{
				menu_price[116] = atoi(linia.c_str());
				break;
			}
			case 35:
			{
				menu_items[117] = linia;
				break;
			}
			case 36:
			{
				menu_price[117] = atoi(linia.c_str());
				break;
			}
			case 37:
			{
				menu_items[118] = linia;
				break;
			}
			case 38:
			{
				menu_price[118] = atoi(linia.c_str());
				break;

			}
			case 39:
			{
				menu_items[119] = linia;
				break;
			}
			case 40:
			{
				menu_price[119] = atoi(linia.c_str());
				break;
			}
			}
			nr_linii++;
		}
		plik.close();
}
void seller::add_prices(player &gracz)
	{
		for (int i = 0; i < 20; i++)
		{
			if (gracz.inventory_usage[i] == "")
			{
				continue;
			}
			else
			{
				for (int j = 0; j < 120; j++)
				{
					if (gracz.inventory_usage[i] == menu_items[j])
					{
						gracz.inventory_usage_price[i] = menu_price[j];
					}
				}
			}
		}
		for (int i = 0; i < 20; i++)
		{
			if (gracz.inventory_crafting[i] == "")
			{
				continue;
			}
			else
			{
				for (int j = 0; j < 120; j++)
				{
					if (gracz.inventory_crafting[i] == menu_items[j])
					{
						gracz.inventory_crafting_price[i] = menu_price[j];
					}
				}
			}
		}
	}
int seller::search_on_lists(string nazwa)
{
	for (int i = 0; i < 120; i++)
	{
		if (menu_items[i] == nazwa)
		{
			if (i < 80)
			{
				return 0;
			}
			else if (i < 100 && i >= 80)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
}
blacksmith::blacksmith()
{
	info[0] = "KUèNIA - ROZMOWA Z KOWALEM";
	info[1] = "W: ZAKO—CZ ROZMOW ";
	info[2] = "M: MIKSTURA ØYCIA";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	info[7] = "";
	menu[0] = "WZMOCNIJ HE£M [+1]";
	menu[1] = "WZMOCNIJ NAPIERåNIK [+1]";
	menu[2] = "WZMOCNIJ R KAWICE [+1]";
	menu[3] = "WZMOCNIJ SPODNIE [+1]";
	menu[4] = "WZMOCNIJ BUTY [+1]";
	menu[5] = "WZMOCNIJ BRO— [+1]";
	menu[6] = "";
	menu[7] = "";
	menu[8] = "";
	menu[9] = "";
	menu[10] = "";
	menu[11] = "";
	menu[12] = "";
	menu[13] = "";
	menu[14] = "";
	menu[15] = "";
	menu[16] = "";
	menu[17] = "";
	menu[18] = "";
	menu[19] = "";
	ceny[0] = 500;
	ceny[1] = 500;
	ceny[2] = 500;
	ceny[3] = 500;
	ceny[4] = 500;
	ceny[5] = 500;
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
}
int blacksmith::gold_info()
{
	return gold;
}
int blacksmith::rep_level_info()
{
	return rep_level;
}
int blacksmith::rep_points_info()
{
	return rep_points;
}
int blacksmith::rep_points_to_next_level_info()
{
	return rep_points_to_next_level;
}
void blacksmith::gold_set(int a)
{
	gold = a;
}
void blacksmith::rep_level_set(int a)
{
	rep_level = a;
}
void blacksmith::rep_points_set(int a)
{
	rep_points = a;
}
void blacksmith::rep_points_to_next_level_set(int a)
{
	rep_points_to_next_level = a;
}
void blacksmith::print_image()
{
	string linia;
	int nr_linii = 1;
	fstream plik;
	plik.open("./txt/kowal/kowal.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		cout << linia << endl;
	}
	plik.close();
	sound_blacksmith();
}
void blacksmith::power_up(player &gracz, int tryb)
{
	switch (tryb)
	{
	case 1:
	{
		if (gracz.gold >= ceny[0])
		{
			print_image();
			cout << endl << "TW”J HE£M ZOSTA£ WZMOCNIONY O JEDEN PUNKT" << endl;
			gracz.helmet = gracz.helmet + 1;
			gracz.gold = gracz.gold - ceny[0];
		}
		else
		{
			no_money();
		}
		system("PAUSE");
		break;
	}
	case 2:
	{
		if (gracz.gold >= ceny[1])
		{
			print_image();
			cout << "TW”J NAPIERSNIK ZOSTA£ WZMOCNIONY O JEDEN PUNKT" << endl;
			gracz.chestplate = gracz.chestplate + 1;
			gracz.gold = gracz.gold - ceny[1];
		}
		else
		{
			no_money();
		}
		system("PAUSE");
		break;
	}
	case 3:
	{
		if (gracz.gold >= ceny[2])
		{
			print_image();
			cout << "TWOJE REKAWICE ZOSTA£Y WZMOCNIONE O JEDEN PUNKT" << endl;
			gracz.gloves = gracz.gloves + 1;
			gracz.gold = gracz.gold - ceny[2];
		}
		else
		{
			no_money();
		}
		system("PAUSE");
		break;
	}
	case 4:
	{
		if (gracz.gold >= ceny[3])
		{
			print_image();
			cout << "TWOJE SPODNIE ZOSTA£Y WZMOCNIONE O JEDEN PUNKT" << endl;
			gracz.pants = gracz.pants + 1;
			gracz.gold = gracz.gold - ceny[3];
		}
		else
		{
			no_money();
		}
		system("PAUSE");
		break;
	}
	case 5:
	{
		if (gracz.gold >= ceny[4])
		{
			print_image();
			cout << "TWOJE BUTY ZOSTA£Y WZMOCNIONE O JEDEN PUNKT" << endl;
			gracz.shoes = gracz.shoes + 1;
			gracz.gold = gracz.gold - ceny[4];
		}
		else
		{
			no_money();
		}
		system("PAUSE");
		break;
	}
	case 6:
	{
		if (gracz.gold >= ceny[5])
		{
			print_image();
			cout << "TWOJA BRO— (" << gracz.weapon_name << ") ZOSTA£A WZMOCNIONA O JEDEN PUNKT" << endl;
			gracz.weapon = gracz.weapon + 1;
			gracz.gold = gracz.gold - ceny[5];
		}
		else
		{
			no_money();
		}
		system("PAUSE");
		break;
	}
	}
}
alchemist::alchemist()
{
	info[0] = "LABORATORIUM - ROZMOWA Z ALCHEMIKIEM";
	info[1] = "W: ZAKO—CZ ROZMOW ";
	info[2] = "M: MIKSTURA ØYCIA";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	info[7] = "";
	menu[0] = "KUP MIKSTURE NOWEGO POZIOMU";
	menu[1] = "KUP MIKSTURE ZDROWIA";
	menu[2] = "";
	menu[3] = "";
	menu[4] = "";
	menu[5] = "";
	menu[6] = "";
	menu[7] = "";
	menu[8] = "";
	menu[9] = "";
	menu[10] = "";
	menu[11] = "";
	menu[12] = "";
	menu[13] = "";
	menu[14] = "";
	menu[15] = "";
	menu[16] = "";
	menu[17] = "";
	menu[18] = "";
	menu[19] = "";
	ceny[0] = 0;
	ceny[1] = 100;
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
}
int alchemist::gold_info()
{
	return gold;
}
int alchemist::rep_level_info()
{
	return rep_level;
}
int alchemist::rep_points_info()
{
	return rep_points;
}
int alchemist::rep_points_to_next_level_info()
{
	return rep_points_to_next_level;
}
void alchemist::gold_set(int a)
{
	gold = a;
}
void alchemist::rep_level_set(int a)
{
	rep_level = a;
}
void alchemist::rep_points_set(int a)
{
	rep_points = a;
}
void alchemist::rep_points_to_next_level_set(int a)
{
	rep_points_to_next_level = a;
}
void alchemist::show_image()
{
	string linia;
	int nr_linii = 1;
	fstream plik;
	plik.open("./txt/alchemik/alchemik.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		cout << linia << endl;
	}
	plik.close();
	sound_alchemy();
}
void alchemist::buy_hp_potion(player &gracz)
{
	if (gracz.gold > ceny[1])
	{
		cout << "KUPI£Eå MIKSTUR  ZDROWIA" << endl;
		gracz.hp_potion = gracz.hp_potion + 1;
		gracz.gold = gracz.gold - ceny[1];
		show_image();
	}
	else
	{
		no_money();
	}
	system("PAUSE");
}
shaman::shaman()
{
	info[0] = "DOM SZMANA - ROZMOWA Z SZAMANEM";
	info[1] = "W: ZAKO—CZ ROZMOW ";
	info[2] = "M: MIKSTURA ØYCIA";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	info[7] = "";
	menu[0] = "POPROå O WZMOCNIENIE TWOJEJ SI£Y";
	menu[1] = "POPROå O WZMOCNIENIE TWOJEJ ZR CZNOåCI";
	menu[2] = "POPROå O WZMOCNIENIE TWOJEJ INTELIGENCJI";
	menu[3] = "POPROå O WZMOCNIENIE TWOJEJ CHARYZMY";
	menu[4] = "POPROå O WZMOCNIENIE TWOJEGO SZCZ åCIA";
	menu[5] = "";
	menu[6] = "";
	menu[7] = "";
	menu[8] = "";
	menu[9] = "";
	menu[10] = "";
	menu[11] = "";
	menu[12] = "";
	menu[13] = "";
	menu[14] = "";
	menu[15] = "";
	menu[16] = "";
	menu[17] = "";
	menu[18] = "";
	menu[19] = "";
	ceny[0] = 200;
	ceny[1] = 200;
	ceny[2] = 200;
	ceny[3] = 200;
	ceny[4] = 200;
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
}
int shaman::gold_info()
{
	return gold;
}
int shaman::rep_level_info()
{
	return rep_level;
}
int shaman::rep_points_info()
{
	return rep_points;
}
int shaman::rep_points_to_next_level_info()
{
	return rep_points_to_next_level;
}
void shaman::gold_set(int a)
{
	gold = a;
}
void shaman::rep_level_set(int a)
{
	rep_level = a;
}
void shaman::rep_points_set(int a)
{
	rep_points = a;
}
void shaman::rep_points_to_next_level_set(int a)
{
	rep_points_to_next_level = a;
}
void shaman::show_image()
{
	string linia;
	int nr_linii = 1;
	fstream plik;
	plik.open("./txt/dom_szamana/shaman.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		cout << linia << endl;
	}
	plik.close();
	sound_shaman();
}
void shaman::add_boost(player &gracz, int tryb)
{
	switch (tryb)
	{
	case 1:
	{
		if (gracz.counter_boost_str == 0)
		{
			if (gracz.gold >= ceny[0])
			{
				cout << "Twoja si≥a zosta≥a czasowo wzmocniona" << endl;
				add_boost_str(gracz, 3, 1);
				gracz.gold = gracz.gold - ceny[0];
				show_image();
			}
			else
			{
				no_money();
			}
		}
		else
		{
			cout << "Juø jesteú wzmocniony, to zbyt niebezpieczne by nak≥adaÊ kolejnπ premiÍ" << endl;
		}
		system("PAUSE");
		break;
	}
	case 2:
	{
		if (gracz.counter_boost_agility == 0)
		{
			if (gracz.gold >= ceny[1])
			{
				cout << "Twoja zrÍcznoúÊ zosta≥a czasowo wzmocniona" << endl;
				add_boost_agility(gracz, 3, 1);
				gracz.gold = gracz.gold - ceny[1];
				show_image();
			}
			else
			{
				no_money();
			}
		}
		else
		{
			cout << "Juø jesteú wzmocniony, to zbyt niebezpieczne by nak≥adaÊ kolejnπ premiÍ" << endl;
		}
		system("PAUSE");
		break;
	}
	case 3:
	{
		if (gracz.counter_boost_intel == 0)
		{
			if (gracz.gold >= ceny[2])
			{
				cout << "Twoja inteligencja zosta≥a czasowo wzmocniona" << endl;
				add_boost_intel(gracz, 3, 1);
				gracz.gold = gracz.gold - ceny[2];
				show_image();
			}
			else
			{
				no_money();
			}
		}
		else
		{
			cout << "Juø jesteú wzmocniony, to zbyt niebezpieczne by nak≥adaÊ kolejnπ premiÍ" << endl;
		}
		system("PAUSE");
		break;
	}
	case 4:
	{
		if (gracz.counter_boost_charisma == 0)
		{
			if (gracz.gold >= ceny[3])
			{
				cout << "Twoja charyzma zosta≥a czasowo wzmocniona" << endl;
				add_boost_charisma(gracz, 3, 1);
				gracz.gold = gracz.gold - ceny[3];
				show_image();
			}
			else
			{
				no_money();
			}
		}
		else
		{
			cout << "Juø jesteú wzmocniony, to zbyt niebezpieczne by nak≥adaÊ kolejnπ premiÍ" << endl;
		}
		system("PAUSE");
		break;
	}
	case 5:
	{
		if (gracz.counter_boost_luck == 0)
		{
			if (gracz.gold >= ceny[4])
			{
				cout << "Twoje szczÍúcie zosta≥o czasowo wzmocnione" << endl;
				add_boost_luck(gracz, 3, 1);
				gracz.gold = gracz.gold - ceny[4];
				show_image();
			}
			else
			{
				no_money();
			}
		}
		else
		{
			cout << "Juø jesteú wzmocniony, to zbyt niebezpieczne by nak≥adaÊ kolejnπ premiÍ" << endl;
		}
		system("PAUSE");
		break;
	}
	}
}
doctor::doctor()
{
	info[0] = "SZPITAL - ROZMOWA Z LEKARZEM";
	info[1] = "W: ZAKO—CZ ROZMOW ";
	info[2] = "M: MIKSTURA ØYCIA";
	info[3] = "";
	info[4] = "";
	info[5] = "";
	info[6] = "";
	info[7] = "";
	menu[0] = "POPROå O WYLECZENIE RAN";
	menu[1] = "POPROå O USUNI CIE ALKOHOLU Z ORGANIZMU";
	menu[2] = "POPROå O ULECZENIE TWOJEJ SI£Y";
	menu[3] = "POPROå O ULECZENIE TWOJEJ ZR CZNOåCI";
	menu[4] = "POPROå O ULECZENIE TWOJEJ INTELIGENCJI";
	menu[5] = "POPROå O ULECZENIE TWOJEJ CHARYZMY";
	menu[6] = "POPROå O ULECZENIE TWOJEGO SZCZ åCIA";
	menu[7] = "";
	menu[8] = "";
	menu[9] = "";
	menu[10] = "";
	menu[11] = "";
	menu[12] = "";
	menu[13] = "";
	menu[14] = "";
	menu[15] = "";
	menu[16] = "";
	menu[17] = "";
	menu[18] = "";
	menu[19] = "";
	ceny[0] = 300;
	ceny[1] = 50;
	ceny[2] = 100;
	ceny[3] = 100;
	ceny[4] = 100;
	ceny[5] = 100;
	ceny[6] = 100;
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
}
int doctor::gold_info()
{
	return gold;
}
int doctor::rep_level_info()
{
	return rep_level;
}
int doctor::rep_points_info()
{
	return rep_points;
}
int doctor::rep_points_to_next_level_info()
{
	return rep_points_to_next_level;
}
void doctor::gold_set(int a)
{
	gold = a;
}
void doctor::rep_level_set(int a)
{
	rep_level = a;
}
void doctor::rep_points_set(int a)
{
	rep_points = a;
}
void doctor::rep_points_to_next_level_set(int a)
{
	rep_points_to_next_level = a;
}
void doctor::show_image()
{
	string linia;
	int nr_linii = 1;
	fstream plik;
	plik.open("./txt/szpital/lekarz.txt", ios::in);
	while (!plik.eof())
	{
		getline(plik, linia);
		cout << linia << endl;
	}
	plik.close();
	sound_heal_up();
}
void doctor::heal(player &gracz)
{
	if (gracz.hp < gracz.max_hp)
	{
		if (gracz.gold >= ceny[0])
		{
			cout << "Twoje rany zosta≥y uleczone" << endl;
			gracz.hp = gracz.max_hp;
			gracz.gold = gracz.gold - ceny[0];
			show_image();
		}
		else
		{
			no_money();
		}
	}
	else
	{
		cout << "Nic ci nie dolega" << endl;
	}
	system("PAUSE");
}
void doctor::sober(player &gracz)
{
	if (gracz.alko != 0)
	{
		if (gracz.gold >= ceny[1])
		{
			cout << "Wytrzeüwia≥eú" << endl;
			gracz.alko = 0;
			gracz.gold = gracz.gold - ceny[1];
			show_image();
		}
		else
		{
			no_money();
		}
	}
	else
	{
		cout << "Jesteú trzeüwy" << endl;
	}
	system("PAUSE");
}
void doctor::remove_nerf(player &gracz, int tryb)
{
	switch (tryb)
	{
	case 1:
	{
		if (gracz.counter_nerf_str != 0)
		{
			if (gracz.gold >= ceny[2])
			{
				cout << "Twoja si≥a wraca do normy" << endl;
				remove_nerf_str(gracz);
				gracz.gold = gracz.gold - ceny[2];
				show_image();
			}
			else
			{
				no_money();
			}
		}
		else if (gracz.counter_boost_str != 0)
		{
			cout << "Nic ci nie dolega, a wrÍcz jest lepiej niø normalnie" << endl;
		}
		else
		{
			cout << "Nic ci nie dolega" << endl;
		}
		system("PAUSE");
		break;
	}
	case 2:
	{
		if (gracz.counter_nerf_agility != 0)
		{
			if (gracz.gold >= ceny[3])
			{
				cout << "Twoja zrÍcznoúÊ wraca do normy" << endl;
				remove_nerf_agility(gracz);
				gracz.gold = gracz.gold - ceny[3];
				show_image();
			}
			else
			{
				no_money();
			}
		}
		else if (gracz.counter_boost_agility != 0)
		{
			cout << "Nic ci nie dolega, a wrÍcz jest lepiej niø normalnie" << endl;
		}
		else
		{
			cout << "Nic ci nie dolega" << endl;
		}
		system("PAUSE");
		break;
	}
	case 3:
	{
		if (gracz.counter_nerf_intel != 0)
		{
			if (gracz.gold >= ceny[4])
			{
				cout << "Twoja inteligencja wraca do normy" << endl;
				remove_nerf_intel(gracz);
				gracz.gold = gracz.gold - ceny[4];
				show_image();
			}
			else
			{
				no_money();
			}
		}
		else if (gracz.counter_boost_intel != 0)
		{
			cout << "Nic ci nie dolega, a wrÍcz jest lepiej niø normalnie" << endl;
		}
		else
		{
			cout << "Nic ci nie dolega" << endl;
		}
		system("PAUSE");
		break;
	}
	case 4:
	{
		if (gracz.counter_nerf_charisma != 0)
		{
			if (gracz.gold >= ceny[5])
			{
				cout << "Twoja charyzma wraca do normy" << endl;
				remove_nerf_charisma(gracz);
				gracz.gold = gracz.gold - ceny[5];
				show_image();
			}
			else
			{
				no_money();
			}
		}
		else if (gracz.counter_boost_charisma != 0)
		{
			cout << "Nic ci nie dolega, a wrÍcz jest lepiej niø normalnie" << endl;
		}
		else
		{
			cout << "Nic ci nie dolega" << endl;
		}
		system("PAUSE");
		break;
	}
	case 5:
	{
		if (gracz.counter_nerf_luck != 0)
		{
			if (gracz.gold >= ceny[6])
			{
				cout << "Twoje szczÍúcie wraca do normy" << endl;
				remove_nerf_luck(gracz);
				gracz.gold = gracz.gold - ceny[6];
				show_image();
			}
			else
			{
				no_money();
			}
		}
		else if (gracz.counter_boost_luck != 0)
		{
			cout << "Nic ci nie dolega, a wrÍcz jest lepiej niø normalnie" << endl;
		}
		else
		{
			cout << "Nic ci nie dolega" << endl;
		}
		system("PAUSE");
		break;
	}
	}
}
#include "biblioteki.h"
#include "tawerna.h"
#include "walka.h"
#include "dwellers.h"


void tab(player gracz, string info[8], string menu[100], long ceny[20])
{
	system("cls");
	string pom1;
	int pomoc_lokacja;
	cout << "X-----------------------------------------X--------------------X--------------------X--------------------X-----------------------------------------X" << endl;
	{
		pom1 = "~~STATYSTYKI POSTACI~~";
		pomoc_lokacja = 41 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
	}
	{
		cout << "|";
		pom1 = "~~DZIEÑ " + to_string(gracz.licznik_dnia) + "~~";
		pomoc_lokacja = 62 - pom1.length();
		int i = pomoc_lokacja % 2;
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
	}
	{
		pom1 = "~~EKWIPUNEK POSTACI~~";
		pomoc_lokacja = 41 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
	}
	cout << "|" << endl;
	cout << "X-----------------------------------------X--------------------X--------------------X--------------------X-----------------------------------------X" << endl;
	{
		cout << "| IMIÊ POSTACI:         ";
		string expikk = gracz.nazwa;
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
	}
	{
		cout << "|";
		pom1 = "~~ZADANIE: " + gracz.quest + "~~";
		pomoc_lokacja = 92 - pom1.length();
		if (pomoc_lokacja < 0)
		{
			cout << "                     ~~B£¥D ZADANIA!!!~~                      ";
		}
		if (pomoc_lokacja == 79)
		{
			cout << "                       ~~BRAK ZADANIA~~                       ";
		}
		else
		{
			int i = pomoc_lokacja % 2;
			if (i == 0)
			{
				for (int j = 0; j < pomoc_lokacja / 2; j++)
				{
					cout << " ";
				}
			}
			else
			{
				for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
				{
					cout << " ";
				}
			}
			cout << pom1;
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
	}
	{
		cout << "| Z£OTO:                 ";
		string expikk = to_string(gracz.gold);
		pomoc_lokacja = 17 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	{
		cout << "| UMIEJÊTNOŒÆ POSTACI:  ";
		string expikk;
		if (gracz.skill == "")
		{
			expikk = "BRAK";
		}
		else
		{
			expikk = gracz.skill;
		}
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
	}
	cout << "X--------------------X--------------------X--------------------X";
	{
		cout << " PUNKTY HE£MU:          ";
		string expikk = to_string(gracz.helmet);
		pomoc_lokacja = 17 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	{
		cout << "| PUNKTY ¯YCIA:         ";
		string expikk = to_string(gracz.hp) + "/" + to_string(gracz.max_hp);
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		int barWidth = 60;
		cout << "|[";
		change_color(12);
		int pos = barWidth * gracz.hp / gracz.max_hp;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		change_color(7);
		cout << "]| PUNKTY NAPIERŒNIKA:    ";
		expikk = to_string(gracz.chestplate);
		pomoc_lokacja = 17 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	{
		cout << "| PUNKTY DOŒWIADCZENIA: ";
		string expikk = to_string(gracz.exp) + "/" + to_string(gracz.exp_to_next_level);
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		int barWidth = 60;
		cout << "|[";
		change_color(14);
		int pos = barWidth * gracz.exp / gracz.exp_to_next_level;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		change_color(7);
		cout << "]| PUNKTY RÊKAWIC:        ";
		expikk = to_string(gracz.gloves);
		pomoc_lokacja = 17 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	{
		cout << "| PUNKTY NAJEDZENIA:    ";
		string expikk = to_string(gracz.hunger) + "/10";
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		int barWidth = 60;
		cout << "|[";
		change_color(10);
		int pos = barWidth * gracz.hunger / 10;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		change_color(7);
		cout << "]| PUNKTY SPODNI:         ";
		expikk = to_string(gracz.pants);
		pomoc_lokacja = 17 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	{
		cout << "| UPOJENIE ALKOHOLOWE:  ";
		string expikk = to_string(gracz.alko) + "/10";
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		int barWidth = 60;
		cout << "|[";
		change_color(13);
		int pos = barWidth * gracz.alko / 10;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		change_color(7);
		cout << "]| PUNKTY BUTÓW:          ";
		expikk = to_string(gracz.shoes);
		pomoc_lokacja = 17 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	{
		cout << "| POZIOM POSTACI:       ";
		string expikk = to_string(gracz.level);
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "X--------------------X--------------------X--------------------X OBRA¯ENIA BRONI:       ";
		expikk = to_string(gracz.weapon);
		pomoc_lokacja = 17 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	{
		cout << "| RANGA POSTACI:        ";
		string expikk = gracz.pseudonym;
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|";
		pomoc_lokacja = 58 - info[0].length();
		int i = pomoc_lokacja % 2;
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << "~~" << info[0] << "~~";
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
		cout << "|                                         |"<<endl;
	}
	cout << "X--------------------X--------------------X--------------------X--------------------X--------------------X--------------------X--------------------X" << endl;
	for (int i = 0; i < 20; i++)
	{
		if (menu[i] != "" || menu[20 + i] != "" || menu[40 + i] != "" || menu[60 + i] != "" || menu[80 + i] !="")
		{
			{
				cout << "| " << menu[i];
				pomoc_lokacja = 22 - menu[i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
				pomoc_lokacja = 17 - menu[i + 20].length();
				if (menu[i] == "PUNKTY SI£Y:" && gracz.counter_nerf_str != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY SI£Y:" && gracz.counter_boost_str != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY ZRÊCZNOŒCI:" && gracz.counter_nerf_agility != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY ZRÊCZNOŒCI:" && gracz.counter_boost_agility != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY INTELIGENCJI:" && gracz.counter_nerf_intel != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY INTELIGENCJI:" && gracz.counter_boost_intel != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY SZCZÊŒCIA:" && gracz.counter_nerf_luck != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY SZCZÊŒCIA:" && gracz.counter_boost_luck != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY CHARYZMY:" && gracz.counter_nerf_charisma != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY CHARYZMY:" && gracz.counter_boost_charisma != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else
				{
					cout << menu[i + 20];
				}
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			
			cout << " |";
			if (menu[i + 40] != "")
			{
				string pomoc2;
				if (i >= 9)
				{
					pomoc2 = " " + to_string(i + 1) + ": " + menu[i + 40];
				}
				else
				{
					pomoc2 = "  " + to_string(i + 1) + ": " + menu[i + 40];
				}
				cout << pomoc2;
				if (ceny[i] == 0)
				{
					pomoc_lokacja = 62 - pomoc2.length();
					for (int j = 0; j < pomoc_lokacja; j++)
					{
						cout << " ";
					}
				}
				else
				{
					string pom3 = "[" + to_string(ceny[i]) + " Z£OTA]";
					pomoc_lokacja = 62 - (pomoc2.length() + pom3.length());
					for (int j = 0; j < pomoc_lokacja; j++)
					{
						cout << " ";
					}
					cout << pom3;
				}
			}
			else
			{
				cout << "                                                              ";
			}
			cout << "| " << menu[i + 60];
			pomoc_lokacja = 22 - menu[i + 60].length();
			for (int j = 0; j < pomoc_lokacja; j++)
			{
				cout << " ";
			}
			cout << " " << menu[i + 80];
			pomoc_lokacja = 17 - menu[i + 80].length();
			for (int j = 0; j < pomoc_lokacja; j++)
			{
				cout << " ";
			}
			cout << "|" << endl;
		}
	}
	cout << "X-----------------------------------------X--------------------X--------------------X--------------------X-----------------------------------------X" << endl;
	cout << "| " << info[1];
	pomoc_lokacja = 19 - info[1].length();
	for (int j = 0; j < pomoc_lokacja; j++)
	{
		cout << " ";
	}
	cout << "| " << info[2];
	pomoc_lokacja = 19 - info[2].length();
	for (int j = 0; j < pomoc_lokacja; j++)
	{
		cout << " ";
	}
	cout << "| " << info[3];
	pomoc_lokacja = 19 - info[3].length();
	for (int j = 0; j < pomoc_lokacja; j++)
	{
		cout << " ";
	}
	cout << "| " << info[4];
	pomoc_lokacja = 19 - info[4].length();
	for (int j = 0; j < pomoc_lokacja; j++)
	{
		cout << " ";
	}
	cout << "| " << info[5];
	pomoc_lokacja = 19 - info[5].length();
	for (int j = 0; j < pomoc_lokacja; j++)
	{
		cout << " ";
	}
	cout << "| " << info[6];
	pomoc_lokacja = 19 - info[6].length();
	for (int j = 0; j < pomoc_lokacja; j++)
	{
		cout << " ";
	}
	cout << "| " << info[7];
	pomoc_lokacja = 19 - info[7].length();
	for (int j = 0; j < pomoc_lokacja; j++)
	{
		cout << " ";
	}
	cout << "|";
	cout << "X-----------------------------------------X--------------------X--------------------X--------------------X-----------------------------------------X" << endl;
}
void tab_items(player gracz,string menu[60])
{
	system("cls");
	cout << "X------------------------------------------------X------------------------------------------------X------------------------------------------------X" << endl;
	string pom1;
	int pomoc_lokacja;
	{
		pom1 = "~~PRZEDMIOTY U¯YTKOWE~~";
		pomoc_lokacja = 48 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
	}
	{
		pom1 = "~~PRZEDMIOTY RZEMIEŒLNICZE~~";
		pomoc_lokacja = 48 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
	}
	{
		pom1 = "~~MIKSTURY~~";
		pomoc_lokacja = 48 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	cout << "X------------------------------------------------X------------------------------------------------X------------------------------------------------X" << endl;
	for (int i = 0; i < 20; i++)
	{
		if (menu[i] != "" || menu[20 + i] != "" || menu[40 + i] != "")
		{
			cout << "|";
			if (i < 9)
			{
				cout << "  " + to_string(i + 1) + ": ";
			}
			else
			{
				cout << " " + to_string(i + 1) + ": ";
			}
			cout << menu[i];
			pomoc_lokacja = 43 - menu[i].length();
			for (int j = 0; j < pomoc_lokacja; j++)
			{
				cout << " ";
			}
			cout << "|";
			cout << " " + to_string(i + 21) + ": ";
			cout << menu[20 + i];
			pomoc_lokacja = 43 - menu[20 + i].length();
			for (int j = 0; j < pomoc_lokacja; j++)
			{
				cout << " ";
			}
			cout << "|";
			cout << " " + to_string(i + 41) + ": ";
			cout << menu[40 + i];
			pomoc_lokacja = 43 - menu[40 + i].length();
			for (int j = 0; j < pomoc_lokacja; j++)
			{
				cout << " ";
			}
			cout << "|" << endl;
		}
	}
	cout << "X-----------------------X------------------------X-----------------------X------------------------X-----------------------X------------------------X" << endl;
	cout << "|                                                | W: WYJD Z EKWIPUNKU  |                        |                                                |" << endl;
	cout << "X-----------------------X------------------------X-----------------------X------------------------X-----------------------X------------------------X" << endl;
}

void tab_trade(player &gracz, seller &handlarz, string temp_table[80], string info[7],int temp_table_price[80], int temp_table_amount[80])
{
	system("cls");
	cout << "X-----------------------X-------------------------------------------------X------------------------------------------------X-----------------------X" << endl;
	{
		string pom1 = "HANDLARZ";
		int pomoc_lokacja = 23 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
	}
	{
		string pom1 = "Z£OTO: " + to_string(handlarz.gold_info());
		int pomoc_lokacja = 49 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
		cout << "|";
	}
	{
		string pom1 = "Z£OTO: " + to_string(gracz.gold);
		int pomoc_lokacja = 48 - pom1.length();
		int i = pomoc_lokacja % 2;
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
		cout << "|";
	}
	{
		string pom1 = gracz.nazwa;
		int pomoc_lokacja = 23 - pom1.length();
		int i = pomoc_lokacja % 2;
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	cout << "X-----------------------X-------------------------------------------------X------------------------------------------------X-----------------------X" << endl;
	{
		int pomoc_lokacja;
		string pom1 = "KUPNO TOWARÓW";
		pomoc_lokacja = 73 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
	}
	{
		int pomoc_lokacja;
		string pom1 = "SPRZEDA¯ TOWARÓW";
		pomoc_lokacja = 72 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
	}
	cout << "|" << endl;
	cout << "X-------------------------------------------------------------------------X------------------------------------------------------------------------X" << endl;
	int pomoc_lokacja;
	for (int i = 0; i < 20; i++)
	{
		if (temp_table[i] != "" || temp_table[40 + i] != "")
		{
			string pomoc2;
			cout << "|";
			if (i < 9)
			{
				pomoc2 = "  " + to_string(i + 1) + ": " + temp_table[i];
			}
			else
			{
				pomoc2 = " " + to_string(i + 1) + ": " + temp_table[i];
			}
			if (temp_table_amount[i] > 1)
			{
				pomoc2 = pomoc2 + " x" +to_string(temp_table_amount[i]);
			}
			cout << pomoc2;
			if (temp_table_price[i] == 0)
			{
				pomoc_lokacja = 68 - temp_table[i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			else
			{
				
				string pom3 = "[" + to_string(temp_table_price[i] * temp_table_amount[i]) + " Z£OTA]";
				pomoc_lokacja = 73 - (pomoc2.length() + pom3.length());
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
				cout << pom3;
			}
			cout << "|";
			pomoc2 = " " + to_string(i + 41) + ": " + temp_table[40 + i];
			if (temp_table_amount[40 + i] > 1)
			{
				pomoc2 = pomoc2 + " x" + to_string(temp_table_amount[40 + i]);
			}
			cout << pomoc2;
			if (temp_table_price[40 + i] == 0)
			{
				pomoc_lokacja = 67 - temp_table[40 + i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			else
			{
				string pom3 = "[" + to_string(temp_table_price[40 + i] * temp_table_amount[40 + i]) + " Z£OTA]";
				pomoc_lokacja = 72 - (pomoc2.length() + pom3.length());
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
				cout << pom3;
			}
			cout << "|" << endl;
			
		}
	}
	cout << "X-------------------------------------------------------------------------X------------------------------------------------------------------------X" << endl;
	{
		int suma = 0;
		for (int i = 0; i < 20; i++)
		{
			suma = suma + temp_table_price[i]*temp_table_amount[i];
		}
		string pom1 = "SUMA: " + to_string(suma);
		pomoc_lokacja = 73 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
	}
	{
		int suma = 0;
		for (int i = 0; i < 20; i++)
		{
			suma = suma + temp_table_price[40 + i] * temp_table_amount[40 + i];
		}
		string pom1 = "SUMA: " + to_string(suma);
		pomoc_lokacja = 72 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	cout << "X-------------------------------------------------------------------------X------------------------------------------------------------------------X" << endl;
	{
		int pomoc_lokacja;
		string pom1 = "EKWIPUNEK HANDLARZA";
		pomoc_lokacja = 73 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
	}
	{
		int pomoc_lokacja;
		string pom1 = "EKWIPUNEK POSTACI";
		pomoc_lokacja = 72 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
	}
	cout << "|" << endl;
	cout << "X-------------------------------------------------------------------------X------------------------------------------------------------------------X" << endl;
	for (int i = 0; i < 20; i++)
	{
		if (temp_table[20 + i] != "" || temp_table[60 + i] != "")
		{
			string pomoc2;
			cout << "|";
			pomoc2 = " " + to_string(i + 21) + ": " + temp_table[20 + i];
			cout << pomoc2;
			if (temp_table_price[20 + i] == 0)
			{
				pomoc_lokacja = 68 - temp_table[20 + i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			else
			{
				string pom3 = "[" + to_string(temp_table_price[20 + i]) + " Z£OTA]";
				pomoc_lokacja = 73 - (pomoc2.length() + pom3.length());
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
				cout << pom3;
			}
			cout << "|";
			pomoc2 = " " + to_string(i + 61) + ": " + temp_table[60 + i];
			if (temp_table_amount[60 + i] > 1)
			{
				pomoc2 = pomoc2 + " x" + to_string(temp_table_amount[60 + i]);
			}
			cout << pomoc2;
			if (temp_table_price[60 + i] == 0)
			{
				pomoc_lokacja = 67 - temp_table[60 + i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			else
			{
				string pom3 = "[" + to_string(temp_table_price[60 + i]) + " Z£OTA]";
				pomoc_lokacja = 72 - (pomoc2.length() + pom3.length());
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
				cout << pom3;
			}
			cout << "|" << endl;
		}
	}
	cout << "X-------------------------------------------------------------------------X------------------------------------------------------------------------X" << endl;
	{
		cout << "| " << info[0];
		pomoc_lokacja = 19 - info[0].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "| " << info[1];
		pomoc_lokacja = 19 - info[1].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "| " << info[2];
		pomoc_lokacja = 19 - info[2].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "| " << info[3];
		pomoc_lokacja = 19 - info[3].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "| " << info[4];
		pomoc_lokacja = 19 - info[4].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "| " << info[5];
		pomoc_lokacja = 19 - info[5].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "| " << info[6];
		pomoc_lokacja = 19 - info[6].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|";
	}
	cout << "X--------------------X--------------------X--------------------X--------------------X--------------------X--------------------X--------------------X" << endl;
}

void tab_fight(player gracz, string menu[80], Przeciwnik enemy)
{
	system("cls");
	string pom1;
	int pomoc_lokacja;
	cout << "X--------------------------------------------------------------------------------------------------------------X" << endl;
	{
		cout << "|";
		string pomoc = "GRACZ";
		pomoc_lokacja = 51 - pomoc.length();
		int i = pomoc_lokacja % 2;
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << "~~" << pomoc << "~~";
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
		cout << "|";
		pomoc = enemy.name;
		pomoc_lokacja = 50 - pomoc.length();
		i = pomoc_lokacja % 2;
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << "~~" << pomoc << "~~";
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
		cout <<"|"<<endl;
	}
	{
		int barWidth = 53;
		cout << "|[";
		change_color(12);
		int pos = barWidth * gracz.hp / gracz.max_hp;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		change_color(7);
		std::cout << "]|[";

		barWidth = 52;
		change_color(12);
		pos = barWidth * enemy.hp / enemy.max_hp;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		change_color(7);
		std::cout << "]|" << endl;
	}
	{
		cout << "|";
		string pomoc = to_string(gracz.hp) + "/" + to_string(gracz.max_hp);
		pomoc_lokacja = 55 - pomoc.length();
		int i = pomoc_lokacja % 2;
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pomoc ;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
		cout << "|";
	}
	{
		string pomoc = to_string(enemy.hp) + "/" + to_string(enemy.max_hp);
		pomoc_lokacja = 54 - pomoc.length();
		int i = pomoc_lokacja % 2;
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pomoc;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	cout << "X-----------------------------------------X-----------------------------------------------X--------------------X" << endl;
	cout << "|            STATYSTYKI GRACZA            |                   ~~WALCZ~~                   |     ~~SKRÓTY~~     |" << endl;
	cout << "X-----------------------------------------X-----------------------------------------------X--------------------X" << endl;
	for (int i = 0; i < 20; i++)
	{
		if (menu[i] != "" || menu[20 + i] != "" || menu[40 + i] != "" || menu[60 + i] != "")
		{
			if (menu[i] == "PRZEDMIOT 1:" || menu[i] == "PRZEDMIOT 2:" || menu[i] == "PRZEDMIOT 3:")
			{
				cout << "| " << menu[i];
				pomoc_lokacja = 14 - menu[i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
				pomoc_lokacja = 17 + 8 - menu[i + 20].length();
				cout << menu[i + 20];
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			else
			{
				cout << "| " << menu[i];
				pomoc_lokacja = 23 - menu[i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
				pomoc_lokacja = 16 - menu[i + 20].length();
				if (menu[i] == "PUNKTY SI£Y:" && gracz.counter_nerf_str != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY SI£Y:" && gracz.counter_boost_str != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY ZRÊCZNOŒCI:" && gracz.counter_nerf_agility != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY ZRÊCZNOŒCI:" && gracz.counter_boost_agility != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY INTELIGENCJI:" && gracz.counter_nerf_intel != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY INTELIGENCJI:" && gracz.counter_boost_intel != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY SZCZÊŒCIA:" && gracz.counter_nerf_luck != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY SZCZÊŒCIA:" && gracz.counter_boost_luck != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else
				{
					cout << menu[i + 20];
				}
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			cout << " |";
			if (menu[i + 40] != "")
			{
				string pomoc2;
				if (i >= 9)
				{
					pomoc2 = " " + to_string(i + 1) + ": " + menu[i + 40];
				}
				else
				{
					pomoc2 = "  " + to_string(i + 1) + ": " + menu[i + 40];
				}
				cout << pomoc2;
				pomoc_lokacja = 47 - pomoc2.length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			else
			{
				cout << "                                               ";
			}
			cout << "| " << menu[i + 60];
			pomoc_lokacja = 19 - menu[i + 60].length();
			for (int j = 0; j < pomoc_lokacja; j++)
			{
				cout << " ";
			}
			cout << "|" << endl;
		}
	}
	cout << "X-----------------------------------------X-----------------------------------------------X--------------------X" << endl;
}

void tab_cheat(player gracz, string info[8], string menu[80])
{
	system("cls");
	string pom1;
	int pomoc_lokacja;
	cout << "X--------------------X--------------------------------------------------------------------X--------------------X" << endl;
	//licznik dnia
	{
		pom1 = "~~DZIEÑ " + to_string(gracz.licznik_dnia) + "~~";
		pomoc_lokacja = 20 - pom1.length();
		int i = pomoc_lokacja % 2;
		cout << "|";
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
	}
	//zadanie
	{
		cout << "|";
		pom1 = "~~ZADANIE: " + gracz.quest + "~~";
		pomoc_lokacja = 68 - pom1.length();
		if (pomoc_lokacja < 0)
		{
			cout << "                       ~~B£¥D ZADANIA!!!~~                         ";
		}
		if (pomoc_lokacja == 55)
		{
			cout << "                         ~~BRAK ZADANIA~~                           ";
		}
		else
		{
			int i = pomoc_lokacja % 2;
			if (i == 0)
			{
				for (int j = 0; j < pomoc_lokacja / 2; j++)
				{
					cout << " ";
				}
			}
			else
			{
				for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
				{
					cout << " ";
				}
			}
			cout << pom1;
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
	}
	//z³oto
	{
		cout << "|";
		pom1 = "Z£OTO: " + to_string(gracz.gold);
		pomoc_lokacja = 20 - pom1.length();
		int i = pomoc_lokacja % 2;
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << pom1;
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	cout << "X--------------------X--------------------X-----------------------------------------------X--------------------X" << endl;
	//pasek hp
	{
		cout << "| PUNKTY ¯YCIA:         ";
		string expikk = to_string(gracz.hp) + "/" + to_string(gracz.max_hp);;
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		int barWidth = 66;
		cout << "|[";
		change_color(12);
		int pos = barWidth * gracz.hp / gracz.max_hp;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		change_color(7);
		std::cout << "]|" << endl;
	}
	//pasek expa
	{
		cout << "| PUNKTY DOŒWIADCZENIA: ";
		string expikk = to_string(gracz.exp) + "/" + to_string(gracz.exp_to_next_level);
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		int barWidth = 66;
		cout << "|[";
		change_color(14);
		int pos = barWidth * gracz.exp / gracz.exp_to_next_level;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		change_color(7);
		std::cout << "]|" << endl;
	}
	//pasek jedzenia
	{
		cout << "| PUNKTY NAJEDZENIA:    ";
		string expikk = to_string(gracz.hunger) + "/10";
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		int barWidth = 66;
		cout << "|[";
		change_color(10);
		int pos = barWidth * gracz.hunger / 10;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		change_color(7);
		std::cout << "]|" << endl;
	}
	if (gracz.alko != 0)
	{
		{
			cout << "| UPOJENIE ALKOHOLOWE:  ";
			string expikk = to_string(gracz.alko) + "/10";
			pomoc_lokacja = 18 - expikk.length();
			cout << expikk;
			for (int j = 0; j < pomoc_lokacja; j++)
			{
				cout << " ";
			}
			int barWidth = 66;
			cout << "|[";
			change_color(13);
			int pos = barWidth * gracz.alko / 10;
			for (int i = 0; i < barWidth; ++i) {
				if (i < pos)
				{
					cout << "#";
				}
				else
				{
					cout << " ";
				}
			}
			change_color(7);
			std::cout << "]|" << endl;
		}
	}
	{
		cout << "| POZIOM POSTACI:       ";
		string expikk = to_string(gracz.level);
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
	}
	cout << "X-----------------------------------------------X--------------------X" << endl;
	//g³ówna statystyka
	{
		cout << "| RANGA POSTACI:        ";
		string expikk = gracz.pseudonym;
		pomoc_lokacja = 18 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
	}
	cout << "| ";
	//lokacja
	{
		pomoc_lokacja = 42 - info[0].length();
		int i = pomoc_lokacja % 2;
		if (i == 0)
		{
			for (int j = 0; j < pomoc_lokacja / 2; j++)
			{
				cout << " ";
			}
		}
		else
		{
			for (int j = 0; j < (pomoc_lokacja / 2) + 1; j++)
			{
				cout << " ";
			}
		}
		cout << "~~" << info[0] << "~~";
		for (int j = 0; j < pomoc_lokacja / 2; j++)
		{
			cout << " ";
		}
		cout << "|     ~~SKRÓTY~~     |" << endl;
	}
	cout << "X-----------------------------------------X-----------------------------------------------X--------------------X" << endl;
	for (int i = 0; i < 20; i++)
	{
		if (menu[i] != "" || menu[20 + i] != "" || menu[40 + i] != "" || menu[60 + i] != "")
		{
			if (menu[i] == "PRZEDMIOT 1:" || menu[i] == "PRZEDMIOT 2:" || menu[i] == "PRZEDMIOT 3:")
			{
				cout << "| " << menu[i];
				pomoc_lokacja = 14 - menu[i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
				pomoc_lokacja = 17 + 8 - menu[i + 20].length();
				cout << menu[i + 20];
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			else
			{
				cout << "| " << menu[i];
				pomoc_lokacja = 23 - menu[i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
				pomoc_lokacja = 16 - menu[i + 20].length();
				if (menu[i] == "PUNKTY SI£Y:" && gracz.counter_nerf_str != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY SI£Y:" && gracz.counter_boost_str != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY ZRÊCZNOŒCI:" && gracz.counter_nerf_agility != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY ZRÊCZNOŒCI:" && gracz.counter_boost_agility != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY INTELIGENCJI:" && gracz.counter_nerf_intel != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY INTELIGENCJI:" && gracz.counter_boost_intel != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY SZCZÊŒCIA:" && gracz.counter_nerf_luck != 0)
				{
					change_color(12);
					cout << menu[i + 20];
					change_color(7);
				}
				else if (menu[i] == "PUNKTY SZCZÊŒCIA:" && gracz.counter_boost_luck != 0)
				{
					change_color(10);
					cout << menu[i + 20];
					change_color(7);
				}
				else
				{
					cout << menu[i + 20];
				}
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			cout << " |";
			if (menu[i + 40] != "")
			{
				string pomoc2;
				if (i >= 9)
				{
					pomoc2 = " " + to_string(i + 1) + ": " + menu[i + 40];
				}
				else
				{
					pomoc2 = "  " + to_string(i + 1) + ": " + menu[i + 40];
				}
				cout << pomoc2;
				pomoc_lokacja = 47 - pomoc2.length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			else
			{
				cout << "                                               ";
			}
			cout << "| " << menu[i + 60];
			pomoc_lokacja = 19 - menu[i + 60].length();
			for (int j = 0; j < pomoc_lokacja; j++)
			{
				cout << " ";
			}
			cout << "|" << endl;
		}
	}
	cout << "X-----------------------------------------X-----------------------------------------------X--------------------X" << endl;
}
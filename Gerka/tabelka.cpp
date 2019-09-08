#include "tabelka.h"

void draw_progress_bar(int min, int max, int how_long, int color)
{
	cout << "[";
	change_color(color);
	int pos = how_long * min / max;
	for (int i = 0; i < how_long; ++i) {
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
	cout << "]";
}
void draw_spaces(int i)
{
	for (int j = 0; j < i; j++)
	{
		cout << " ";
	}
}
void draw_on_center(int how_log, string name)
{
	int i = how_log % 2;
	if (i == 0)
	{
		for (int j = 0; j < how_log / 2; j++)
		{
			cout << " ";
		}
	}
	else
	{
		for (int j = 0; j < (how_log / 2) + 1; j++)
		{
			cout << " ";
		}
	}
	cout << name;
	for (int j = 0; j < how_log / 2; j++)
	{
		cout << " ";
	}
}
void draw_to_right_with_parameter_and_space_before(string name0, int how_long0, string name1, int how_long1)
{
	if (name0 == "")
	{
		cout << " " << name0;
		how_long0++;
	}
	else
	{
		cout << " " << name0 << ":";
	}
	for (int j = 0; j < how_long0; j++)
	{
		cout << " ";
	}
	cout << name1;
	for (int j = 0; j < how_long1; j++)
	{
		cout << " ";
	}
}
void tab(player gracz, string info[8], string menu[100], long ceny[20])
{
	system("cls");
	string pom1;
	int pomoc_lokacja;
	cout << "X-----------------------------------------X--------------------X--------------------X--------------------X-----------------------------------------X" << endl;
	{
		cout << "|";
		pom1 = "~~STATYSTYKI POSTACI~~";
		pomoc_lokacja = 41 - pom1.length();
		draw_on_center(pomoc_lokacja, pom1);
	}
	{
		cout << "|";
		pom1 = "~~DZIEÑ " + to_string(gracz.licznik_dnia) + "~~";
		pomoc_lokacja = 62 - pom1.length();
		draw_on_center(pomoc_lokacja, pom1);
	}
	{
		cout << "|";
		pom1 = "~~EKWIPUNEK POSTACI~~";
		pomoc_lokacja = 41 - pom1.length();
		draw_on_center(pomoc_lokacja, pom1);
	}
	cout << "|" << endl;
	cout << "X-----------------------------------------X--------------------X--------------------X--------------------X-----------------------------------------X" << endl;
	{
		cout << "|";
		string name0 = "IMIÊ POSTACI";
		int how_long0 = 21- name0.length();
		string name1 = gracz.nazwa;
		int how_long1= 18 - name1.length();
		draw_to_right_with_parameter_and_space_before(name0, how_long0, name1, how_long1);
	}
	{
		cout << "|";
		pom1 = "~~ZADANIE: " + gracz.quest + "~~";
		pomoc_lokacja = 62 - pom1.length();
		if (pomoc_lokacja < 0)
		{
			pom1 = "~~B£¥D ZADANIA!!!~~";
			draw_on_center(pomoc_lokacja, pom1);
		}
		if (pomoc_lokacja == 49)
		{
			pom1 = "~~BRAK ZADANIA~~";
			draw_on_center(pomoc_lokacja-3, pom1);
		}
		else
		{
			draw_on_center(pomoc_lokacja, pom1);
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
		cout << "|";
		string name0 = "UMIEJÊTNOŒÆ POSTACI";
		int how_long0 = 21 - name0.length();
		string name1;
		if (gracz.skill == "")
		{
			name1 = "BRAK";
		}
		else
		{
			name1 = gracz.skill;
		}
		int how_long1 = 18 - name1.length();
		draw_to_right_with_parameter_and_space_before(name0, how_long0, name1, how_long1);
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
		cout << "|";
		string name0 = "PUNKTY ¯YCIA";
		int how_long0 = 21 - name0.length();
		string name1 = to_string(gracz.hp) + "/" + to_string(gracz.max_hp);
		int how_long1 = 18 - name1.length();
		draw_to_right_with_parameter_and_space_before(name0, how_long0, name1, how_long1);
		cout << "|";
		draw_progress_bar(gracz.hp,gracz.max_hp,60,12);
		cout << "| PUNKTY NAPIERŒNIKA:    ";
		string expikk = to_string(gracz.chestplate);
		pomoc_lokacja = 17 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	{
		cout << "|";
		string name0 = "PUNKTY DOŒWIADCZENIA";
		int how_long0 = 21 - name0.length();
		string name1 = to_string(gracz.exp) + "/" + to_string(gracz.exp_to_next_level);
		int how_long1 = 18 - name1.length();
		draw_to_right_with_parameter_and_space_before(name0, how_long0, name1, how_long1);
		cout << "|";
		draw_progress_bar(gracz.exp, gracz.exp_to_next_level, 60, 14);
		cout << "| PUNKTY RÊKAWIC:        ";
		string expikk = to_string(gracz.gloves);
		pomoc_lokacja = 17 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	{
		cout << "|";
		string name0 = "PUNKTY NAJEDZENIA";
		int how_long0 = 21 - name0.length();
		string name1 = to_string(gracz.hunger) + "/10";
		int how_long1 = 18 - name1.length();
		draw_to_right_with_parameter_and_space_before(name0, how_long0, name1, how_long1);
		cout << "|";
		draw_progress_bar(gracz.hunger, 10, 60, 10);
		cout << "| PUNKTY SPODNI:         ";
		string expikk = to_string(gracz.pants);
		pomoc_lokacja = 17 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	{
		cout << "|";
		string name0 = "UPOJENIE ALKOHOLOWE";
		int how_long0 = 21 - name0.length();
		string name1 = to_string(gracz.alko) + "/10";
		int how_long1 = 18 - name1.length();
		draw_to_right_with_parameter_and_space_before(name0, how_long0, name1, how_long1);
		cout << "|";
		draw_progress_bar(gracz.alko, 10, 60, 13);
		cout << "| PUNKTY BUTÓW:          ";
		string expikk = to_string(gracz.shoes);
		pomoc_lokacja = 17 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	{
		cout << "|";
		string name0 = "POZIOM POSTACI";
		int how_long0 = 21 - name0.length();
		string name1 = to_string(gracz.level);
		int how_long1 = 18 - name1.length();
		draw_to_right_with_parameter_and_space_before(name0, how_long0, name1, how_long1);
		cout << "X--------------------X--------------------X--------------------X OBRA¯ENIA BRONI:       ";
		string expikk = to_string(gracz.weapon);
		pomoc_lokacja = 17 - expikk.length();
		cout << expikk;
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	{
		cout << "|";
		string name0 = "RANGA POSTACI";
		int how_long0 = 21 - name0.length();
		string name1 = gracz.pseudonym;
		int how_long1 = 18 - name1.length();
		draw_to_right_with_parameter_and_space_before(name0, how_long0, name1, how_long1);
	}
	{
		cout << "|";
		pomoc_lokacja = 58 - info[0].length();
		pom1 = "~~" + info[0] + "~~";
		draw_on_center(pomoc_lokacja, pom1);
	}
	{
		cout << "|";
		draw_spaces(41);
		cout << "|" << endl;
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
				draw_spaces(pomoc_lokacja);
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
					draw_spaces(pomoc_lokacja);
				}
				else
				{
					string pom3 = "[" + to_string(ceny[i]) + " Z£OTA]";
					pomoc_lokacja = 62 - (pomoc2.length() + pom3.length());
					draw_spaces(pomoc_lokacja);
					cout << pom3;
				}
			}
			else
			{
				draw_spaces(63);
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
	{
		cout << "| " << info[1];
		pomoc_lokacja = 19 - info[1].length();
		draw_spaces(pomoc_lokacja);
	}
	{
		cout << "| " << info[2];
		pomoc_lokacja = 19 - info[2].length();
		draw_spaces(pomoc_lokacja);
	}
	{
		cout << "| " << info[3];
		pomoc_lokacja = 19 - info[3].length();
		draw_spaces(pomoc_lokacja);
	}
	{
		cout << "| " << info[4];
		pomoc_lokacja = 19 - info[4].length();
		draw_spaces(pomoc_lokacja);
	}
	{
		cout << "| " << info[5];
		pomoc_lokacja = 19 - info[5].length();
		draw_spaces(pomoc_lokacja);
	}
	{
		cout << "| " << info[6];
		pomoc_lokacja = 19 - info[6].length();
		draw_spaces(pomoc_lokacja);
	}
	{
		cout << "| " << info[7];
		pomoc_lokacja = 19 - info[7].length();
		draw_spaces(pomoc_lokacja);
	}
	cout << "|"<<endl;
	cout << "X-----------------------------------------X--------------------X--------------------X--------------------X-----------------------------------------X" << endl;
}
void tab_items(player gracz,string menu[100], int menu_amount[60], string info[7])
{
	system("cls");
	cout << "X------------------------------------X------------------------------------X------------------------------------X-----------------------------------X" << endl;
	//36
	//36
	//36
	//35
	string pom1;
	int pomoc_lokacja;
	{
		cout << "|";
		pom1 = "~~PRZEDMIOTY U¯YTKOWE~~";
		pomoc_lokacja = 36 - pom1.length();
		draw_on_center(pomoc_lokacja,pom1);
	}
	{
		cout << "|";
		pom1 = "~~PRZEDMIOTY ALCHEMICZNE~~";
		pomoc_lokacja = 36 - pom1.length();
		draw_on_center(pomoc_lokacja, pom1);
	}
	{
		cout << "|";
		pom1 = "~~PRZEDMIOTY KOWALSKIE~~";
		pomoc_lokacja = 36 - pom1.length();
		draw_on_center(pomoc_lokacja, pom1);
	}
	{
		cout << "|";
		pom1 = "~~EKWIPUNEK POSTACI~~";
		pomoc_lokacja = 35 - pom1.length();
		draw_on_center(pomoc_lokacja, pom1);
	}
	cout << "|" << endl;
	cout << "X------------------------------------X------------------------------------X------------------------------------X-----------------------------------X" << endl;
	for (int i = 0; i < 20; i++)
	{
		if (menu[i] != "" || menu[20 + i] != "" || menu[40 + i] != "" || menu[60 + i] != "" || menu[80 + i] != "")
		{
			{
				cout << "|";
				string name;
				if (i < 9)
				{
					name = "  " + to_string(i + 1) + ": " + menu[i];
				}
				else
				{
					name = " " + to_string(i + 1) + ": " + menu[i];
				}
				if (menu_amount[i] > 1)
				{
					name = name + " x" + to_string(menu_amount[i]);
				}
				pomoc_lokacja = 36 - name.length();
				cout << name;
				draw_spaces(pomoc_lokacja);
			}
			{
				cout << "|";
				string name;
				name = " " + to_string(i + 21) + ": " + menu[20 + i];
				if (menu_amount[20 + i] > 1)
				{
					name = name + " x" + to_string(menu_amount[20 + i]);
				}
				pomoc_lokacja = 36 - name.length();
				cout << name;
				draw_spaces(pomoc_lokacja);
			}
			{
				cout << "|";
				string name;
				name = " " + to_string(i + 41) + ": " + menu[40 + i];
				if (menu_amount[40 + i] > 1)
				{
					name = name + " x" + to_string(menu_amount[40 + i]);
				}
				pomoc_lokacja = 36 - name.length();
				cout << name;
				draw_spaces(pomoc_lokacja);
			}
			{
				cout << "|";
				int how_long0 = 20 - menu[i + 60].length();
				int how_long1 = 13 - menu[i + 80].length();
				draw_to_right_with_parameter_and_space_before(menu[i + 60], how_long0, menu[i + 80], how_long1);
			}
			cout << "|" << endl;
		}
	}
	cout << "X-----------------------------------------X--------------------X--------------------X--------------------X-----------------------------------------X" << endl;
	{
		cout << "| " << info[0];
		pomoc_lokacja = 19 - info[0].length();
		draw_spaces(pomoc_lokacja);
	}
	{
		cout << "| " << info[1];
		pomoc_lokacja = 19 - info[1].length();
		draw_spaces(pomoc_lokacja);
	}
	{
		cout << "| " << info[2];
		pomoc_lokacja = 19 - info[2].length();
		draw_spaces(pomoc_lokacja);
	}
	{
		cout << "| " << info[3];
		pomoc_lokacja = 19 - info[3].length();
		draw_spaces(pomoc_lokacja);
	}
	{
		cout << "| " << info[4];
		pomoc_lokacja = 19 - info[4].length();
		draw_spaces(pomoc_lokacja);
	}
	{
		cout << "| " << info[5];
		pomoc_lokacja = 19 - info[5].length();
		draw_spaces(pomoc_lokacja);
	}
	{
		cout << "| " << info[6];
		pomoc_lokacja = 19 - info[6].length();
		draw_spaces(pomoc_lokacja);
	}
	cout << "|" << endl;
	cout << "X-----------------------------------------X--------------------X--------------------X--------------------X-----------------------------------------X" << endl;
}
void tab_trade(player &gracz, seller &handlarz, table &menu)
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
		if (menu.temp_table[i] != "" || menu.temp_table[40 + i] != "")
		{
			string pomoc2;
			cout << "|";
			if (i < 9)
			{
				pomoc2 = "  " + to_string(i + 1) + ": " + menu.temp_table[i];
			}
			else
			{
				pomoc2 = " " + to_string(i + 1) + ": " + menu.temp_table[i];
			}
			if (menu.temp_table_amount[i] > 1)
			{
				pomoc2 = pomoc2 + " x" +to_string(menu.temp_table_amount[i]);
			}
			cout << pomoc2;
			if (menu.temp_table_price[i] == 0)
			{
				pomoc_lokacja = 68 - menu.temp_table[i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			else
			{
				
				string pom3 = "[" + to_string(menu.temp_table_price[i] * menu.temp_table_amount[i]) + " Z£OTA]";
				pomoc_lokacja = 73 - (pomoc2.length() + pom3.length());
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
				cout << pom3;
			}
			cout << "|";
			pomoc2 = " " + to_string(i + 41) + ": " + menu.temp_table[40 + i];
			if (menu.temp_table_amount[40 + i] > 1)
			{
				pomoc2 = pomoc2 + " x" + to_string(menu.temp_table_amount[40 + i]);
			}
			cout << pomoc2;
			if (menu.temp_table_price[40 + i] == 0)
			{
				pomoc_lokacja = 67 - menu.temp_table[40 + i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			else
			{
				string pom3 = "[" + to_string(menu.temp_table_price[40 + i] * menu.temp_table_amount[40 + i]) + " Z£OTA]";
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
			suma = suma + menu.temp_table_price[i]* menu.temp_table_amount[i];
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
			suma = suma + menu.temp_table_price[40 + i] * menu.temp_table_amount[40 + i];
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
		if (menu.temp_table[20 + i] != "" || menu.temp_table[60 + i] != "")
		{
			string pomoc2;
			cout << "|";
			pomoc2 = " " + to_string(i + 21) + ": " + menu.temp_table[20 + i];
			cout << pomoc2;
			if (menu.temp_table_price[20 + i] == 0)
			{
				pomoc_lokacja = 68 - menu.temp_table[20 + i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			else
			{
				string pom3 = "[" + to_string(menu.temp_table_price[20 + i]) + " Z£OTA]";
				pomoc_lokacja = 73 - (pomoc2.length() + pom3.length());
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
				cout << pom3;
			}
			cout << "|";
			pomoc2 = " " + to_string(i + 61) + ": " + menu.temp_table[60 + i];
			if (menu.temp_table_amount[60 + i] > 1)
			{
				pomoc2 = pomoc2 + " x" + to_string(menu.temp_table_amount[60 + i]);
			}
			cout << pomoc2;
			if (menu.temp_table_price[60 + i] == 0)
			{
				pomoc_lokacja = 67 - menu.temp_table[60 + i].length();
				for (int j = 0; j < pomoc_lokacja; j++)
				{
					cout << " ";
				}
			}
			else
			{
				string pom3 = "[" + to_string(menu.temp_table_price[60 + i]) + " Z£OTA]";
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
		cout << "| " << menu.info[0];
		pomoc_lokacja = 19 - menu.info[0].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "| " << menu.info[1];
		pomoc_lokacja = 19 - menu.info[1].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "| " << menu.info[2];
		pomoc_lokacja = 19 - menu.info[2].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "| " << menu.info[3];
		pomoc_lokacja = 19 - menu.info[3].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "| " << menu.info[4];
		pomoc_lokacja = 19 - menu.info[4].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "| " << menu.info[5];
		pomoc_lokacja = 19 - menu.info[5].length();
		for (int j = 0; j < pomoc_lokacja; j++)
		{
			cout << " ";
		}
		cout << "| " << menu.info[6];
		pomoc_lokacja = 19 - menu.info[6].length();
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